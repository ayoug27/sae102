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

    if (y == 14){
        if (x == 0){
            if (not(map[y-1][x] == 'X')){sortie[0] = true;}
            if (not(map[y][x+1] == 'X')){sortie[1] = true;}
            if (not(map[y+1][x] == 'X')){sortie[2] = true;}
            sortie[3] = true;
        }
        else if (x == map.size()-5){
            if (not(map[y-1][x] == 'X')){sortie[0] = true;}
            sortie[1] = true;
            if (not(map[y+1][x] == 'X')){sortie[2] = true;}
            if (not(map[y][x-1] == 'X')){sortie[3] = true;}
        }
        else {
            if (not(map[y-1][x] == 'X')){sortie[0] = true;}
            if (not(map[y][x+1] == 'X')){sortie[1] = true;}
            if (not(map[y+1][x] == 'X')){sortie[2] = true;}
            if (not(map[y][x-1] == 'X')){sortie[3] = true;}
        }
    }
    else {
        if (not(map[y-1][x] == 'X')){sortie[0] = true;}
        if (not(map[y][x+1] == 'X')){sortie[1] = true;}
        if (not(map[y+1][x] == 'X')){sortie[2] = true;}
        if (not(map[y][x-1] == 'X')){sortie[3] = true;}

    }

    return sortie;
}

//*****************************************************************************
//***********************    calcule distance     *****************************
//*****************************************************************************
vector <float> CalculeDistance (vector<bool> sortie,unsigned yg , unsigned xg,
                                unsigned yp , unsigned xp){

    vector<float> distance ={1000000,1100000,1000000,1000000};
    for(unsigned i = 0;i < sortie.size();++i){
        if (sortie[i] == true){
            if (i == 0){
            distance[i] = sqrt(((xp-xg)*(xp-xg))+((yp-(yg-1))*(yp-(yg-1))));;
            }
            if (i == 1){
            distance[i] = sqrt(((xp-(xg+1))*(xp-(xg+1)))+((yp-yg)*(yp-yg)));;
            }
            if (i == 2){
            distance[i] = sqrt(((xp-xg)*(xp-xg))+((yp-(yg+1))*(yp-(yg+1))));;
            }
            if (i == 3){
            distance[i] = sqrt(((xp-(xg-1))*(xp-(xg-1)))+((yp-yg)*(yp-yg)));;
            }
        }
    }
    return distance;
}
//*****************************************************************************
//***********************    calcule distance     *****************************
//*****************************************************************************
unsigned TrouveIndiceMinDanstab (vector<float> Vec){
    unsigned imin = 0;
    unsigned Vecmin = Vec[0];
    for (unsigned i = 1;i < Vec.size(); ++i){
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
                          unsigned yp , unsigned xp, Entity & entity)
{
    vector<float> distance = CalculeDistance(sortie,yg,xg,yp,xp);
    unsigned imin = TrouveIndiceMinDanstab(distance);
    if(imin == 0){entity.viewdirection = "Top";}
    if(imin == 1){entity.viewdirection = "Right";}
    if(imin == 2){entity.viewdirection = "Bottom";}
    if(imin == 3){entity.viewdirection = "Left";}
}
