#include "clock.h"

Clock::Clock(int posX, int posY, int clockH1, int clockH2)
{
    this->posX = posX;
    this->posY = posY;
    this->clockHand_1 = clockH1;
    this->clockHand_2 = clockH2;
}

void Clock::setClockH1(int pos){
    this->clockHand_1 = pos;
}

void Clock::setClockH2(int pos){
    this->clockHand_2 = pos;
}

void Clock::setClock(int hand1, int hand2){
    this->clockHand_1 = hand1;
    this->clockHand_2 = hand2;
}

void Clock::setClockWise(bool cw){
    this->clockWise = clockWise;
}

int Clock::getClockH1(){
    return clockHand_1;
}

int Clock::getClockH2(){
    return clockHand_2;
}

bool Clock::getClockWise(){
    return clockWise;
}

void Clock::draw(){

}
