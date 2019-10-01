#include "factory.h"

Factory::Factory()
{
    QString title;
    title.sprintf("Clock Design");
    view = new View(100,100,1000,400,title);
}

Factory::~Factory(){

}

void Factory::build(){

}
