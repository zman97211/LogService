#include <string>
#include <memory>
#include "logger.h"
#include "boost_logger.h"

void rr::log::init_logging() {
	// Make sure we pass the initialization on to the implementation to give it a chance to initialize itself.
	rr::log::boost_imp::init_logging();
}

std::unique_ptr<rr::log::logger> rr::log::get_logger(const std::string& module) {
	return std::make_unique<rr::log::boost_imp::boost_logger>(module);
}

std::string rr::log::to_string(rr::log::severity_level level) {
	switch (level) {
	case rr::log::severity_level::debug:
		return "Debug";
		break;
	case rr::log::severity_level::error:
		return "Error";
		break;
	case rr::log::severity_level::fatal:
		return "Fatal";
		break;
	case rr::log::severity_level::info:
		return "Info";
		break;
	case rr::log::severity_level::trace:
		return "Trace";
		break;
	case rr::log::severity_level::warning:
		return "Warning";
		break;
	default:
		return "Unknown";
		break;
	}
}

rr::log::logger::logger(const std::string& module) : _module{ module } {
}

void rr::log::logger::trace(const std::string& msg) {
	send_log(rr::log::severity_level::trace, _module, msg);
}

void rr::log::logger::debug(const std::string& msg) {
	send_log(rr::log::severity_level::debug, _module, msg);
}

void rr::log::logger::info(const std::string& msg) {
	send_log(rr::log::severity_level::info, _module, msg);
}

void rr::log::logger::warning(const std::string& msg) {
	send_log(rr::log::severity_level::warning, _module, msg);
}

void rr::log::logger::error(const std::string& msg) {
	send_log(rr::log::severity_level::error, _module, msg);
}

void rr::log::logger::fatal(const std::string& msg) {
	send_log(rr::log::severity_level::fatal, _module, msg);
}
