#include "CFinishingUserCase.h"

CFinishingUserCase::CFinishingUserCase()
{}

CFinishingUserCase::~CFinishingUserCase()
{}

int CFinishingUserCase::run()
{
    return 0;
}

int CFinishingUserCase::initialize(IPlayer* player1, IPlayer* player2)
{
    player1->positions();
    player2->positions();
    player1->positions();

    return 0;
}