/**
 *
 * @file : Misk.h
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Fonctions diverses et variés.
 *
**/
#ifndef MISC_H
#define MISC_H

#include "type.h"

/**
 * @brief Permet à PacMan de manger les billes.
 * @param[in] PacMan : Entité Pacman.
 * @param[in] gumGrid : Matrice ou se trouvent les billes.
 * @param[in] NbGum : Nombre de billes.
 * @param[in] score : Score actuel.
 * @fn void gumEating(Entity PacMan, CMat & gumGrid, unsigned & NbGum, unsigned & score);
 */
void gumEating(nsAudio::AudioEngine & audioEngine, Entity PacMan, CMat & gumGrid, unsigned & NbGum, unsigned & score);

/**
 * @brief Permet de passer d'un niveau à l'autre.
 * @param[in] PacMan : Entité Pacman.
 * @param[in] Ghost1 : Entité Fantôme 1.
 * @param[in] Ghost2 : Entité Fantôme 2.
 * @param[in] Ghost3 : Entité Fantôme 3.
 * @param[in] Ghost4 : Entité Fantôme 4.
 * @param[in] posMap : Positions initiales des Entités.
 * @param[in] gumGrid : Matrice ou se trouvent les billes.
 * @fn void ChangementNiveau(Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap, CMat & gumGrid);
 */
void ChangementNiveau(Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap, CMat & gumGrid);

/**
 * @brief Permet de vérifier si PacMan est mort.
 * @param[in] PacMan : Entité Pacman.
 * @param[in] Ghost1 : Entité Fantôme 1.
 * @param[in] Ghost2 : Entité Fantôme 2.
 * @param[in] Ghost3 : Entité Fantôme 3.
 * @param[in] Ghost4 : Entité Fantôme 4.
 * @fn bool isDead (Entity & PacMan, Entity Ghost1, Entity Ghost2, Entity Ghost3, Entity Ghost4);
 */
bool isDead (Entity & PacMan, Entity Ghost1, Entity Ghost2, Entity Ghost3, Entity Ghost4);

#endif // MISC_H
