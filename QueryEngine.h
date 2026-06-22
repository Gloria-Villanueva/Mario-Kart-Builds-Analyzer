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

    // Referencias a los catalogos cargados (no son duenos de la memoria)
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

    // -------------------------------------------------------
    // CONSULTA 1: Ranking de builds
    // Construye N builds (top N del catalogo completo) y las
    // devuelve ordenadas de mayor a menor performance score.
    // topN = 0 significa devolver todas.
    // -------------------------------------------------------
    vector<Build> ranking(int topN = 10) const;

    // -------------------------------------------------------
    // CONSULTA 2: Similitud
    // Dado un build de referencia, devuelve los K builds mas
    // parecidos del catalogo (excluye el build identico).
    // -------------------------------------------------------
    vector<Build> similares(const Build& referencia, int k = 5) const;

    // -------------------------------------------------------
    // CONSULTA 3: Agregacion con filtro
    // Filtra el catalogo de COMPONENTES por categoria y
    // devuelve promedio / maximo / minimo del score.
    //
    // tipoFiltro: "driver_size", "body_type"
    // valorFiltro: "Small"/"Medium"/"Large" o "Kart"/"Std Bike"/etc.
    // operacion:  "promedio", "maximo", "minimo"
    // -------------------------------------------------------
    double agregacion(
        const string& tipoFiltro,
        const string& valorFiltro,
        const string& operacion
    ) const;

    // -------------------------------------------------------
    // CONSULTA 4: Percentil de rendimiento
    // Calcula en que percentil queda un build respecto a TODAS
    // las combinaciones posibles del catalogo.
    // -------------------------------------------------------
    double percentil(const Build& build) const;

};

#endif
