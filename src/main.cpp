#include <iostream>

#include "Logger.h"

int main()
{
	// XXX: TESTING LOGGER AND COMPILATION
	Logger *Log = new Logger();
	Log->d("TEST", "testing %s", "things");

	std::cout << "Hello, World!" << std::endl;

	delete Log;
	return 0;
}