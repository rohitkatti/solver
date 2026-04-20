#pragma once

#include <geometry/generated/v1/geometry.grpc.pb.h>
#include <geometry/generated/v1/geometry.pb.h>
#include <grpcpp/server_context.h>
#include <grpcpp/grpcpp.h>

namespace Geometry {
	class FileServiceImpl final : public geometry::v1::FileService::Service {
			grpc::Status Load(grpc::ServerContext * /*context*/,
			                  const geometry::v1::FileRequest *fileRequest,
			                  geometry::v1::LoadResponse *response) override;

			grpc::Status LoadPoints(
			    grpc::ServerContext * /*context*/,
			    const geometry::v1::FileRequest *fileRequest,
			    grpc::ServerWriter<geometry::v1::Point> *writer) override;
	};

	inline void AddServices(grpc::ServerBuilder& builder) {
		static FileServiceImpl impl;
		builder.RegisterService(&impl);
    }
}   // namespace Geometry