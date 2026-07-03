#ifndef QUERYENGINE_H
#define QUERYENGINE_H

#include <vector>
#include <string>
#include <memory>

#include "Build.h"
#include "Driver.h"
#include "Body.h"
#include "Tire.h"
#include "Glider.h"

using namespace std;

class QueryEngine {
private:
    const vector<unique_ptr<Driver>>& drivers;
    const vector<unique_ptr<Body>>&   bodies;
    const vector<unique_ptr<Tire>>&   tires;
    const vector<unique_ptr<Glider>>& gliders;

public:
    QueryEngine(
        const vector<unique_ptr<Driver>>& drivers,
        const vector<unique_ptr<Body>>&   bodies,
        const vector<unique_ptr<Tire>>&   tires,
        const vector<unique_ptr<Glider>>& gliders
    );

    // Ranking de builds: top N por performance score.
    vector<Build> ranking(int topN = 10) const;

    // Builds mas parecidos a una referencia.
    vector<Build> similares(const Build& referencia, int k = 5) const;

    // Agregacion (promedio / maximo / minimo) filtrada por categoria.
    double agregacion(
        const string& tipoFiltro,
        const string& valorFiltro,
        const string& operacion
    ) const;

    // Percentil de rendimiento de un build contra todo el catalogo.
    double percentil(const Build& build) const;
};

#endif
