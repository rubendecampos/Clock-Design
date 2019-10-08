#include "factory.h"
#include <QDesktopWidget>
#include <QApplication>

Factory::Factory()
{
    QString title;
    title.sprintf("Clock Design");
    int screenWidth = QApplication::desktop()->width();
    int screenHeight = QApplication::desktop()->height();

    view = new View(0,0,screenWidth,screenHeight,title);
    data = new Data(screenWidth, screenHeight);
    controller = new Controller();
}

Factory::~Factory(){

}

void Factory::build(){
    view->initRelations(controller);
    //controller->initRelations(data,view);
    controller->initRelations(data);
    controller->initialize();
    data->initRelations(view);
}
