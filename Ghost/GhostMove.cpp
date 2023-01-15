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
#include <iostream>
#include <cstdlib>
#include <algorithm>

using namespace std;



//*****************************************************************************
//******************************     RED     **********************************
//*****************************************************************************
void RedGhostMove (Entity & RedGhost, Entity PacMan, CMat map){
    if (RedGhost.state == "Hunt"){
        vector<bool> Sorties;
        Sorties = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        if(RedGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(RedGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(RedGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,RedGhost.Pos.second,RedGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first,RedGhost);
    }
    if (RedGhost.state == "Flee"){
        vector<bool> Sorties;
        Sorties = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        if(RedGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(RedGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(RedGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,RedGhost.Pos.second,RedGhost.Pos.first,0,0,RedGhost);
    }
    if (RedGhost.state == "Kill"){
        vector<bool> Sorties;
        Sorties = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        if(RedGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(RedGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(RedGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,RedGhost.Pos.second,RedGhost.Pos.first,13,14,RedGhost);
    }
    if (RedGhost.state == "Hide"){
        vector<bool> Sorties;
        Sorties = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
        if(RedGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(RedGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(RedGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(RedGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 26;}
        if(PacMan.viewdirection == "Right"){xp -= 26;}
        if(PacMan.viewdirection == "Bottom"){yp -= 28;}
        if(PacMan.viewdirection == "Left"){xp += 27;}
        MOVE(Sorties,RedGhost.Pos.second,RedGhost.Pos.first,xp,yp,RedGhost);
    }
}

//*****************************************************************************
//******************************     Pink     *********************************
//*****************************************************************************
void PinkGhostMove (Entity & PinkGhost ,Entity PacMan, CMat map){
    if (PinkGhost.state == "Hunt"){
        vector<bool> Sorties;
        Sorties = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(PinkGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(PinkGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 4;}
        if(PacMan.viewdirection == "Right"){xp -= 4;}
        if(PacMan.viewdirection == "Bottom"){yp -= 4;}
        if(PacMan.viewdirection == "Left"){xp += 4;}
        MOVE(Sorties,PinkGhost.Pos.second,PinkGhost.Pos.first,xp,yp,PinkGhost);
    }
    if (PinkGhost.state == "Flee"){
        vector<bool> Sorties;
        Sorties = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(PinkGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(PinkGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,PinkGhost.Pos.second,PinkGhost.Pos.first,28,0,PinkGhost);
    }
    if (PinkGhost.state == "Kill"){
        vector<bool> Sorties;
        Sorties = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(PinkGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(PinkGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,PinkGhost.Pos.second,PinkGhost.Pos.first,13,14,PinkGhost);
    }

    if (PinkGhost.state == "Hide"){
        vector<bool> Sorties;
        Sorties = nbsortie(PinkGhost.Pos.second,PinkGhost.Pos.first,map);
        if(PinkGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(PinkGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(PinkGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(PinkGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 29;}
        if(PacMan.viewdirection == "Right"){xp -= 24;}
        if(PacMan.viewdirection == "Bottom"){yp -= 23;}
        if(PacMan.viewdirection == "Left"){xp += 26;}
        MOVE(Sorties,PinkGhost.Pos.second,PinkGhost.Pos.first,xp,yp,PinkGhost);

    }
}

//*****************************************************************************
//******************************     Blue     *********************************
//*****************************************************************************
void BlueGhostMove (Entity & BlueGhost,Entity PacMan, CMat map){
    if (BlueGhost.state == "Hunt"){
        vector<bool> Sorties;
        Sorties = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        if(BlueGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(BlueGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(BlueGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 15;}
        if(PacMan.viewdirection == "Right"){xp -= 13;}
        if(PacMan.viewdirection == "Bottom"){yp -= 11;}
        if(PacMan.viewdirection == "Left"){xp += 14;}
        MOVE(Sorties,BlueGhost.Pos.second,BlueGhost.Pos.first,xp,yp,BlueGhost);
    }
    if (BlueGhost.state == "Flee"){
        vector<bool> Sorties;
        Sorties = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        if(BlueGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(BlueGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(BlueGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,BlueGhost.Pos.second,BlueGhost.Pos.first,34,28,BlueGhost);
    }
    if (BlueGhost.state == "Kill"){
        vector<bool> Sorties;
        if(BlueGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(BlueGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(BlueGhost.viewdirection == "Left"){Sorties[1] = false;}
        Sorties = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        MOVE(Sorties,BlueGhost.Pos.second,BlueGhost.Pos.first,13,14,BlueGhost);
    }

    if (BlueGhost.state == "Hide"){
        vector<bool> Sorties;
        Sorties = nbsortie(BlueGhost.Pos.second,BlueGhost.Pos.first,map);
        if(BlueGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(BlueGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(BlueGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(BlueGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 21;}
        if(PacMan.viewdirection == "Right"){xp -= 24;}
        if(PacMan.viewdirection == "Bottom"){yp -= 26;}
        if(PacMan.viewdirection == "Left"){xp += 23;}
        MOVE(Sorties,BlueGhost.Pos.second,BlueGhost.Pos.first,xp,yp,BlueGhost);

    }
}

//*****************************************************************************
//******************************     Orange    ********************************
//*****************************************************************************
void OrangeGhostMove (Entity & OrangeGhost,Entity PacMan, CMat map){
    if (OrangeGhost.state == "Hunt"){
        vector<bool> Sorties;
        Sorties = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        if(OrangeGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 12;}
        if(PacMan.viewdirection == "Right"){xp -= 10;}
        if(PacMan.viewdirection == "Bottom"){yp -= 13;}
        if(PacMan.viewdirection == "Left"){xp += 11;}
        MOVE(Sorties,OrangeGhost.Pos.second,OrangeGhost.Pos.first,xp,yp,OrangeGhost);
//                cout << OrangeGhost.viewdirection << endl;
    }
    if (OrangeGhost.state == "Flee"){
        vector<bool> Sorties;
        Sorties = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        if(OrangeGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,OrangeGhost.Pos.second,OrangeGhost.Pos.first,0,28,OrangeGhost);
    }
    if (OrangeGhost.state == "Kill"){
        vector<bool> Sorties;
        Sorties = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        if(OrangeGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){Sorties[1] = false;}
        MOVE(Sorties,OrangeGhost.Pos.second,OrangeGhost.Pos.first,13,14,OrangeGhost);
    }

    if (OrangeGhost.state == "Hide"){
        vector<bool> Sorties;
        Sorties = nbsortie(OrangeGhost.Pos.second,OrangeGhost.Pos.first,map);
        if(OrangeGhost.viewdirection == "Top"){Sorties[2] = false;}
        if(OrangeGhost.viewdirection == "Right"){Sorties[3] = false;}
        if(OrangeGhost.viewdirection == "Bottom"){Sorties[0] = false;}
        if(OrangeGhost.viewdirection == "Left"){Sorties[1] = false;}
        unsigned xp = PacMan.Pos.second;
        unsigned yp = PacMan.Pos.first;
        if(PacMan.viewdirection == "Top"){yp += 24;}
        if(PacMan.viewdirection == "Right"){xp -= 27;}
        if(PacMan.viewdirection == "Bottom"){yp -= 20;}
        if(PacMan.viewdirection == "Left"){xp += 26;}
        MOVE(Sorties,OrangeGhost.Pos.second,OrangeGhost.Pos.first,xp,yp,OrangeGhost);

    }
}
