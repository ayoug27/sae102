#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/shape/rectangle.h"
#include "type.h"
#include "MiskH/Misk.h"
#include "MovementH/Movement.h"

using namespace std;

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
    if (Entity.state == "Hide")
        return nsGui::Sprite (Entity.SpriteMap[Entity.state][tick % Entity.SpriteMap[Entity.state].size()], nsGraphics::Vec2D(24*Entity.Pos.first-12,24*Entity.Pos.second-12));
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

void reinitLevel (Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, map<char, CPos> posMap)
{
    PacMan.viewdirection = "Left";
    PacMan.Pos = posMap[PacMan.ident];
    Ghost1.state = "Flee";
    Ghost1.viewdirection = "Left";
    Ghost1.Pos = posMap[Ghost1.ident];
    Ghost2.state = "Flee";
    Ghost2.viewdirection = "Top";
    Ghost2.Pos = posMap[Ghost2.ident];
    Ghost3.state = "Flee";
    Ghost3.viewdirection = "Bottom";
    Ghost3.Pos = posMap[Ghost3.ident];
    Ghost4.state = "Flee";
    Ghost4.viewdirection = "Bottom";
    Ghost4.Pos = posMap[Ghost4.ident];
}
