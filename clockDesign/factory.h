#ifndef FACTORY_H
#define FACTORY_H

#include "Model\data.h"
#include "Controller\controller.h"
#include "View\view.h"
#include <QString>

const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 400;

class Factory
{
public:
    Factory();
    ~Factory();
    void build();
private:
    Data* data;
    Controller* controller;
    View* view;
};

#endif // FACTORY_H
