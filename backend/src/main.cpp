#include "CLI/CLI.hpp"
#include <thread>
#include <utilities/interface.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <rbdl/rbdl.h>
#include <CLI/CLI.hpp>

void parseArgs(int argc, char *argv[]) {
  Utilities::Config cfg = Utilities::GetConfig();
  CLI::App app{"Project<=>Workspace"};
    app.add_option("--host", cfg.host, "Server Host");
    app.add_option("--port", cfg.port, "Server Port");

    try {
      app.parse(argc, argv);

    } catch (const CLI::ParseError&e){
        app.exit(e);
    }
}

int main(int, char**) {
  // QGuiApplication app(argc, argv);
  // QQmlApplicationEngine engine;
  // engine.loadFromModule("com.myapp", "Main");
  // return app.exec();
  Utilities::Config cfg = Utilities::GetConfig();
  cfg.mainThreadId = std::this_thread::get_id();
}