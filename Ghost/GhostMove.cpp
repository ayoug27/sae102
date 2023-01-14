//*****************************************************************************
//*************************     Initialisation     ****************************
//*****************************************************************************
#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include <vector>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "GhostH/PhaseGhost.h"
#include "type.h"
#include "GhostH/GhostMove.h"
#include "GhostH/iaghost.h"
#include <cmath>

using namespace std;

//*****************************************************************************
//******************************     RED     **********************************
//*****************************************************************************
void RedGhostMove (Entity & RedGhost, Entity PacMan, CMat map){
    if (RedGhost.state == "hunt"){
        vector<bool> intersection;
        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        MOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,RedGhost);
//        cout << RedGhost.viewdirection << endl;
    }
    if (RedGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        MOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,28,0,RedGhost);
    }
    if (RedGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        MOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,13,14,RedGhost);
    }

    if (RedGhost.state == "hide"){

    }
}

//*****************************************************************************
//******************************     Pink     *********************************
//*****************************************************************************
void PinkGhostMove (Entity PinkGhost ,Entity PacMan, CMat map){
    if (PinkGhost.state == "hunt"){
        vector<bool> intersection;
        intersection = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        MOVE(intersection,PinkGhost.Pos.second,PinkGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,PinkGhost);
    }
    if (PinkGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        MOVE(intersection,PinkGhost.Pos.second,PinkGhost.Pos.first,28,0,PinkGhost);
    }
    if (PinkGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        MOVE(intersection,PinkGhost.Pos.second,PinkGhost.Pos.first,13,14,PinkGhost);
    }

    if (PinkGhost.state == "hide"){

    }
}

//*****************************************************************************
//******************************     Blue     *********************************
//*****************************************************************************
void BlueGhostMove (Entity & BlueGhost,Entity PacMan, CMat map){
    if (BlueGhost.state == "hunt"){
        vector<bool> intersection;
        intersection = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        MOVE(intersection,BlueGhost.Pos.second,BlueGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,BlueGhost);
    }
    if (BlueGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        MOVE(intersection,BlueGhost.Pos.second,BlueGhost.Pos.first,28,0,BlueGhost);
    }
    if (BlueGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        MOVE(intersection,BlueGhost.Pos.second,BlueGhost.Pos.first,13,14,BlueGhost);
    }

    if (BlueGhost.state == "hide"){

    }
}

//*****************************************************************************
//******************************     Orange    ********************************
//*****************************************************************************
void OrangeGhostMove (Entity & OrangeGhost,Entity PacMan, CMat map){
    if (OrangeGhost.state == "hunt"){
        vector<bool> intersection;
        intersection = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        MOVE(intersection,OrangeGhost.Pos.second,OrangeGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,OrangeGhost);
//                cout << OrangeGhost.viewdirection << endl;
    }
    if (OrangeGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        MOVE(intersection,OrangeGhost.Pos.second,OrangeGhost.Pos.first,28,0,OrangeGhost);
    }
    if (OrangeGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        MOVE(intersection,OrangeGhost.Pos.second,OrangeGhost.Pos.first,13,14,OrangeGhost);
    }

    if (OrangeGhost.state == "hide"){

    }
}
