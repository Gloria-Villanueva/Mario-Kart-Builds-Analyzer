#ifndef BUILD_H
#define BUILD_H

#include <iostream>

#include "Driver.h"
#include "Body.h"
#include "Tire.h"
#include "Glider.h"

// Combinacion de los 4 componentes de un kart.
// Formula oficial del juego: (Driver + Body + Tires + Glider [+3 solo en Speed Ground]) / 4
class Build {
private:
    const Driver* driver;
    const Body* body;
    const Tire* tire;
    const Glider* glider;

public:
    Build(
        const Driver* driver,
        const Body* body,
        const Tire* tire,
        const Glider* glider
    );

    double getSpeedGround() const;
    double getSpeedWater() const;
    double getSpeedAir() const;
    double getSpeedAntiG() const;

    double getAcceleration() const;
    double getWeight() const;

    double getHandlingGround() const;
    double getHandlingWater() const;
    double getHandlingAir() const;
    double getHandlingAntiG() const;

    double getTraction() const;

    double getPerformanceScore() const;

    double similarity(const Build& other) const;

    bool operator<(const Build& other) const;

    const Driver* getDriver() const { return driver; }
    const Body* getBody() const { return body; }
    const Tire* getTire() const { return tire; }
    const Glider* getGlider() const { return glider; }

    friend ostream& operator<<(ostream& os, const Build& build);
};

#endif
