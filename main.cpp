#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"

using namespace std;

// FONCTION OBSOLETE ET NON UTILISE (a supprimer plus tard)
//map <string, vector <nsGui::Sprite>> initSpriteMap(const string & sourceFile)
//{
//    ifstream ifs (sourceFile);
//    map <string, vector <nsGui::Sprite>> spriteMap;
//    string str;
//    string title;
//    vector <nsGui::Sprite> spriteList;
//    for (int i = 0; !ifs.eof() ;++i)
//    {
//        getline(ifs,str);
//        if (str == "")
//        {
//            spriteMap[title] = spriteList;
//            spriteList.clear();
//            i = -1;
//        }
//        if (i == 0)
//            title = str;
//        else if (i > 0)
//            spriteList.push_back(nsGui::Sprite (str, nsGraphics::Vec2D(13,13)));
//    }
//    return spriteMap;
//}
//void showSpritePacMan (MinGL & window, vector <nsGui::Sprite> & spriteList, unsigned short & tick)
//{
//    window << spriteList[tick % spriteList.size()];
//    this_thread::sleep_for(chrono::milliseconds(1 / FPS_LIMIT));
//}

map <string, vector <string>> initSpriteMapV2(const string & sourceFile)
{
    ifstream ifs (sourceFile);
    map <string, vector <string>> spriteMap;
    string str;
    string title;
    vector <string> spriteList;
    for (int i = 0; !ifs.eof() ;++i)
    {
        getline(ifs,str);
        if (str == "")
        {
            spriteMap[title] = spriteList;
            spriteList.clear();
            i = -1;
        }
        if (i == 0)
            title = str;
        else if (i > 0)
            spriteList.push_back(str);
    }
    return spriteMap;
}
void showSpritePacManV2 (MinGL & window, vector <string> & spriteList, unsigned short & tick)
{
    nsGui::Sprite spriteName (spriteList[tick % spriteList.size()], nsGraphics::Vec2D(13,13));
    window << spriteName;
    this_thread::sleep_for(chrono::milliseconds(1 / FPS_LIMIT));
}

int main()
{
    // Initialise le système
    MinGL window("PAC-MAN", nsGraphics::Vec2D(672, 744), nsGraphics::Vec2D(120, 120), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    map <string, vector <string>> PacManSprite = initSpriteMapV2("../sae102/res/sprites/pacman/spriteMap");
    nsGui::Sprite maze("../sae102/res/sprites/maze0.si2", nsGraphics::Vec2D(0,0));

    // On fait tourner la boucle tant que la fenêtre est ouverte
    for (unsigned short tick = 0; window.isOpen(); ++tick)
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        //window << maze; //afficher le labyrinthe à chaque fois fait bugger le programme
        showSpritePacManV2(window, PacManSprite["Right"], tick);
        if (tick == 65535)
            tick = 0;

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    return 0;
}
