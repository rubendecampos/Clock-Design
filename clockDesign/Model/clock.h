#ifndef CLOCK_H
#define CLOCK_H


class Clock
{
public:
    Clock(int posX, int posY, int clockH1, int clockH2);
    void setClockH1(int pos);
    void setClockH2(int pos);
    void setClock(int hand1, int hand2);
    void setClockWise(bool cw);
    int getClockH1();
    int getClockH2();
    bool getClockWise();
    void draw();

private:
    int posX;
    int posY;
    int clockHand_1;
    int clockHand_2;
    bool clockWise;
};

#endif // CLOCK_H
