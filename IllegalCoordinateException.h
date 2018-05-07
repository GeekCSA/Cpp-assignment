/*
 * IllegalCoordinateException.h
 *
 *  Created on: May 6, 2018
 *      Author: mcsa
 */

#ifndef ILLEGALCOORDINATEEXCEPTION_H_
#define ILLEGALCOORDINATEEXCEPTION_H_

class IllegalCoordinateException{

private:

	int x;
	int y;

public:

	IllegalCoordinateException(int new_y,int new_x){
		y = new_y;
		x = new_x;
	}

	const std::string theCoordinate() const{

//		x + "," + y;

		return x + "," + y;
	}

};


#endif /* ILLEGALCOORDINATEEXCEPTION_H_ */
