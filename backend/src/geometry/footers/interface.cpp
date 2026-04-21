#include <geometry/interface.hpp>
#include <geometry/typedefs.hpp>
#include <grpcpp/support/status.h>
#include <utilities/logger.hpp>

using namespace Utilities;

namespace Geometry {
	static const char *getFileExtn(const geometry::v1::FileType &fileType) {
		switch (fileType) {
		case geometry::v1::FileType::FT_STL:
			return ".stl";
		case geometry::v1::FileType::FT_OFF:
			return ".off";
		case geometry::v1::FileType::FT_OBJ:
			return ".obj";
		case geometry::v1::FileType::FT_PLY:
			return ".ply";
		case geometry::v1::FileType::FT_TS:
			return ".ts";
		case geometry::v1::FileType::FT_VTP:
			return ".vtp";
		default:
			return "";
		}
	}

	grpc::Status
	FileServiceImpl::Load(grpc::ServerContext * /*context*/,
	                      const geometry::v1::FileRequest *fileRequest,
	                      geometry::v1::LoadResponse *response) {
		switch (fileRequest->type()) {
		case geometry::v1::FileType::FT_STL:
		case geometry::v1::FileType::FT_OFF:
		case geometry::v1::FileType::FT_OBJ:
		case geometry::v1::FileType::FT_PLY:
		case geometry::v1::FileType::FT_TS:
		case geometry::v1::FileType::FT_VTP: {
			auto filePath = fileRequest->path();
			if (filePath.empty()) {
				return grpc::Status::CANCELLED;
			}

			SurfaceMesh mesh;

			if (!CGAL::IO::read_polygon_mesh(filePath, mesh)) {
				auto errMsg = std::format("Invalid {} file",
				                          getFileExtn(fileRequest->type()));
				FL().Fail(errMsg);
				CL().Fail(errMsg);
				return grpc::Status::CANCELLED;
			}

			int count = CGAL::num_vertices(mesh);
			auto msg = std::format("Number of Points: {} \n", count);

			for (const Point3 &p : mesh.points()) {
				auto *pnt = response->add_points();
				pnt->set_x(static_cast<float>(p.x()));
				pnt->set_y(static_cast<float>(p.y()));
				pnt->set_z(static_cast<float>(p.z()));
			}

			response->set_message(msg);
			break;
		}
		case geometry::v1::FileType::FT_UNDEFINED:
		default:
			break;
		}

		return grpc::Status::OK;
	}

	grpc::Status FileServiceImpl::LoadPoints(
	    grpc::ServerContext * /*context*/,
	    const geometry::v1::FileRequest *fileRequest,
	    grpc::ServerWriter<geometry::v1::Point> *writer) {

		switch (fileRequest->type()) {
		case geometry::v1::FileType::FT_STL:
		case geometry::v1::FileType::FT_OFF:
		case geometry::v1::FileType::FT_OBJ:
		case geometry::v1::FileType::FT_PLY:
		case geometry::v1::FileType::FT_TS:
		case geometry::v1::FileType::FT_VTP: {
			auto filePath = fileRequest->path();
			if (filePath.empty()) {
				return grpc::Status::CANCELLED;
			}

			SurfaceMesh mesh;

			if (!CGAL::IO::read_polygon_mesh(filePath, mesh)) {
				auto errMsg = std::format("Invalid {} file",
				                          getFileExtn(fileRequest->type()));
				FL().Fail(errMsg);
				CL().Fail(errMsg);
				return grpc::Status::CANCELLED;
			}

			for (const Point3 &p : mesh.points()) {
				geometry::v1::Point pnt;
				pnt.set_x(static_cast<float>(p.x()));
				pnt.set_y(static_cast<float>(p.y()));
				pnt.set_z(static_cast<float>(p.z()));
				writer->Write(pnt);
			}

			break;
		}
		case geometry::v1::FileType::FT_UNDEFINED:
		default:
			break;
		}

		return grpc::Status::OK;
	}
} // namespace Geometry