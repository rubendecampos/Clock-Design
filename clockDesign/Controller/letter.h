#ifndef LETTER_H
#define LETTER_H

#include "controller.h"

class Letter
{
public:
    Letter(Controller* host);
    void setB(int column);
    void setE(int column);
    void setX(int column);

private:
    Controller* host;
};

#endif // LETTER_H
