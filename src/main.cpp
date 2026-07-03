#include <QGuiApplication>
#include <QtQml/QQmlApplicationEngine>
#include <QtQml/QQmlContext>
#include <QIcon>
#include <QCoreApplication>

#include "viewmodels/AppController.h"

int main(int argc, char* argv[]) {
    QGuiApplication app(argc, argv);
    app.setOrganizationName("MK8BuildAnalyzer");
    app.setApplicationName("Mario Kart 8 - Build Analyzer");
    app.setWindowIcon(QIcon(":/assets/icons/icon_logo.svg"));

    AppController controller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("appController", &controller);

    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);

    engine.loadFromModule("MarioKartBuildAnalyzer", "Main");

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
