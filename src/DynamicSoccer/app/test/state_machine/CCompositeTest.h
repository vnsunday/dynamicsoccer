#ifndef APP_TEST_STATEMACHINE_CCOMPOSITETEST_H_
#define APP_TEST_STATEMACHINE_CCOMPOSITETEST_H_

#include "app/fundamental/impl/statemachine/sm_composite.h"

/* 
 * Use-case:
 * 
 */

struct TestCompositeMsg
{
    int msgID;
    double data;
};

class CCompositeTest
{
public:
    CCompositeTest(/* args */);
    virtual ~CCompositeTest();

    void run();
};

#endif