#ifndef DATA_H
#define DATA_H

#include "clock.h"
#include <QPainter>
#include <QTimer>
#include <QWidget>

const int clockLength = 48;

class Data: public QWidget
{
public:
    Data();
    ~Data();
    void drawALL(QPainter* painter);
    void drawColumn(QPainter* painter);
    void drawLine(QPainter* painter);
    Clock* getClock(int lineIndex, int columnIndex);
    int getNbLine();
    int getNbColumn();

private:
    Clock* clock[5][10];
    QTimer timer;
    int nbLine;
    int nbColumn;

private slots:
    void moveClock();
};

#endif // DATA_H
