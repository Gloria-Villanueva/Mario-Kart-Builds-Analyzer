#include "Component.h"
using namespace std;

Component::Component(
    const string& name, int speedGround, int speedWater, int speedAir,
    int speedAntiG, int acceleration, int weight, int handlingGround,
    int handlingWater, int handlingAir, int handlingAntiG, int traction)
    : name(name), speedGround(speedGround), speedWater(speedWater),
      speedAir(speedAir), speedAntiG(speedAntiG), acceleration(acceleration),
      weight(weight), handlingGround(handlingGround), handlingWater(handlingWater),
      handlingAir(handlingAir), handlingAntiG(handlingAntiG), traction(traction) {}

string Component::getName() const { return name; }

int Component::getSpeedGround() const { return speedGround; }
int Component::getSpeedWater() const { return speedWater; }
int Component::getSpeedAir() const { return speedAir; }
int Component::getSpeedAntiG() const { return speedAntiG; }

int Component::getAcceleration() const { return acceleration; }
int Component::getWeight() const { return weight; }

int Component::getHandlingGround() const { return handlingGround; }
int Component::getHandlingWater() const { return handlingWater; }
int Component::getHandlingAir() const { return handlingAir; }
int Component::getHandlingAntiG() const { return handlingAntiG; }

int Component::getTraction() const { return traction; }

bool Component::operator<(const Component& other) const {
    return calculateScore() < other.calculateScore();
}

bool Component::operator==(const Component& other) const {
    return name == other.name;
}

ostream& operator<<(ostream& os, const Component& component) {
    os << component.getName() << " [" << component.getType() << "]";
    return os;
}
