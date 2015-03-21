#include <string>
#include <memory>
#include "logger.h"
#include "boost_logger.h"

void rr::log::init_logging() {
	// Make sure we pass the initialization on to the implementation to give it a chance to initialize itself.
	boost_imp::init_logging();
}

std::unique_ptr<rr::log::logger> rr::log::get_logger(const std::string& module) {
	return std::make_unique<boost_imp::boost_logger>(module);
}

std::string rr::log::to_string(severity_level level) {
	switch (level) {
	case debug:
		return "Debug";
	case error:
		return "Error";
	case fatal:
		return "Fatal";
	case info:
		return "Info";
	case trace:
		return "Trace";
	case warning:
		return "Warning";
	default:
		return "Unknown";
	}
}

rr::log::logger::logger(const std::string& module) : _module( module ) {
}

void rr::log::logger::trace(const std::string& msg) {
	send_log(severity_level::trace, _module, msg);
}

void rr::log::logger::debug(const std::string& msg) {
	send_log(severity_level::debug, _module, msg);
}

void rr::log::logger::info(const std::string& msg) {
	send_log(severity_level::info, _module, msg);
}

void rr::log::logger::warning(const std::string& msg) {
	send_log(severity_level::warning, _module, msg);
}

void rr::log::logger::error(const std::string& msg) {
	send_log(severity_level::error, _module, msg);
}

void rr::log::logger::fatal(const std::string& msg) {
	send_log(severity_level::fatal, _module, msg);
}
