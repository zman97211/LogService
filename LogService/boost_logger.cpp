#include <string>
#include "boost_logger.h"

rr::log::boost_logger::boost_logger(const std::string& module) : logger{ module } {};

void rr::log::boost_logger::send_log(rr::log::severity_level level, std::string module, std::string msg) {
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
