/*
 * Integer.h
 *
 *  Created on: 16 нояб. 2017 г.
 *      Author: pavel
 */

#ifndef LAB9_INTEGER_H_
#define LAB9_INTEGER_H_

class Integer {
private:
	int _value;
	char* _buffer;
public:
	Integer(int value);
	~Integer();
	operator char*();
};

#endif /* LAB9_INTEGER_H_ */
