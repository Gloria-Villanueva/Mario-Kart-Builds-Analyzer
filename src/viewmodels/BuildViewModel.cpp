#include "BuildViewModel.h"
#include <algorithm>

BuildViewModel::BuildViewModel(QObject* parent) : QObject(parent) {}

void BuildViewModel::setBuild(std::shared_ptr<Build> build) {
    m_build = std::move(build);
    emit changed();
}

static double clampNorm(double v, double cap) {
    return std::clamp(v / cap, 0.0, 1.0);
}

QString BuildViewModel::driverName() const {
    return m_build ? QString::fromStdString(m_build->getDriver()->getName()).trimmed() : QString();
}
QString BuildViewModel::bodyName() const {
    return m_build ? QString::fromStdString(m_build->getBody()->getName()).trimmed() : QString();
}
QString BuildViewModel::tireName() const {
    return m_build ? QString::fromStdString(m_build->getTire()->getName()).trimmed() : QString();
}
QString BuildViewModel::gliderName() const {
    return m_build ? QString::fromStdString(m_build->getGlider()->getName()).trimmed() : QString();
}

double BuildViewModel::speedGround() const { return m_build ? m_build->getSpeedGround() : 0.0; }
double BuildViewModel::speedWater() const { return m_build ? m_build->getSpeedWater() : 0.0; }
double BuildViewModel::speedAir() const { return m_build ? m_build->getSpeedAir() : 0.0; }
double BuildViewModel::speedAntiG() const { return m_build ? m_build->getSpeedAntiG() : 0.0; }
double BuildViewModel::acceleration() const { return m_build ? m_build->getAcceleration() : 0.0; }
double BuildViewModel::weight() const { return m_build ? m_build->getWeight() : 0.0; }
double BuildViewModel::handlingGround() const { return m_build ? m_build->getHandlingGround() : 0.0; }
double BuildViewModel::handlingWater() const { return m_build ? m_build->getHandlingWater() : 0.0; }
double BuildViewModel::handlingAir() const { return m_build ? m_build->getHandlingAir() : 0.0; }
double BuildViewModel::handlingAntiG() const { return m_build ? m_build->getHandlingAntiG() : 0.0; }
double BuildViewModel::traction() const { return m_build ? m_build->getTraction() : 0.0; }

double BuildViewModel::normSpeedGround() const { return clampNorm(speedGround(), kStatCap); }
double BuildViewModel::normSpeedWater() const { return clampNorm(speedWater(), kStatCap); }
double BuildViewModel::normSpeedAir() const { return clampNorm(speedAir(), kStatCap); }
double BuildViewModel::normSpeedAntiG() const { return clampNorm(speedAntiG(), kStatCap); }
double BuildViewModel::normAcceleration() const { return clampNorm(acceleration(), kStatCap); }
double BuildViewModel::normWeight() const { return clampNorm(weight(), kStatCap); }
double BuildViewModel::normHandlingGround() const { return clampNorm(handlingGround(), kStatCap); }
double BuildViewModel::normHandlingWater() const { return clampNorm(handlingWater(), kStatCap); }
double BuildViewModel::normHandlingAir() const { return clampNorm(handlingAir(), kStatCap); }
double BuildViewModel::normHandlingAntiG() const { return clampNorm(handlingAntiG(), kStatCap); }
double BuildViewModel::normTraction() const { return clampNorm(traction(), kStatCap); }

double BuildViewModel::performanceScore() const { return m_build ? m_build->getPerformanceScore() : 0.0; }
double BuildViewModel::normPerformanceScore() const { return clampNorm(performanceScore(), kScoreCap); }
