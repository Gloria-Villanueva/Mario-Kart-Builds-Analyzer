cmake_minimum_required(VERSION 3.21)

project(MarioKartBuildAnalyzer VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# --- Ayuda a CMake a encontrar Qt6 instalado via Homebrew en macOS ---
if(APPLE)
    if(EXISTS "/opt/homebrew/opt/qt")
        list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt")
    elseif(EXISTS "/usr/local/opt/qt")
        list(APPEND CMAKE_PREFIX_PATH "/usr/local/opt/qt")
    endif()
endif()

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2 Multimedia)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(MarioKartBuildAnalyzer
    src/main.cpp

    src/core/Component.h        src/core/Component.cpp
    src/core/Driver.h           src/core/Driver.cpp
    src/core/Body.h             src/core/Body.cpp
    src/core/Tire.h             src/core/Tire.cpp
    src/core/Glider.h           src/core/Glider.cpp
    src/core/Build.h            src/core/Build.cpp
    src/core/QueryEngine.h      src/core/QueryEngine.cpp
    src/core/CSVLoader.h        src/core/CSVLoader.cpp
    src/core/MK8Exception.h

    src/models/ComponentListModel.h   src/models/ComponentListModel.cpp
    src/models/BuildListModel.h       src/models/BuildListModel.cpp

    src/viewmodels/AppController.h    src/viewmodels/AppController.cpp
    src/viewmodels/BuildViewModel.h   src/viewmodels/BuildViewModel.cpp

    resources.qrc
)

qt_add_qml_module(MarioKartBuildAnalyzer
    URI MarioKartBuildAnalyzer
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/Theme.qml
        qml/components/StatBar.qml
        qml/components/PrimaryButton.qml
        qml/components/GlassCard.qml
        qml/components/SectionHeader.qml
        qml/components/ComponentPicker.qml
        qml/components/NavRail.qml
        qml/components/SoundFx.qml
        qml/views/HomeView.qml
        qml/views/BuildView.qml
        qml/views/RankingView.qml
        qml/views/SimilarView.qml
        qml/views/StatsView.qml
        qml/views/CatalogView.qml
)

target_link_libraries(MarioKartBuildAnalyzer
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Qml
        Qt6::Quick
        Qt6::QuickControls2
        Qt6::Multimedia
)

set_target_properties(MarioKartBuildAnalyzer PROPERTIES
    MACOSX_BUNDLE TRUE
    MACOSX_BUNDLE_BUNDLE_NAME "MK8 Build Analyzer"
    MACOSX_BUNDLE_GUI_IDENTIFIER "com.mk8buildanalyzer.app"
    MACOSX_BUNDLE_SHORT_VERSION_STRING "1.0.0"
    MACOSX_BUNDLE_LONG_VERSION_STRING "1.0.0"
    WIN32_EXECUTABLE TRUE
)

# --- deploy de Qt para poder distribuir el .app en otro Mac (opcional) ---
if(APPLE)
    find_program(MACDEPLOYQT_EXECUTABLE macdeployqt HINTS "${Qt6_DIR}/../../../bin")
    if(MACDEPLOYQT_EXECUTABLE)
        add_custom_target(deploy_mac
            COMMAND ${MACDEPLOYQT_EXECUTABLE} $<TARGET_BUNDLE_DIR:MarioKartBuildAnalyzer> -qmldir=${CMAKE_SOURCE_DIR}/qml
            DEPENDS MarioKartBuildAnalyzer
            COMMENT "Empaquetando dependencias de Qt dentro del .app"
        )
    endif()
endif()
