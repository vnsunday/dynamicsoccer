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

template<class T>
class Delay: public MITSM<T,T,T>
{
public:
	Delay(T initState): MITSM<T,T,T>(initState) {}

	T getNextValues(T currentState, T input, T& output)
	{
		output = currentState;		// Output is the current state
		return input;				// Input is the next state
	}
};

class Average2 : public MITSM<double, double, double>
{
public:
	Average2(double initState): MITSM<double, double, double>(initState) {}

	double getNextStates(double currentState, double input, double& output)
	{
		double nextStt = input;
		output = (currentState + input) / 2;
		return nextStt;
	}
};

struct DoubleDouble
{
	double d1;
	double d2;

	DoubleDouble()
	{
		d1=0;
		d2=0;
	}

	DoubleDouble(double dd1, double dd2)
	{
		d1 = dd1;
		d2 = dd2;
	}
};

class SumLast3 : public MITSM<DoubleDouble, double, double>
{
public:
	SumLast3(double initSum): MITSM<DoubleDouble, double, double>(DoubleDouble(0, initSum)) {}

	DoubleDouble getNextStates(DoubleDouble currentState, double input, double& output)
	{
		DoubleDouble nextStt = DoubleDouble(currentState.d2, input);
		output = currentState.d1 + currentState.d2 + input;

		return nextStt;
	}
};

template<class T>
class Selector: public MITSM<T, std::vector<T>, T>
{
public:
	Selector(T initState, int K): MITSM<T, std::vector<T>, T>(initState)
	{
		this->K = K;
	}

	T getNextStates(T currentState, std::vector<T> input, T& output)
	{
		T nextStt = input[K];
		output = nextStt;

		return nextStt;
	}
private:
	int K;
};

class Increment: public MITSM<double, double, double>
{
public:
	Increment(double initVal, double incr): MITSM<double, double, double>(initVal)
	{
		_incr = incr;
	}

	double getNextStates(double currentState, double input, double& output)
	{
		double nextStt = input;
		output = input + currentState;

		return nextStt;
	}
private:
	double _incr;	
};

#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_MIT_EXAMPLE_H_ */
