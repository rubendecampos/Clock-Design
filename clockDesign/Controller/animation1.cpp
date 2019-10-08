#include "animation1.h"

Animation1::Animation1(Controller* host)
{
    this->host = host;
    state = ST_INIT;
    animDone = false;
    column = 0;
}

void Animation1::animate(){
    STATE oldState = state;

    //transition switch
    switch(state){
    case ST_INIT:
        state = ST_START;
        column = host->pData->getNbColumn() - 1;
        animDone = false;
        break;
    case ST_START:
        if(host->pData->getClockMoved() == false){
            state = ST_WAVE;
        }
        break;
    case ST_WAVE:
        if(column >= 0){
            for(int line=0;line<host->pData->getNbLine();line++){
                host->pData->getClock(line,column)->startMoving();
            }
            column--;
        }

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
            host->pData->setAllClock(0,180);
            host->pData->setAllClockWise(true);
            host->pData->startAllClock();
            host->setValueTimer(50);
            break;
        case ST_WAVE:
            host->pData->setAllClock(90,270);
            for(int line=0;line<host->pData->getNbLine();line++){
                //Start from the last column
                host->pData->getClock(line,column)->startMoving();
            }
            column--;
            host->setValueTimer(500);
            break;
        case ST_END:
            host->pData->setAllClock(0,0);
            host->pData->setAllClockWise(false);
            host->pData->startAllClock();
            host->setValueTimer(50);
            break;
        }
    }
}

bool Animation1::isDone(){
    return animDone;
}

void Animation1::setIsDone(bool isDone){
    animDone = isDone;
}
