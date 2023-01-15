/**
 *
 * @file : Movement.cpp
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Fonctions liés au mouvement dans la matrice du PacMan et des fantômes.
 *
**/

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


bool checkCollision (CMat Grid, unsigned X, unsigned Y)
{
    return (!(Grid[Y][X] == KWall || Grid[Y][X] == KGhostDoor));
}

void pacManDirection(MinGL & window, CMat & entityGrid, Entity & PacMan)
{
    if (PacMan.Pos.first == 0 || PacMan.Pos.first == entityGrid.size()-3) return;
    if (window.isPressed({'z', false}) && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second-1))
        PacMan.viewdirection = "Top";
    if (window.isPressed({'s', false}) && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second+1))
        PacMan.viewdirection = "Bottom";
    if (window.isPressed({'q', false}) && checkCollision(entityGrid,PacMan.Pos.first-1,PacMan.Pos.second))
        PacMan.viewdirection = "Left";
    if (window.isPressed({'d', false}) && checkCollision(entityGrid,PacMan.Pos.first+1,PacMan.Pos.second))
        PacMan.viewdirection = "Right";
}
void GhostMovement(CMat & entityGrid, Entity & Ghost,short unsigned & tick)
{
    if (tick%2 == 0)
    {
        entityGrid[Ghost.Pos.second][Ghost.Pos.first] = KEmpty;
        if (Ghost.viewdirection == "Top" && checkCollision(entityGrid,Ghost.Pos.first,Ghost.Pos.second-1))
        {
            --Ghost.Pos.second;
        }
        if (Ghost.viewdirection == "Bottom" && checkCollision(entityGrid,Ghost.Pos.first,Ghost.Pos.second+1))
        {

            ++Ghost.Pos.second;

        }
        if (Ghost.viewdirection == "Left")
        {
            if (Ghost.Pos.first != 0)
            {
                if (checkCollision(entityGrid,Ghost.Pos.first-1,Ghost.Pos.second))
                    --Ghost.Pos.first;
            }
            else
            {
                Ghost.Pos.first = entityGrid[1].size()-1;
                Ghost.Pos.second = 14;
            }
        }
        if (Ghost.viewdirection == "Right" && checkCollision(entityGrid,Ghost.Pos.first+1,Ghost.Pos.second))
        {
            if (Ghost.Pos.first < entityGrid.size()-5)
            {
                if (checkCollision(entityGrid,Ghost.Pos.first+1,Ghost.Pos.second))
                    ++Ghost.Pos.first;
            }
            else
            {
                Ghost.Pos.first = 0;
                Ghost.Pos.second = 14;
            }
        }
        entityGrid[Ghost.Pos.second][Ghost.Pos.first] = Ghost.ident;
    }
}
void pacManMovement(CMat & entityGrid, Entity & PacMan,short unsigned & tick)
{
    if (tick%2 == 0)
    {
        entityGrid[PacMan.Pos.second][PacMan.Pos.first] = KEmpty;
        if (PacMan.viewdirection == "Top" && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second-1))
        {
            --PacMan.Pos.second;
        }
        if (PacMan.viewdirection == "Bottom" && checkCollision(entityGrid,PacMan.Pos.first,PacMan.Pos.second+1))
        {

            ++PacMan.Pos.second;

        }
        if (PacMan.viewdirection == "Left")
        {
            if (PacMan.Pos.first != 0)
            {
                if (checkCollision(entityGrid,PacMan.Pos.first-1,PacMan.Pos.second))
                    --PacMan.Pos.first;
            }
            else
            {
                PacMan.Pos.first = entityGrid[1].size()-1;
                PacMan.Pos.second = 14;
            }
        }
        if (PacMan.viewdirection == "Right" && checkCollision(entityGrid,PacMan.Pos.first+1,PacMan.Pos.second))
        {
            if (PacMan.Pos.first < entityGrid.size()-5)
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
}


void move_entity_in_mat(CMat Mat, Entity entity){
    Mat[entity.Pos.second][entity.Pos.first] = KEmpty;
    if (entity.viewdirection == "Top"){
        if (Mat[entity.Pos.second-1][entity.Pos.first]!= KWall){
            Mat[entity.Pos.second-1][entity.Pos.first] = entity.ident;
            entity.Pos.second -=1;
        }
    }
    if (entity.viewdirection == "Right"){
        if (Mat[entity.Pos.second][entity.Pos.first+1]!= KWall){
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
        if (Mat[entity.Pos.second+1][entity.Pos.first]!= KWall){
            Mat[entity.Pos.second+1][entity.Pos.first] = entity.ident;
            entity.Pos.second +=1;
        }
    }
    if (entity.viewdirection == "Left"){
        if (Mat[entity.Pos.second][entity.Pos.first-1]!= KWall){
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

