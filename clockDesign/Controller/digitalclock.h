#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "controller.h"

class Controller;

class DigitalClock
{
public:
    DigitalClock(Controller* host);
    void set_0(double column);
    void set_1(double column);
    void set_2(double column);
    void set_3(double column);
    void set_4(double column);
    void set_5(double column);
    void set_6(double column);
    void set_7(double column);
    void set_8(double column);
    void set_9(double column);

private:
    Controller* host;

};

#endif // DIGITALCLOCK_H
