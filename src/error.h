#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

class Error
{
private:
	int errno;

protected:
	virtual void parse(void) = 0;

public:
	enum TYPE {
		Logger      = 0,
		Video       = 1
	};

	/**
	 * Create a string to represent the error, and return it.
	 *
	 * @return 		a string describing the error
	 */
	virtual std::string get(void) = 0;
};


#endif

