//
// Created by robin on 6/13/19.
//

#ifndef SPACEROGUE_ERROR_H
#define SPACEROGUE_ERROR_H


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


#endif //SPACEROGUE_ERROR_H
