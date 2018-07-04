#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_BASE_MACHINE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_BASE_MACHINE_H_

#include "sm.h"

template<typename T_I, typename T_O>
class SMCascade: public SMBase<int, T_I, T_O>
{
public:
    SMCascade(SMCore*p1, SMCore* p2)
    {
        // assert(p1->TypeOfInput() == T_I)
        // assert(p1->TypeOfOutput()) == p2->TypeOfInPut())
        // assert(p2->TypeOfOutput()) == T_O
        _p1 = p1;
        _p2 = p2;
    }

    
    int getNextValues(int current_State, T_I input, T_O& out) 
    {
        /*
        out = current_State;
        
        SMDATA p_Input = (SMDATA)&input;
        SMDATA p_Out = (SMDATA)& out;

        SMDATA pOut1 = _p1->newOutputData();
        _p1->getNextValues(_p1->pointerToState_Data(), p_Input, pOut1);
        _p2->getNextValues(_p2->pointerToState_Data(), pOut1, p_Out);

        _p1->delOutputData(pOut1);
        return input;
        */

       return 0;
    }

    T_O step(T_I input)
	{
		T_O o;

        SMDATA p_Input = (SMDATA)&input;
        SMDATA p_Out1 = _p1->newOutputData();
        SMDATA p_Out2_Cast = (SMDATA) &o;

        _p1->step(p_Input, p_Out1);
        _p2->step(p_Out1, p_Out2_Cast);
        _p1->delOutputData(p_Out1);
        
		return o;
	}

protected:
    SMCore* _p1;
    SMCore* _p2;    
};

class SMDelay2 : public SMBase<double, double, double>
{
public:
    SMDelay2(double initState_Val)
    {
        setStateVal(initState_Val);
    }

    double getNextValues(double current_State, double input, double& out) 
    {
        out = current_State;
        return input;
    }
};

#endif