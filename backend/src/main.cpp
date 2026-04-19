#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <rbdl/rbdl.h>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.loadFromModule("com.myapp", "Main");
    return app.exec();
}