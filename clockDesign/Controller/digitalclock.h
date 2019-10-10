#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "controller.h"

class Controller;

class DigitalClock
{
public:
    DigitalClock(Controller* host);
    void set_0(double digit);
    void set_1(double digit);
    void set_2(double digit);
    void set_3(double digit);
    void set_4(double digit);
    void set_5(double digit);
    void set_6(double digit);
    void set_7(double digit);
    void set_8(double digit);
    void set_9(double digit);

private:
    Controller* host;

};

#endif // DIGITALCLOCK_H
