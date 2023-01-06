#ifndef IAGHOST_H
#define IAGHOST_H
#include <vector>
#include <string>
#include <map>



std::vector<bool> nbsortie (unsigned y , unsigned x, std::vector<std::vector<char>> map);

bool estintersection (std::vector<bool> sortie);

std::vector<unsigned> REDMOVE(std::vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp);

#endif // IAGHOST_H
