#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include "XF/xf.h"
#include "XF/xfevent.h"
#include "Controller/controller.h"

class Button: public QPushButton
{
    Q_OBJECT

public:
    Button(QWidget* parent);
    ~Button();
    void initEvent(XF::CEVENT event, Controller* target);

private:
    XF::CEVENT event;
    Controller* target;

private slots:
    void buttonClicked();

signals:
    void close();
};

#endif // BUTTON_H
