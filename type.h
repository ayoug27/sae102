/**
 *
 * @file : type.h
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Initialisation de typedef, de constantes et de structs utiles au bon fonctionnement du programme.
 *
**/

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
#include "mingl/audio/audioengine.h"



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
};


const char KEmpty = ' ';
const char KGhostDoor = '_';
const char KWall = 'X';
const char KGum = '*';
const char KSuperGum = '0';

#endif // TYPE_H
