#ifndef APPCONTROLLER_H
#define APPCONTROLLER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <memory>
#include <vector>

#include "../core/Driver.h"
#include "../core/Body.h"
#include "../core/Tire.h"
#include "../core/Glider.h"
#include "../core/Build.h"
#include "../core/QueryEngine.h"

#include "../models/ComponentListModel.h"
#include "../models/BuildListModel.h"
#include "BuildViewModel.h"

// Controller / ViewModel raiz de la aplicacion.
// - Carga el catalogo (capa Model, CSVLoader) una sola vez al iniciar.
// - Expone modelos Qt listos para bindear en QML (capa View).
// - Traduce las acciones del usuario en llamadas al QueryEngine
//   (mismo motor de consultas del proyecto de consola original).
class AppController : public QObject {
    Q_OBJECT

    Q_PROPERTY(bool loaded READ loaded NOTIFY loadedChanged)
    Q_PROPERTY(QString errorMessage READ errorMessage NOTIFY errorChanged)

    Q_PROPERTY(ComponentListModel* driversModel READ driversModel CONSTANT)
    Q_PROPERTY(ComponentListModel* bodiesModel READ bodiesModel CONSTANT)
    Q_PROPERTY(ComponentListModel* tiresModel READ tiresModel CONSTANT)
    Q_PROPERTY(ComponentListModel* glidersModel READ glidersModel CONSTANT)

    Q_PROPERTY(BuildListModel* rankingModel READ rankingModel CONSTANT)
    Q_PROPERTY(BuildListModel* similarModel READ similarModel CONSTANT)

    Q_PROPERTY(BuildViewModel* currentBuild READ currentBuild CONSTANT)

    Q_PROPERTY(int selectedDriverIndex READ selectedDriverIndex NOTIFY selectionChanged)
    Q_PROPERTY(int selectedBodyIndex READ selectedBodyIndex NOTIFY selectionChanged)
    Q_PROPERTY(int selectedTireIndex READ selectedTireIndex NOTIFY selectionChanged)
    Q_PROPERTY(int selectedGliderIndex READ selectedGliderIndex NOTIFY selectionChanged)

    Q_PROPERTY(double lastPercentile READ lastPercentile NOTIFY percentileChanged)
    Q_PROPERTY(bool percentileReady READ percentileReady NOTIFY percentileChanged)

    Q_PROPERTY(QStringList driverSizes READ driverSizes CONSTANT)
    Q_PROPERTY(QStringList bodyTypes READ bodyTypes CONSTANT)

public:
    explicit AppController(QObject* parent = nullptr);

    bool loaded() const { return m_loaded; }
    QString errorMessage() const { return m_errorMessage; }

    ComponentListModel* driversModel() const { return m_driversModel; }
    ComponentListModel* bodiesModel() const { return m_bodiesModel; }
    ComponentListModel* tiresModel() const { return m_tiresModel; }
    ComponentListModel* glidersModel() const { return m_glidersModel; }

    BuildListModel* rankingModel() const { return m_rankingModel; }
    BuildListModel* similarModel() const { return m_similarModel; }

    BuildViewModel* currentBuild() const { return m_currentBuild; }

    int selectedDriverIndex() const { return m_selDriver; }
    int selectedBodyIndex() const { return m_selBody; }
    int selectedTireIndex() const { return m_selTire; }
    int selectedGliderIndex() const { return m_selGlider; }

    double lastPercentile() const { return m_lastPercentile; }
    bool percentileReady() const { return m_percentileReady; }

    QStringList driverSizes() const { return m_driverSizes; }
    QStringList bodyTypes() const { return m_bodyTypes; }

public slots:
    // Seleccion de componentes para armar el build actual
    void selectDriver(int index);
    void selectBody(int index);
    void selectTire(int index);
    void selectGlider(int index);

    // Consultas (equivalentes a las opciones 1-5 del menu de consola)
    void calculatePercentile();
    void computeRanking(int topN);
    void computeSimilar(int k);
    double computeAggregation(const QString& filterType, const QString& filterValue, const QString& operation);

private:
    void loadCatalog();
    void rebuildCurrentBuild();
    void setError(const QString& msg);

    bool m_loaded = false;
    QString m_errorMessage;

    std::vector<std::unique_ptr<Driver>> m_drivers;
    std::vector<std::unique_ptr<Body>>   m_bodies;
    std::vector<std::unique_ptr<Tire>>   m_tires;
    std::vector<std::unique_ptr<Glider>> m_gliders;

    std::unique_ptr<QueryEngine> m_queryEngine;

    ComponentListModel* m_driversModel;
    ComponentListModel* m_bodiesModel;
    ComponentListModel* m_tiresModel;
    ComponentListModel* m_glidersModel;

    BuildListModel* m_rankingModel;
    BuildListModel* m_similarModel;

    BuildViewModel* m_currentBuild;

    int m_selDriver = -1;
    int m_selBody = -1;
    int m_selTire = -1;
    int m_selGlider = -1;

    double m_lastPercentile = 0.0;
    bool m_percentileReady = false;

    QStringList m_driverSizes;
    QStringList m_bodyTypes;

signals:
    void loadedChanged();
    void errorChanged();
    void selectionChanged();
    void percentileChanged();
};

#endif
