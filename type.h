#ifndef TYPE_H
#define TYPE_H
#include <vector>
#include <string>
#include <map>

class type
{
public :
    /**
     * @bried this is ghost
    */
    /**
     * @brief RedGhostMove : blablka
     * @param RedGhost : test
     * @param PacMan : pacman
     * @param map
     */
};

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
