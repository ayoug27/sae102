//*****************************************************************************
//*************************     Initialisation     ****************************
//*****************************************************************************
#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "type.h"
#include "iaghost.h"
#include "GhostH/PhaseGhost.h"
#include "GhostH/GhostMove.h"
#include "MatriceMove.h"

using namespace std;


string pacManviewdirection(MinGL & window, string viewdirection)
{
    if (window.isPressed({'z', false}))
        return "Top";
    if (window.isPressed({'s', false}))
        return "Bottom";
    if (window.isPressed({'q', false}))
        return "Left";
    if (window.isPressed({'d', false}))
        return "Right";
    return viewdirection;
}

void move_entity_in_mat(CMat Mat, Entity entity){
    Mat[entity.Pos.second][entity.Pos.first] = KEmpty;
    if (entity.viewdirection == "Top"){
        if (Mat[entity.Pos.second-1][entity.Pos.first]!= KMur){
            Mat[entity.Pos.second-1][entity.Pos.first] = entity.ident;
            entity.Pos.second -=1;
        }
    }
    if (entity.viewdirection == "Right"){
        if (Mat[entity.Pos.second][entity.Pos.first+1]!= KMur){
            if (entity.Pos.first+1 > Mat[entity.Pos.second].size()-1){
                Mat[entity.Pos.second][0]= entity.ident;
                entity.Pos.first = 0;
            }
            else {
                Mat[entity.Pos.second][entity.Pos.first+1] = entity.ident;
                entity.Pos.first +=1;
            }
        }
    }
    if (entity.viewdirection == "Bottom"){
        if (Mat[entity.Pos.second+1][entity.Pos.first]!= KMur){
            Mat[entity.Pos.second+1][entity.Pos.first] = entity.ident;
            entity.Pos.second +=1;
        }
    }
    if (entity.viewdirection == "Left"){
        if (Mat[entity.Pos.second][entity.Pos.first-1]!= KMur){
            if (entity.Pos.first-1 < 0){
                Mat[entity.Pos.second][Mat[entity.Pos.second].size()-1]= entity.ident;
                entity.Pos.first = Mat[entity.Pos.second].size()-1;
            }
            else {
                Mat[entity.Pos.second][entity.Pos.first-1] = entity.ident;
                entity.Pos.first -=1;
            }
        }
    }
}
