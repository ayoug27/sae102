#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/shape/rectangle.h"
#include "type.h"
#include "mingl/gui/text.h"
#include "mingl/shape/line.h"
#include "DisplayH/Display.h"

using namespace std;

void affichageScore(MinGL & window, unsigned & score) {
    window << nsGui::Text(nsGraphics::Vec2D(20, 772), "SCORE : ", nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
    window << nsGui::Text(nsGraphics::Vec2D(100, 772), to_string(score) ,nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

void affichageVies(map <std::string, std::vector <std::string>> & PacManSpriteMap, MinGL & window, unsigned & vies) {
    nsGui::Sprite pacmanVie1 (PacManSpriteMap["Right"][1], nsGraphics::Vec2D(250, 746));
    nsGui::Sprite pacmanVie2 (PacManSpriteMap["Right"][1], nsGraphics::Vec2D(300, 746));
    nsGui::Sprite pacmanVie3 (PacManSpriteMap["Right"][1], nsGraphics::Vec2D(350, 746));
    if (vies == 3) {
        window << pacmanVie1;
        window << pacmanVie2;
        window << pacmanVie3; }
    else if (vies == 2) {
        window << pacmanVie1;
        window << pacmanVie2;
    }
    else if (vies == 1) {
        window << pacmanVie1;
    }
}

void affichageNiveau(MinGL & window, unsigned & niveau) {
    window << nsGui::Text(nsGraphics::Vec2D(550, 772), "NIVEAU : ", nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
    window << nsGui::Text(nsGraphics::Vec2D(635, 772), to_string(niveau) ,nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
}

void affichageNiveauGagne(MinGL & window){
    window << nsShape::Rectangle(nsGraphics::Vec2D(0, 0), nsGraphics::Vec2D(672, 790), nsGraphics::KBlack);
    window << nsGui::Text(nsGraphics::Vec2D(250, 376), "Vous avez fini ce niveau", nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);
    window << nsGui::Text(nsGraphics::Vec2D(285, 396), "Niveau suivant", nsGraphics::KWhite, nsGui::GlutFont::BITMAP_HELVETICA_18);

}

void showGumInMaze(MinGL & window, const CMat & gumGrid, unsigned & NbGum)
{
    NbGum = 0;
    for (unsigned y = 0; y < gumGrid.size(); ++y)
    {
        for (unsigned x = 0; x < gumGrid[y].size(); ++x)
        {
            if (gumGrid[y][x] == KGum){
                window << nsShape::Rectangle(nsGraphics::Vec2D(24*x+9, 24*y+9), nsGraphics::Vec2D(24*x+15, 24*y+15), nsGraphics::KWhite);
                NbGum +=1;
            }
            if (gumGrid[y][x] == KSuperGum){
                window << nsGui::Sprite ("../sae102/res/sprites/supergum.si2", nsGraphics::Vec2D(24*x,24*y));
                NbGum +=1;
            }
        }
    }
}

