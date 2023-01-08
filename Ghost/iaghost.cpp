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
#include "GhostH/iaghost.h"
#include "type.h"
#include <cmath>
using namespace std;


//*****************************************************************************
//*****************************     nbsortie     ******************************
//*****************************************************************************
vector<bool> nbsortie(unsigned y , unsigned x, CMat map){
    vector<bool> sortie = {false,false,false,false};
    if (not(map[y-1][x] == 'X')){sortie[0] = true;}
    if (not(map[y][x+1] == 'X')){sortie[1] = true;}
    if (not(map[y+1][x] == 'X')){sortie[2] = true;}
    if (not(map[y][x-1] == 'X')){sortie[3] = true;}
    return sortie;
}

//*****************************************************************************
//***********************    calcule distance     *****************************
//*****************************************************************************
vector <float> CalculeDistance (vector<bool> sortie,unsigned yg , unsigned xg,
                                unsigned yp , unsigned xp){
    vector<float> distance ={0,0,0,0};
    for(unsigned i = 0;i < sortie.size();++i){
        if (sortie[i] == true){
            if(i == 0){
                distance[i] = sqrt(((xp-xg)*(xp-xg))+((yp-yg)*(yp-yg)));
            }
        }
    }
    return distance;
}
//*****************************************************************************
//***********************    calcule distance     *****************************
//*****************************************************************************
unsigned TrouveIndiceMinDanstab (vector<float> Vec){
    unsigned imin;
    unsigned Vecmin = 0;
    for (unsigned i = 0;i < Vec.size(); ++i){
        if(Vec[i] < Vecmin){
            Vecmin = Vec[i];
            imin = i;
        }
    }
    return imin;
}

//*****************************************************************************
//**************************    déplacement     *******************************
//*****************************************************************************
void MOVE(vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp, Entity RedGhost)
{
    vector<float> distance = CalculeDistance(sortie,yg,xg,yp,xp);
    unsigned imin = TrouveIndiceMinDanstab(distance);

    if(imin == 0){RedGhost.viewdirection = "up";}
    if(imin == 1){RedGhost.viewdirection = "right";}
    if(imin == 2){RedGhost.viewdirection = "down";}
    if(imin == 3){RedGhost.viewdirection = "left";}
}







