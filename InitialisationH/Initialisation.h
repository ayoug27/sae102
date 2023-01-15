#ifndef INITIALISATION_H
#define INITIALISATION_H
#include "type.h"

std::map <std::string, std::vector <std::string>> initSpriteMap (const std::string & sourceFile);

nsGui::Sprite initSprite (Entity & Entity, CMat & entityGrid, unsigned short & tick);

std::pair <CMat, std::map<char, CPos>> initEntityMaze (const std::string & sourceFile);

CMat initGumMaze(const std::string & sourceFile);

void reinitLevel (Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap);

#endif // INITIALISATION_H
