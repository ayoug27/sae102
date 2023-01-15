/**
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @synopsis: déplacement des fantomes 1 par 1
*/

#ifndef GHOSTMOVE_H
#define GHOSTMOVE_H

#include "type.h"
#include <vector>
#include <string>
#include <map>

/**
 * @brief DemiTour : sert a supprimé la possibilité de faire demi tour
 * @param Sorties : vecteur de bool contenant les sorties possibles
 * sous forme de false pour non disponible et true pour disponible
 * @param entity : struct Entity contenant des info sur les fantomes
 * @return renvoie un veteur de bool des sortie possible mais sans
 * la sortie situer deriere lui
*/
std::vector<bool> DemiTour(std::vector<bool> Sorties,Entity entity);

/**
 * @brief RedGhostMove : déplace le fantomes rouge en fonction de ses spésificités
 * @param RedGhost : données du fantomes rouge
 * @param PacMan : données de PacMan
 * @param map : Map dans laquel se deplace le fantome
 */
void RedGhostMove (Entity & RedGhost, Entity PacMan, CMat map);

/**
 * @brief PinkGhostMove : déplace le fantomes rose en fonction de ses spésificités
 * @param PinkGhost : données du fantomes rouge
 * @param PacMan : données de PacMan
 * @param map : Map dans laquel se deplace le fantome
 */
void PinkGhostMove (Entity & PinkGhost, Entity PacMan, CMat map);

/**
 * @brief BlueGhostMove : déplace le fantomes blue en fonction de ses spésificités
 * @param BlueGhost : données du fantomes rouge
 * @param PacMan : données de PacMan
 * @param map : Map dans laquel se deplace le fantome
 */
void BlueGhostMove (Entity & BlueGhost, Entity PacMan, CMat map);

/**
 * @brief OrangeGhostMove : déplace le fantomes Orange en fonction de ses spésificités
 * @param OrangeGhost : données du fantomes rouge
 * @param PacMan : données de PacMan
 * @param map : Map dans laquel se deplace le fantome
 */
void OrangeGhostMove (Entity & OrangeGhost, Entity PacMan, CMat map);



#endif // GHOSTMOVE_H
