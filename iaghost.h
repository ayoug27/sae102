#ifndef IAGHOST_H
#define IAGHOST_H
#include "type.h"
#include <vector>
#include <string>
#include <map>



std::vector<bool> nbsortie(unsigned y , unsigned x, CMat map);

std::vector <float> CalculeDistance (std::vector<bool> sortie,unsigned yg ,
                                    unsigned xg,unsigned yp , unsigned xp);

unsigned TrouveIndiceMinDanstab (std::vector<float> Vec);

void MOVE(std::vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp, Entity RedGhost);


#endif // IAGHOST_H

