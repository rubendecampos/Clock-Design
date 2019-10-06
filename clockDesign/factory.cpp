#include "factory.h"

Factory::Factory()
{
    QString title;
    title.sprintf("Clock Design");
    view = new View(100,100,SCREEN_WIDTH,SCREEN_HEIGHT,title);
    data = new Data(SCREEN_WIDTH, SCREEN_HEIGHT);
    controller = new Controller();
}

Factory::~Factory(){

}

void Factory::build(){
    view->initRelations(controller);
    controller->initRelations(data);
    controller->initialize();
    data->initRelations(view);
}
