#ifndef TYPE_H
#define TYPE_H

#include <string>
#include <vector>
#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/shape/rectangle.h"



typedef std::vector <char> CVLine;
typedef std::vector <CVLine> CMat;
typedef std::pair <unsigned, unsigned> CPos;


struct Entity
{
    char ident;
    std::map <std::string, std::vector <std::string>> SpriteMap;
    std::string viewdirection;
    std::string state;
    CPos Pos;
    std::string oldposs;
};


const char KEmpty = ' ';
const char KGhostDoor = '_';
const char KWall = 'X';
const char KGum = '*';
const char KSuperGum = '0';

#endif // TYPE_H
