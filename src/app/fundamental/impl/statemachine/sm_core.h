/*
 * MIT_Example.h
 *
 *  Created on: Jan 14, 2018
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_CORE_H_
#define APP_FUNDAMENTAL_IMPL_STATEMACHINE_SM_CORE_H_

#include "sm.h"

class SMAdder : public MITSM<int,  DoubleField<double, double>, double>
{
public:
    SMAdder() : MITSM<int,  DoubleField<double, double>, double>(0)
    {
    }

    
};

#endif