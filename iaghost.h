#ifndef IAGHOST_H
#define IAGHOST_H
#include "type.h"
#include <vector>
#include <string>
#include <map>



std::vector<bool> nbsortie(unsigned y , unsigned x, CMat map);

bool estintersection (std::vector<bool> sortie);

void REDMOVE(std::vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp, Entity RedGhost);

#endif // IAGHOST_H

