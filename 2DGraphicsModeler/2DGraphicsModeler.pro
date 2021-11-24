QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Parser/InputManager.cpp \
    Shapes/Circle.cpp \
    Shapes/Ellipse.cpp \
    Shapes/Line.cpp \
    Shapes/Polygon.cpp \
    Shapes/Rectangle.cpp \
    Shapes/Shape.cpp \
    Shapes/Square.cpp \
    Shapes/Text.cpp \
    loginapp.cpp \
    main.cpp \
    paint.cpp

HEADERS += \
    Parser/InputManager.h \
    Shapes/Circle.h \
    Shapes/Ellipse.h \
    Shapes/Line.h \
    Shapes/Polygon.h \
    Shapes/Rectangle.h \
    Shapes/Shape.h \
    Shapes/Square.h \
    Shapes/Text.h \
    Util/vector.h \
    loginapp.h \
    paint.h

FORMS += \
    loginapp.ui \
    paint.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
