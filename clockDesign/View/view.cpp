#include "view.h"

View::View(int x, int y, int width, int height, QString title)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    setupUI();

    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(updateClock()));
    timer.start(50);
}

View::~View(){

}

void View::initRelations(Controller* controller){
    this->pController = controller;
}

void View::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    pController->pData->drawALL(&painter);
}

void View::setupUI(){
    this->setGeometry(x,y,width,height);
    this->setWindowTitle(title);
    this->setVisible(true);
}

void View::updateClock()
{
    pController->anim1->animate();
    /*pController->digClock->set_5(0);
    pController->digClock->set_7(1);
    pController->digClock->set_8(2);
    pController->digClock->set_9(3);

    pController->pData->startAllClock();*/
    pController->pData->updateClock();

}

//update the view
void View::changed()
{
    update();
}

//stop
void View::stop()
{
    this->close();
}
