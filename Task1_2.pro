QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Circle.cpp \
    Hex.cpp \
    Rect.cpp \
    RegPolygon.cpp \
    Rhomb.cpp \
    Square.cpp \
    Star.cpp \
    Star5.cpp \
    Star6.cpp \
    Star8.cpp \
    Triangle.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Circle.h \
    Figure.h \
    Hex.h \
    Rect.h \
    RegPolygon.h \
    Rhomb.h \
    Square.h \
    Star.h \
    Star5.h \
    Star6.h \
    Star8.h \
    Triangle.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
