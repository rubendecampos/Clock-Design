#include "view.h"

//Constructor
View::View(int x, int y, int width, int height, QString title)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    animation1 = new Button(this);
    exit = new Button(this);
    countDown = new Button(this);
    bex = new Button(this);
    setupUI();

    QObject::connect(exit,SIGNAL(close()),this,SLOT(stop()));
}

//Destructor
View::~View(){

}

//Initialize the relation between view and controller
void View::initRelations(Controller* controller){
    this->pController = controller;
    animation1->initEvent(XF::evAnim1,pController);
    exit->initEvent(XF::evExit,pController);
    countDown->initEvent(XF::evCountdown,pController);
    bex->initEvent(XF::evBeX,pController);
}

//Update the view by painting all object in pData
void View::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    pController->pData->drawALL(&painter);
}

//Setup the User Interface
void View::setupUI(){
    this->showFullScreen();
    this->setWindowTitle(title);
    animation1->setGeometry(100,height/2-50,100,40);
    animation1->setText("animation 1");
    exit->setGeometry(100,height/2+50,100,40);
    exit->setText("Exit");
    countDown->setGeometry(100,height/2-100,100,40);
    countDown->setText("Countdown");
    bex->setGeometry(100,height/2,100,40);
    bex->setText("BeX");
    this->setVisible(true);
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
