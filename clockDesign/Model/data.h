#ifndef DATA_H
#define DATA_H

#include "clock.h"
#include "View\observer.h"
#include <QPainter>

const int proportion = 20;

class Data
{
public:
    Data(int width, int height);
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
    void setAllClockWise(bool clockWise);

private:
    Clock* clock[5][10];
    bool clockMoved;
    int nbLine;
    int nbColumn;
    Observer* pObserver;
};

#endif // DATA_H
