#include "letter.h"

Letter::Letter(Controller* host)
{
    this->host = host;
}

void Letter::setB(int column){
    host->pData->getClock(0,column)->setClockDown(1);
    host->pData->getClock(0,column)->setClockRight(2);
    host->pData->getClock(1,column)->setClockUp(1);
    host->pData->getClock(1,column)->setClockDown(2);
    host->pData->getClock(2,column)->setClockUp(1);
    host->pData->getClock(2,column)->setClockDown(2);
    host->pData->getClock(3,column)->setClockUp(1);
    host->pData->getClock(3,column)->setClockDown(2);
    host->pData->getClock(4,column)->setClockDown(1);
    host->pData->getClock(4,column)->setClockDown(2);
    host->pData->getClock(5,column)->setClockUp(1);
    host->pData->getClock(5,column)->setClockRight(2);

    host->pData->getClock(0,column+1)->setClockLeft(1);
    host->pData->getClock(0,column+1)->setClockRight(2);
    host->pData->getClock(1,column+1)->setClockRight(1);
    host->pData->getClock(1,column+1)->setClockDown(2);
    host->pData->getClock(2,column+1)->setClockUp(1);
    host->pData->getClock(2,column+1)->setClockRight(2);
    host->pData->getClock(3,column+1)->setClockRight(1);
    host->pData->getClock(3,column+1)->setClockDown(2);
    host->pData->getClock(4,column+1)->setClockUp(1);
    host->pData->getClock(4,column+1)->setClockRight(2);
    host->pData->getClock(5,column+1)->setClockLeft(1);
    host->pData->getClock(5,column+1)->setClockRight(2);

    host->pData->getClock(0,column+2)->setClockLeft(1);
    host->pData->getClock(0,column+2)->setClockDownRight(2);
    host->pData->getClock(1,column+2)->setClockLeft(1);
    host->pData->getClock(1,column+2)->setClockDown(2);
    host->pData->getClock(2,column+2)->setClockUp(1);
    host->pData->getClock(2,column+2)->setClockLeft(2);
    host->pData->getClock(3,column+2)->setClockLeft(1);
    host->pData->getClock(3,column+2)->setClockDown(2);
    host->pData->getClock(4,column+2)->setClockUp(1);
    host->pData->getClock(4,column+2)->setClockLeft(2);
    host->pData->getClock(5,column+2)->setClockLeft(1);
    host->pData->getClock(5,column+2)->setClockUpRight(2);

    host->pData->getClock(0,column+3)->setClockDownLeft(1);
    host->pData->getClock(0,column+3)->setClockDownLeft(2);
    host->pData->getClock(1,column+3)->setCLockUpLeft(1);
    host->pData->getClock(1,column+3)->setClockDown(2);
    host->pData->getClock(2,column+3)->setClockUp(1);
    host->pData->getClock(2,column+3)->setClockRight(2);
    host->pData->getClock(3,column+3)->setClockRight(1);
    host->pData->getClock(3,column+3)->setClockDown(2);
    host->pData->getClock(4,column+3)->setClockUp(1);
    host->pData->getClock(4,column+3)->setClockDownLeft(2);
    host->pData->getClock(5,column+3)->setClockDownLeft(1);
    host->pData->getClock(5,column+3)->setClockDownLeft(2);
}
