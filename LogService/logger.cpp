#include <iostream>

#include "logger.h"

rr::logger::logger(const std::string& module) : _module{ module } {
}

void rr::logger::log(const std::string& msg) const {
	std::cout << _module << ": " << msg << std::endl;
}