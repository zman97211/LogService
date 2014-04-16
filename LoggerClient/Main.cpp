#include "../LogService/logger.h"
#include <iostream>

int main(int argc, char* argv[]) {
	rr::logger lg{ "TestProg" };

	lg.info("This is an info message.");
	lg.debug("This is a debug message.");

	system("pause");
	return 0;
}
