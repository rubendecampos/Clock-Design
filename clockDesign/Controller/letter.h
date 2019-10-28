#ifndef LETTER_H
#define LETTER_H

#include "controller.h"

class Letter
{
public:
    Letter(Controller* host);
    void setB(int column);

private:
    Controller* host;
};

#endif // LETTER_H
