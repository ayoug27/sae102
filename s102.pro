TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Ghost/GhostMove.cpp \
        Ghost/PhaseGhost.cpp \
        Ghost/iaghost.cpp \
        MatriceMove.cpp \
        game.cpp \
        grid_maze.cpp \
        init.cpp \
        main.cpp
        include(MinGL2/mingl.pri)

DISTFILES += \
    res/doggo.si2

HEADERS += \
    GhostH/GhostMove.h \
    GhostH/PhaseGhost.h \
    GhostH/iaghost.h \
    MatriceMove.h \
    game.h \
    init.h \
    type.h
