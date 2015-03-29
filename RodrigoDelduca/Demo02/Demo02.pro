QT += \
    widgets qml quick network

CONFIG += c++11
TARGET = Demo02
TEMPLATE = app

SOURCES += \
    MainWindow.cpp \
    Main.cpp \
    Member.cpp

HEADERS += \
    MainWindow.h \
    Member.h

RESOURCES += \
    Resources.qrc
