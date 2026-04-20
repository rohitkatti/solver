#pragma once

#include <chrono>
#include <cstring>
#include <ctime>
#include <mutex>
#include <thread>
#include <utilities/interface.hpp>

using namespace std;

namespace Utilities {
	const string LOG_FILE_PATH = format("/Users/rohitkatti/github/solver/backend/tmp/logs/{:%Y-%m-%d_%H-%M-%S}.log",
	                                    chrono::system_clock::now());

	class ILog {
		public:
			virtual void Warn(const std::string &s) = 0;
			virtual void Fail(const std::string &s) = 0;
			virtual void Info(const std::string &s) = 0;
			virtual void Show(const std::string &s) = 0;

			virtual void Warn(const char *s) = 0;
			virtual void Fail(const char *s) = 0;
			virtual void Info(const char *s) = 0;
			virtual void Show(const char *s) = 0;
	};

	enum class LogType { CONSOLE, LOGFILE };

	class Log : public ILog {
		public:
			explicit Log(LogType t);

		private:
			std::string to_string(std::thread::id id) {
				std::stringstream ss;
				ss << id;
				return ss.str();
			}

			void Warn(const std::string &s) override;
			void Warn(const char *s) override;

			void Fail(const std::string &s) override;
			void Fail(const char *s) override;

			void Info(const std::string &s) override;
			void Info(const char *s) override;

			void Show(const std::string &s) override;
			void Show(const char *s) override;

			// header
			void LogFileHeader();

			LogType m_logType;
			mutex m_logMutex;
	};

	inline ILog &CL() {
		static Log cl(LogType::CONSOLE);
		return cl;
	}

	inline ILog &FL() {
		static Log fl(LogType::LOGFILE);
		return fl;
	}

} // namespace Utilities