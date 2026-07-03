#include "CSVLoader.h"
#include "MK8Exception.h"

#include <QFile>
#include <QTextStream>
#include <QString>
#include <sstream>

using namespace std;

static vector<string> splitCSV(const string& line) {
    vector<string> tokens;
    stringstream ss(line);
    string token;
    while (getline(ss, token, ',')) {
        tokens.push_back(token);
    }
    return tokens;
}

// Abre un archivo (recurso Qt o ruta de disco) y devuelve sus lineas,
// ya sin el encabezado y sin retornos de carro sobrantes.
static vector<string> readLines(const string& path) {
    QFile file(QString::fromStdString(path));
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        throw MK8Exception("No se pudo abrir: " + path);
    }

    QTextStream in(&file);
    vector<string> lines;
    bool first = true;
    while (!in.atEnd()) {
        QString qline = in.readLine();
        if (first) { first = false; continue; } // encabezado
        if (qline.trimmed().isEmpty()) continue;
        lines.push_back(qline.toStdString());
    }
    return lines;
}

vector<unique_ptr<Driver>> CSVLoader::loadDrivers(const string& resourcePath) {
    vector<unique_ptr<Driver>> drivers;

    for (const auto& line : readLines(resourcePath)) {
        auto row = splitCSV(line);
        if (row.size() != 13)
            throw MK8Exception("Linea invalida en Drivers.csv");

        try {
            drivers.push_back(make_unique<Driver>(
                row[0], row[1],
                stoi(row[2]), stoi(row[3]), stoi(row[4]), stoi(row[5]),
                stoi(row[6]), stoi(row[7]),
                stoi(row[8]), stoi(row[9]), stoi(row[10]), stoi(row[11]),
                stoi(row[12])
            ));
        } catch (...) {
            throw MK8Exception("Dato numerico invalido en Drivers.csv");
        }
    }
    return drivers;
}

vector<unique_ptr<Body>> CSVLoader::loadBodies(const string& resourcePath) {
    vector<unique_ptr<Body>> bodies;

    for (const auto& line : readLines(resourcePath)) {
        auto row = splitCSV(line);
        if (row.size() != 13)
            throw MK8Exception("Linea invalida en Bodies.csv");

        try {
            bodies.push_back(make_unique<Body>(
                row[0], row[1],
                stoi(row[2]), stoi(row[3]), stoi(row[4]), stoi(row[5]),
                stoi(row[6]), stoi(row[7]),
                stoi(row[8]), stoi(row[9]), stoi(row[10]), stoi(row[11]),
                stoi(row[12])
            ));
        } catch (...) {
            throw MK8Exception("Dato numerico invalido en Bodies.csv");
        }
    }
    return bodies;
}

vector<unique_ptr<Tire>> CSVLoader::loadTires(const string& resourcePath) {
    vector<unique_ptr<Tire>> tires;

    for (const auto& line : readLines(resourcePath)) {
        auto row = splitCSV(line);
        if (row.size() != 12)
            throw MK8Exception("Linea invalida en Tires.csv");

        try {
            tires.push_back(make_unique<Tire>(
                row[0],
                stoi(row[1]), stoi(row[2]), stoi(row[3]), stoi(row[4]),
                stoi(row[5]), stoi(row[6]),
                stoi(row[7]), stoi(row[8]), stoi(row[9]), stoi(row[10]),
                stoi(row[11])
            ));
        } catch (...) {
            throw MK8Exception("Dato numerico invalido en Tires.csv");
        }
    }
    return tires;
}

vector<unique_ptr<Glider>> CSVLoader::loadGliders(const string& resourcePath) {
    vector<unique_ptr<Glider>> gliders;

    for (const auto& line : readLines(resourcePath)) {
        auto row = splitCSV(line);
        if (row.size() != 12)
            throw MK8Exception("Linea invalida en Gliders.csv");

        try {
            gliders.push_back(make_unique<Glider>(
                row[0],
                stoi(row[1]), stoi(row[2]), stoi(row[3]), stoi(row[4]),
                stoi(row[5]), stoi(row[6]),
                stoi(row[7]), stoi(row[8]), stoi(row[9]), stoi(row[10]),
                stoi(row[11])
            ));
        } catch (...) {
            throw MK8Exception("Dato numerico invalido en Gliders.csv");
        }
    }
    return gliders;
}
