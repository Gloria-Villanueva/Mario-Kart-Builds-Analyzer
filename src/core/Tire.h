#ifndef TIRE_H
#define TIRE_H

#include "Component.h"

class Tire : public Component {
public:
    Tire(
        const string& name,
        int speedGround, int speedWater, int speedAir, int speedAntiG,
        int acceleration, int weight,
        int handlingGround, int handlingWater, int handlingAir, int handlingAntiG,
        int traction
    );

    string getType() const override;
    double calculateScore() const override;
};

#endif
