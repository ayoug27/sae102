#ifndef MISK_H
#define MISK_H
#include "type.h"

void gumEating(Entity PacMan, CMat & gumGrid, unsigned & NbGum, unsigned & score);

void ChangementNiveau(Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap, CMat & gumGrid);

bool isDead (Entity & PacMan, Entity Ghost1, Entity Ghost2, Entity Ghost3, Entity Ghost4);

#endif // MISK_H
