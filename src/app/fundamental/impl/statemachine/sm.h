/*
 * sm.h
 *
 *  Created on: Dec 26, 2017
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_H_

#include <vector>
#include <stdlib.h>
#include <stdio.h>

template<class T, class T_I, class T_O>
class MITSM
{
public:
	MITSM(T initState)
	{
		startState_ = initState;
	}

	virtual ~MITSM() {}

	int start()
	{
		state = startState_;
		return 0;
	}

	virtual T getNextValues(T currentState, T_I input, T_O& output) = 0;
	
	T_O step(T_I input)
	{
		T_O output;
		state = getNextValues(state, input, output);

		return output;
	}
	
	int transduce(T_I inputs[], int n, std::vector<T_O>& output)
	{
		// int n = sizeof((inputs))/sizeof(T_I);
		output.clear();
		printf("Size = %d\r\n", n);
		for (int i=0;i<n;i++)
		{
			output.push_back(step(inputs[i]));
		}

		return 0;
	}
private:
	T state;
	T startState_;
};

#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_H_ */
