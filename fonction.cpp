#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/shape/rectangle.h"
#include "type.h"

using namespace std;

bool checkCollision (CMat Grid, unsigned X, unsigned Y)
{
    return (!(Grid[Y][X] == KWall || Grid[Y][X] == KGhostDoor));
}

map <string, vector <string>> initSpriteMap (const string & sourceFile)
{
    ifstream ifs (sourceFile);
    map <string, vector <string>> spriteMap;
    string str;
    string title;
    vector <string> spriteList;
    for (int i = 0; !ifs.eof() ;++i)
    {
        getline(ifs,str);
        if (str == "")
        {
            spriteMap[title] = spriteList;
            spriteList.clear();
            i = -1;
        }
        if (i == 0)
            title = str;
        else if (i > 0)
            spriteList.push_back(str);
    }
    return spriteMap;
}

nsGui::Sprite initSprite (Entity & Entity, CMat & entityGrid, unsigned short & tick)
{
    if (Entity.Pos.first == 0 || Entity.Pos.first == entityGrid.size()-3)
        return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12));
    if (Entity.viewdirection == "Top")
    {
        if (checkCollision(entityGrid,Entity.Pos.first,Entity.Pos.second-1))
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12-(12*(tick%2))));
        else
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12));
    }
    if (Entity.viewdirection == "Bottom")
    {
        if (checkCollision(entityGrid,Entity.Pos.first,Entity.Pos.second+1))
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12+(12*(tick%2))));
        else
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12));
    }
    if (Entity.viewdirection == "Right")
    {
        if (checkCollision(entityGrid,Entity.Pos.first+1,Entity.Pos.second))
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12+(12*(tick%2)),24*Entity.Pos.second-12));
        else
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12));
    }
    else if (Entity.viewdirection == "Left")
    {
        if (checkCollision(entityGrid,Entity.Pos.first-1,Entity.Pos.second))
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12-(12*(tick%2)),24*Entity.Pos.second-12));
        else
            return nsGui::Sprite (Entity.SpriteMap[Entity.viewdirection][tick % Entity.SpriteMap[Entity.viewdirection].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12));
    }
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
void GhostMovement(CMat & entityGrid, Entity & PacMan,short unsigned & tick)
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
pair <CMat, map<char, CPos>> initEntityMaze (const string & sourceFile)
{
    pair <CMat, map<char, CPos>> gridInfo;
    CVLine maze_line;
    string line;
    CMat mat_maze;
    map<char, CPos> posMap;
    CPos Pos;
    ifstream ifs (sourceFile);
    while (!ifs.eof())
    {
        getline(ifs,line);
        for (unsigned i = 0; i < line.size(); ++i)
        {
            maze_line.push_back(line[i]);
            if (line[i] == 'P' || line[i] == 'R' || line[i] == 'B' || line[i] == 'K' || line[i] == 'O')
            {
                Pos.first = maze_line.size()-1;
                Pos.second = mat_maze.size();
                posMap[line[i]] = Pos;
            }
        }
        mat_maze.push_back(maze_line);
        maze_line.clear();
    }
    gridInfo.first = mat_maze;
    gridInfo.second = posMap;
    return gridInfo;
}

CMat initGumMaze(const string & sourceFile)
{
    ifstream ifs (sourceFile);
    vector<char> maze_line;
    string line;
    CMat mat_maze;
    while (!ifs.eof())
    {
        getline(ifs,line);
        for (unsigned i = 0; i < line.size(); ++i)
            maze_line.push_back(line[i]);
        mat_maze.push_back(maze_line);
        maze_line.clear();
    }
    return mat_maze;
}

void showGumInMaze(MinGL & window, const CMat & gumGrid)
{
    for (unsigned y = 0; y < gumGrid.size(); ++y)
            {
                for (unsigned x = 0; x < gumGrid[y].size(); ++x)
                {
                    if (gumGrid[y][x] == KGum)
                        window << nsShape::Rectangle(nsGraphics::Vec2D(24*x+9, 24*y+9), nsGraphics::Vec2D(24*x+15, 24*y+15), nsGraphics::KWhite);
                    if (gumGrid[y][x] == KSuperGum)
                        window << nsGui::Sprite ("../sae102/res/sprites/supergum.si2", nsGraphics::Vec2D(24*x,24*y));
                }
            }
}

void gumEating(Entity PacMan, CMat & gumGrid)
{
    if (gumGrid[PacMan.Pos.second][PacMan.Pos.first] == KGum)
        gumGrid[PacMan.Pos.second][PacMan.Pos.first] = KEmpty;
    if (gumGrid[PacMan.Pos.second][PacMan.Pos.first] == KSuperGum)
        gumGrid[PacMan.Pos.second][PacMan.Pos.first] = KEmpty;
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
