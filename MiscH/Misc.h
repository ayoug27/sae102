<<<<<<< Updated upstream:MiskH/Misk.h
/**
 *
 * @file : Misk.h
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Fonctions diverses et variés.
 *
**/

#ifndef MISK_H
#define MISK_H
=======
#ifndef MISC_H
#define MISC_H
>>>>>>> Stashed changes:MiscH/Misc.h
#include "type.h"

void gumEating(Entity PacMan, CMat & gumGrid, unsigned & NbGum, unsigned & score);

void ChangementNiveau(Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap, CMat & gumGrid);

bool isDead (Entity & PacMan, Entity Ghost1, Entity Ghost2, Entity Ghost3, Entity Ghost4);

#endif // MISC_H
