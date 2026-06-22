#include "CSVLoader.h"
#include "MK8Exception.h"

#include <fstream>
#include <sstream>

static vector<string>
splitCSV(const string& line)
{
    vector<string> tokens;
    stringstream ss(line);
    string token;

    while(getline(ss, token, ',')){
        tokens.push_back(token);
    }
    return tokens;
}
//LOADDRIVER
vector<unique_ptr<Driver>>
CSVLoader::loadDrivers(const string& filename)
{
    ifstream file(filename);

    if (!file){
        throw MK8Exception(
            "No se pudo abrir: " + filename
        );
    }

    vector<unique_ptr<Driver>> drivers;
    string line;

    getline(file, line); // encabezado

    while (getline(file, line))
    {
        auto row = splitCSV(line);

        if (row.size() != 13)
        {
            throw MK8Exception(
                "Linea invalida en Drivers.csv"
            );
        }

        try
        {
            drivers.push_back(
                make_unique<Driver>(

                    row[0], // Size
                    row[1], // Character

                    stoi(row[2]),
                    stoi(row[3]),
                    stoi(row[4]),
                    stoi(row[5]),

                    stoi(row[6]),
                    stoi(row[7]),

                    stoi(row[8]),
                    stoi(row[9]),
                    stoi(row[10]),
                    stoi(row[11]),

                    stoi(row[12])
                )
            );
        }
        catch (...)
        {
            throw MK8Exception(
                "Dato numerico invalido en Drivers.csv"
            );
        }
    }

    return drivers;
}
//LOADBODY
vector<unique_ptr<Body>>
CSVLoader::loadBodies(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        throw MK8Exception(
            "No se pudo abrir: " + filename
        );
    }

    vector<unique_ptr<Body>> bodies;

    string line;

    getline(file, line);

    while (getline(file, line))
    {
        auto row = splitCSV(line);

        if (row.size() != 13)
        {
            throw MK8Exception(
                "Linea invalida en Bodies.csv"
            );
        }

        try
        {
            bodies.push_back(
                make_unique<Body>(

                    row[0], // Body
                    row[1], // Vehicle Type

                    stoi(row[2]),
                    stoi(row[3]),
                    stoi(row[4]),
                    stoi(row[5]),

                    stoi(row[6]),
                    stoi(row[7]),

                    stoi(row[8]),
                    stoi(row[9]),
                    stoi(row[10]),
                    stoi(row[11]),

                    stoi(row[12])
                )
            );
        }
        catch (...)
        {
            throw MK8Exception(
                "Dato numerico invalido en Bodies.csv"
            );
        }
    }

    return bodies;
}
//LOADTIRE
vector<unique_ptr<Tire>>
CSVLoader::loadTires(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        throw MK8Exception(
            "No se pudo abrir: " + filename
        );
    }

    vector<unique_ptr<Tire>> tires;

    string line;

    getline(file, line);

    while (getline(file, line))
    {
        auto row = splitCSV(line);

        if (row.size() != 12)
        {
            throw MK8Exception(
                "Linea invalida en Tires.csv"
            );
        }

        try
        {
            tires.push_back(
                make_unique<Tire>(

                    row[0],

                    stoi(row[1]),
                    stoi(row[2]),
                    stoi(row[3]),
                    stoi(row[4]),

                    stoi(row[5]),
                    stoi(row[6]),

                    stoi(row[7]),
                    stoi(row[8]),
                    stoi(row[9]),
                    stoi(row[10]),

                    stoi(row[11])
                )
            );
        }
        catch (...)
        {
            throw MK8Exception(
                "Dato numerico invalido en Tires.csv"
            );
        }
    }

    return tires;
}
//LOADGLIDER
vector<unique_ptr<Glider>>
CSVLoader::loadGliders(const string& filename)
{
    ifstream file(filename);

    if (!file)
    {
        throw MK8Exception(
            "No se pudo abrir: " + filename
        );
    }

    vector<unique_ptr<Glider>> gliders;

    string line;

    getline(file, line);

    while (getline(file, line))
    {
        auto row = splitCSV(line);

        if (row.size() != 12)
        {
            throw MK8Exception(
                "Linea invalida en Gliders.csv"
            );
        }

        try
        {
            gliders.push_back(
                make_unique<Glider>(

                    row[0],

                    stoi(row[1]),
                    stoi(row[2]),
                    stoi(row[3]),
                    stoi(row[4]),

                    stoi(row[5]),
                    stoi(row[6]),

                    stoi(row[7]),
                    stoi(row[8]),
                    stoi(row[9]),
                    stoi(row[10]),

                    stoi(row[11])
                )
            );
        }
        catch (...)
        {
            throw MK8Exception(
                "Dato numerico invalido en Gliders.csv"
            );
        }
    }

    return gliders;
}