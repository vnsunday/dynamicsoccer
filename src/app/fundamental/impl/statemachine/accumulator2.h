/*
 * accumulator2.h
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_ACCUMULATOR2_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_ACCUMULATOR2_H_

#include "sm.h"

template<class T>
class CAccumulator2 : public SM<T, T, T>
{
public:
	CAccumulator2(T initState) : SM<T,T,T>(initState)
	{}

	T getNextValues(T currentState, T input, T& output)
	{
		T nextState;

		nextState = currentState + input;
		output = currentState + input;

		return nextState;
	}
};


#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_ACCUMULATOR2_H_ */
