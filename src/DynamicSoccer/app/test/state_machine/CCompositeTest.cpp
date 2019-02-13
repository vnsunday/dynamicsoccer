#include "CCompositeTest.h"

CarFurnitureSM::CarFurnitureSM()
{}

CarFactoryState CarFurnitureSM::getNextValues(CarFactoryState currentState, CarFactoryMsg input, CarFactoryOut& output)
{
        
}

CarFactorySM::CarFactorySM(CarFurnitureSM* pOutsource)
                            :CarSystemContainer(std::vector<CarSystem*>{pOutsource})
{}

int CarFactorySM::isThisACompositeState(CarFactoryState state)
{
    if (state.stateID == CAR_FACTORY_STATE_OUTSOURCE_FURNITURE)
    {
        return 0;       // Return the index of Furniture machine
    }
    else
    {
        return -1;
    }
}

CarFactoryState CarFactorySM::getNextValues(CarFactoryState currentState, CarFactoryMsg input, CarFactoryOut& output)
{
    CarFactoryState newState = currentState;
    
    if (currentState.stateID == CAR_FACTORY_STATE_INIT)
    {
        if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_ENGINE)
        {
            newState.stateID = CAR_FACTORY_STATE_PRODUCE_ENGINE;
            newState.engineProduced = 1;
            output.strData = "EngineID=";
            output.strData += rand();
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_WHEEL)
        {
            newState.stateID = CAR_FACTORY_STATE_PRODUCE_WHEEL;
            newState.wheelProduced = 1;
            output.strData = "WheelID=";
            output.strData += rand();
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE)
        {
            newState.stateID = CAR_FACTORY_STATE_OUTSOURCE_FURNITURE;
            // TODO
            newState.wheelProduced = 1;
            output.strData = "WheelID=";
            output.strData += rand();
        }
    }
    else if (currentState.stateID == CAR_FACTORY_STATE_FINISH)
    {
        // Do Nothing
    }
    else
    {
        if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_ENGINE)
        {
            newState.stateID = CAR_FACTORY_STATE_PRODUCE_ENGINE;
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_WHEEL)
        {
            newState.stateID = CAR_FACTORY_STATE_PRODUCE_WHEEL;
        }
        else if (input.msgID == CAR_FACTORY_SM_MSG_PRODUCE_FURNITUE)
        {
            newState.stateID = CAR_FACTORY_STATE_PRODUCE_WHEEL;
        }
    }

    return newState;
}

CCompositeTest::CCompositeTest(/* args */)
{}

CCompositeTest::~CCompositeTest()
{}

void CCompositeTest::run()
{
    
}