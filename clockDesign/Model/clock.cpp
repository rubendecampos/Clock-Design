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
    this->clockWise = true;
    this->isMoving = false;
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

void Clock::setClockWise(bool cw)
{
    this->clockWise = clockWise;
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
    return clockWise;
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
    if(clockHandFinal_1 != clockHand_1)
    {
        isMoving = true;

        //Rotation clockWise or not
        if(clockWise)
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
        if(clockWise)
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
