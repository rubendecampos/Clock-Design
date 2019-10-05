#ifndef DATA_H
#define DATA_H

#include "clock.h"
#include "View\observer.h"
#include <QPainter>

const int clockLength = 48;

class Data
{
public:
    Data();
    ~Data();
    void initRelations(Observer* observer);
    void drawALL(QPainter* painter);
    Clock* getClock(int lineIndex, int columnIndex);
    bool getClockMoved();
    int getNbLine();
    int getNbColumn();
    void updateClock();
    void startAllClock();
    void setAllClock(int hand1, int hand2);

private:
    Clock* clock[5][10];
    bool clockMoved;
    int nbLine;
    int nbColumn;
    Observer* pObserver;
};

#endif // DATA_H
