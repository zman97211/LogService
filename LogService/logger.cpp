#include <string>
#include "logger.h"


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
		return std::string{ 0, 0 }; // Stores a null instead of a string, basically let's fail silently.
		break;
	}
}

// Constructor
rr::logger::logger(const std::string& module) : _module{ module } {
}

// Private implementation
// Function to send a log to _lg.
void rr::logger::send_log(rr::log::severity_level level, std::string module, std::string msg) {

	using namespace boost::log;

	record rec = _lg.open_record();
	if (rec)
	{
		record_ostream strm(rec);
		strm << '[' << rr::log::to_string(level) << "] ";
		strm << '[' << module << "] ";
		strm << msg;
		strm.flush();
		_lg.push_record(boost::move(rec));
	}
}

// public
void rr::logger::debug(const std::string& msg) {
	send_log(rr::log::severity_level::debug, _module, msg);
}

//public
void rr::logger::info(const std::string& msg) {
	send_log(rr::log::severity_level::info, _module, msg);
}
