#include "countdown.h"

//Constructor
Countdown::Countdown(Controller* host)
{
    this->host = host;
    animDone = false;
    state = ST_INIT;
    countDown = 10;
}

//Animate a countdown
void Countdown::animate(){
    STATE oldState = state;

    //transition switch
    switch(state){
    case ST_INIT:
        state = ST_COUNT;
        countDown = 10;
        animDone = false;
        break;
    case ST_COUNT:
        animCountDown();
        host->pData->startAllClock();
        countDown --;
        if(host->pData->getClockMoved() == false && countDown < 0){
            state = ST_ANIM;
        }
        break;
    case ST_ANIM:
        if(host->pData->getClockMoved() == false){
            state = ST_END;
            host->pData->setFastWay(false);
        }
        break;
    case ST_END:
        if(host->pData->getClockMoved() == false){
            state = ST_INIT;
            animDone = true;
        }
    }

    if (oldState != state)
    {
        //action switch
        switch (state){
        case ST_COUNT:
            animCountDown();
            host->pData->setFastWay(true);
            host->pData->startAllClock();
            countDown --;
            host->setValueTimer(2000);
            break;
        case ST_ANIM:
            host->pData->setAllClock(180,180);
            host->pData->setFastWay(false);
            host->pData->setAllClockWise(true,false);
            host->setValueTimer(50);
            break;
        case ST_END:
            host->pData->setAllClock(0,0);
            host->pData->startAllClock();
        }
    }
}

//Inform the controller that the animation is done
bool Countdown::isDone(){
    return animDone;
}

//Set the private argument animDone
void Countdown::setIsDone(bool isDone){
    animDone = isDone;
}

//Set the digit in function of the number to display
void Countdown::animCountDown(){
    switch(countDown){
    case 10:
        host->digClock->set_1(1);
        host->digClock->set_0(2);
        break;
    case 9:
        //Reset the digits first, because 10 is on two digits
        host->pData->setAllClock(0,0);
        host->digClock->set_9(1.5);
        break;
    case 8:
        host->digClock->set_8(1.5);
        break;
    case 7:
        host->digClock->set_7(1.5);
        break;
    case 6:
        host->digClock->set_6(1.5);
        break;
    case 5:
        host->digClock->set_5(1.5);
        break;
    case 4:
        host->digClock->set_4(1.5);
        break;
    case 3:
        host->digClock->set_3(1.5);
        break;
    case 2:
        host->digClock->set_2(1.5);
        break;
    case 1:
        host->digClock->set_1(1.5);
        break;
    case 0:
        host->digClock->set_0(1.5);
        break;
    }
}
