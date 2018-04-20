#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T21:25:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = puzzle_extended
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    main.cpp \
    Model/board.cpp \
    Model/tile.cpp \
    Model/gamestate.cpp \
    Model/game.cpp \
    Controller/gameviewcontroller.cpp \
    Controller/gamestatecontroller.cpp \
    Controller/mainwindowviewcontroller.cpp \
    Controller/controller.cpp \
    View/gamewindow.cpp \
    View/gamestartdialog.cpp \
    View/startwindow.cpp \
    Utilities/gamestatesaver.cpp \
    Utilities/imageprocessor.cpp

HEADERS += \
    Model/board.hpp \
    Model/tile.hpp \
    Model/image.hpp \
    Model/gamestate.h \
    Model/location.h \
    Model/game.h \
    Model/direction.h \
    Model/range.h \
    Controller/gameviewcontroller.h \
    Controller/gamestatecontroller.h \
    Controller/mainwindowviewcontroller.h \
    Controller/controller.h \
    View/gamewindow.h \
    View/gamestartdialog.h \
    View/startwindow.h \
    Utilities/gamestatesaver.h \
    Utilities/helperfunctions.h \
    Utilities/imageprocessor.hpp

FORMS += \
    View/gamewindow.ui \
    View/gamestartdialog.ui \
    View/startwindow.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
