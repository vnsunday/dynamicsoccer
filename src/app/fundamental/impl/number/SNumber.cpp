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

int SNumber::next_Values(char ch, int current_State, int& out_put)
{
	int START = 0;
	int INVALID = -1;
	int SIGN = 1;
	int NUMBER = 2;
	int DOT_REAL = 3;
	int REAL_NUMBER = 4;

	int SIGN_POWER = 5;
	int NUMBER_POWER = 6;
	int DOT_REAL_POWER = 7;
	int REAL_NUMBER_POWER= 9;
	int END = 10;

	int nwState = 0;

	if (current_State == START)
	{
		if (ch == '-' || ch == '+')
		{
			nwState = SIGN;
		}
		else if (ch == ' ' || ch=='\t')
		{
			nwState = START;
		}
		else if (ch >= '0' && ch<='9')
		{
			nwState = NUMBER;
		}
		else
		{
			nwState = INVALID;
		}
	}
	else if (current_State == INVALID)
	{
		nwState = END;
	}
	else if (current_State == SIGN)
	{
		if (ch == ' ' || ch=='\t')
		{
			nwState = SIGN;
		}
		else if (ch >= '0' && ch<='9')
		{
			nwState = NUMBER;
		}
		else
		{
			nwState = INVALID;
		}
	}
	else if (current_State == NUMBER)
	{
		if (ch == '.')
		{
			nwState = DOT_REAL;
		}
		else if (ch >= '0' && ch<='9')
		{
			nwState = NUMBER;
		}
		else
		{
			nwState = INVALID;
		}
	}
	else if (current_State == DOT_REAL)
	{
		if (ch >= '0' && ch<='9')
		{
			nwState = REAL_NUMBER;
		}
		else
		{
			nwState = INVALID;
		}
	}
	else if (current_State == REAL_NUMBER)
	{
		if (ch >= '0' && ch<='9')
		{
			nwState = REAL_NUMBER;
		}
		else if (ch == 'e' || ch == 'E')
		{
			nwState = 
		}
	}
	// if (current_State == )
	return 0;
}