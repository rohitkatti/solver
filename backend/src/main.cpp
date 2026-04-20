#include <CLI/CLI.hpp>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <dynamics/typedefs.hpp>
#include <protos/interface.hpp>
#include <thread>
#include <utilities/interface.hpp>
#include <utilities/logger.hpp>

void parseArgs(int argc, char *argv[]) {
	Utilities::Config cfg = Utilities::GetConfig();
	CLI::App app{"Project<=>Workspace"};
	app.add_option("--host", cfg.host, "Server Host");
	app.add_option("--port", cfg.port, "Server Port");

	try {
		app.parse(argc, argv);

	} catch (const CLI::ParseError &e) {
		app.exit(e);
	}
}

int main(int argc, char **argv) {
	parseArgs(argc, argv);

	Utilities::Config cfg = Utilities::GetConfig();
	cfg.mainThreadId = std::this_thread::get_id();
	cfg.rbdlVersion = Dynamics::GetRBDLVersion();
	Utilities::SetConfig(cfg);

	Utilities::FL().Info("\n\nInitialization Done !\n\n");

	Protos::Service svc;
	// std::thread serverThread(svc.RunServer);
	svc.RunServer();

	// QGuiApplication app(argc, argv);
	// QQmlApplicationEngine engine;
	// engine.loadFromModule("com.myapp", "Main");
	// return app.exec();
	// serverThread.join();

	return 0;
}