/**
 *
 * @file : Initialisation.h
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Fonctions liés à l'initialisation de l'animation des sprites et des matrices (entité et gum).
 *
**/

#ifndef INITIALISATION_H
#define INITIALISATION_H
#include "type.h"

/**
 * @brief Initialise la map des sprites pour une entité.
 * @param[in] sourceFile : emplacement du fichier "SpriteMap"
 * @fn std::map <std::string, std::vector <std::string>> initSpriteMap (const std::string & sourceFile);
 */
std::map <std::string, std::vector <std::string>> initSpriteMap (const std::string & sourceFile);

/**
 * @brief Instancie le sprite de l'Entité.
 * @param[in] Entity : Entité dont le sprite est à instancier
 * @param[in] entityGrid : matrice ou se trouve les entités et les obstacles.
 * @param[in] tick : Compteur de frame
 * @fn nsGui::Sprite initSprite (Entity & Entity, CMat & entityGrid, unsigned short & tick);
 */
nsGui::Sprite initSprite (Entity & Entity, CMat & entityGrid, unsigned short & tick);

/**
 * @brief Initialise la matrice et les positions ou se trouve les entités et les obstacles.
 * @param[in] sourceFile : emplacement du fichier ou sont configurés l'emplacement initial des entités et des obstacles.
 * @fn std::pair <CMat, std::map<char, CPos>> initEntityMaze (const std::string & sourceFile);
 */
std::pair <CMat, std::map<char, CPos>> initEntityMaze (const std::string & sourceFile);

/**
 * @brief Initialise la matrice ou se trouve les billes.
 * @param[in] sourceFile : emplacement du fichier ou sont configurés l'emplacement initial des billes.
 * @fn CMat initGumMaze(const std::string & sourceFile);
 */
CMat initGumMaze(const std::string & sourceFile);

/**
 * @brief Réintialise le niveau et les positions des entités.
 * @param[in] PacMan : Entité Pacman.
 * @param[in] Ghost1 : Entité Fantôme 1.
 * @param[in] Ghost2 : Entité Fantôme 2.
 * @param[in] Ghost3 : Entité Fantôme 3.
 * @param[in] Ghost4 : Entité Fantôme 4.
 * @param[in] posMap : Positions initiales des Entités.
 * @fn void reinitLevel (Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap);
 */
void reinitLevel (Entity & PacMan, Entity & Ghost1, Entity & Ghost2, Entity & Ghost3, Entity & Ghost4, std::map<char, CPos> posMap);

#endif // INITIALISATION_H
