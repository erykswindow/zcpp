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
    Controller/gameviewcontroller.cpp \
    Controller/imageprocessor.cpp \
    Controller/viewcontroller.cpp \
    Controller/gamestatecontroller.cpp \
    View/pewindow.cpp \
    View/view.cpp \
    Model/gamestate.cpp \
    Model/game.cpp \
    View/tileview.cpp \
    Controller/mainwindowviewcontroller.cpp \
    View/gamewindow.cpp \
    View/gamestartdialog.cpp \
    Controller/gamestatesaver.cpp

HEADERS += \
    Model/board.hpp \
    Model/tile.hpp \
    Model/image.hpp \
    Controller/imageprocessor.hpp \
    Controller/gameviewcontroller.h \
    Controller/viewcontroller.h \
    Controller/gamestatecontroller.h \
    View/pewindow.h \
    View/view.h \
    Model/gamestate.h \
    Model/location.h \
    Model/game.h \
    View/tileview.h \
    Controller/mainwindowviewcontroller.h \
    View/gamewindow.h \
    Model/direction.h \
    Model/helperfunctions.h \
    Model/range.h \
    View/gamestartdialog.h \
    Controller/gamestatesaver.h

FORMS += \
    View/pewindow.ui \
    View/gamewindow.ui \
    View/gamestartdialog.ui

RESOURCES += \
    resources.qrc

DISTFILES +=
