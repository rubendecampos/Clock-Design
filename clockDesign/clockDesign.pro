QT += core gui widgets

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp \
    factory.cpp \
    Controller\controller.cpp \
    View\view.cpp \
    Model\data.cpp \
    Model/clock.cpp \
    View/observer.cpp \
    Controller/digitalclock.cpp \
    XF/xf.cpp \
    XF/xfevent.cpp \
    XF/xftimer.cpp \
    Controller/animation1.cpp \
    Button/button.cpp \
    Controller/countdown.cpp \
    Controller/letter.cpp \
    Controller/animationbex.cpp

HEADERS += \
    factory.h \
    Controller\controller.h \
    View\view.h \
    Model\data.h \
    Model/clock.h \
    View/observer.h \
    Controller/digitalclock.h \
    XF/ism.h \
    XF/xf.h \
    XF/xfevent.h \
    XF/xftimer.h \
    Controller/animation1.h \
    Button/button.h \
    Controller/countdown.h \
    Controller/letter.h \
    Controller/animationbex.h
