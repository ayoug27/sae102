#ifndef INIT_H
#define INIT_H
#include "type.h"
#include <vector>
#include <string>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"





std::map <std::string, std::vector <std::string>> initSpriteMap (const std::string & sourceFile);


std::pair <CMat, std::map<char, CPos>> initEntityMaze (const std::string & sourceFile);


CMat initGumMaze(const std::string & sourceFile);


#endif // INIT_H
