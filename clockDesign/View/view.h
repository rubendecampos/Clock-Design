#ifndef VIEW_H
#define VIEW_H

#include <QWidget>
#include <QString>
#include <QPainter>
#include "Model\data.h"

class View: public QWidget
{
    Q_OBJECT

public:
    View(int x, int y, int width, int height, QString title);
    ~View();
    void paintEvent(QPaintEvent* event);
    void setupUI();

private:
    int x;
    int y;
    int height;
    int width;
    QString title;
};

#endif // VIEW_H
