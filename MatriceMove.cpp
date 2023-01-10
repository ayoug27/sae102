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
#include "game.h"



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
nsGui::Sprite pacManComportment(Entity & PacMan, short unsigned & tick)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    if (PacMan.state == "Top")
    {
        posPacMan.setY(24*PacMan.Pos.second-12);
        return initSprite(PacMan.SpriteMap["Top"], tick);
    }
    if (PacMan.state == "Bottom")
    {
        posPacMan.setY(24*PacMan.Pos.second-12);
        return initSprite(PacMan.SpriteMap["Bottom"], tick);
    }
    if (PacMan.state == "Left")
    {
        posPacMan.setX(24*PacMan.Pos.first-12);
        return initSprite(PacMan.SpriteMap["Left"], tick);
    }
    else if (PacMan.state == "Right")
    {
        posPacMan.setX(24*PacMan.Pos.first-12);
        return initSprite(PacMan.SpriteMap["Right"], tick);
    }
}
//************************************************
// En double mais différente a voir laquel gardé
//***********************************************
//nsGui::Sprite pacManComportment(Entity PacMan, short unsigned tick)
//{
//    // On vérifie si ZQSD est pressé, et met a jour la position
//    if (PacMan.viewdirection == "Top")
//    {
//        posPacMan.setY(posPacMan.getY() - 12);
//        return initSprite(PacMan.SpriteMap["Top"], tick);
//    }
//    if (PacMan.viewdirection == "Bottom")
//    {
//        posPacMan.setY(posPacMan.getY() + 12);
//        return initSprite(PacMan.SpriteMap["Bottom"], tick);
//    }
//    if (PacMan.viewdirection == "Left")
//    {
//        posPacMan.setX(posPacMan.getX() - 12);
//        return initSprite(PacMan.SpriteMap["Left"], tick);
//    }
//    if (PacMan.viewdirection == "Right")
//    {
//        posPacMan.setX(posPacMan.getX() + 12);
//        return initSprite(PacMan.SpriteMap["Right"], tick);
//    }
//    return initSprite(PacMan.SpriteMap["Right"], tick);
//}

bool checkCollision (CMat Grid, unsigned X, unsigned Y)
{
    return (!(Grid[Y][X] == 'X'));
}

void pacManState(MinGL & window, CMat & entityGrid, Entity & PacMan)
{
    if (PacMan.Pos.first == 0 || PacMan.Pos.first == entityGrid.size()-1) return;
    if (window.isPressed({'z', false}) && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second-1))
        PacMan.state = "Top";
    if (window.isPressed({'s', false}) && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second+1))
        PacMan.state = "Bottom";
    if (window.isPressed({'q', false}) && checkCollision(entityGrid,PacMan.Pos.first-1,PacMan.Pos.second))
        PacMan.state = "Left";
    if (window.isPressed({'d', false}) && checkCollision(entityGrid,PacMan.Pos.first+1,PacMan.Pos.second))
        PacMan.state = "Right";
}

void pacManMovement(CMat & entityGrid, Entity & PacMan)
{
    entityGrid[PacMan.Pos.second][PacMan.Pos.first] = KEmpty;
    if (PacMan.state == "Top" && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second-1))
    {
        --PacMan.Pos.second;
    }
    if (PacMan.state == "Bottom" && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second+1))
    {
        ++PacMan.Pos.second;

    }
    if (PacMan.state == "Left")
    {
        if (PacMan.Pos.first != 0)
        {
            if (checkCollision(entityGrid,PacMan.Pos.first-1,PacMan.Pos.second))
                --PacMan.Pos.first;
        }
        else
        {
            PacMan.Pos.first = entityGrid.size()-1;
            PacMan.Pos.second = 14;
        }
    }
    if (PacMan.state == "Right" && checkCollision(entityGrid,PacMan.Pos.first+1,PacMan.Pos.second))
    {
        if (PacMan.Pos.first != entityGrid.size()-1)
        {
            if (checkCollision(entityGrid,PacMan.Pos.first+1,PacMan.Pos.second))
                ++PacMan.Pos.first;
        }
        else
        {
            PacMan.Pos.first = 0;
            PacMan.Pos.second = 14;
        }
    }
    entityGrid[PacMan.Pos.second][PacMan.Pos.first] = PacMan.ident;
}

