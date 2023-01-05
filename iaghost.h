#ifndef IAGHOST_H
#define IAGHOST_H
#include <vector>
#include <string>
#include <map>


typedef std::vector <char> CVLine; // ligne
typedef std::vector <CVLine> CMat; // grille
typedef std::pair <unsigned, unsigned> CPos;


struct Entity
{
    std::map <std::string, std::vector <std::string>> SpriteMap;
    std::string state;
    CPos Pos;
    std::string viewdirection;
};


std::vector<bool> nbsortie (unsigned y , unsigned x, std::vector<std::vector<char>> map);

bool estintersection (std::vector<bool> sortie);

std::vector<unsigned> REDMOVE(std::vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp);

#endif // IAGHOST_H
