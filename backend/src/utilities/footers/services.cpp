#include <grpcpp/support/status.h>
#include <utilities/services.hpp>

namespace Utilities {
	grpc::Status
	HealthServiceImpl::Check(grpc::ServerContext * /*context*/,
	                         const google::protobuf::Empty * /*request*/,
	                         utilities::v1::Response *response) {
		response->clear_healthy();
		response->set_healthy(true);
		return grpc::Status::OK;
	}
} // namespace Utilities