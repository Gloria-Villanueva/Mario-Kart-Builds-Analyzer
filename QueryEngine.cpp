#include "QueryEngine.h"
#include "MK8Exception.h"

#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;

QueryEngine::QueryEngine(
    const vector<unique_ptr<Driver>>& drivers,
    const vector<unique_ptr<Body>>&   bodies,
    const vector<unique_ptr<Tire>>&   tires,
    const vector<unique_ptr<Glider>>& gliders
)
: drivers(drivers),
  bodies(bodies),
  tires(tires),
  gliders(gliders)
{}


// CONSULTA 1: Ranking

vector<Build> QueryEngine::ranking(int topN) const
{
    vector<Build> todos;

    for (const auto& d : drivers)
    for (const auto& b : bodies)
    for (const auto& t : tires)
    for (const auto& g : gliders)
        todos.emplace_back(d.get(), b.get(), t.get(), g.get());

    sort(todos.begin(), todos.end(),
        [](const Build& a, const Build& b){ return b < a; });

    // Deduplicar por score (muchas combos dan el mismo resultado)
    vector<Build> unicos;
    for (const Build& build : todos)
    {
        bool yaVisto = false;
        for (const Build& u : unicos)
        {
            if (abs(build.getPerformanceScore()
                    - u.getPerformanceScore()) < 0.001)
            { yaVisto = true; break; }
        }
        if (!yaVisto) unicos.push_back(build);
        if (topN > 0 && (int)unicos.size() >= topN) break;
    }

    return unicos;
}


// CONSULTA 2: Similitud

vector<Build> QueryEngine::similares(
    const Build& referencia, int k) const
{
    vector<pair<double, Build>> candidatos;

    for (const auto& d : drivers)
    for (const auto& b : bodies)
    for (const auto& t : tires)
    for (const auto& g : gliders)
    {
        Build candidato(d.get(), b.get(), t.get(), g.get());
        double dist = referencia.similarity(candidato);
        if (dist < 0.001) continue;  // excluir identico
        candidatos.emplace_back(dist, candidato);
    }

    if (candidatos.empty())
        throw MK8Exception("No se encontraron builds similares.");

    sort(candidatos.begin(), candidatos.end(),
        [](const auto& a, const auto& b){ return a.first < b.first; });

    // Deduplicar: un representante por score distinto
    vector<Build> resultado;
    vector<double> scoresVistos;

    for (const auto& par : candidatos)
    {
        double sc = par.second.getPerformanceScore();
        bool yaVisto = false;
        for (double sv : scoresVistos)
            if (abs(sc - sv) < 0.001) { yaVisto = true; break; }

        if (!yaVisto)
        {
            scoresVistos.push_back(sc);
            resultado.push_back(par.second);
        }
        if ((int)resultado.size() >= k) break;
    }

    return resultado;
}


// CONSULTA 3: Agregacion con filtro

double QueryEngine::agregacion(
    const string& tipoFiltro,
    const string& valorFiltro,
    const string& operacion) const
{
    // Trim helper
    auto trim = [](string s) {
        s.erase(0, s.find_first_not_of(" \t\r\n"));
        s.erase(s.find_last_not_of(" \t\r\n") + 1);
        return s;
    };

    vector<double> scores;

    if (tipoFiltro == "driver_size")
    {
        for (const auto& d : drivers)
            if (trim(d->getSize()) == valorFiltro)
                scores.push_back(d->calculateScore());
    }
    else if (tipoFiltro == "body_type")
    {
        for (const auto& b : bodies)
            if (trim(b->getVehicleType()) == valorFiltro)
                scores.push_back(b->calculateScore());
    }
    else
    {
        throw MK8Exception(
            "Tipo de filtro invalido: " + tipoFiltro +
            ". Use 'driver_size' o 'body_type'.");
    }

    if (scores.empty())
        throw MK8Exception(
            "No se encontraron componentes con " +
            tipoFiltro + " = " + valorFiltro);

    if (operacion == "promedio")
        return accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
    else if (operacion == "maximo")
        return *max_element(scores.begin(), scores.end());
    else if (operacion == "minimo")
        return *min_element(scores.begin(), scores.end());
    else
        throw MK8Exception(
            "Operacion invalida: " + operacion +
            ". Use 'promedio', 'maximo' o 'minimo'.");
}


// CONSULTA 4: Percentil

double QueryEngine::percentil(const Build& build) const
{
    double miScore = build.getPerformanceScore();
    long long menores = 0, total = 0;

    for (const auto& d : drivers)
    for (const auto& b : bodies)
    for (const auto& t : tires)
    for (const auto& g : gliders)
    {
        Build otro(d.get(), b.get(), t.get(), g.get());
        if (otro.getPerformanceScore() < miScore) menores++;
        total++;
    }

    return (static_cast<double>(menores) / total) * 100.0;
}
