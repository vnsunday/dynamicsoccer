/*
 * CAccumulator.h
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_CACCUMULATOR_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_CACCUMULATOR_H_

class CAccumulator {
public:
	CAccumulator();
	CAccumulator(int initVal);
	virtual ~CAccumulator();

	int getNextValues(int currentState, int input, int& output);	// return next state
	int step(int input);
private:
	int state;
};

#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_CACCUMULATOR_H_ */
