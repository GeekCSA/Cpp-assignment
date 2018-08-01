/*
 * IllegalCharException.h
 *
 *  Created on: May 7, 2018
 *      Author: mcsa
 */

#ifndef ILLEGALCHAREXCEPTION_H_
#define ILLEGALCHAREXCEPTION_H_


class IllegalCharException{

private:

	char c;

public:

	IllegalCharException(char new_c):c(new_c){
	}

	const char theChar() const{
		return c;
	}
};


#endif /* ILLEGALCHAREXCEPTION_H_ */
