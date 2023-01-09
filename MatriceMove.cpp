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
#include "init.h"

using namespace std;

nsGraphics::Vec2D posPacMan;

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

nsGui::Sprite pacManComportment(Entity PacMan, short unsigned tick)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    if (PacMan.viewdirection == "Top")
    {
        posPacMan.setY(posPacMan.getY() - 12);
        return initSprite(PacMan.SpriteMap["Top"], tick);
    }
    if (PacMan.viewdirection == "Bottom")
    {
        posPacMan.setY(posPacMan.getY() + 12);
        return initSprite(PacMan.SpriteMap["Bottom"], tick);
    }
    if (PacMan.viewdirection == "Left")
    {
        posPacMan.setX(posPacMan.getX() - 12);
        return initSprite(PacMan.SpriteMap["Left"], tick);
    }
    if (PacMan.viewdirection == "Right")
    {
        posPacMan.setX(posPacMan.getX() + 12);
        return initSprite(PacMan.SpriteMap["Right"], tick);
    }
    return initSprite(PacMan.SpriteMap["Right"], tick);
}

//*****************************************************************************
//************************     animation sprite     ***************************
//*****************************************************************************
nsGui::Sprite initSprite (vector <string> & spriteList, unsigned short & tick)
{
    nsGui::Sprite spriteName (spriteList[tick % spriteList.size()], posPacMan);
    return spriteName;
}

