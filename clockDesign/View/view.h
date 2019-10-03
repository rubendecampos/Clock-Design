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
    void initRelations(Data* data);
    void paintEvent(QPaintEvent* event);
    void setupUI();

private:
    int x;
    int y;
    int height;
    int width;
    QString title;
    Data* data;

private slots:
    void update();
};

#endif // VIEW_H
