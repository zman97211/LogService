#ifndef __BOOST_LOGGER_H__
#define __BOOST_LOGGER_H__

#include <string>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include "logger.h"

namespace rr {

	namespace log {

		namespace boost_imp {

			void init_logging();

			class boost_logger : public logger {

			public:
				boost_logger(const std::string& module);

			protected:
				void send_log(rr::log::severity_level level, std::string module, std::string msg);	// Logs a message with _lg.

			private:
				boost::log::sources::severity_logger<rr::log::severity_level> _lg;					// This is Boost.Log's logger we're going to send our log records to.
			};

		}

	}

}

#endif