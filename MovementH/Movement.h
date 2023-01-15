/**
 *
 * @file : Movement.h
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Fonctions liés au mouvement dans la matrice du PacMan et des fantômes.
 *
**/

#ifndef MOVEMENT_H
#define MOVEMENT_H
#include "type.h"

bool checkCollision (CMat Grid, unsigned X, unsigned Y);

void pacManDirection(MinGL & window, CMat & entityGrid, Entity & PacMan);

void GhostMovement(CMat & entityGrid, Entity & PacMan,short unsigned & tick);

void pacManMovement(CMat & entityGrid, Entity & PacMan,short unsigned & tick);

void move_entity_in_mat(CMat Mat, Entity entity);

#endif // MOVEMENT_H
