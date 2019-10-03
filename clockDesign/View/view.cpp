#include "view.h"

View::View(int x, int y, int width, int height, QString title)
{
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    setupUI();
}

View::~View(){

}

void View::initRelations(Data* data){
    this->data = data;
}

void View::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    data->drawALL(&painter);
}

void View::setupUI(){
    this->setGeometry(x,y,width,height);
    this->setWindowTitle(title);
    this->setVisible(true);
}
