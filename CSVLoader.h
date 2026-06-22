#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <vector>
#include <memory>
#include <string>

#include "Driver.h"
#include "Body.h"
#include "Tire.h"
#include "Glider.h"

class CSVLoader {

public:

    static vector<unique_ptr<Driver>>
    loadDrivers(const string& filename);

    static vector<unique_ptr<Body>>
    loadBodies(const string& filename);

    static vector<unique_ptr<Tire>>
    loadTires(const string& filename);

    static vector<unique_ptr<Glider>>
    loadGliders(const string& filename);
};

#endif