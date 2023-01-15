#ifndef AFFICHAGE_H
#define AFFICHAGE_H
#include "type.h"

void affichageScore(MinGL & window, unsigned & score);

void affichageVies(std::map <std::string, std::vector <std::string>> & PacManSprite, MinGL & window, unsigned & vies);

void affichageNiveau(MinGL & window, unsigned & niveau);

void affichageNiveauGagne(MinGL & window);

//void affichageGameOver(MinGL & window);

#endif // AFFICHAGE_H
