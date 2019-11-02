#include "digitalclock.h"

//Constructor
DigitalClock::DigitalClock(Controller* host)
{
    this->host = host;
}

//Set a 0
void DigitalClock::set_0(double column)
{
    host->pData->getClock(1,column)->setClockDown(1);
    host->pData->getClock(1,column)->setClockRight(2);

    host->pData->getClock(2,column)->setClockUp(1);
    host->pData->getClock(2,column)->setClockDown(2);

    host->pData->getClock(3,column)->setClockRight(1);
    host->pData->getClock(3,column)->setClockUp(2);

    host->pData->getClock(1,column+1)->setClockDown(1);
    host->pData->getClock(1,column+1)->setClockLeft(2);

    host->pData->getClock(2,column+1)->setClockUp(1);
    host->pData->getClock(2,column+1)->setClockDown(2);

    host->pData->getClock(3,column+1)->setClockLeft(1);
    host->pData->getClock(3,column+1)->setClockUp(2);
}

//Set a 1
void DigitalClock::set_1(double column)
{
    host->pData->getClock(1,column)->setClockDownLeft(1);
    host->pData->getClock(1,column)->setClockDownLeft(2);

    host->pData->getClock(2,column)->setClockDownLeft(1);
    host->pData->getClock(2,column)->setClockDownLeft(2);

    host->pData->getClock(3,column)->setClockDownLeft(1);
    host->pData->getClock(3,column)->setClockDownLeft(2);

    host->pData->getClock(1,1+column)->setClockDown(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockUp(1);
    host->pData->getClock(2,1+column)->setClockDown(2);

    host->pData->getClock(3,1+column)->setClockUp(1);
    host->pData->getClock(3,1+column)->setClockUp(2);
}

//Set a 2
void DigitalClock::set_2(double column)
{
    host->pData->getClock(1,column)->setClockRight(1);
    host->pData->getClock(1,column)->setClockRight(2);

    host->pData->getClock(2,column)->setClockRight(1);
    host->pData->getClock(2,column)->setClockDown(2);

    host->pData->getClock(3,column)->setClockRight(1);
    host->pData->getClock(3,column)->setClockUp(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockLeft(1);
    host->pData->getClock(2,1+column)->setClockUp(2);

    host->pData->getClock(3,1+column)->setClockLeft(1);
    host->pData->getClock(3,1+column)->setClockLeft(2);
}

//Set a 3
void DigitalClock::set_3(double column)
{
    host->pData->getClock(1,column)->setClockRight(1);
    host->pData->getClock(1,column)->setClockRight(2);

    host->pData->getClock(2,column)->setClockRight(1);
    host->pData->getClock(2,column)->setClockRight(2);

    host->pData->getClock(3,column)->setClockRight(1);
    host->pData->getClock(3,column)->setClockRight(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockLeft(1);
    host->pData->getClock(2,1+column)->setClockUp(2);

    host->pData->getClock(3,1+column)->setClockLeft(1);
    host->pData->getClock(3,1+column)->setClockUp(2);
}

//Set a 4
void DigitalClock::set_4(double column)
{
    host->pData->getClock(1,column)->setClockDown(1);
    host->pData->getClock(1,column)->setClockDown(2);

    host->pData->getClock(2,column)->setClockUp(1);
    host->pData->getClock(2,column)->setClockRight(2);

    host->pData->getClock(3,column)->setClockDownLeft(1);
    host->pData->getClock(3,column)->setClockDownLeft(2);

    host->pData->getClock(1,1+column)->setClockDown(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockUp(1);
    host->pData->getClock(2,1+column)->setClockLeft(2);

    host->pData->getClock(3,1+column)->setClockUp(1);
    host->pData->getClock(3,1+column)->setClockUp(2);
}

//Set a 5
void DigitalClock::set_5(double column)
{
    host->pData->getClock(1,column)->setClockRight(1);
    host->pData->getClock(1,column)->setClockDown(2);

    host->pData->getClock(2,column)->setClockRight(1);
    host->pData->getClock(2,column)->setClockUp(2);

    host->pData->getClock(3,column)->setClockRight(1);
    host->pData->getClock(3,column)->setClockRight(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockLeft(2);

    host->pData->getClock(2,1+column)->setClockLeft(1);
    host->pData->getClock(2,1+column)->setClockDown(2);

    host->pData->getClock(3,1+column)->setClockUp(1);
    host->pData->getClock(3,1+column)->setClockLeft(2);
}

//Set a 6
void DigitalClock::set_6(double column)
{
    host->pData->getClock(1,column)->setClockDown(1);
    host->pData->getClock(1,column)->setClockRight(2);

    host->pData->getClock(2,column)->setClockUp(1);
    host->pData->getClock(2,column)->setClockDown(2);

    host->pData->getClock(3,column)->setClockRight(1);
    host->pData->getClock(3,column)->setClockUp(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockLeft(2);

    host->pData->getClock(2,1+column)->setClockLeft(1);
    host->pData->getClock(2,1+column)->setClockDown(2);

    host->pData->getClock(3,1+column)->setClockUp(1);
    host->pData->getClock(3,1+column)->setClockLeft(2);
}

//Set a 7
void DigitalClock::set_7(double column)
{
    host->pData->getClock(1,column)->setClockRight(1);
    host->pData->getClock(1,column)->setClockRight(2);

    host->pData->getClock(2,column)->setClockDownLeft(1);
    host->pData->getClock(2,column)->setClockDownLeft(2);

    host->pData->getClock(3,column)->setClockDownLeft(1);
    host->pData->getClock(3,column)->setClockDownLeft(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockUp(1);
    host->pData->getClock(2,1+column)->setClockDown(2);

    host->pData->getClock(3,1+column)->setClockUp(1);
    host->pData->getClock(3,1+column)->setClockUp(2);
}

//Set a 8
void DigitalClock::set_8(double column)
{
    host->pData->getClock(1,column)->setClockRight(1);
    host->pData->getClock(1,column)->setClockDown(2);

    host->pData->getClock(2,column)->setClockUp(1);
    host->pData->getClock(2,column)->setClockRight(2);

    host->pData->getClock(3,column)->setClockUp(1);
    host->pData->getClock(3,column)->setClockRight(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockLeft(1);
    host->pData->getClock(2,1+column)->setClockDown(2);

    host->pData->getClock(3,1+column)->setClockLeft(1);
    host->pData->getClock(3,1+column)->setClockUp(2);
}

//Set a 9
void DigitalClock::set_9(double column)
{
    host->pData->getClock(1,column)->setClockRight(1);
    host->pData->getClock(1,column)->setClockDown(2);

    host->pData->getClock(2,column)->setClockUp(1);
    host->pData->getClock(2,column)->setClockRight(2);

    host->pData->getClock(3,column)->setClockRight(1);
    host->pData->getClock(3,column)->setClockRight(2);

    host->pData->getClock(1,1+column)->setClockLeft(1);
    host->pData->getClock(1,1+column)->setClockDown(2);

    host->pData->getClock(2,1+column)->setClockUp(1);
    host->pData->getClock(2,1+column)->setClockDown(2);

    host->pData->getClock(3,1+column)->setClockLeft(1);
    host->pData->getClock(3,1+column)->setClockUp(2);
}
