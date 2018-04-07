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

template <typename T>
struct DoubleT
{
	T t1;
	T t2;

	DoubleT()
	{}

	DoubleT(T val1, T val2)
	{
		t1 = val1;
		t2 = val2;
	}
};

template <typename T>
struct TripleT
{
	T t1;
	T t2;
	T t3;

	TripleT()
	{}

	TripleT(T val1, T val2, T val3)
	{
		t1 = val1;
		t2 = val2;
		t3 = val3;
	}
};

template <typename T1, typename T2, typename T3>
struct TripleField
{
	T1 f1;
	T2 f2;
	T3 f3;

	TripleField()
	{}

	TripleField(T1 val1, T2 val2, T3 val3)
	{
		f1 = val1;
		f2 = val2;
		f3 = val3;
	}
};

// template<typename T, typename T_I, typename T_O>
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

		T myState()
		{
			return state;
		}

	private:
		T state;
		T startState_;
};

template<class T, class T_IO>	// Input & output has same type
class MITSMCascade : public MITSM<DoubleT<T>,T_IO,T_IO>
// class MITSMCascade : public MITSM<T,T_IO,T_IO>
{
public:
	MITSMCascade(MITSM<T,T_IO,T_IO>* p1, MITSM<T,T_IO,T_IO>* p2) :
			MITSM<DoubleT<T>,T_IO,T_IO>(DoubleT<T>(p1->myState(),p2->myState()))
			// MITSM<T,T_IO,T_IO>(p1->myState())
	{
		_p1 = p1;
		_p2 = p2;
	}

	DoubleT<T> getNextValues(DoubleT<T> currentState, T_IO input, T_IO& output)
	{
		T_IO out1;
		T_IO out2;

		T nextState1_ = _p1->getNextValues(currentState.t1, input, out1);
		T nextState2_ = _p2->getNextValues(currentState.t2, out1, out2);

		output = out2;
		return DoubleT<T>(nextState1_, nextState2_);
	}

	/*
	T getNextValues(T currentState, T_IO input, T_IO& output)
	{
		return currentState;
	}
	*/
private:
	MITSM<T, T_IO, T_IO>* _p1;
	MITSM<T, T_IO, T_IO>* _p2;
};

template<class T, class T_IO>	// Input & output has same type
class MITSMCascade2 : public MITSM<int,T_IO,T_IO>
// class MITSMCascade : public MITSM<T,T_IO,T_IO>
{
public:
	MITSMCascade2(MITSM<T,T_IO,T_IO>* p1, MITSM<T,T_IO,T_IO>* p2) :
			MITSM<int,T_IO,T_IO>(0)
	{
		_p1 = p1;
		_p2 = p2;
	}

	int getNextValues(int currentState, T_IO input, T_IO& output)
	{
		T_IO out1;
		T_IO out2;


		T nextState1_ = _p1->getNextValues(_p1->myState(), input, out1);
		T nextState2_ = _p2->getNextValues(_p2->myState(), out1, out2);

		output = out2;
		return 0;
	}

	/*
	T getNextValues(T currentState, T_IO input, T_IO& output)
	{
		return currentState;
	}
	*/
private:
	MITSM<T, T_IO, T_IO>* _p1;
	MITSM<T, T_IO, T_IO>* _p2;
};


#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_H_ */
