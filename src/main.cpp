#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "app/AppController.h"
#include "network/ConnectionTypes.h"

int main(int argc, char *argv[])
{
    qmlRegisterUncreatableMetaObject(
        Connection::staticMetaObject,
        "QtSignalHub.Connection",
        1, 0,
        "Connection",
        "Access enums only"
    );

    QGuiApplication app(argc, argv);

    AppController controller;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("appController", &controller);
    engine.rootContext()->setContextProperty("connectionManager", controller.connectionManager());
    engine.rootContext()->setContextProperty("messageModel", controller.messageModel());
    engine.rootContext()->setContextProperty("appState", controller.appState());

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("QtSignalHub", "Main");

    return app.exec();
}
