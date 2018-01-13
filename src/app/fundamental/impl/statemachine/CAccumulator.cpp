/*
 * CAccumulator.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

#include <fundamental/impl/statemachine/CAccumulator.h>

CAccumulator::CAccumulator(double initVal) : MITSM(initVal) {
}

CAccumulator::~CAccumulator() {
}

double CAccumulator::getNextValues(double currentState, double input, double& output)
{
	output = currentState + input;
	return input;
}
