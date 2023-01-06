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
#include "iaghost.h"
#include <cmath>
using namespace std;


//*****************************************************************************
//*****************************     nbsortie     ******************************
//*****************************************************************************
vector<bool> nbsortie(unsigned y , unsigned x, vector<vector<char> > map){
    vector<bool> sortie = {false,false,false,false};
    if (not(map[y-1][x] == 'X')){
        sortie[0] = true;
    }
    if (not(map[y][x+1] == 'X')){
        sortie[1] = true;
    }
    if (not(map[y+1][x] == 'X')){
        sortie[2] = true;
    }
    if (not(map[y][x-1] == 'X')){
        sortie[3] = true;
    }
    return sortie;
}

//*****************************************************************************
//*************************     estintersection     ***************************
//*****************************************************************************
bool estintersection (vector<bool> sortie,string direction){
    unsigned nbsortie = 0;
    unsigned direct;
    if(direction == "up"){direct = 0;}
    if(direction == "right"){direct = 0;}
    if(direction == "down"){direct = 0;}
    if(direction == "left"){direct = 0;}
    for(unsigned i = 0;i < sortie.size();++i){
        if (sortie[i] == true and i != direct){
            ++nbsortie;
        }
    }
    bool intersection = false;
    if (nbsortie >= 2){intersection = true;}
    return intersection;
}

//*****************************************************************************
//****************************     REDMOVE     ***********+********************
//*****************************************************************************
vector<unsigned> REDMOVE(vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp)
{
    vector<float> distance ={0,0,0,0};
    for(unsigned i = 0;i < sortie.size();++i){
        if (sortie[i] == true){
            if(i == 0){
                distance[i] = sqrt((xp-xg)*(xp-xg))+((yp-yg)*(yp-yg));
            }
        }
    }
    unsigned imin;
    unsigned distancemin = 0;
    for (unsigned i = 0;i < distance.size(); ++i){
        if(distance[i] < distancemin){
            distancemin = distance[i];
            imin = i;
        }
    }
    vector<unsigned> deplacement;
    if(imin == 0){deplacement[0] = xg;deplacement[1] = yg-1;}
    if(imin == 1){deplacement[0] = xg+1;deplacement[1] = yg;}
    if(imin == 2){deplacement[0] = xg;deplacement[1] = yg+1;}
    if(imin == 3){deplacement[0] = xg-1;deplacement[1] = yg;}

    return deplacement;
}
