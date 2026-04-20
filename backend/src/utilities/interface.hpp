#pragma once

#include <string>
#include <thread>

using namespace std;

namespace Utilities {
	struct Config {
			string host = "localhost";
			int port = 50051;
			thread::id mainThreadId;
			string rbdlVersion;
			auto operator<=>(const Config &) const = default;
	};

	static Config cfg;

	inline void SetConfig(Config &c) {
		cfg = c;
	}

	inline const Config GetConfig() {
		return cfg;
	}
} // namespace Utilities