#include "Build.h"
#include <cmath>

using namespace std;

Build::Build(const Driver* driver, const Body* body, const Tire* tire, const Glider* glider): driver(driver), body(body), tire(tire), glider(glider){}

//speed ground
double Build::getSpeedGround() const
{
    return
    (
        driver->getSpeedGround()
        + body->getSpeedGround()
        + tire->getSpeedGround()
        + glider->getSpeedGround()
        + 3
    ) / 4.0;
}
//speed water
double Build::getSpeedWater() const
{
    return
    (
        driver->getSpeedWater()
        + body->getSpeedWater()
        + tire->getSpeedWater()
        + glider->getSpeedWater()
    ) / 4.0;
}
//speed air
double Build::getSpeedAir() const
{
    return
    (
        driver->getSpeedAir()
        + body->getSpeedAir()
        + tire->getSpeedAir()
        + glider->getSpeedAir()
    ) / 4.0;
}
//speed antiG
double Build::getSpeedAntiG() const 
{
    return
    (
        driver->getSpeedAntiG()
        + body->getSpeedAntiG()
        + tire->getSpeedAntiG()
        + glider->getSpeedAntiG()
    ) / 4.0;
}
//acceleration
double Build::getAcceleration() const
{
    return
    (   
        driver->getAcceleration()
        + body->getAcceleration()
        + tire->getAcceleration()
        + glider->getAcceleration()
    ) / 4.0;
}
//weight
double Build::getWeight() const
{
    return
    (
        driver->getWeight()
        + body->getWeight()
        + tire->getWeight()
        + glider->getWeight()
    ) / 4.0;
}
//handling ground
double Build::getHandlingGround() const
{
    return
    (
        driver->getHandlingGround()
        + body->getHandlingGround()
        + tire->getHandlingGround()
        + glider->getHandlingGround()
    ) / 4.0;
}
//handling water
double Build::getHandlingWater() const
{
    return
    (
        driver->getHandlingWater()
        + body->getHandlingWater()
        + tire->getHandlingWater()
        + glider->getHandlingWater()
    ) / 4.0;
}
//handling air
double Build::getHandlingAir() const
{
    return
    (
        driver->getHandlingAir()
        + body->getHandlingAir()
        + tire->getHandlingAir()
        + glider->getHandlingAir()
    ) / 4.0;
}
//handling antiG
double Build::getHandlingAntiG() const
{
    return
    (
        driver->getHandlingAntiG()
        + body->getHandlingAntiG()
        + tire->getHandlingAntiG()
        + glider->getHandlingAntiG()
    ) / 4.0;
}
//traction
double Build::getTraction() const
{
    return
    (
        driver->getTraction()
        + body->getTraction()
        + tire->getTraction()
        + glider->getTraction()
    ) / 4.0;
}
//performance score
double Build::getPerformanceScore() const   
{
    return
    0.20 * getSpeedGround() +
    0.20 * getAcceleration() +
    0.10 * getSpeedWater() +
    0.10 * getSpeedAir() +
    0.10 * getSpeedAntiG() +
    0.10 * getHandlingGround() +
    0.04 * getHandlingWater() +
    0.04 * getHandlingAir() +
    0.04 * getHandlingAntiG() +
    0.06 * getTraction() +
    0.02 * getWeight();
}   
//Operador <
bool Build::operator<(
    const Build& other
) const
{
    return getPerformanceScore()
           <
           other.getPerformanceScore();
}
// similitud
double Build::similarity(
    const Build& other
) const
{
    double diff = 0;

    diff += abs(
        getSpeedGround()
        - other.getSpeedGround()
    );

    diff += abs(
        getSpeedWater()
        - other.getSpeedWater()
    );

    diff += abs(
        getSpeedAir()
        - other.getSpeedAir()
    );

    diff += abs(
        getSpeedAntiG()
        - other.getSpeedAntiG()
    );

    diff += abs(
        getAcceleration()
        - other.getAcceleration()
    );

    diff += abs(
        getWeight()
        - other.getWeight()
    );

    diff += abs(
        getHandlingGround()
        - other.getHandlingGround()
    );

    diff += abs(
        getTraction()
        - other.getTraction()
    );

    return diff;
}
//Operador <<
ostream&operator<<(ostream& os,
           const Build& build)
{
    os
    << build.driver->getName()
    << " | "
    << build.body->getName()
    << " | "
    << build.tire->getName()
    << " | "
    << build.glider->getName();

    return os;
}