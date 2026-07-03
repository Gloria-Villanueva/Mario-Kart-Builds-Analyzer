#ifndef COMPONENT_H
#define COMPONENT_H

#include <string>
#include <iostream>
using namespace std;

// Clase base abstracta de todo componente de un kart
// (Driver, Body, Tire, Glider). Se mantiene identica a la
// version de consola: es el "Modelo" puro, sin dependencias de Qt.
class Component {
protected:

    string name;

    int speedGround;
    int speedWater;
    int speedAir;
    int speedAntiG;

    int acceleration;
    int weight;

    int handlingGround;
    int handlingWater;
    int handlingAir;
    int handlingAntiG;

    int traction;

public:

    Component(
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

    virtual ~Component() = default;

    virtual string getType() const = 0;

    virtual double calculateScore() const = 0;

    string getName() const;

    int getSpeedGround() const;
    int getSpeedWater() const;
    int getSpeedAir() const;
    int getSpeedAntiG() const;

    int getAcceleration() const;
    int getWeight() const;

    int getHandlingGround() const;
    int getHandlingWater() const;
    int getHandlingAir() const;
    int getHandlingAntiG() const;

    int getTraction() const;

    bool operator<(const Component& other) const;
    bool operator==(const Component& other) const;

    friend ostream& operator<<(
        ostream& os,
        const Component& component
    );
};

#endif
