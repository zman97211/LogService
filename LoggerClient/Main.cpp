#include "logger.h"

int main(int argc, char* argv[]) {
	rr::log::init_logging();

	auto lg = rr::log::get_logger("TestProg");

	lg->trace("This is a trace message.");
	lg->debug("This is a debug message.");
	lg->info("This is an info message.");
	lg->warning("This is a warning message.");
	lg->error("This is a error message.");
	lg->fatal("This is a fatal message.");

	system("pause");
	return 0;
}
