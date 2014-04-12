#include "logger.h"

int main(int argc, char* argv[]) {

	// Get a logger.
	rr::logger log{ "Main" };

	// Log a message.
	log.log("Hello, world.");

	system("pause");
	return 0;
}