#ifndef DISPLAY_H
#define DISPLAY_H

#include "type.h"

void affichageScore(MinGL & window, unsigned & score);

void affichageVies(std::map <std::string, std::vector <std::string>> & PacManSprite, MinGL & window, unsigned & vies);

void affichageNiveau(MinGL & window, unsigned & niveau);

void affichageNiveauGagne(MinGL & window);

void showGumInMaze(MinGL & window, const CMat & gumGrid, unsigned & NbGum);

//void affichageGameOver(MinGL & window);

#endif // DISPLAY_H
