#ifndef driver_h
#define driver_h

#include "Component.h"

class Driver: public Component{
private:
    string size;
public:
    Driver(
        const string& size,
        const string& name,

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

    string getSize() const;
    string getType() const override;
    double calculateScore() const override;
};

#endif