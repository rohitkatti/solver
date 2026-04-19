// Workaround: absl lts_20240116 declares extern template for LogMessage
// operator<< specializations but never instantiates them in the library.
// This is a known aarch64 bug. We provide the missing instantiations here.
//
// The extern template declarations suppress local instantiation in every TU
// that includes log_message.h, so we must provide them exactly once.

// Undefine ABSL_ATTRIBUTE_NOINLINE so the instantiations are emitted
#include <absl/log/internal/log_message.h>

namespace absl {
	inline namespace lts_20240116 {
		namespace log_internal {

			// Provide the missing explicit instantiations declared as extern
			// template
			template LogMessage &LogMessage::operator<<(const char &v);
			template LogMessage &LogMessage::operator<<(const signed char &v);
			template LogMessage &LogMessage::operator<<(const unsigned char &v);
			template LogMessage &LogMessage::operator<<(const short &v);
			template LogMessage &
			LogMessage::operator<<(const unsigned short &v);
			template LogMessage &LogMessage::operator<<(const int &v);
			template LogMessage &LogMessage::operator<<(const unsigned int &v);
			template LogMessage &LogMessage::operator<<(const long &v);
			template LogMessage &LogMessage::operator<<(const unsigned long &v);
			template LogMessage &LogMessage::operator<<(const long long &v);
			template LogMessage &
			LogMessage::operator<<(const unsigned long long &v);
			template LogMessage &LogMessage::operator<<(void *const &v);
			template LogMessage &LogMessage::operator<<(const void *const &v);

		} // namespace log_internal
	} // namespace lts_20240116
} // namespace absl

/*
Quick summary of what caused it and what fixed it:
Root cause: absl lts_20240116 (shipped with gRPC 1.62-1.64) declares extern
template for LogMessage::operator<< specializations in the header — telling
every translation unit "don't instantiate these, they're in the library." But
the library never actually provided them. On aarch64 this manifested as an
undefined symbol at link time. Fix: absl_fix.cpp provides the missing explicit
instantiations that the library was supposed to ship.
*/