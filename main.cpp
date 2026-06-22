#include <iostream>
#include <vector>
#include <limits>
#include <iomanip>

#include "CSVLoader.h"
#include "Build.h"
#include "QueryEngine.h"
#include "MK8Exception.h"
#include "Component.h"

using namespace std;

int pedirIndice(int maximo)
{
    int opcion;
    while (true)
    {
        cin >> opcion;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Entrada invalida. Ingresa un numero: ";
            continue;
        }
        if (opcion < 0 || opcion >= maximo)
        {
            cout << "  Indice fuera de rango (0-"
                 << maximo - 1 << "): ";
            continue;
        }
        return opcion;
    }
}

int pedirOpcion(int minVal, int maxVal)
{
    int opcion;
    while (true)
    {
        cin >> opcion;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  Entrada invalida. Ingresa un numero: ";
            continue;
        }
        if (opcion < minVal || opcion > maxVal)
        {
            cout << "  Opcion invalida ("
                 << minVal << "-" << maxVal << "): ";
            continue;
        }
        return opcion;
    }
}

// Muestra lista de componentes numerada
template <typename T>
void listarComponentes(const vector<unique_ptr<T>>& vec,
                       const string& titulo)
{
    cout << "\n--- " << titulo << " ---\n";
    for (size_t i = 0; i < vec.size(); i++)
        cout << "  " << setw(2) << i
             << " - " << vec[i]->getName() << "\n";
}

// Seleccion de un build por parte del usuario
Build seleccionarBuild(
    const vector<unique_ptr<Driver>>& drivers,
    const vector<unique_ptr<Body>>&   bodies,
    const vector<unique_ptr<Tire>>&   tires,
    const vector<unique_ptr<Glider>>& gliders)
{
    listarComponentes(drivers, "DRIVERS");
    cout << "  Selecciona driver (0-"
         << drivers.size()-1 << "): ";
    int di = pedirIndice(drivers.size());

    listarComponentes(bodies, "BODIES");
    cout << "  Selecciona body (0-"
         << bodies.size()-1 << "): ";
    int bi = pedirIndice(bodies.size());

    listarComponentes(tires, "TIRES");
    cout << "  Selecciona tire (0-"
         << tires.size()-1 << "): ";
    int ti = pedirIndice(tires.size());

    listarComponentes(gliders, "GLIDERS");
    cout << "  Selecciona glider (0-"
         << gliders.size()-1 << "): ";
    int gi = pedirIndice(gliders.size());

    return Build(
        drivers[di].get(),
        bodies[bi].get(),
        tires[ti].get(),
        gliders[gi].get()
    );
}

void mostrarBuild(const Build& b)
{
    cout << fixed << setprecision(2);
    cout << "\n  Build: " << b << "\n";
    cout << "  +-----------------------+-------+\n";
    cout << "  | Atributo              | Valor |\n";
    cout << "  +-----------------------+-------+\n";
    cout << "  | Velocidad Tierra      | "
         << setw(5) << b.getSpeedGround()    << " |\n";
    cout << "  | Velocidad Agua        | "
         << setw(5) << b.getSpeedWater()     << " |\n";
    cout << "  | Velocidad Aire        | "
         << setw(5) << b.getSpeedAir()       << " |\n";
    cout << "  | Velocidad Anti-G      | "
         << setw(5) << b.getSpeedAntiG()     << " |\n";
    cout << "  | Aceleracion           | "
         << setw(5) << b.getAcceleration()   << " |\n";
    cout << "  | Peso                  | "
         << setw(5) << b.getWeight()         << " |\n";
    cout << "  | Manejo Tierra         | "
         << setw(5) << b.getHandlingGround() << " |\n";
    cout << "  | Manejo Agua           | "
         << setw(5) << b.getHandlingWater()  << " |\n";
    cout << "  | Manejo Aire           | "
         << setw(5) << b.getHandlingAir()    << " |\n";
    cout << "  | Manejo Anti-G         | "
         << setw(5) << b.getHandlingAntiG()  << " |\n";
    cout << "  | Agarre                | "
         << setw(5) << b.getTraction()       << " |\n";
    cout << "  +-----------------------+-------+\n";
    cout << "  | PERFORMANCE SCORE     | "
         << setw(5) << b.getPerformanceScore() << " |\n";
    cout << "  +-----------------------+-------+\n";
}

