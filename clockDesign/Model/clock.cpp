#include "clock.h"

Clock::Clock(int posX, int posY, int length, int clockH1, int clockH2)
{
    this->posX = posX;
    this->posY = posY;
    this->length = length;
    this->clockHand_1 = clockH1;
    this->clockHand_2 = clockH2;
    this->clockHandFinal_1 = clockH1;
    this->clockHandFinal_2 = clockH2;
    this->clockWise1 = true;
    this->clockWise2 = true;
    this->isMoving = false;
    this->fastway = false;
}

void Clock::setClockHand(int clockHand, int pos)
{
    switch(clockHand)
    {
    case 1:
        this->clockHandFinal_1 = pos;
        break;
    case 2:
        this->clockHandFinal_2 = pos;
        break;
    }

}

void Clock::setClock(int hand1, int hand2)
{
    this->clockHandFinal_1 = hand1;
    this->clockHandFinal_2 = hand2;
}


void Clock::setClockLeft(int clockHand)
{
    setClockHand(clockHand,90);
}

void Clock::setClockRight(int clockHand)
{
    setClockHand(clockHand,270);
}

void Clock::setClockUp(int clockHand)
{
    setClockHand(clockHand,180);
}

void Clock::setClockDown(int clockHand)
{
    setClockHand(clockHand,0);
}

void Clock::setClockDownLeft(int clockHand){
    setClockHand(clockHand,46);
}

void Clock::setClockDownRight(int clockHand){
    setClockHand(clockHand,316);
}

void Clock::setClockUpRight(int clockHand){
    setClockHand(clockHand,226);
}

void Clock::setClockUpLeft(int clockHand){
    setClockHand(clockHand,136);
}

void Clock::setClockWise(bool cw1, bool cw2)
{
    this->clockWise1 = cw1;
    this->clockWise2 = cw2;
}

int Clock::getClockHand(int clockHand){
    switch(clockHand){
    case 1:
        return clockHand_1;
        break;
    case 2:
        return clockHand_2;
        break;
    }
}

bool Clock::getClockWise()
{
    return clockWise1;              //Not use yet, to modify
}

void Clock::draw(QPainter* painter)
{
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

void Clock::move(){
    if(fastway){
        //for clockwise1
        if(clockHandFinal_1>clockHand_1){
            int dist = clockHandFinal_1-clockHand_1;
            dist>180?clockWise1=false:clockWise1=true;
        }else{
            int dist = clockHand_1-clockHandFinal_1;
            dist>180?clockWise1=true:clockWise1=false;
        }
        //for clokwise2
        if(clockHandFinal_2>clockHand_2){
            int dist = clockHandFinal_2-clockHand_2;
            dist>180?clockWise2=false:clockWise2=true;
        }else{
            int dist = clockHand_2-clockHandFinal_2;
            dist>180?clockWise2=true:clockWise2=false;
        }
    }

    if(clockHandFinal_1 != clockHand_1)
    {
        isMoving = true;

        //Rotation clockWise or not
        if(clockWise1)
        {
            clockHand_1 += SPEED;
        }else
        {
            clockHand_1 -= SPEED;
        }

        //Stay between 0 and 360
        if(clockHand_1 < 0)
        {
            clockHand_1 = 360 + clockHand_1;
        }
        clockHand_1 %= 360;
    }
    else
    {
        isMoving = false;
    }

    if(clockHandFinal_2 != clockHand_2)
    {
        isMoving = true;

        //Rotation clockWise or not
        if(clockWise2)
        {
            clockHand_2 += SPEED;
        }
        else
        {
            clockHand_2 -= SPEED;
        }

        //Stay between 0 and 360
        if(clockHand_2 < 0)
        {
            clockHand_2 = 360 + clockHand_2;
        }
        clockHand_2 %= 360;
    }
    else
    {
        if(isMoving == false){
            isMoving = false;
        }
    }
}

bool Clock::getIsMoving()
{
    return isMoving;
}

void Clock::startMoving()
{
    isMoving = true;
}

void Clock::setFastWay(bool fastway){
    this->fastway = fastway;
}
