#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/shape/rectangle.h"
#include "type.h"
#include "InitialisationH/Initialisation.h"

using namespace std;


void gumEating(Entity PacMan, CMat & gumGrid, unsigned & NbGum, unsigned & score)
{
    if (gumGrid[PacMan.Pos.second][PacMan.Pos.first] == KGum){
        gumGrid[PacMan.Pos.second][PacMan.Pos.first] = KEmpty;
        NbGum -=1;
        score += 10;
    }
    if (gumGrid[PacMan.Pos.second][PacMan.Pos.first] == KSuperGum){
        gumGrid[PacMan.Pos.second][PacMan.Pos.first] = KEmpty;
        NbGum -=1;
        score += 50;
    }
}

void ChangementNiveau(Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, map<char, CPos> posMap, CMat & gumGrid){
    PacMan.viewdirection = "Left";
    PacMan.Pos = posMap[PacMan.ident];
    Ghost1.state = "Flee";
    Ghost1.viewdirection = "Left";
    Ghost1.Pos = posMap[Ghost1.ident];
    Ghost2.state = "Flee";
    Ghost2.viewdirection = "Top";
    Ghost2.Pos = posMap[Ghost2.ident];
    Ghost3.state = "Flee";
    Ghost3.viewdirection = "Bottom";
    Ghost3.Pos = posMap[Ghost3.ident];
    Ghost4.state = "Flee";
    Ghost4.viewdirection = "Bottom";
    Ghost4.Pos = posMap[Ghost4.ident];

    gumGrid = initGumMaze("../sae102/res/guminitialmap");
}

bool isDead (Entity & PacMan, Entity Ghost1, Entity Ghost2, Entity Ghost3, Entity Ghost4)
{
    return (PacMan.Pos == Ghost1.Pos || PacMan.Pos == Ghost2.Pos || PacMan.Pos == Ghost3.Pos || PacMan.Pos == Ghost4.Pos);
}


