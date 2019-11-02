#include "data.h"

//Constructor
Data::Data(int width, int height)
{
    double percent = 0.71;
    int ecart = 5;
    nbLine = 6;
    nbColumn = 14;
    int clockLength = 1;
    while(((clockLength+ecart)*nbColumn+ecart) < (width*percent))
    {
        clockLength++;
    }
    double offsetW = (width-nbColumn*(clockLength+ecart)-ecart)/2;
    double offsetH = (height-nbLine*(clockLength+ecart)-ecart)/2;

    //draw all clocks
    for(int line=0;line<nbLine;line++)
    {
        for(int column=0;column<nbColumn;column++)
        {

            clock[line][column] = new Clock((int)(offsetW+(clockLength/2)+(clockLength+ecart)*(column)),
                               (int)(offsetH+(clockLength/2)+(clockLength+ecart)*(line)),clockLength,0,0);
        }
    }

    QObject::connect(&timer,SIGNAL(timeout()),this,SLOT(updateClock()));
    timer.start(15);
}

//Destructor
Data::~Data()
{

}

//Initialize the relation
void Data::initRelations(Observer *observer)
{
    this->pObserver = observer;
}

//Draw all object in Data
void Data::drawALL(QPainter* painter)
{
    for(int line=0;line<nbLine;line++)
    {
        for(int column=0;column<nbColumn;column++)
        {
            clock[line][column]->draw(painter);
        }
    }
}

//Return the clock
Clock* Data::getClock(int lineIndex, int columnIndex)
{

    return clock[lineIndex][columnIndex];
}

//Return if a clock has been moved
bool Data::getClockMoved(){
    return clockMoved;
}

//Return the number of column
int Data::getNbColumn(){
    return nbColumn;
}

//Return the number of line
int Data::getNbLine(){
    return nbLine;
}


//Update the clock
void Data::updateClock()
{
    clockMoved = false;

    for(int line = 0;line<this->nbLine;line++)
    {
        for(int column = 0;column<this->nbColumn;column++)
        {
            //If the clock is still moving
            if(clock[line][column]->getIsMoving())
            {
                clock[line][column]->move();
                clockMoved = true;
            }
        }
    }

    if(clockMoved){
        pObserver->changed();
    }
}

//Start moving all clock
void Data::startAllClock(){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->startMoving();
        }
    }
}

//Set the hands of all clock
void Data::setAllClock(int hand1, int hand2){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setClock(hand1,hand2);
        }
    }
}

void Data::setAllClockDownLeft(){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setClockDownLeft(1);
            clock[line][column]->setClockDownLeft(2);
        }
    }
}

//Set all the clock wise
void Data::setAllClockWise(bool cw1, bool cw2){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setClockWise(cw1,cw2);
        }
    }
}

//Indicate to data that the clock must go to their final
//position by the short way (clockWise or not)
void Data::setFastWay(bool fastWay){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setFastWay(fastWay);
        }
    }
}