void mostrarCatalogoPolimorfico(
    const vector<Component*>& catalogo,
    const string& filtroTipo = "")
{
    cout << "\n--- CATALOGO";
    if (!filtroTipo.empty())
        cout << " [" << filtroTipo << "]";
    cout << " ---\n";
    cout << fixed << setprecision(2);

    int mostrados = 0;
    for (const Component* c : catalogo)
    {
        // Si hay filtro, saltamos los que no coinciden
        if (!filtroTipo.empty() && c->getType() != filtroTipo)
            continue;

        // operator<< polimorficamente (nombre + tipo)
        cout << "  " << *c
             << "  |  score: "
             << setw(5) << c->calculateScore()  // virtual puro
             << "\n";
        mostrados++;
    }

    if (mostrados == 0)
        throw MK8Exception(
            "No se encontraron componentes de tipo: " + filtroTipo
        );

    cout << "  (" << mostrados << " componentes)\n";
}

int main()
{
    cout << "\n╔══════════════════════════════════════╗\n";
    cout << "║   MARIO KART 8 - BUILD ANALYZER      ║\n";
    cout << "╚══════════════════════════════════════╝\n";

    // --- Carga de datos ---
    vector<unique_ptr<Driver>> drivers;
    vector<unique_ptr<Body>>   bodies;
    vector<unique_ptr<Tire>>   tires;
    vector<unique_ptr<Glider>> gliders;

    try
    {
        cout << "\nCargando catalogos...\n";
        drivers = CSVLoader::loadDrivers("data/Drivers.csv");
        bodies  = CSVLoader::loadBodies("data/Bodies.csv");
        tires   = CSVLoader::loadTires("data/Tires.csv");
        gliders = CSVLoader::loadGliders("data/Gliders.csv");
        cout << "  Drivers : " << drivers.size() << "\n";
        cout << "  Bodies  : " << bodies.size()  << "\n";
        cout << "  Tires   : " << tires.size()   << "\n";
        cout << "  Gliders : " << gliders.size() << "\n";
    }
    catch (const MK8Exception& e)
    {
        cout << "\n[ERROR al cargar] " << e.what() << "\n";
        return 1;
    }

    vector<Component*> catalogo;
    catalogo.reserve(
        drivers.size() + bodies.size() +
        tires.size()   + gliders.size()
    );

    for (const auto& d : drivers) catalogo.push_back(d.get());
    for (const auto& b : bodies)  catalogo.push_back(b.get());
    for (const auto& t : tires)   catalogo.push_back(t.get());
    for (const auto& g : gliders) catalogo.push_back(g.get());

    QueryEngine qe(drivers, bodies, tires, gliders);

    // --- Menu principal ---
    bool salir = false;
    while (!salir)
    {
        cout << "\n┌─────────────────────────────────────┐\n";
        cout << "│           MENU PRINCIPAL            │\n";
        cout << "├─────────────────────────────────────┤\n";
        cout << "│  1. Armar y analizar mi build       │\n";
        cout << "│  2. Ranking top builds              │\n";
        cout << "│  3. Builds similares a la mia       │\n";
        cout << "│  4. Estadisticas por categoria      │\n";
        cout << "│  5. Ver catalogo de componentes     │\n";
        cout << "│  0. Salir                           │\n";
        cout << "└─────────────────────────────────────┘\n";
        cout << "  Opcion: ";

        int opcion = pedirOpcion(0, 5);

        try
        {

            // OPCION 1: Armar build + percentil

            if (opcion == 1)
            {
                cout << "\n=== ARMA TU BUILD ===\n";
                Build miBuild = seleccionarBuild(
                    drivers, bodies, tires, gliders
                );

                mostrarBuild(miBuild);

                cout << "\n  Calculando percentil de rendimiento...\n";
                double perc = qe.percentil(miBuild);
                cout << fixed << setprecision(1);
                cout << "\n  ★ Percentil de Rendimiento: "
                     << perc << " %\n";
                cout << "    Tu build supera al "
                     << perc
                     << "% de todas las combinaciones posibles.\n";
            }


            // OPCION 2: Ranking top 
            else if (opcion == 2)
            {
                cout << "\n  Cuantos builds mostrar en el ranking? (1-20): ";
                int n = pedirOpcion(1, 20);

                cout << "\n  Calculando ranking...\n";
                vector<Build> top = qe.ranking(n);

                cout << "\n=== TOP " << n
                     << " BUILDS POR PERFORMANCE ===\n";
                cout << fixed << setprecision(2);
                for (int i = 0; i < (int)top.size(); i++)
                {
                    cout << "\n  #" << setw(2) << (i+1)
                         << " [Score: "
                         << setw(5) << top[i].getPerformanceScore()
                         << "]  " << top[i] << "\n";
                }
            }


            // OPCION 3: Similitud
 
            else if (opcion == 3)
            {
                cout << "\n=== ARMA TU BUILD DE REFERENCIA ===\n";
                Build miBuild = seleccionarBuild(
                    drivers, bodies, tires, gliders
                );

                mostrarBuild(miBuild);

                cout << "\n  Cuantos builds similares quieres ver? (1-10): ";
                int k = pedirOpcion(1, 10);

                cout << "\n  Buscando builds similares...\n";
                vector<Build> sim = qe.similares(miBuild, k);

                cout << "\n=== " << k
                     << " BUILDS MAS SIMILARES ===\n";
                cout << fixed << setprecision(2);
                for (int i = 0; i < (int)sim.size(); i++)
                {
                    cout << "\n  #" << setw(2) << (i+1)
                         << " [Score: "
                         << setw(5) << sim[i].getPerformanceScore()
                         << "]  " << sim[i] << "\n";
                }
            }

            // OPCION 4: Agregacion con filtro
            else if (opcion == 4)
            {
                cout << "\n=== ESTADISTICAS POR CATEGORIA ===\n";
                cout << "\n  Filtrar por:\n";
                cout << "    1. Tamano de driver (Small / Medium / Large)\n";
                cout << "    2. Tipo de body (Kart / Std Bike / Sport Bike)\n";
                cout << "  Opcion: ";
                int filtroOp = pedirOpcion(1, 2);

                string tipoFiltro, valorFiltro;

                if (filtroOp == 1)
                {
                    tipoFiltro = "driver_size";
                    cout << "\n  Tamano (Small / Medium / Large): ";
                    cin.ignore();
                    getline(cin, valorFiltro);
                }
                else
                {
                    tipoFiltro = "body_type";
                    cout << "\n  Tipo de body (Kart / Std Bike / Sport Bike): ";
                    cin.ignore();
                    getline(cin, valorFiltro);
                }

                cout << "\n  Operacion:\n";
                cout << "    1. Promedio\n";
                cout << "    2. Maximo\n";
                cout << "    3. Minimo\n";
                cout << "  Opcion: ";
                int opAgg = pedirOpcion(1, 3);

                string operacion;
                if (opAgg == 1) operacion = "promedio";
                else if (opAgg == 2) operacion = "maximo";
                else operacion = "minimo";

                double resultado = qe.agregacion(
                    tipoFiltro, valorFiltro, operacion
                );

                cout << fixed << setprecision(2);
                cout << "\n  " << operacion << " de score"
                     << " para " << tipoFiltro
                     << " = \"" << valorFiltro << "\": "
                     << resultado << "\n";
            }

            // OPCION 5: Catalogo polimorficoo
            else if (opcion == 5)
            {
                cout << "\n=== CATALOGO DE COMPONENTES ===\n";
                cout << "\n  Filtrar por tipo:\n";
                cout << "    1. Driver\n";
                cout << "    2. Body\n";
                cout << "    3. Tire\n";
                cout << "    4. Glider\n";
                cout << "    5. Todos\n";
                cout << "  Opcion: ";
                int filtroOp = pedirOpcion(1, 5);

                string filtro = "";
                if      (filtroOp == 1) filtro = "Driver";
                else if (filtroOp == 2) filtro = "Body";
                else if (filtroOp == 3) filtro = "Tire";
                else if (filtroOp == 4) filtro = "Glider";

                // Polimorfismo real: recorre Component* y llama
                // getType() y calculateScore() virtualmente
                mostrarCatalogoPolimorfico(catalogo, filtro);
            }

            else if (opcion == 0)
            {
                salir = true;
                cout << "\n  Hasta luego!\n\n";
            }
        }
        catch (const MK8Exception& e)
        {
            cout << "\n  [ERROR] " << e.what() << "\n";
        }
        catch (const exception& e)
        {
            cout << "\n  [ERROR inesperado] " << e.what() << "\n";
        }
    }

    return 0;
}
