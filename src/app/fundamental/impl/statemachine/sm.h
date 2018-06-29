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

template <typename T1, typename T2>
struct DoubleField
{
	T1 f1;
	T2 f2;

	DoubleField()
	{}

	DoubleField(T1 val1, T2 val2)
	{
		f1 = val1;
		f2 = val2;
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

		virtual T_O step(T_I input)
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

	protected:
		T state;
		T startState_;
};

template<class T_State1, class T_I1, class T_O1, class T_State2, class T_O2>	// T_O1 == T_I2 ; Output 1 == Input2
class MITSMCascade : public MITSM<int,T_I1,T_O2>
// class MITSMCascade : public MITSM<T,T_IO,T_IO>
{
public:
	MITSMCascade(MITSM<T_State1,T_I1,T_O1>* p1, 
	             MITSM<T_State2,T_O1,T_O2>* p2) :
			MITSM<int,T_I1,T_O2>(0)
			// MITSM<T,T_IO,T_IO>(p1->myState())
	{
		_p1 = p1;
		_p2 = p2;
	}

	int getNextValues(int currentState, T_I1 input, T_O2& output)
	{
		T_O1 out1;
		T_O2 out2;

		T_State1 nextState1_ = _p1->getNextValues(_p1->myState(), input, out1);
		T_State2 nextState2_ = _p2->getNextValues(_p2->myState(), out1, out2);		

		output = out2;
		return this->state;
	}

	T_O2 step(T_I1 input)
	{
		T_O1 o1 = _p1->step(input);
		T_O2 o2 = _p2->step(o1);

		return o2;
	}

    MITSM<T_State1, T_I1, T_O1>* subMachine1()
	{
		return _p1;
	}
	
	MITSM<T_State2, T_O1, T_O2>* subMachine2() 
	{
		return _p2;
	}	
	
private:
	MITSM<T_State1, T_I1, T_O1>* _p1;
	MITSM<T_State2, T_O1, T_O2>* _p2;
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

	T_IO step(T_IO input)
	{
		T_IO o1 = _p1->step(input);
		T_IO o2 = _p2->step(o1);

		return o2;
	}

	MITSM<T, T_IO, T_IO>* subMachine1()
	{
		return _p1;
	}
	
	MITSM<T, T_IO, T_IO>* subMachine2() 
	{
		return _p2;
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


template<typename T_State1, typename T_State2, typename T_I, typename T_O1, typename T_O2>
class MITSMParallel : public MITSM<int , T_I,  DoubleField<T_O1, T_O2> >
{
public:
	MITSMParallel(MITSM<T_State1, T_I, T_O1>* p_Sm1, MITSM<T_State2, T_I, T_O2>* p_Sm2)
						:MITSM<int, T_I,  DoubleField<T_O1, T_O2> > (0)
	{
		_p1 = p_Sm1;
		_p2 = p_Sm2;
	}

	int getNextValues(int currentState, T_I input, DoubleField<T_O1, T_O2>& output)
	{
		T_O1 out1;
		T_O2 out2;
		
		T_State1 nextState1_ = _p1->getNextValues(_p1->myState(), input, out1);
		T_State2 nextState2_ = _p2->getNextValues(_p2->myState(), input, out2);

		output.f1 = out1;
		output.f2 = out2;

		return this->state;
	}

	DoubleField<T_O1, T_O2> step(T_I input)
	{
		T_O1 o1 = _p1->step(input);
		T_O2 o2 = _p2->step(input);
		
		return DoubleField<T_O1,T_O2>(o1,o2);
	}

	MITSM<T_State1, T_I, T_O1>* subMachine1()
	{
		return _p1;
	}	

	MITSM<T_State2, T_I, T_O2>* subMachine2()
	{
		return _p2;
	}

private:
	MITSM<T_State1, T_I, T_O1>* _p1;	
	MITSM<T_State2, T_I, T_O2>* _p2;
};

// template<typename T_State1, typename T_State2, typename T_I1, typename T_I2, typename T_O1, typename T_O2>
// class MITSMParallel2 : public MITSM<DoubleField<T_State1, T_State2> , DoubleField<T_I1, T_I2>,  DoubleField<T_O1, T_O2> >
// {
// public:
// 	MITSMParallel2(MITSM<T_State1, T_I1, T_O1>* p_Sm1, MITSM<T_State2, T_I2, T_O2>* p_Sm2)
// 						: MITSM<DoubleField<T_State1, T_State2> , DoubleField<T_I1, T_I2>,  DoubleField<T_O1, T_O2> > ( DoubleField<T_State1, T_State1> (p_Sm1->myState(), p_Sm2->myState()) )
// 	{
// 		_p1 = p_Sm1;
// 		_p2 = p_Sm2;
// 	}

// 	DoubleField<T_State1, T_State2> getNextValues(DoubleField<T_State1, T_State2> currentState, DoubleField<T_I1, T_I2> input, DoubleField<T_O1, T_O2>& output)
// 	{
// 		T_O1 out1;
// 		T_O2 out2;
		
// 		T_State1 nextState1_ = _p1->getNextValues(currentState.f1, input.f1, out1);
// 		T_State2 nextState2_ = _p2->getNextValues(currentState.f2, input.f2, out2);

// 		output.f1 = out1;
// 		output.f2 = out2;

// 		return DoubleField<T_State1, T_State2>(nextState1_, nextState2_);
// 	}
	
// private:
// 	MITSM<T_State1, T_I1, T_O1>* _p1;	
// 	MITSM<T_State2, T_I2, T_O2>* _p2;
// };

/*
 * 
 * 	T: Input and output of Feedback
 *	T_StateOfEngine: The type of state of pEngine
 * 
 */
template <typename T, typename T_StateOfEngine>
class MITSMFeedback : public MITSM<T, int, T>
{
public:
	MITSMFeedback(MITSM<T_StateOfEngine, T, T>* pEngine)
	{
		_pEng = pEngine;
	}
	
	T getNextValues(T current_State, int input, T& output)
	{
		T val;
		_pEng->getNextValues(_pEng->myState(), current_State, val);

		output = val;
		return val;	// State store the new value
	}

	T step(int input)
	{
		T output =  _pEng->step(this->state);	
		this->state = output;	// Store the new value			
		return output;
	}
	
private:
	MITSM<T_StateOfEngine, T, T>* _pEng;
};

// #define ANYTYPE void*

// class SMCore
// {
// public:
// 	virtual ~SMCore() {}
// 	virtual ANYTYPE getNextValues(ANYTYPE currentState, ANYTYPE input, ANYTYPE output) = 0;

// 	virtual ANYTYPE step(ANYTYPE input)
// 	{
// 		return NULL;
// 	}
// };

#endif /* APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_H_ */
