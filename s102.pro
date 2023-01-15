TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Ghost/GhostMove.cpp \
        Ghost/PhaseGhost.cpp \
        Ghost/iaghost.cpp \
        TourDeJeu/TourDeJeu.cpp \
        affichage.cpp \
        fonction.cpp \
        main.cpp
        include(MinGL2/mingl.pri)

DISTFILES += \
    res/doggo.si2

HEADERS += \
    GhostH/GhostMove.h \
    GhostH/PhaseGhost.h \
    GhostH/iaghost.h \
    TourDeJeuH/TourDeJeu.h \
    affichage.h \
    fonction.h \
    type.h
