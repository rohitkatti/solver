#pragma once

#include <grpcpp/grpcpp.h>
#include <grpcpp/server_context.h>
#include <utilities/generated/v1/health.grpc.pb.h>
#include <utilities/generated/v1/health.pb.h>

namespace Utilities {
	class HealthServiceImpl final : public utilities::v1::Health::Service {
			grpc::Status Check(grpc::ServerContext * /*context*/,
			                   const google::protobuf::Empty * /*request*/,
			                   utilities::v1::Response *response) override;
	};

	inline void AddServices(grpc::ServerBuilder &builder) {
		static HealthServiceImpl impl;
		builder.RegisterService(&impl);
	}
} // namespace Utilities