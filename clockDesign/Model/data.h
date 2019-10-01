#ifndef DATA_H
#define DATA_H

#include "clock.h"

class Data
{
public:
    Data();
    ~Data();
    void drawALL();
    void drawColumn();
    void drawLine();
    Clock* getClock(int lineIndex, int columnIndex);

private:
    Clock* clock;
};

#endif // DATA_H
