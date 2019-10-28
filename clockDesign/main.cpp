#include <QApplication>
#include "factory.h"
#include "XF/xf.h"

//Main function
int main(int argc, char *argv[])
{
    XF::getInstance();
    //QApplication a(argc, argv);
    Factory f;
    f.build();
    //return a.exec();
    return XF::getInstance().exec();
}
