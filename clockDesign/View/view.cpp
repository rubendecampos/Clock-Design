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

void View::paintEvent(QPaintEvent *event){
    //Set the polygon of the clock hands
    /*static const QPoint hourHand[3] = {
        QPoint(10, 8),
        QPoint(-10, 8),
        QPoint(0, -86)
    };
    static const QPoint minuteHand[3] = {
        QPoint(10, 8),
        QPoint(-10, 8),
        QPoint(0, -86)
    };*/

    //Set color to black
    QColor handColor1(0, 0, 0);
    QColor handColor2(0, 0, 0);

    //set the position
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.translate(width / 2, height / 2);
    //painter.scale(200,200);

    //Draw clock hand 1
    painter.setPen(Qt::NoPen);
    painter.setBrush(handColor1);

    painter.save();
    //painter.rotate(30.0 * ((time.hour() + time.minute() / 60.0)));
    painter.drawRect(-2,0,4,86);
    painter.restore();

    painter.setPen(handColor1);

    //Draw the hours dots
    for (int i = 0; i < 12; ++i) {
        painter.drawLine(86, 0, 96, 0);
        painter.rotate(30.0);
    }

    //Draw clock hand 2
    painter.setPen(Qt::NoPen);
    painter.setBrush(handColor2);

    painter.save();
    painter.rotate(180);
    painter.drawRect(-2, 0, 4, 86);
    painter.restore();

    painter.setPen(handColor2);

    //Draw the minutes dots
    for (int j = 0; j < 60; ++j) {
        if ((j % 5) != 0)
            painter.drawLine(92, 0, 96, 0);
        painter.rotate(6.0);
    }
}

void View::setupUI(){
    this->setGeometry(x,y,width,height);
    this->setWindowTitle(title);
    this->setVisible(true);
}
