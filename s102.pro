TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp
        include(MinGL2/mingl.pri)

DISTFILES += \
    res/doggo.si2
