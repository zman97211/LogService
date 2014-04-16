#ifndef __LOG_SERVICE_H__
#define __LOG_SERVICE_H__

// The following line indicates that the object file will need to have LogService.lib linked with it.
#pragma comment (lib, "LogService")

#include <memory>
#include <string>
#include <boost/log/trivial.hpp>

namespace rr {

	namespace log {

		enum severity_level
		{
			trace,
			debug,
			info,
			warning,
			error,
			fatal
		};

		std::string to_string(rr::log::severity_level level);

	}

	/* Create a static member variable in your class to hold an instance of this class,
	 * supplying the name of your class to the constructor. Then, use that object to log 
	 * debug and informational messages to the core.
	 */
	class logger {

	public:
		logger(const std::string& module);			// module is the tag for the log message.

		logger(const logger&) = delete;				// No copy constructor.
		bool operator=(const logger&) =delete;		// No assignment.

		void info(const std::string& msg);			// Log a message with info severity level.
		void debug(const std::string& msg);			// Log a message with debug severity level.


	private:
		std::string _module;
		boost::log::sources::severity_logger<rr::log::severity_level> _lg;	// This is Boost.Log's logger we're going to send our log records to.
		void send_log(rr::log::severity_level level, std::string module, std::string msg);	// Logs a message with _lg.
	};

}

#endif
