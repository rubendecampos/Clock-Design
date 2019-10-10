#include "data.h"

Data::Data(int width, int height)
{
    double percent = 0.71;
    int ecart = 5;
    nbLine = 5;
    nbColumn = 10;
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
}

Data::~Data()
{

}

void Data::initRelations(Observer *observer)
{
    this->pObserver = observer;
}

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

Clock* Data::getClock(int lineIndex, int columnIndex)
{

    return clock[lineIndex][columnIndex];
}

bool Data::getClockMoved(){
    return clockMoved;
}

int Data::getNbColumn(){
    return nbColumn;
}

int Data::getNbLine(){
    return nbLine;
}

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

void Data::startAllClock(){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->startMoving();
        }
    }
}

void Data::setAllClock(int hand1, int hand2){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setClock(hand1,hand2);
        }
    }
}

void Data::setAllClockWise(bool cw1, bool cw2){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setClockWise(cw1,cw2);
        }
    }
}

void Data::setFastWay(bool fastWay){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->setFastWay(fastWay);
        }
    }
}
