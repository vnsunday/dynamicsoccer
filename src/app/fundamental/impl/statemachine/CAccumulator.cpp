/*
 * CAccumulator.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

#include <fundamental/impl/statemachine/CAccumulator.h>

CAccumulator::CAccumulator() {
	state = 0;
}

CAccumulator::CAccumulator(int initVal) {
	state = initVal;
}

CAccumulator::~CAccumulator() {
}

int CAccumulator::getNextValues(int currentState, int input, int& output)
{
	output = currentState + input;
	return output;
}

int CAccumulator::step(int input)
{
	int output;
	state = getNextValues(state, input, output);

	return output;
}