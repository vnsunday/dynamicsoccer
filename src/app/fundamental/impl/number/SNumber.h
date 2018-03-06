/*
 * SNumber.h
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_IMPL_NUMBER_SNUMBER_H_
#define APP_FUNDAMENTAL_IMPL_NUMBER_SNUMBER_H_

#include <string> 

// Every numbers here
class SNumber {

public:
	SNumber(const char* szNum);
	virtual ~SNumber();

	bool operator>(const SNumber& num1, const SNumber& num2);
	SNumber operator+(const SNumber& num1);
protected:
	bool isNumber(const char* szNum);
	int next_Values(char ch, int current_State, int& out_put);
private:
	std::string _strNum;
};

#endif /* APP_FUNDAMENTAL_IMPL_NUMBER_SNUMBER_H_ */
