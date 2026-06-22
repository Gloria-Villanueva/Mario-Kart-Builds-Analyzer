#ifndef BODY_H
#define BODY_H

#include "Component.h"

class Body : public Component {

private:

    string vehicleType;

public:

    Body(
        const string& name,
        const string& vehicleType,

        int speedGround,
        int speedWater,
        int speedAir,
        int speedAntiG,

        int acceleration,
        int weight,

        int handlingGround,
        int handlingWater,
        int handlingAir,
        int handlingAntiG,

        int traction
    );

    string getVehicleType() const;
    string getType() const override;
    double calculateScore() const override;
};

#endif