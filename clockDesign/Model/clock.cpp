#include "clock.h"

Clock::Clock(int posX, int posY, int length, int clockH1, int clockH2)
{
    this->posX = posX;
    this->posY = posY;
    this->length = length;
    this->clockHand_1 = clockH1;
    this->clockHand_2 = clockH2;
    this->clockWise = true;
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

void Clock::draw(QPainter* painter){
    int handWidth = length/ratio;
    int hourDot = length/ratio;

    //Set color to black
    QColor handColor1(0, 0, 0);
    QColor handColor2(0, 0, 0);

    //set the position
    painter->setRenderHint(QPainter::Antialiasing);
    painter->translate(posX, posY);

    //Draw clock hand 1
    painter->setPen(Qt::NoPen);
    painter->setBrush(handColor1);
    painter->save();
    painter->rotate(clockHand_1);
    painter->drawRect(-handWidth/2,0,handWidth,length/2);
    painter->restore();
    painter->setPen(handColor1);

    //Draw the hours dots
    for (int i = 0; i < 12; ++i) {
        painter->drawLine(length/2-hourDot, 0, length/2, 0);
        painter->rotate(30.0);
    }

    //Draw clock hand 2
    painter->setPen(Qt::NoPen);
    painter->setBrush(handColor2);
    painter->save();
    painter->rotate(clockHand_2);
    painter->drawRect(-handWidth/2, 0, handWidth, length/2);
    painter->restore();
    painter->setPen(handColor2);

    //Reset the position
    painter->translate(-posX,-posY);
}
