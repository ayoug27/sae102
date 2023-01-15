/**
 *
 * @file : Display.h
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @brief : Fonctions liés à l'affichage de l'interface.
 *
**/


#ifndef DISPLAY_H
#define DISPLAY_H

#include "type.h"

/**
 * @brief Affiche le score sur l'interface de la fenêtre.
 * @param[in] window : Fenêtre MinGL
 * @param[in] score : Valeur du score
 * @fn void affichageScore(MinGL & window, unsigned & score);
 */
void affichageScore(MinGL & window, unsigned & score);

/**
 * @brief Affiche les vies restantes sur l'interface de la fenêtre.
 * @param[in] PacManSprite : SpriteMap permettant d'afficher le sprite côté droit de PacMan.
 * @param[in] window : Fenêtre MinGL
 * @param[in] vies : Vies restantes
 * @fn void affichageVies(std::map <std::string, std::vector <std::string>> & PacManSprite, MinGL & window, unsigned & vies);
 */
void affichageVies(std::map <std::string, std::vector <std::string>> & PacManSprite, MinGL & window, unsigned & vies);

/**
 * @brief Affiche le niveau actuel sur l'interface de la fenêtre.
 * @param[in] window : Fenêtre MinGL
 * @param[in] niveau : Niveau actuel
 * @fn void affichageNiveau(MinGL & window, unsigned & niveau);
 */
void affichageNiveau(MinGL & window, unsigned & niveau);

/**
 * @brief Affiche un message signifiant qu'un niveau a été passé sur la fenêtre.
 * @param[in] window : Fenêtre MinGL
 * @param[in] niveau : Niveau actuel
 * @fn void affichageNiveauGagne(MinGL & window);
 */
void affichageNiveauGagne(MinGL & window);

/**
 * @brief Affiche les billes sur le labyrinthe graphiquement.
 * @param[in] window : Fenêtre MinGL
 * @param[in] gumGrid : Matrice contenant l'emplacement des billes
 * @param[in] NbGum : Nombre de billes
 * @fn void affichageNiveauGagne(MinGL & window);
 */
void showGumInMaze(MinGL & window, const CMat & gumGrid, unsigned & NbGum);

//void affichageGameOver(MinGL & window);

#endif // DISPLAY_H
