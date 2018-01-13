/*
 * MIT_Example.h
 *
 *  Created on: Jan 14, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_MIT_EXAMPLE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_MIT_EXAMPLE_H_

#include "sm.h"

class UpDown : public MITSM<int, char, int>
{
public:
	UpDown(int initState): MITSM<int, char, int>(initState) {}

	int getNextValues(int currentState, char input, int& output)
	{
		int nextStt;

		if (input == 'u')
		{
			nextStt = currentState+1;
			output = nextStt;
		}
		else
		{
			nextStt = currentState - 1;
			output = nextStt;
		}

		return nextStt;
	}
};


#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_MIT_EXAMPLE_H_ */
