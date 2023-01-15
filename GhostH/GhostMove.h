#ifndef GHOSTMOVE_H
#define GHOSTMOVE_H

#include "type.h"
#include <vector>
#include <string>
#include <map>

std::vector<bool> DemiTour(std::vector<bool> Sorties,Entity entity);

void RedGhostMove (Entity & RedGhost, Entity PacMan, CMat map);

void PinkGhostMove (Entity & PinkGhost, Entity PacMan, CMat map);

void BlueGhostMove (Entity & BlueGhost, Entity PacMan, CMat map);

void OrangeGhostMove (Entity & OrangeGhost, Entity PacMan, CMat map);



#endif // GHOSTMOVE_H
