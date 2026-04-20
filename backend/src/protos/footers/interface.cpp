#include "protos/interface.hpp"
#include "grpcpp/ext/proto_server_reflection_plugin.h"
#include "grpcpp/grpcpp.h"
#include "utilities/logger.hpp"

using namespace Utilities;

namespace Protos {
	void Service::RunServer() {
		grpc::reflection::InitProtoReflectionServerBuilderPlugin();

		Utilities::Config cfg = Utilities::GetConfig();

		std::string server_address = std::format("{}:{}", cfg.host, cfg.port);

		grpc::ServerBuilder builder;
		builder.AddListeningPort(server_address,
		                         grpc::InsecureServerCredentials());

		std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
		if (!server) {
			CL().Fail("[gRPC] Server failed to start");
			return;
		}

		CL().Info(std::format("[gRPC] Server listening on {}", server_address)
		              .c_str());

		server->Wait();
	}
} // namespace Protos