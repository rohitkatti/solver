#include "utilities/logger.hpp"
#include "fstream"
#include "rang.hpp"

using namespace std;

namespace Utilities {
	Log::Log(LogType t) : m_logType(t) {
		if (m_logType == LogType::LOGFILE) {
			LogFileHeader();
		}
	}

	void Log::LogFileHeader() {
		std::ofstream log_file(LOG_FILE_PATH, std::ios::app);

		log_file << "######################################" << endl;
		log_file << "\tLOG" << endl;
		log_file << "######################################" << endl;

		auto cfg = GetConfig();
		log_file << "HOST           \t" << cfg.host << endl;
		log_file << "PORT           \t" << cfg.port << endl;
		log_file << "RBDL Version   \t" << cfg.rbdlVersion << endl;
	}

	void Log::Warn(const std::string &s) {
		Warn(s.c_str());
	}

	void Log::Warn(const char *s) {
		std::lock_guard<std::mutex> lock(m_logMutex);

		auto thread_id = std::this_thread::get_id();
		auto cfg = GetConfig();
		auto warnId = (cfg.mainThreadId == thread_id)
		                  ? "[WARN]\t"
		                  : format("[WARN]({})\t", to_string(thread_id));

		if (m_logType == LogType::CONSOLE) {
			cout << rang::fg::yellow << rang::style::bold << "[WARN]\t"
			     << rang::style::reset << s << endl;
		} else {
			std::ofstream log_file(LOG_FILE_PATH, std::ios::app);
			log_file << rang::fg::yellow << rang::style::bold << warnId
			         << rang::style::reset << s << std::endl;
		}
	}

	void Log::Fail(const std::string &s) {
		Fail(s.c_str());
	}

	void Log::Fail(const char *s) {
		std::lock_guard<std::mutex> lock(m_logMutex);
		auto thread_id = std::this_thread::get_id();
		auto cfg = GetConfig();
		auto failId = (cfg.mainThreadId == thread_id)
		                  ? "[FAIL]\t"
		                  : format("[FAIL]({})\t", to_string(thread_id));

		if (m_logType == LogType::CONSOLE) {
			cout << rang::fg::red << rang::style::bold << "[FAIL]\t"
			     << rang::style::reset << s << endl;
		} else {
			std::ofstream log_file(LOG_FILE_PATH, std::ios::app);
			log_file << rang::fg::red << rang::style::bold << failId
			         << rang::style::reset << s << std::endl;
		}
	}

	void Log::Info(const std::string &s) {
		Info(s.c_str());
	}

	void Log::Info(const char *s) {
		std::lock_guard<std::mutex> lock(m_logMutex);
		auto thread_id = std::this_thread::get_id();
		auto cfg = GetConfig();
		auto infoId = (cfg.mainThreadId == thread_id)
		                  ? "[INFO]\t"
		                  : format("[INFO]({})\t", to_string(thread_id));

		if (m_logType == LogType::CONSOLE) {
			cout << rang::fg::green << rang::style::bold << "[INFO]\t"
			     << rang::style::reset << s << endl;
		} else {
			std::ofstream log_file(LOG_FILE_PATH, std::ios::app);
			log_file << rang::fg::green << rang::style::bold << infoId
			         << rang::style::reset << s << std::endl;
		}
	}

	void Log::Show(const std::string &s) {
		Show(s.c_str());
	}

	void Log::Show(const char *s) {
		std::lock_guard<std::mutex> lock(m_logMutex);
		auto thread_id = std::this_thread::get_id();
		auto cfg = GetConfig();
		auto infoId = (cfg.mainThreadId == thread_id)
		                  ? "[SHOW]\t"
		                  : format("[SHOW]({})\t", to_string(thread_id));

		if (m_logType == LogType::CONSOLE) {
			cout << rang::fg::yellow << rang::style::bold << rang::style::reset
			     << s << endl;
		} else {
			std::ofstream log_file(LOG_FILE_PATH, std::ios::app);
			log_file << rang::fg::green << rang::style::bold << infoId
			         << rang::style::reset << s << std::endl;
		}
	}
} // namespace Utilities