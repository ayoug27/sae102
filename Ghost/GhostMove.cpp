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
        if(RedGhost.viewdirection == "Top"){intersection[2] = false;}
        if(RedGhost.viewdirection == "Right"){intersection[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(RedGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,RedGhost);
//        cout << RedGhost.viewdirection << endl;
    }
    if (RedGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        if(RedGhost.viewdirection == "Top"){intersection[2] = false;}
        if(RedGhost.viewdirection == "Right"){intersection[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(RedGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,28,0,RedGhost);
    }
    if (RedGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        if(RedGhost.viewdirection == "Top"){intersection[2] = false;}
        if(RedGhost.viewdirection == "Right"){intersection[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(RedGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,13,14,RedGhost);
    }

    if (RedGhost.state == "hide"){

    }
}

//*****************************************************************************
//******************************     Pink     *********************************
//*****************************************************************************
void PinkGhostMove (Entity & PinkGhost ,Entity PacMan, CMat map){
    if (PinkGhost.state == "hunt"){
        vector<bool> intersection;
        intersection = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){intersection[2] = false;}
        if(PinkGhost.viewdirection == "Right"){intersection[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(PinkGhost.viewdirection == "Left"){intersection[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp -= 2;}
        if(PacMan.viewdirection == "Right"){xp += 2;}
        if(PacMan.viewdirection == "Bottom"){yp += 2;}
        if(PacMan.viewdirection == "Left"){xp -= 2;}
        MOVE(intersection,PinkGhost.Pos.second,PinkGhost.Pos.first,xp,yp,PinkGhost);
    }
    if (PinkGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){intersection[2] = false;}
        if(PinkGhost.viewdirection == "Right"){intersection[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(PinkGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,PinkGhost.Pos.second,PinkGhost.Pos.first,28,0,PinkGhost);
    }
    if (PinkGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){intersection[2] = false;}
        if(PinkGhost.viewdirection == "Right"){intersection[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(PinkGhost.viewdirection == "Left"){intersection[1] = false;}
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
        if(BlueGhost.viewdirection == "Top"){intersection[2] = false;}
        if(BlueGhost.viewdirection == "Right"){intersection[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(BlueGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,BlueGhost.Pos.second,BlueGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,BlueGhost);
    }
    if (BlueGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        if(BlueGhost.viewdirection == "Top"){intersection[2] = false;}
        if(BlueGhost.viewdirection == "Right"){intersection[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(BlueGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,BlueGhost.Pos.second,BlueGhost.Pos.first,28,0,BlueGhost);
    }
    if (BlueGhost.state == "kill"){
        vector<bool> intersection;
        if(BlueGhost.viewdirection == "Top"){intersection[2] = false;}
        if(BlueGhost.viewdirection == "Right"){intersection[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(BlueGhost.viewdirection == "Left"){intersection[1] = false;}
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
        if(OrangeGhost.viewdirection == "Top"){intersection[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){intersection[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,OrangeGhost.Pos.second,OrangeGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,OrangeGhost);
//                cout << OrangeGhost.viewdirection << endl;
    }
    if (OrangeGhost.state == "flee"){
        vector<bool> intersection;
        intersection = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        if(OrangeGhost.viewdirection == "Top"){intersection[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){intersection[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,OrangeGhost.Pos.second,OrangeGhost.Pos.first,28,0,OrangeGhost);
    }
    if (OrangeGhost.state == "kill"){
        vector<bool> intersection;
        intersection = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        if(OrangeGhost.viewdirection == "Top"){intersection[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){intersection[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){intersection[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){intersection[1] = false;}
        MOVE(intersection,OrangeGhost.Pos.second,OrangeGhost.Pos.first,13,14,OrangeGhost);
    }

    if (OrangeGhost.state == "hide"){

    }
}
