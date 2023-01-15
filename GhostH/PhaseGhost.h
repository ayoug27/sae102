/*
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @synopsis: changement de phase
*/

#ifndef PHASEGHOST_H
#define PHASEGHOST_H
#include "type.h"
#include <vector>
#include <string>
#include <map>

/**
 * @brief Phase : Change les etats des fantomes en fonction du temps passé
 * @param VecPhase : vecteur contenant les phases
 * @param tick : tick servant a connaitre le temps de jeu
 * @param entity : struct avec les phantomes
 */
void Phase (std::vector<bool> VecPhase, unsigned short tick,
                    Entity & entity);


#endif // PHASEGHOST_H
