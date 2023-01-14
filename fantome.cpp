//*****************************************************************************
//***************************     initialisation     **************************
//*****************************************************************************
#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"

using namespace std;

nsGraphics::Vec2D posPacMan;

struct Entity
{
    map <string, vector <string>> SpriteMap;
    string state;
    unsigned int X;
    unsigned int Y;
};

//*****************************************************************************
//*************************     initialisation map     ************************
//*****************************************************************************
map <string, vector <string>> initSpriteMap (const string & sourceFile)
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

nsGui::Sprite initSprite (vector <string> & spriteList, unsigned short & tick)
{
    nsGui::Sprite spriteName (spriteList[tick % spriteList.size()], posPacMan);
    return spriteName;
}

string pacManState(MinGL & window, string state)
{
    if (window.isPressed({'z', false}))
        return "Top";
    if (window.isPressed({'s', false}))
        return "Bottom";
    if (window.isPressed({'q', false}))
        return "Left";
    if (window.isPressed({'d', false}))
        return "Right";
    return state;
}

nsGui::Sprite pacManComportment(MinGL & window, Entity PacMan, short unsigned tick)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    if (PacMan.state == "Top")
    {
        posPacMan.setY(posPacMan.getY() - 12);
        return initSprite(PacMan.SpriteMap["Top"], tick);
    }
    if (PacMan.state == "Bottom")
    {
        posPacMan.setY(posPacMan.getY() + 12);
        return initSprite(PacMan.SpriteMap["Bottom"], tick);
    }
    if (PacMan.state == "Left")
    {
        posPacMan.setX(posPacMan.getX() - 12);
        return initSprite(PacMan.SpriteMap["Left"], tick);
    }
    if (PacMan.state == "Right")
    {
        posPacMan.setX(posPacMan.getX() + 12);
        return initSprite(PacMan.SpriteMap["Right"], tick);
    }
    return initSprite(PacMan.SpriteMap["Right"], tick);
}

//*****************************************************************************
//******************************     main     *********************************
//*****************************************************************************
int main()
{
    // Initialise le système
    MinGL window("PAC-MAN", nsGraphics::Vec2D(672, 744), nsGraphics::Vec2D(120, 120), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    Entity PacMan;
    Entity RedGhost;
    PacMan.state = "Right";
    PacMan.SpriteMap = initSpriteMap("../sae102/res/sprites/pacman/spriteMap");
    RedGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/redghost/spriteMap");
    nsGui::Sprite maze("../sae102/res/sprites/maze0.si2", nsGraphics::Vec2D(0,0));


    // On fait tourner la boucle tant que la fenêtre est ouverte
    for (unsigned short tick = 0; window.isOpen(); ++tick)
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        window << maze; //afficher le labyrinthe à chaque fois fait bugger le programme
        PacMan.state = pacManState(window, PacMan.state);

        //*********************************************************************
        //************************     code fantome     ************************
        //*********************************************************************





















        nsGui::Sprite pacman = pacManComportment(window, PacMan, tick);
        nsGui::Sprite redghost (RedGhost.SpriteMap["Left"][tick % RedGhost.SpriteMap["Left"].size()], nsGraphics::Vec2D(24*(27-1)-12, 24*(2-1)-12));
        window << pacman;
        window << redghost;
        // cout << posPacMan.getX() << " " << posPacMan.getY() << PacMan.state << endl;
        if (tick == 65535)
            tick = 0;

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(4000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    return 0;
}

// 28 x 31
