#include <geometry/interface.hpp>
#include <grpcpp/support/status.h>

namespace Geometry {
	grpc::Status
	FileServiceImpl::Load(grpc::ServerContext * /*context*/,
	                      const geometry::v1::FileRequest *fileRequest,
	                      geometry::v1::LoadResponse *response) {
		return grpc::Status::OK;
	}

	grpc::Status FileServiceImpl::LoadPoints(
	    grpc::ServerContext * /*context*/,
	    const geometry::v1::FileRequest *fileRequest,
	    grpc::ServerWriter<geometry::v1::Point> *writer) {
		return grpc::Status::OK;
	}
} // namespace Geometry