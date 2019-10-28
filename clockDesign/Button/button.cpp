#include "button.h"

//Constructor
Button::Button(QWidget* parent)
    :QPushButton(parent)
{
    QObject::connect(this,SIGNAL(clicked()),this,SLOT(buttonClicked()));
}

//Destructor
Button::~Button()
{

}

//Slot buttonClicked when there's a signal clicked()
//from a button
void Button::buttonClicked(){
    XFEvent* ev = new XFEvent();
    ev->setID(event);
    ev->setTarget(target);
    XF::getInstance().pushEvent(ev);

    //If the event is exit, emit the signal close
    //for the view
    if(event == XF::evExit){
        emit close();
    }
}

//Initialize wich event is generate by this button and his target
void Button::initEvent(XF::CEVENT event, Controller *target){
    this->event = event;
    this->target = target;
}
