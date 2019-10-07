#include "button.h"

Button::Button(QWidget* parent)
    :QPushButton(parent)
{
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(buttonClicked()));
}

Button::~Button()
{

}

void Button::buttonClicked(){
    XFEvent* ev = new XFEvent();
    ev->setID(event);
    ev->setTarget(target);
    XF::getInstance().pushEvent(ev);
}

void Button::initEvent(XF::CEVENT event, Controller *target){
    this->event = event;
    this->target = target;
}
