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

/**
 * @brief Permet de vérifier si un mur est présent aux coordonnées indiqués.
 * @param[in] Grid : Matrice ou se trouve les obstacles.
 * @param[in] X : coordonnée X.
 * @param[in] Y : coordonnée Y.
 * @fn bool checkCollision (CMat Grid, unsigned X, unsigned Y);
 */
bool checkCollision (CMat Grid, unsigned X, unsigned Y);

/**
 * @brief Permet de changer la direction du PacMan.
 * @param[in] window : fenêtre MinGL.
 * @param[in] entityGrid : Matrice ou se trouve les obstacles.
 * @param[in] PacMan : Entité PacMan.
 * @fn void pacManDirection(MinGL & window, CMat & entityGrid, Entity & PacMan);
 */
void pacManDirection(MinGL & window, CMat & entityGrid, Entity & PacMan);

/**
 * @brief Permet de déplacer le fantôme dans la matrice.
 * @param[in] entityGrid : Matrice ou se trouve le fantôme.
 * @param[in] Ghost : Entité Fantôme.
 * @param[in] tick : compteur de frame.
 * @fn void GhostMovement(CMat & entityGrid, Entity & Ghost,short unsigned & tick);
 */
void GhostMovement(CMat & entityGrid, Entity & Ghost,short unsigned & tick);

/**
 * @brief Permet de déplacer le PacMan dans la matrice.
 * @param[in] entityGrid : Matrice ou se trouve le PacMan.
 * @param[in] PacMan : Entité PacMan.
 * @param[in] tick : compteur de frame.
 * @fn void pacManMovement(CMat & entityGrid, Entity & PacMan,short unsigned & tick);
 */
void pacManMovement(CMat & entityGrid, Entity & PacMan,short unsigned & tick);

void move_entity_in_mat(CMat Mat, Entity entity);

#endif // MOVEMENT_H
