#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "Model\data.h"
#include "observer.h"
#include "Controller\controller.h"
#include "Button\button.h"

class Button;

class View: public QWidget, public Observer
{
    Q_OBJECT

public:
    View(int x, int y, int width, int height, QString title);
    ~View();
    void initRelations(Controller* controller);
    void paintEvent(QPaintEvent* event);
    void setupUI();
    void changed();
private slots:
    void stop();

private:
    int x;
    int y;
    int height;
    int width;
    QString title;
    Controller* pController;
    //QTimer timer;
    Button* animation1;
    Button* exit;
    Button* countDown;
};

#endif // VIEW_H
