TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        iaghost.cpp \
        main.cpp
        include(MinGL2/mingl.pri)

DISTFILES += \
    res/doggo.si2

HEADERS += \
    iaghost.h
