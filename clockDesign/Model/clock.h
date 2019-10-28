#ifndef CLOCK_H
#define CLOCK_H

#include <QPainter>

//proportion of the dots and the clock hands
const int ratio = 20;
const int SPEED = 2;

class Clock
{
public:
    Clock(int posX, int posY, int length, int clockH1, int clockH2);
    void setClockHand(int clockHand, int pos);
    void setClock(int hand1, int hand2);
    void setClockLeft(int clockHand);
    void setClockRight(int clockHand);
    void setClockUp(int clockHand);
    void setClockDown(int clockHand);
    void setCLockUpLeft(int clockHand);
    void setClockUpRight(int clockHand);
    void setClockDownLeft(int clockHand);
    void setClockDownRight(int clockHand);
    void setClockWise(bool cw1, bool cw2);
    int getClockHand(int clockHand);
    bool getClockWise();
    void draw(QPainter* painter);
    void move();
    bool getIsMoving();
    void startMoving();
    void setFastWay(bool fastway);

private:
    //Position of the clock
    int posX;
    int posY;
    //Position of the clock hands
    int clockHand_1;
    int clockHand_2;
    int clockHandFinal_1;
    int clockHandFinal_2;

    bool clockWise1;         //rotation clockWise?
    bool clockWise2;
    int length;             //length of the clock
    bool isMoving;            //Indicate if a clock is moving
    bool fastway;

};

#endif // CLOCK_H
