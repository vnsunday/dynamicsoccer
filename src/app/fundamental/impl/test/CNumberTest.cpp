/*
 * CNumberTest.cpp
 *
 *  Created on: Mar 7, 2018
 *      Author: spider
 */

#include <fundamental/impl/test/CNumberTest.h>
#include <fundamental/impl/number/SNumber.h>
#include <sstream>
#include <string>
#include <fstream>
#include "util/TestUtil.h"

using namespace std;

CNumberTest::CNumberTest() {
}

CNumberTest::~CNumberTest() {
}

void CNumberTest::runTest(const char* szFile_Test)
{
	std::ifstream io_Test(szFile_Test);
	std::string sLine;

	int state = "StartNewTest";
	int isLoading = 1;	

	while (std::getline(io_Test, sLine))
	{
		isLoading = 0;
		if (sLine == "Test")
		{			
		}
	}

	int numberFailed = 0;
	int numberTest = 0;
	SNumber num1("+10.23");
	SNumber num2("10.234");
	SNumber num3("1E+23");
	SNumber num4("1E23");

 	numberFailed += TestUtil::assert(num1.rawData().sign_ == 1, "Sign of number1 must +");
 	numberTest++;

 	numberFailed += TestUtil::assert(num1.rawData().number_ == "10", "Sign of number must +");
 	numberTest++;

 	numberFailed += TestUtil::assert(num1.rawData().dot_number_ == "23", "Sign of number1 must +");
 	numberTest++;



}
