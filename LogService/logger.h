#pragma once

// The following line indicates that the object file will need to have LogService.lib linked with it.
#pragma comment (lib, "LogService")

#include <memory>
#include <string>

namespace rr {

	namespace log {

		// Ensure this function is called before using any part of the logging library.
		void init_logging();

		enum severity_level
		{
			trace,
			debug,
			info,
			warning,
			error,
			fatal
		};

		// Returns the enum value as a string representation.
		std::string to_string(rr::log::severity_level level); 

		/* Create a static member variable in your class to hold an instance of this class,
		 * supplying the name of your class to the constructor. Then, use that object to log
		 * debug and informational messages to the core.
		 *
		 * Note that the current implementation is not thread safe - meaning two threads can use
		 * the same logger instance at the same time. However, each thread can have its own
		 * logger instance, and they can both be used simultaneously from different threads. This
		 * is preferred anyway, because each logger can identify the source thread of the
		 * log message which might help when it comes to debug time.
		 */
		class logger {
		public:

			logger(const std::string& module);				// module is the tag for the log message.
			virtual ~logger() {}

			logger(const logger&) = delete;					// No copy constructor.
			bool operator=(const logger&) = delete;			// No assignment.

			std::string module() { return _module; };		// Gets the name of the module associated with this logger.

			virtual void trace(const std::string& msg);		// Log a message with trace severity level.
			virtual void debug(const std::string& msg);		// Log a message with debug severity level.
			virtual void info(const std::string& msg);		// Log a message with info severity level.
			virtual void warning(const std::string& msg);	// Log a message with warning severity level.
			virtual void error(const std::string& msg);		// Log a message with error severity level.
			virtual void fatal(const std::string& msg);		// Log a message with fatal severity level.

		protected:
			virtual void send_log(severity_level level, std::string module, std::string msg) = 0;  // Sub-classes implement this to actually log a message.

		private:
			std::string _module;							// The source module using the logger.
		};

		// This is a factory function for obtaining a concrete implementation of a logger.
		std::unique_ptr<logger> get_logger(const std::string& module);

	}

}
