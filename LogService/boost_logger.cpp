#include <string>
#include <fstream>
#include <boost/log/sinks.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include "boost_logger.h"

void rr::log::boost_imp::init_logging() {
	auto core = boost::log::core::get();

	auto backend = boost::make_shared<boost::log::sinks::text_ostream_backend>();
	backend->add_stream(boost::shared_ptr<std::ostream>(&std::cout, boost::serialization::null_deleter()));

	// Enable auto-flushing after each log record written
	backend->auto_flush(true);

	// Wrap it into the frontend and register in the core.
	// The backend requires synchronization in the frontend.
	typedef boost::log::sinks::synchronous_sink<boost::log::sinks::text_ostream_backend> sink_t;
	boost::shared_ptr< sink_t > sink(new sink_t(backend));
	core->add_sink(sink);
}

rr::log::boost_imp::boost_logger::boost_logger(const std::string& module) : logger{ module } {};

void rr::log::boost_imp::boost_logger::send_log(rr::log::severity_level level, std::string module, std::string msg) {
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
