#include "AppController.h"
#include "../core/CSVLoader.h"
#include "../core/MK8Exception.h"

#include <algorithm>
#include <set>

AppController::AppController(QObject* parent) : QObject(parent) {
    m_driversModel = new ComponentListModel(this);
    m_bodiesModel = new ComponentListModel(this);
    m_tiresModel = new ComponentListModel(this);
    m_glidersModel = new ComponentListModel(this);

    m_rankingModel = new BuildListModel(this);
    m_similarModel = new BuildListModel(this);

    m_currentBuild = new BuildViewModel(this);

    loadCatalog();
}

static QString trimmedQ(const std::string& s) {
    return QString::fromStdString(s).trimmed();
}

void AppController::loadCatalog() {
    try {
        m_drivers = CSVLoader::loadDrivers(":/data/Drivers.csv");
        m_bodies  = CSVLoader::loadBodies(":/data/Bodies.csv");
        m_tires   = CSVLoader::loadTires(":/data/Tires.csv");
        m_gliders = CSVLoader::loadGliders(":/data/Gliders.csv");
    } catch (const MK8Exception& e) {
        setError(QString::fromStdString(e.what()));
        return;
    }

    m_queryEngine = std::make_unique<QueryEngine>(m_drivers, m_bodies, m_tires, m_gliders);

    // --- Poblar modelos de catalogo ---
    std::vector<const Component*> driverPtrs;
    QVector<QString> driverCats;
    std::set<QString> sizesSeen;
    for (const auto& d : m_drivers) {
        driverPtrs.push_back(d.get());
        QString size = trimmedQ(d->getSize());
        driverCats.push_back(size);
        sizesSeen.insert(size);
    }
    m_driverSizes = QStringList(sizesSeen.begin(), sizesSeen.end());

    std::vector<const Component*> bodyPtrs;
    QVector<QString> bodyCats;
    std::set<QString> typesSeen;
    for (const auto& b : m_bodies) {
        bodyPtrs.push_back(b.get());
        QString type = trimmedQ(b->getVehicleType());
        bodyCats.push_back(type);
        typesSeen.insert(type);
    }
    m_bodyTypes = QStringList(typesSeen.begin(), typesSeen.end());

    std::vector<const Component*> tirePtrs;
    for (const auto& t : m_tires) tirePtrs.push_back(t.get());

    std::vector<const Component*> gliderPtrs;
    for (const auto& g : m_gliders) gliderPtrs.push_back(g.get());

    m_driversModel->setData(driverPtrs, driverCats, "Driver", "qrc:/assets/icons/icon_driver.svg");
    m_bodiesModel->setData(bodyPtrs, bodyCats, "Body", "qrc:/assets/icons/icon_kart.svg");
    m_tiresModel->setData(tirePtrs, {}, "Tire", "qrc:/assets/icons/icon_tire.svg");
    m_glidersModel->setData(gliderPtrs, {}, "Glider", "qrc:/assets/icons/icon_glider.svg");

    // Seleccion inicial: el primer elemento de cada catalogo, para
    // que el usuario vea un build valido apenas abre la app.
    m_selDriver = m_drivers.empty() ? -1 : 0;
    m_selBody = m_bodies.empty() ? -1 : 0;
    m_selTire = m_tires.empty() ? -1 : 0;
    m_selGlider = m_gliders.empty() ? -1 : 0;
    rebuildCurrentBuild();

    m_loaded = true;
    emit loadedChanged();
    emit selectionChanged();
}

void AppController::rebuildCurrentBuild() {
    if (m_selDriver < 0 || m_selBody < 0 || m_selTire < 0 || m_selGlider < 0) return;
    if (m_selDriver >= (int)m_drivers.size() || m_selBody >= (int)m_bodies.size() ||
        m_selTire >= (int)m_tires.size() || m_selGlider >= (int)m_gliders.size()) return;

    auto build = std::make_shared<Build>(
        m_drivers[m_selDriver].get(),
        m_bodies[m_selBody].get(),
        m_tires[m_selTire].get(),
        m_gliders[m_selGlider].get()
    );
    m_currentBuild->setBuild(build);

    // Cambiar cualquier componente invalida el percentil calculado antes.
    m_percentileReady = false;
    emit percentileChanged();
}

void AppController::selectDriver(int index) {
    if (index == m_selDriver) return;
    m_selDriver = index;
    rebuildCurrentBuild();
    emit selectionChanged();
}
void AppController::selectBody(int index) {
    if (index == m_selBody) return;
    m_selBody = index;
    rebuildCurrentBuild();
    emit selectionChanged();
}
void AppController::selectTire(int index) {
    if (index == m_selTire) return;
    m_selTire = index;
    rebuildCurrentBuild();
    emit selectionChanged();
}
void AppController::selectGlider(int index) {
    if (index == m_selGlider) return;
    m_selGlider = index;
    rebuildCurrentBuild();
    emit selectionChanged();
}

void AppController::calculatePercentile() {
    if (!m_queryEngine || !m_currentBuild->rawBuild()) return;
    try {
        m_lastPercentile = m_queryEngine->percentil(*m_currentBuild->rawBuild());
        m_percentileReady = true;
        emit percentileChanged();
    } catch (const MK8Exception& e) {
        setError(QString::fromStdString(e.what()));
    }
}

void AppController::computeRanking(int topN) {
    if (!m_queryEngine) return;
    try {
        auto builds = m_queryEngine->ranking(topN);
        m_rankingModel->setBuilds(builds);
    } catch (const MK8Exception& e) {
        setError(QString::fromStdString(e.what()));
    }
}

void AppController::computeSimilar(int k) {
    if (!m_queryEngine || !m_currentBuild->rawBuild()) return;
    try {
        auto builds = m_queryEngine->similares(*m_currentBuild->rawBuild(), k);
        std::vector<double> distances;
        distances.reserve(builds.size());
        for (const auto& b : builds)
            distances.push_back(m_currentBuild->rawBuild()->similarity(b));
        m_similarModel->setBuilds(builds, distances);
    } catch (const MK8Exception& e) {
        setError(QString::fromStdString(e.what()));
    }
}

double AppController::computeAggregation(const QString& filterType, const QString& filterValue, const QString& operation) {
    if (!m_queryEngine) return 0.0;
    try {
        double result = m_queryEngine->agregacion(
            filterType.toStdString(), filterValue.toStdString(), operation.toStdString());
        return result;
    } catch (const MK8Exception& e) {
        setError(QString::fromStdString(e.what()));
        return -1.0;
    }
}

void AppController::setError(const QString& msg) {
    m_errorMessage = msg;
    emit errorChanged();
}
