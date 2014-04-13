#include "../LogService/logger.h"

int main(int argc, char* argv[]) {
	rr::logger log{ "TestProg" };
	log.log("Hello, world!");

	system("pause");
	return 0;
}