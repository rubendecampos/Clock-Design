#include "factory.h"
#include <QDesktopWidget>
#include <QApplication>

//Constructor
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

//Destructor
Factory::~Factory(){

}

//Build all the components and their relations
void Factory::build(){
    view->initRelations(controller);
    controller->initRelations(data);
    controller->initialize();
    data->initRelations(view);
}
