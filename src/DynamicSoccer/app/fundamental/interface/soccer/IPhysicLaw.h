/*
 * IPhysicLaw.h
 *  Created on: Jan 05, 2019
 *      Author: ducvd
 */

#ifndef APP_FUNDAMENTAL_INTERFACE_SOCCER_IPHYSICLAW_H_
#define APP_FUNDAMENTAL_INTERFACE_SOCCER_IPHYSICLAW_H_

#include <string>

class IPhysicLaw
{
public:
	virtual ~IPhysicLaw() {}

    int next_state(void* object) = 0;
};

#endif 