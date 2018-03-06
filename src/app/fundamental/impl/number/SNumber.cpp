/*
 * SNumber.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#include <fundamental/impl/number/SNumber.h>
#include <stdio.h>
#include <stdlib.h>

SNumber::SNumber(const char* szNum) {
	_strNum = szNum;
}

SNumber::~SNumber() {
}

bool SNumber::operator>(const SNumber& num1, const SNumber& num2)
{
	return true;
}

SNumber SNumber::operator+(const SNumber& num1)
{
	return SNumber("");
}

bool SNumber::operator>(const SNumber& num1, const SNumber& num2)
{
	return true;
}

bool SNumber::isNumber(const char* szNum)
{
	/*
	 * What is Number's representation
	 *	+1000
	 *	+ 10000
	 *	100
	 *	-100
	 *	- 1000
	 *  10E10
	 *  10e10
	 *  +10E10
	 *  +10e10
	 *
	 *  10E-10
	 *  10e-10
	 *  -10E-10
	 *  -10E-10
	 *
	 *  +1000.23456
	 *  1000.23456
	 */

	 /*
	  *		Number types
	  *			Type01 = [space][+/-][space](number)[space]
	  *			Type02 = [space][+/-][space](number)(e/E)(number)[space]
	  */
	int n = strlen(szNum);	

	/*
		Dummy approach:
			Use a scanner from Left to Right 
							
	*/
	int type = 1;

	for (int i = 0; i < n; ++i)
	{
		// Use a state machine for detect which type of number 
	}	
	// State Machine
	//	Type = Start, Invalid, TypeNumber, TypeE
	//	Start ->(space)-> Start
	//	Start ->(+) -> PreNumber
	//  Start ->(-) -> PreNumber
	//	Start ->(0-9) -> Seminumber
	//	SemiNumber->(0-9) -> SemiNumber
	//  Seminumber->(+/-/Space) -> Invalid -> End
	//  
	// 	
	//	

	return true;
}
