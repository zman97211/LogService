#include "../LogService/logger.h"

int main(int argc, char* argv[]) {
	auto lg = rr::log::get_logger("TestProg");

	lg->info("This is an info message.");
	lg->debug("This is a debug message.");

	system("pause");
	return 0;
}
