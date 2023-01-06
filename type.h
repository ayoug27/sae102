#ifndef TYPE_H
#define TYPE_H
#include "iaghost.h"
#include <vector>
#include <string>
#include <map>



typedef std::vector <char> CVLine;

typedef std::vector <CVLine> CMat;

const char KEmpty = ' ';
const char KMur = 'X';


typedef std::vector <char> CVLine; // ligne
typedef std::vector <CVLine> CMat; // grille
typedef std::pair <unsigned, unsigned> CPos;


struct Entity
{
    char ident;
    std::map <std::string, std::vector <std::string>> SpriteMap;
    std::string state;
    CPos Pos;
    std::string viewdirection;
};


#endif // TYPE_H
