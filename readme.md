# Mario Kart 8 - Build Analyzer

Catálogo interactivo de builds de Mario Kart 8 Deluxe. Selecciona un piloto, vehículo, neumáticos y alas, y el programa calcula el **Percentil de Rendimiento** de tu combinación comparándola contra todas las combinaciones posibles del catálogo.

## Cómo compilar

g++ -std=c++17 main.cpp Body.cpp Tire.cpp Driver.cpp Glider.cpp Component.cpp Build.cpp CSVLoader.cpp QueryEngine.cpp -o main

## Cómo correr

./main

El programa busca los archivos de datos en la subcarpeta **data/** relativa al directorio desde donde se ejecuta. Asegúrate de correrlo desde la carpeta raíz del proyecto.

## Menú principal

| Opción | Descripción 
| 1 | Arma tu build y calcula su Percentil de Rendimiento 
| 2 | Muestra el ranking de los mejores N builds del catálogo 
| 3 | Encuentra los K builds más similares al tuyo 
| 4 | Estadísticas (promedio / máximo / mínimo) por categoría 
| 5 | Explora el catálogo completo de componentes 
| 0 | Salir 


## Formato de los archivos de datos

Los CSV están en la carpeta `data/`. El separador es coma (`,`). La primera fila es el encabezado y se ignora al cargar.

### data/Drivers.csv

Size, Character(s), Speed(Ground), Speed(Water), Speed(Air), Speed(Anti-G),
Acceleration, Weight, Handling(Ground), Handling(Water), Handling(Air),
Handling(Anti-G), Traction

- **Size**: Small | Medium | Large

### data/Bodies.csv

Body, Vehicle Type, Speed(Ground), Speed(Water), Speed(Air), Speed(Anti-G),
Acceleration, Weight, Handling(Ground), Handling(Water), Handling(Air),
Handling(Anti-G), Traction

- **Vehicle Type**: Kart | Std Bike | Sport Bike | ATV

### data/Tires.csv

Tire, Speed(Ground), Speed(Water), Speed(Air), Speed(Anti-G),
Acceleration, Weight, Handling(Ground), Handling(Water), Handling(Air),
Handling(Anti-G), Traction

### data/Gliders.csv

Glider, Speed(Ground), Speed(Water), Speed(Air), Speed(Anti-G),
Acceleration, Weight, Handling(Ground), Handling(Water), Handling(Air),
Handling(Anti-G), Traction


## Estructura del proyecto

main.cpp            # Punto de entrada y menú
Component.h/cpp     # Clase base abstracta
Driver.h/cpp        # Clase derivada: piloto
Body.h/cpp          # Clase derivada: vehículo
Tire.h/cpp          # Clase derivada: neumáticos
Glider.h/cpp        # Clase derivada: alas
Build.h/cpp         # Combinación de los 4 componentes
QueryEngine.h/cpp   # Motor de consultas (ranking, similitud, agregación)
MK8Exception.h      # Excepción propia
data
    Drivers.csv
    Bodies.csv
    Tires.csv
    Gliders.csv

## Fórmula de Performance Score

La puntuación pondera cada atributo según su impacto real en una carrera:


Velocidad Tierra | 20% 
Aceleración | 20% 
Velocidad Agua | 10% 
Velocidad Aire | 10% 
Velocidad Anti-G | 10%
Manejo Tierra | 10% 
Agarre | 6% 
Manejo Agua | 4% 
Manejo Aire | 4% 
Manejo Anti-G | 4% 
Peso | 2% 

Los valores en barra de cada componente se promedian con la fórmula oficial del juego: **(Driver + Body + Tires + Glider + 3) / 4**

## Video defensa
https://youtu.be/FPx-_5Qfan8 

## Fuente de datos

Wiki, S. M. (2026). Mario Kart 8 Deluxe in-game statistics.  
https://www.mariowiki.com/Mario_Kart_8_Deluxe_in-game_statistics