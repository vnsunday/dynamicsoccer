/*
 * SNumber.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: ducvd
 */

#include <fundamental/impl/number/SNumber.h>

SNumber::SNumber() {
}

SNumber::~SNumber() {
}

bool SNumber::operator>(const SNumber& num1, const SNumber& num2)\
{
	return true;
}

SNumber SNumber::operator+(const SNumber& num1)
{
	return SNumber("");
}
