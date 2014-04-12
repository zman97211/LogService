#ifndef __LOG_SERVICE_H__
#define __LOG_SERVICE_H__

#include <memory>
#include <string>

namespace rr {

	class logger {
	public:
		logger(const std::string& module);
		void log(const std::string& msg) const;
	private:
		std::string _module;
	};

}

#endif