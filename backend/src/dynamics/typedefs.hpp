#pragma once

#include <format>
#include <rbdl/rbdl.h>

using namespace RigidBodyDynamics;

namespace Dynamics {
	inline std::string GetRBDLVersion() {
		int v = rbdl_get_api_version();
		int major = (v >> 16) & 0xFF;
		int minor = (v >> 8) & 0xFF;
		int patch = v & 0xFF;
		return std::format("{}.{}.{}", major, minor, patch);
	}
}   //  namespace Dynamics