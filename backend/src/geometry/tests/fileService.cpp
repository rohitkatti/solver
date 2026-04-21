#include <geometry/generated/v1/geometry.grpc.pb.h>
#include <geometry/generated/v1/geometry.pb.h>
#include <gtest/gtest.h>
#include <memory>
#include <utilities/tests/helper.hpp>

// Ensure this matches the class definition
class GrpcClientTest : public ::testing::Test {
protected:
	void SetUp() override{
		stub_ = geometry::v1::FileService::NewStub(Utilities::GetGrpcChannel());
	}

	std::unique_ptr<geometry::v1::FileService::Stub> stub_;
};

TEST_F(GrpcClientTest, LoadPointsCheck) {
	geometry::v1::FileRequest fileRequest;
	fileRequest.set_path("/Users/rohitkatti/github/solver/samples/shaft.stl");
	fileRequest.set_type(geometry::v1::FileType::FT_STL);

	grpc::ClientContext context;
	auto reader = stub_->LoadPoints(&context, fileRequest);

	geometry::v1::Point p;
	int count = 0;
	while (reader->Read(&p)) {
		count++;
		EXPECT_FALSE(std::isnan(p.x()));
		EXPECT_FALSE(std::isnan(p.y()));
		EXPECT_FALSE(std::isnan(p.z()));
	}

	auto status = reader->Finish();
	EXPECT_TRUE(status.ok());
	
	EXPECT_GT(count, 0);
}