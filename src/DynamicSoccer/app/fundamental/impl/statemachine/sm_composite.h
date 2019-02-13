/*
 *  Created on: Feb 01, 2019
 *      Author: spider
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_SMCOMPOSITE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_SMCOMPOSITE_H_

#include "sm.h"
#include <vector>
#include <map>

template<typename T_S,typename T_I,typename T_O>
class SMComposite : public MITSM<T_S, T_I, T_O>
{
public:
    SMComposite(std::vector<MITSM<T_S, T_I, T_O>* > vComposite)
    {
        _mapComposite.clear();
        _vComposite.clear();
        _vComposite.copy(vComposite.begin(), vComposite.end());
    }

    virtual int isThisACompositeState(T_S state) = 0;    // Return -1: if state is in composite machine; 
                                                            // Else: return the vector index of composite-machine

    /*
    int registerComposite(MITSM<T_S, T_I, T_O>* pSubMachine, T_S equalState)    // Assign pSub as the delegationStateID in SMComposite
    {
        _mapComposite[equalState] = pSubMachine;
        return 0;
    }

    bool isInCompositeState()
    {
        // Is currently in composite state
        return (_mapComposite.find(myState()) != _mapComposite.end());
    }

    MITSM<T_S, T_I, T_O>* currentCompositeMachine()
    {
        // Is currently in composite state
        if (isInCompositeState())
        {
            return _mapComposite[myState()];
        }
        else 
        {
            return NULL;
        }
    }
    */

    T_O step(T_I input)
    {
        T_O output;
        T_O outputFake;

        T_S state = myState();

        int index = isThisACompositeState(state);

        if (index >= 0 && index < _vComposite.size())
        {
            MITSM<T_S, T_I, T_O>* pSubMachine = _vComposite[index]  ; //_mapComposite[myState()];
            pSubMachine->getNextValues( pSubMachine->myState(), input, output);

            return output;
        }
        state = getNextValues(state, input, outputFake);

        return output;
    }
private:
    // std::map<T_S, MITSM<T_S, T_I, T_O>* > _mapComposite;
    std::vector<MITSM<T_S, T_I, T_O>* > _vComposite;
};

#endif