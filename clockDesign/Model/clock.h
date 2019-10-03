#ifndef CLOCK_H
#define CLOCK_H

#include <QPainter>

//proportion of the dots and the clock hands
const int ratio = 20;

class Clock
{
public:
    Clock(int posX, int posY, int length, int clockH1, int clockH2);
    void setClockH1(int pos);
    void setClockH2(int pos);
    void setClock(int hand1, int hand2);
    void setClockWise(bool cw);
    int getClockH1();
    int getClockH2();
    bool getClockWise();
    void draw(QPainter* painter);

private:
    //Position of the clock
    int posX;
    int posY;
    //Position of the clock hands
    int clockHand_1;
    int clockHand_2;

    bool clockWise;         //rotation clockWise?
    int length;             //length of the clock

};

#endif // CLOCK_H
