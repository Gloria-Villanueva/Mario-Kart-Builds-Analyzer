#ifndef CSVLOADER_H
#define CSVLOADER_H

#include <vector>
#include <memory>
#include <string>

#include "Driver.h"
#include "Body.h"
#include "Tire.h"
#include "Glider.h"

// Adaptado a Qt: lee desde el sistema de recursos (":/data/...")
// para que los CSV queden empaquetados dentro del .app en macOS
// y no dependan de la carpeta de trabajo desde la que se ejecuta.
class CSVLoader {
public:
    static vector<unique_ptr<Driver>> loadDrivers(const string& resourcePath);
    static vector<unique_ptr<Body>>   loadBodies(const string& resourcePath);
    static vector<unique_ptr<Tire>>   loadTires(const string& resourcePath);
    static vector<unique_ptr<Glider>> loadGliders(const string& resourcePath);
};

#endif
