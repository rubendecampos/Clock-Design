#include "animationbex.h"

AnimationBex::AnimationBex(Controller* host)
{
    this->host = host;
    state = ST_INIT;
    animDone = false;
    column = 0;
}

//display BEX in with a wave
void AnimationBex::animate(){
    STATE oldState = state;

    //transition switch
    switch(state){
    case ST_INIT:
        state = ST_START;
        animDone = false;
        break;
    case ST_START:
        if(host->pData->getClockMoved() == false){
            state = ST_BEX;
        }
        break;
    case ST_BEX:
        if(host->pData->getClockMoved() == false){
            state = ST_END;
        }
        break;
    case ST_END:
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
        case ST_START:
            host->pData->setAllClock(0,0);
            host->pData->setFastWay(true);
            host->pData->startAllClock();
            host->setValueTimer(50);
            break;
        case ST_BEX:
            host->pData->setAllClockDownLeft();
            host->letter->setB(1);
            host->letter->setE(5);
            host->letter->setX(9);
            host->pData->startAllClock();
            host->setValueTimer(2000);
            break;
        case ST_END:
            host->pData->setAllClock(0,0);
            host->pData->setFastWay(true);
            host->pData->startAllClock();
            host->setValueTimer(50);
            break;
        }
    }
}

//Inform the controller that the animation is done
bool AnimationBex::isDone(){
    return animDone;
}

//Set the private argument animDone
void AnimationBex::setIsDone(bool isDone){
    animDone = isDone;
}
