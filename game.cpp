//*****************************************************************************
//*************************     Initialisation     ****************************
//*****************************************************************************
#define FPS_LIMIT 120

#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "type.h"
#include "iaghost.h"
#include "GhostH/PhaseGhost.h"
#include "GhostH/GhostMove.h"
#include "MatriceMove.h"
#include "init.h"
#include "game.h"


using namespace std;




void game(){


    pair <CMat, map<char, CPos>> gridInfo = initEntityMaze("../sae102/res/mazeinitialmap");
    CMat entityGrid = gridInfo.first;
//    map<char, CPos> posMap = gridInfo.second;
    CMat gumGrid = initGumMaze("../sae102/res/guminitialmap");
//    Entity PacMan;
//    Entity RedGhost;
    map<char, CPos> posMap = gridInfo.second;
    // Initialise le système
    MinGL window("PAC-MAN", nsGraphics::Vec2D(672, 744), nsGraphics::Vec2D(120, 120), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    //*****************************************************************************
    //**************************     Init entity     ******************************
    //*****************************************************************************

    // PacMan
    Entity PacMan;
    PacMan.Pos = posMap[PacMan.ident];
    posPacMan.setX(24*PacMan.Pos.first-12);
    posPacMan.setY(24*PacMan.Pos.second-12);
    PacMan.viewdirection = "Left"; //etat
    PacMan.ident = 'P';
    PacMan.SpriteMap = initSpriteMap("../sae102/res/sprites/pacman/spriteMap");

    // RedGhost
    Entity RedGhost;
    RedGhost.Pos = posMap[RedGhost.ident];
    RedGhost.Pos.first = 13;  //coordonnee X
    RedGhost.Pos.second = 11; //coordonnee Y
    RedGhost.state = "hunt";  //etat
    RedGhost.ident = 'R';
    RedGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/redghost/spriteMap");

    // PinkGhost
    Entity PinkGhost;
    // PinkGhost.Pos.first = 13;  //coordonnee X
    // PinkGhost.Pos.second = 14; //coordonnee Y
    PinkGhost.state = "hide";  //etat

    // OrangeGhost
    Entity OrangeGhost;
    // OrangeGhost.Pos.first = 15;  //coordonnee X
    // OrangeGhost.Pos.second = 14; //coordonnee Y
    OrangeGhost.state = "hide";  //etat

    // BlueGhost
    Entity BlueGhost;
    // BlueGhost.Pos.first = 11;  //coordonnee X
    // BlueGhost.Pos.second = 14; //coordonnee Y
    BlueGhost.state = "hide";  //etat

    // Maze
    nsGui::Sprite maze("../sae102/res/sprites/maze0.si2", nsGraphics::Vec2D(0,0)); //sprite

    vector<bool> phase = {false,false,false,false,false,false,false};


    //     On fait tourner la boucle tant que la fenêtre est ouverte
    for (unsigned short tick = 0; window.isOpen(); ++tick)
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        window << maze; //afficher le labyrinthe à chaque fois fait bugger le programme

        //*****************************************************************************
        //**********************     PacMan deplacement     ***************************
        //*****************************************************************************

        PacMan.viewdirection = pacManviewdirection(window, PacMan.viewdirection);
        nsGui::Sprite pacman = pacManComportment(PacMan, tick);
        nsGui::Sprite redghost (RedGhost.SpriteMap["Left"][tick % RedGhost.SpriteMap["Left"].size()], nsGraphics::Vec2D(24*(27-1)-12, 24*(2-1)-12));

    //*****************************************************************************
    //***********************     ghost deplacement     ***************************
    //*****************************************************************************

    Phase(phase,tick,RedGhost,PinkGhost,BlueGhost,OrangeGhost);

    RedGhostMove(RedGhost,PacMan,gridInfo.first);
    PinkGhostMove(PinkGhost,PacMan,gridInfo.first);
    OrangeGhostMove(OrangeGhost,PacMan,gridInfo.first);
    BlueGhostMove(BlueGhost,PacMan,gridInfo.first);


    //*****************************************************************************
    //*****************************     autre     *********************************
    //*****************************************************************************
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
}

// 28 x 31
