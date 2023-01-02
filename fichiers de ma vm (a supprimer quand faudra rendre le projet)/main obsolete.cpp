#define FPS_LIMIT 60

#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"

using namespace std;

nsGraphics::Vec2D RectPos;

struct Entity
{
    map <string, vector <string>> SpriteMap;
    unsigned int X;
    unsigned int Y;
    nsGraphics::Vec2D posWindow;
};

map <string, vector <string>> initSpriteMap(const string & sourceFile)
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

nsGui::Sprite initSprite (vector <string> & spriteList, nsGraphics::Vec2D posWindow , unsigned short & tick)
{
    nsGui::Sprite spriteName (spriteList[tick % spriteList.size()], posWindow);
    return spriteName;
}

nsGui::Sprite pacManControl(MinGL & window, Entity Pacman, short unsigned tick)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    if (window.isPressed({'z', false}))
    {
        Pacman.posWindow.setY(Pacman.posWindow.getY() - 20);
        return initSprite(Pacman.SpriteMap["Top"], Pacman.posWindow, tick);
    }
    if (window.isPressed({'s', false}))
    {
        Pacman.posWindow.setY(Pacman.posWindow.getY() + 20);
        return initSprite(Pacman.SpriteMap["Bottom"], Pacman.posWindow, tick);
    }
    if (window.isPressed({'q', false}))
    {
        Pacman.posWindow.setX(Pacman.posWindow.getX() - 20);
        return initSprite(Pacman.SpriteMap["Left"], Pacman.posWindow, tick);
    }
    if (window.isPressed({'d', false}))
    {
        Pacman.posWindow.setX(Pacman.posWindow.getX() + 20);
        return initSprite(Pacman.SpriteMap["Right"], Pacman.posWindow, tick);
    }
    return initSprite(Pacman.SpriteMap["Right"], Pacman.posWindow, tick);
}

int main()
{
    // Initialise le système
    MinGL window("PAC-MAN", nsGraphics::Vec2D(672, 744), nsGraphics::Vec2D(120, 120), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    Entity Pacman;
    Entity RedGhost;
    Pacman.SpriteMap = initSpriteMap("../sae102/res/sprites/pacman/spriteMap");
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
        nsGui::Sprite pacman = pacManControl(window, Pacman, tick);
        nsGui::Sprite redghost (RedGhost.SpriteMap["Left"][tick % RedGhost.SpriteMap["Left"].size()], nsGraphics::Vec2D(195, 195));
        window << pacman;
        window << redghost;

        if (tick == 65535)
            tick = 0;

        // On finit la frame en cours
        window.finishFrame();

        // On vide la queue d'évènements
        window.getEventManager().clearEvents();

        // On attend un peu pour limiter le framerate et soulager le CPU
        this_thread::sleep_for(chrono::milliseconds(1 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));

        // On récupère le temps de frame
        frameTime = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start);
    }
    return 0;
}
