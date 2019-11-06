#include "animationbex.h"

AnimationBex::AnimationBex(Controller* host)
{
    this->host = host;
    state = ST_INIT;
    animDone = false;
    column = 0;
    line = 0;
}

//display BEX in with a wave
void AnimationBex::animate(){
    STATE oldState = state;

    //transition switch
    switch(state){
    case ST_INIT:
        state = ST_START;
        animDone = false;
        column = 0;
        line = 0;
        break;
    case ST_START:
        if(host->pData->getClockMoved() == false){
            state = ST_BEX;
        }
        break;
    case ST_BEX:
        for(int l=0;l<=line;l++){
            for(int c=0;c<=column;c++){
                host->pData->getClock(l,c)->startMoving();
            }
        }
        //Limit of column or line?
        if(line < host->pData->getNbLine()-1){
            line++;
        }
        if(column < host->pData->getNbColumn()-1){
            column++;
        }

        //All clock stoped?
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
            //host->pData->setFastWay(true);
            host->pData->setAllClockWise(false,true);
            host->pData->startAllClock();
            host->setValueTimer(50);
            break;
        case ST_BEX:
            host->pData->setAllClockDownLeft();
            host->letter->setB(1);
            host->letter->setE(5);
            host->letter->setX(9);
            //Start the first clock
            host->pData->getClock(line,column)->startMoving();
            column++;
            line++;
            host->setValueTimer(300);
            break;
        case ST_END:
            host->pData->setAllClock(0,0);
            //host->pData->setFastWay(true);
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
