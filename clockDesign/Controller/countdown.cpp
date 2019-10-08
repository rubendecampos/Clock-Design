#include "countdown.h"

Countdown::Countdown(Controller* host)
{
    this->host = host;
    animDone = false;
    state = ST_INIT;
    countDown = 10;
}

void Countdown::animate(){
    STATE oldState = state;

    //transition switch
    switch(state){
    case ST_INIT:
        state = ST_COUNT;
        animDone = false;
        break;
    case ST_COUNT:
        animCountDown();
        host->pData->startAllClock();
        countDown --;
        if(host->pData->getClockMoved() == false && countDown == 0){
            state = ST_ANIM;
        }
        break;
    case ST_ANIM:
        if(host->pData->getClockMoved() == false){
            animDone = true;
            state = ST_INIT;
        }
        break;
    }

    if (oldState != state)
    {
        //action switch
        switch (state){
        case ST_COUNT:
            host->setValueTimer(5000);
            break;
        case ST_ANIM:
            host->pData->setAllClock(0,0);
            host->setValueTimer(50);
            break;
        }
    }
}

bool Countdown::isDone(){
    return animDone;
}

void Countdown::setIsDone(bool isDone){
    animDone = isDone;
}

void Countdown::animCountDown(){
    switch(countDown){
    case 10:
        host->digClock->set_1(2);
        host->digClock->set_0(3);
        break;
    case 9:
        host->digClock->set_9(2.5);
        break;
    case 8:
        host->digClock->set_8(2.5);
        break;
    case 7:
        host->digClock->set_7(2.5);
        break;
    case 6:
        host->digClock->set_6(2.5);
        break;
    case 5:
        host->digClock->set_5(2.5);
        break;
    case 4:
        host->digClock->set_4(2.5);
        break;
    case 3:
        host->digClock->set_3(2.5);
        break;
    case 2:
        host->digClock->set_2(2.5);
        break;
    case 1:
        host->digClock->set_1(2.5);
        break;
    }
}
