#include <iostream>

#include <boost/log/trivial.hpp>

#include "logger.h"

rr::logger::logger(const std::string& module) : _module{ module } {
}

void rr::logger::log(const std::string& msg) const {
	BOOST_LOG_TRIVIAL(info) << msg;
}