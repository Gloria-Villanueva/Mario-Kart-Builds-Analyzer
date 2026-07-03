#ifndef BUILDVIEWMODEL_H
#define BUILDVIEWMODEL_H

#include <QObject>
#include <QString>
#include <memory>

#include "../core/Build.h"

// ViewModel de la build actualmente armada por el usuario.
// Traduce el Modelo (Build/Component, C++ puro) a propiedades Qt
// listas para bindear en QML (incluye valores normalizados 0..1
// para animar las barras de estadisticas).
class BuildViewModel : public QObject {
    Q_OBJECT

    Q_PROPERTY(bool ready READ ready NOTIFY changed)

    Q_PROPERTY(QString driverName READ driverName NOTIFY changed)
    Q_PROPERTY(QString bodyName READ bodyName NOTIFY changed)
    Q_PROPERTY(QString tireName READ tireName NOTIFY changed)
    Q_PROPERTY(QString gliderName READ gliderName NOTIFY changed)

    Q_PROPERTY(double speedGround READ speedGround NOTIFY changed)
    Q_PROPERTY(double speedWater READ speedWater NOTIFY changed)
    Q_PROPERTY(double speedAir READ speedAir NOTIFY changed)
    Q_PROPERTY(double speedAntiG READ speedAntiG NOTIFY changed)
    Q_PROPERTY(double acceleration READ acceleration NOTIFY changed)
    Q_PROPERTY(double weight READ weight NOTIFY changed)
    Q_PROPERTY(double handlingGround READ handlingGround NOTIFY changed)
    Q_PROPERTY(double handlingWater READ handlingWater NOTIFY changed)
    Q_PROPERTY(double handlingAir READ handlingAir NOTIFY changed)
    Q_PROPERTY(double handlingAntiG READ handlingAntiG NOTIFY changed)
    Q_PROPERTY(double traction READ traction NOTIFY changed)

    Q_PROPERTY(double normSpeedGround READ normSpeedGround NOTIFY changed)
    Q_PROPERTY(double normSpeedWater READ normSpeedWater NOTIFY changed)
    Q_PROPERTY(double normSpeedAir READ normSpeedAir NOTIFY changed)
    Q_PROPERTY(double normSpeedAntiG READ normSpeedAntiG NOTIFY changed)
    Q_PROPERTY(double normAcceleration READ normAcceleration NOTIFY changed)
    Q_PROPERTY(double normWeight READ normWeight NOTIFY changed)
    Q_PROPERTY(double normHandlingGround READ normHandlingGround NOTIFY changed)
    Q_PROPERTY(double normHandlingWater READ normHandlingWater NOTIFY changed)
    Q_PROPERTY(double normHandlingAir READ normHandlingAir NOTIFY changed)
    Q_PROPERTY(double normHandlingAntiG READ normHandlingAntiG NOTIFY changed)
    Q_PROPERTY(double normTraction READ normTraction NOTIFY changed)

    Q_PROPERTY(double performanceScore READ performanceScore NOTIFY changed)
    Q_PROPERTY(double normPerformanceScore READ normPerformanceScore NOTIFY changed)

public:
    explicit BuildViewModel(QObject* parent = nullptr);

    void setBuild(std::shared_ptr<Build> build);
    const Build* rawBuild() const { return m_build.get(); }

    bool ready() const { return m_build != nullptr; }

    QString driverName() const;
    QString bodyName() const;
    QString tireName() const;
    QString gliderName() const;

    double speedGround() const;
    double speedWater() const;
    double speedAir() const;
    double speedAntiG() const;
    double acceleration() const;
    double weight() const;
    double handlingGround() const;
    double handlingWater() const;
    double handlingAir() const;
    double handlingAntiG() const;
    double traction() const;

    double normSpeedGround() const;
    double normSpeedWater() const;
    double normSpeedAir() const;
    double normSpeedAntiG() const;
    double normAcceleration() const;
    double normWeight() const;
    double normHandlingGround() const;
    double normHandlingWater() const;
    double normHandlingAir() const;
    double normHandlingAntiG() const;
    double normTraction() const;

    double performanceScore() const;
    double normPerformanceScore() const;

signals:
    void changed();

private:
    std::shared_ptr<Build> m_build;
    static constexpr double kStatCap = 12.0;   // techo de normalizacion para las barras
    static constexpr double kScoreCap = 12.0;
};

#endif
