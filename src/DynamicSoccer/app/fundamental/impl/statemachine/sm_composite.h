/*
 *  Created on: Feb 01, 2019
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_SMCOMPOSITE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_SMCOMPOSITE_H_

#include "sm.h"
#include <vector>

template<typename T_S,typename T_I,typename T_O>
class SMComposite : public MITSM<T_S, T_I, T_O>
{


public:
    SMComposite()
    {}

    int addSubMachine(MITSM<T_S, T_I, T_O>* pSub, T_S delegationStateID)    // Assign pSub as the delegationStateID in SMComposite
    {
        return 0;
    }


    T_S getNextValues(T_S currentState, T_I input, T_O& output)
    {
        T_S s;
        if (isChangeToSubMachine(currentState, input))
        {}

        if (WhoProcessThisMsg(currentState, input) == -1)
        {
            
        }
    }

    virtual int WhoProcessThisMsg(T_S currentState, T_I incomingMsg, T_S& delegationState) = 0;   // = 0: Main Machine; 1: Composite Machine
};

#endif