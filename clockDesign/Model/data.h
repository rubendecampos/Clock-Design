#ifndef DATA_H
#define DATA_H

#include "clock.h"
#include "View\observer.h"
#include <QPainter>
#include <QTimer>
#include <QWidget>

const int proportion = 18;

class Data: public QWidget
{
    Q_OBJECT

public:
    Data(int width, int height);
    ~Data();
    void initRelations(Observer* observer);
    void drawALL(QPainter* painter);
    Clock* getClock(int lineIndex, int columnIndex);
    bool getClockMoved();
    int getNbLine();
    int getNbColumn();
    void startAllClock();
    void setAllClock(int hand1, int hand2);
    void setAllClockDownLeft();
    void setAllClockWise(bool cw1, bool cw2);
    void setFastWay(bool fastWay);

private:
    Clock* clock[6][14];
    bool clockMoved;
    int nbLine;
    int nbColumn;
    Observer* pObserver;
    QTimer timer;

private slots:
    void updateClock();
};

#endif // DATA_H
