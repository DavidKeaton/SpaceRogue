#include <iostream>

#include "Logger.h"

int main()
{
	Logger *Log = new Logger();
	Log->d("TEST", "testing %s", "things");
	std::cout << "Hello, World!" << std::endl;
	delete Log;
	return 0;
}