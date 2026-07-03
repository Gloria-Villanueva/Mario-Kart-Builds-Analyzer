## 🗂️ Estructura del proyecto

```
MarioKartBuildAnalyzer/
├── CMakeLists.txt
├── resources.qrc              # empaqueta CSVs + iconos + sonidos en el binario
├── data/                      # tus mismos CSV (Drivers, Bodies, Tires, Gliders)
├── assets/
│   ├── icons/                 # SVG originales (piloto, kart, llanta, ala, logo)
│   └── sounds/                # WAV cortos sintetizados
├── src/
│   ├── core/                  # >>> Modelo: idéntico a tu proyecto de consola <<<
│   │   ├── Component.h/.cpp   Driver.h/.cpp   Body.h/.cpp
│   │   ├── Tire.h/.cpp        Glider.h/.cpp   Build.h/.cpp
│   │   ├── QueryEngine.h/.cpp MK8Exception.h
│   │   └── CSVLoader.h/.cpp   (adaptado a QFile para leer desde recursos Qt)
│   ├── models/                # QAbstractListModel para exponer catálogos a QML
│   │   ├── ComponentListModel.h/.cpp
│   │   └── BuildListModel.h/.cpp
│   ├── viewmodels/            # Controller/ViewModel raíz + VM del build actual
│   │   ├── AppController.h/.cpp
│   │   └── BuildViewModel.h/.cpp
│   └── main.cpp
└── qml/
    ├── Main.qml                # ventana, navegación, toasts de error
    ├── Theme.qml                # paleta, tipografía, espaciados (singleton)
    ├── components/              # StatBar, PrimaryButton, GlassCard, ComponentPicker...
    └── views/                   # HomeView, BuildView, RankingView, SimilarView,
                                  # StatsView, CatalogView
```

### Cómo se mapea el menú de consola a la GUI

| Opción original (consola)                  | Pantalla en la app       |
|---------------------------------------------|---------------------------|
| 1. Armar build + percentil                  | **Build**                 |
| 2. Ranking top builds                       | **Ranking**                |
| 3. Builds similares                         | **Similares**              |
| 4. Estadísticas por categoría               | **Estadísticas**           |
| 5. Ver catálogo de componentes              | **Catálogo**               |

## 🔧 Compilar en macOS

Requisitos: **Qt 6.5 o superior** y **CMake 3.21+**.

```bash
# 1. Instalar Qt6 y CMake (si no los tienes)
brew install qt cmake ninja

# 2. Configurar el proyecto
cd MarioKartBuildAnalyzer
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Release

# 3. Compilar
cmake --build build

# 4. Ejecutar
open build/MarioKartBuildAnalyzer.app
```

Si `cmake` no encuentra Qt automáticamente, agrega la ruta de Homebrew:

```bash
cmake -S . -B build -G Ninja -DCMAKE_PREFIX_PATH="$(brew --prefix qt)"
```

### Generar un `.app` distribuible (opcional)

```bash
cmake --build build --target deploy_mac
```

Esto corre `macdeployqt` para empaquetar las librerías de Qt dentro del
bundle, de forma que el `.app` se pueda copiar a otro Mac sin tener Qt
instalado.

## 🎨 Nota de diseño (por qué no hay arte de Mario Kart)

Por restricciones de derechos de autor no se incluye ningún personaje, kart,
logo o sonido oficial de Nintendo/Mario Kart. En su lugar:

- Cada piloto/vehículo/llanta/ala se representa con un **avatar en
  degradado** (color derivado del índice + inicial del nombre), consistente
  y fácil de mantener sin depender de cientos de imágenes.
- Los 4 íconos de categoría (casco de piloto, kart, llanta, ala) y el logo
  son ilustraciones vectoriales **propias**, en `assets/icons/*.svg`.
- Los efectos de sonido son tonos sintetizados originales.

Si más adelante quieres reemplazar los avatares por imágenes reales de tus
propios karts/personajes (por ejemplo, arte original tuyo, no de Nintendo),
solo tendrías que:
1. Poner los `.png`/`.svg` en `assets/`.
2. Agregarlos a `resources.qrc`.
3. Cambiar el `Image { source: ... }` correspondiente en `ComponentPicker.qml`
   / `CatalogView.qml` por la ruta del recurso (por ejemplo, mapeando el
   `name` del componente a un archivo).

## 🧠 Notas de arquitectura (MVVM)

- **Modelo** (`src/core/`): C++ estándar, sin ninguna dependencia de Qt
  (excepto `CSVLoader`, que usa `QFile`/`QTextStream` para poder leer los CSV
  empaquetados dentro del `.app` vía el sistema de recursos `:/data/...`).
  Esto es intencional: la lógica de negocio se puede testear o reutilizar
  fuera de Qt si algún día lo necesitas.
- **Modelos Qt** (`src/models/`): adaptan las colecciones de `Component`/
  `Build` a `QAbstractListModel`, que es lo que QML consume nativamente en
  `ListView`/`GridView` (con roles, animaciones automáticas de inserción,
  etc.).
- **ViewModel/Controller** (`src/viewmodels/AppController`,
  `BuildViewModel`): única puerta de entrada desde QML hacia el `QueryEngine`.
  Traduce excepciones `MK8Exception` a un `errorMessage` observable (que la
  UI muestra como un toast rojo), y expone valores ya **normalizados 0–1**
  para animar las barras sin que la vista tenga que hacer ningún cálculo.
- **Vista** (`qml/`): solo bindings y animaciones; no contiene lógica de
  negocio. `Theme.qml` centraliza colores/tipografía/espaciados para que la
  identidad visual sea consistente y fácil de ajustar.

## ⚠️ Limitaciones conocidas

- No pude compilar el proyecto en este entorno (no tiene Qt6 instalado ni
  acceso a red), así que revísalo con `cmake --build` en tu Mac. Si algo no
  compila, lo más probable es un detalle de versión de Qt (usa 6.5+) o de
  ruta de Homebrew (`CMAKE_PREFIX_PATH`).
- El cálculo de percentil recorre todas las combinaciones del catálogo
  (~drivers × bodies × tires × gliders), igual que en la consola; en C++ es
  rápido (milisegundos), pero si algún día el catálogo crece mucho, se puede
  mover a un hilo con `QtConcurrent` para no bloquear la UI.
