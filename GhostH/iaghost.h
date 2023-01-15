/**
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @synop: déplacement des fantomes dans la matrice recherche du meilleur chemin
*/

#ifndef IAGHOST_H
#define IAGHOST_H
#include "type.h"
#include <vector>
#include <string>
#include <map>

/**
 * @brief nbsortie : reharde autour de coordonnée si il y a des croix
 * @param y : position en Y
 * @param x : positrion en X
 * @param map : map sur la quel on veux verifier
 * @return return un vector de bool qui a true pour une sortie libre
 * et false pour une sortie non possible
 */
std::vector<bool> nbsortie(unsigned y , unsigned x, CMat map);

/**
 * @brief CalculeDistance : calcule la distance entre 2 points
 * @param sortie : regarde a quel case ils faut faire le calcule
 * @param yg : Y du fantomes
 * @param xg : X du fantomes
 * @param yp : Y de PacMan
 * @param xp : X de PacMan
 * @return : Return une distance pour chaque pixel considéré comme
 * une sortie
 */
std::vector <float> CalculeDistance (std::vector<bool> sortie,unsigned yg ,
                                    unsigned xg,unsigned yp , unsigned xp);

/**
 * @brief TrouveIndiceMinDanstab : trouve le minimum dans un tableau
 * @param Vec : vecteur dans lequel on cherche le plus petit nombre
 * @return l'indice du plus petit des nombres du vecteur
 */
unsigned TrouveIndiceMinDanstab (std::vector<float> Vec);

/**
 * @brief MOVE : sert a dire vers ou le fantomes ira
 * @param sortie : les sortie possible pour le fantomes
 * @param yg : Y du fantome
 * @param xg : X du fantome
 * @param yp : Y de PacMan
 * @param xp : X de PacMan
 * @param entity : La struct avec les fantomes a déplacer
 */
void MOVE(std::vector<bool> sortie,unsigned yg , unsigned xg,
                          unsigned yp , unsigned xp, Entity & entity);


#endif // IAGHOST_H
