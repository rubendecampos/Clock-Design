#include "digitalclock.h"

DigitalClock::DigitalClock(Controller* host)
{
    this->host = host;
}

void DigitalClock::set_0(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockDown(1);
    host->pData->getClock(1,1+offset)->setClockRight(2);

    host->pData->getClock(2,1+offset)->setClockUp(1);
    host->pData->getClock(2,1+offset)->setClockDown(2);

    host->pData->getClock(3,1+offset)->setClockRight(1);
    host->pData->getClock(3,1+offset)->setClockUp(2);

    host->pData->getClock(1,2+offset)->setClockDown(1);
    host->pData->getClock(1,2+offset)->setClockLeft(2);

    host->pData->getClock(2,2+offset)->setClockUp(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockLeft(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}

void DigitalClock::set_1(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockDown(1);
    host->pData->getClock(1,1+offset)->setClockDown(2);

    host->pData->getClock(2,1+offset)->setClockDown(1);
    host->pData->getClock(2,1+offset)->setClockDown(2);

    host->pData->getClock(3,1+offset)->setClockDown(1);
    host->pData->getClock(3,1+offset)->setClockDown(2);

    host->pData->getClock(1,2+offset)->setClockDown(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockUp(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockUp(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}

void DigitalClock::set_2(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockRight(1);
    host->pData->getClock(1,1+offset)->setClockRight(2);

    host->pData->getClock(2,1+offset)->setClockRight(1);
    host->pData->getClock(2,1+offset)->setClockDown(2);

    host->pData->getClock(3,1+offset)->setClockRight(1);
    host->pData->getClock(3,1+offset)->setClockUp(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockLeft(1);
    host->pData->getClock(2,2+offset)->setClockUp(2);

    host->pData->getClock(3,2+offset)->setClockLeft(1);
    host->pData->getClock(3,2+offset)->setClockLeft(2);
}

void DigitalClock::set_3(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockRight(1);
    host->pData->getClock(1,1+offset)->setClockRight(2);

    host->pData->getClock(2,1+offset)->setClockRight(1);
    host->pData->getClock(2,1+offset)->setClockRight(2);

    host->pData->getClock(3,1+offset)->setClockRight(1);
    host->pData->getClock(3,1+offset)->setClockRight(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockLeft(1);
    host->pData->getClock(2,2+offset)->setClockUp(2);

    host->pData->getClock(3,2+offset)->setClockLeft(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}

void DigitalClock::set_4(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockDown(1);
    host->pData->getClock(1,1+offset)->setClockDown(2);

    host->pData->getClock(2,1+offset)->setClockUp(1);
    host->pData->getClock(2,1+offset)->setClockRight(2);

    host->pData->getClock(3,1+offset)->setClockDown(1);
    host->pData->getClock(3,1+offset)->setClockDown(2);

    host->pData->getClock(1,2+offset)->setClockDown(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockUp(1);
    host->pData->getClock(2,2+offset)->setClockLeft(2);

    host->pData->getClock(3,2+offset)->setClockUp(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}

void DigitalClock::set_5(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockRight(1);
    host->pData->getClock(1,1+offset)->setClockDown(2);

    host->pData->getClock(2,1+offset)->setClockRight(1);
    host->pData->getClock(2,1+offset)->setClockUp(2);

    host->pData->getClock(3,1+offset)->setClockRight(1);
    host->pData->getClock(3,1+offset)->setClockRight(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockLeft(2);

    host->pData->getClock(2,2+offset)->setClockLeft(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockUp(1);
    host->pData->getClock(3,2+offset)->setClockLeft(2);
}

void DigitalClock::set_6(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockDown(1);
    host->pData->getClock(1,1+offset)->setClockRight(2);

    host->pData->getClock(2,1+offset)->setClockUp(1);
    host->pData->getClock(2,1+offset)->setClockDown(2);

    host->pData->getClock(3,1+offset)->setClockRight(1);
    host->pData->getClock(3,1+offset)->setClockUp(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockLeft(2);

    host->pData->getClock(2,2+offset)->setClockLeft(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockUp(1);
    host->pData->getClock(3,2+offset)->setClockLeft(2);
}

void DigitalClock::set_7(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockRight(1);
    host->pData->getClock(1,1+offset)->setClockRight(2);

    host->pData->getClock(2,1+offset)->setClockDown(1);
    host->pData->getClock(2,1+offset)->setClockDown(2);

    host->pData->getClock(3,1+offset)->setClockDown(1);
    host->pData->getClock(3,1+offset)->setClockDown(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockUp(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockUp(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}

void DigitalClock::set_8(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockRight(1);
    host->pData->getClock(1,1+offset)->setClockDown(2);

    host->pData->getClock(2,1+offset)->setClockUp(1);
    host->pData->getClock(2,1+offset)->setClockRight(2);

    host->pData->getClock(3,1+offset)->setClockUp(1);
    host->pData->getClock(3,1+offset)->setClockRight(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockLeft(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockLeft(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}

void DigitalClock::set_9(int digit)
{
    int offset = digit * 2;


    host->pData->getClock(1,1+offset)->setClockRight(1);
    host->pData->getClock(1,1+offset)->setClockDown(2);

    host->pData->getClock(2,1+offset)->setClockUp(1);
    host->pData->getClock(2,1+offset)->setClockRight(2);

    host->pData->getClock(3,1+offset)->setClockRight(1);
    host->pData->getClock(3,1+offset)->setClockRight(2);

    host->pData->getClock(1,2+offset)->setClockLeft(1);
    host->pData->getClock(1,2+offset)->setClockDown(2);

    host->pData->getClock(2,2+offset)->setClockUp(1);
    host->pData->getClock(2,2+offset)->setClockDown(2);

    host->pData->getClock(3,2+offset)->setClockLeft(1);
    host->pData->getClock(3,2+offset)->setClockUp(2);
}