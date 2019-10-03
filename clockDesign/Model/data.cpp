#include "data.h"

Data::Data()
{
    nbLine = 5;
    nbColumn = 10;

    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column] = new Clock(40+(48+5)*column,40+(48+5)*line,clockLength,0,180);
        }
    }

    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(moveClock()));
    timer.start(1000);
}

Data::~Data(){

}

void Data::drawALL(QPainter* painter){
    for(int line=0;line<nbLine;line++){
        for(int column=0;column<nbColumn;column++){
            clock[line][column]->draw(painter);
        }
    }
}

void Data::drawColumn(QPainter* painter){

}

void Data::drawLine(QPainter* painter){

}

Clock* Data::getClock(int lineIndex, int columnIndex){
    return clock[lineIndex][columnIndex];
}

void Data::moveClock(){
    int i;
    i++;
}
