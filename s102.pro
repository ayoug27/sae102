TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Display/Display.cpp \
        Ghost/GhostMove.cpp \
        Ghost/PhaseGhost.cpp \
        Ghost/iaghost.cpp \
        Initialisation/Initialisation.cpp \
        GameTurn/GameTurn.cpp \
        Misc/Misc.cpp \
        Movement/Movement.cpp \
        main.cpp
        include(MinGL2/mingl.pri)

DISTFILES += \
    res/doggo.si2

HEADERS += \
    DisplayH/Display.h \
    GhostH/GhostMove.h \
    GhostH/PhaseGhost.h \
    GhostH/iaghost.h \
    GameTurnH/GameTurn.h \
    InitialisationH/Initialisation.h \
    MiskH/Misk.h \
    MovementH/Movement.h \
    type.h
