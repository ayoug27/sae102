#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>
#include "type.h"
using namespace std;
ifstream ifs;

//pair <CMat, map<char, CPos>> initEntityMaze (const string & sourceFile)
//{
//    pair <CMat, map<char, CPos>> gridInfo;
//    CVLine maze_line;
//    string line;
//    CMat mat_maze;
//    map<char, CPos> posMap;
//    CPos Pos;
//    ifstream ifs (sourceFile);
//    while (!ifs.eof())
//    {
//        getline(ifs,line);
//        for (unsigned i = 0; i < line.size(); ++i)
//        {
//            maze_line.push_back(line[i]);
//            if (line[i] == 'P' || line[i] == 'R' || line[i] == 'B' || line[i] == 'K' || line[i] == 'O')
//            {
//                Pos.first = maze_line.size()-1;
//                Pos.second = mat_maze.size();
//                posMap[line[i]] = Pos;
//            }
//        }
//        mat_maze.push_back(maze_line);
//        maze_line.clear();
//    }
//    gridInfo.first = mat_maze;
//    gridInfo.second = posMap;
//    return gridInfo;
//}

//CMat initGumMaze(const string & sourceFile)
//{
//    ifstream ifs (sourceFile);
//    vector<char> maze_line;
//    string line;
//    CMat mat_maze;
//    while (!ifs.eof())
//    {
//        getline(ifs,line);
//        for (unsigned i = 0; i < line.size(); ++i)
//            maze_line.push_back(line[i]);
//        mat_maze.push_back(maze_line);
//        maze_line.clear();
//    }
//    return mat_maze;
//}
