#include "Tire.h"

Tire::Tire(
    const string& name,
    int speedGround, int speedWater, int speedAir, int speedAntiG,
    int acceleration, int weight,
    int handlingGround, int handlingWater, int handlingAir, int handlingAntiG,
    int traction)
    : Component(name, speedGround, speedWater, speedAir, speedAntiG,
                acceleration, weight, handlingGround, handlingWater,
                handlingAir, handlingAntiG, traction) {}

string Tire::getType() const { return "Tire"; }

double Tire::calculateScore() const {
    return
        0.20 * speedGround +
        0.20 * acceleration +
        0.10 * speedWater +
        0.10 * speedAir +
        0.10 * speedAntiG +
        0.10 * handlingGround +
        0.04 * handlingWater +
        0.04 * handlingAir +
        0.04 * handlingAntiG +
        0.06 * traction +
        0.02 * weight;
}
