QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++14

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Parser/InputManager.cpp \
    Shapes/Ellipse.cpp \
    Shapes/Line.cpp \
    Shapes/Polygon.cpp \
    Shapes/Polyline.cpp \
    Shapes/Rectangle.cpp \
    Shapes/Shape.cpp \
    Shapes/Text.cpp \
    Util/EnumStrConv.cpp \
    contact.cpp \
    loginapp.cpp \
    main.cpp \
    dialog.cpp \
    renderarea.cpp

HEADERS += \
    Parser/InputManager.h \
    Shapes/Ellipse.h \
    Shapes/Line.h \
    Shapes/Polygon.h \
    Shapes/Polyline.h \
    Shapes/Rectangle.h \
    Shapes/Shape.h \
    Shapes/Text.h \
    Util/EnumStrConv.h \
    Util/vector.h \
    contact.h \
    dialog.h \
    loginapp.h \
    renderarea.h

FORMS += \
    contact.ui \
    dialog.ui \
    loginapp.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
