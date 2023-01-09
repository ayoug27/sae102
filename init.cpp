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

//*****************************************************************************
//**********************    init animation sprite     *************************
//*****************************************************************************
map<string, vector<string> > initSpriteMap(const string & sourceFile)
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

//*****************************************************************************
//****************************     init maze     ******************************
//*****************************************************************************
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
