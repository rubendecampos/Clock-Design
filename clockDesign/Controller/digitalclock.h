#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include "controller.h"

class Controller;

class DigitalClock
{
public:
    DigitalClock(Controller* host);
    void set_0(int digit);
    void set_1(int digit);
    void set_2(int digit);
    void set_3(int digit);
    void set_4(int digit);
    void set_5(int digit);
    void set_6(int digit);
    void set_7(int digit);
    void set_8(int digit);
    void set_9(int digit);

private:
    Controller* host;

};

#endif // DIGITALCLOCK_H
