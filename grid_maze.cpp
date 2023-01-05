#include <iostream>
#include <fstream>
#include <iomanip>

#include "type.h"

using namespace std;
ifstream ifs;

void init_maze(){
    ifs.open("../sae102/res/mazeinitialmap");
    vector<char> maze_line;
    string line;
    CMat mat_maze;
    while (ifs.eof()){
        maze_line.clear();
        getline (ifs, line);
        for (unsigned i : line){
            maze_line.push_back(line[i]);
        }
        mat_maze.push_back(maze_line);
    }
}

void init_gomme(){

}
