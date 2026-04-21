#pragma once

#include <grpcpp/grpcpp.h>
#include <memory>

namespace Utilities {

	inline std::shared_ptr<grpc::Channel> GetGrpcChannel() {
		static auto channel = grpc::CreateChannel(
		    "localhost:50051", grpc::InsecureChannelCredentials());

		return channel;
	}
} // namespace Utilities