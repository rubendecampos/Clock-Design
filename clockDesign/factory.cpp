#include "factory.h"

Factory::Factory()
{
    QString title;
    title.sprintf("Clock Design");
    view = new View(100,100,1000,400,title);
    data = new Data();
}

Factory::~Factory(){

}

void Factory::build(){
    view->initRelations(data);
    controller->initRelations(data);
}
