#pragma

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
				// Logs a message with _lg.
				void send_log(rr::log::severity_level level, std::string module, std::string msg);

			private:
				// This is Boost.Log's logger we're going to send our log records to.
				boost::log::sources::severity_logger<rr::log::severity_level> _lg;
			};

		}

	}

}
