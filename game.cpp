#define FPS_LIMIT 10
#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "mingl/shape/rectangle.h"
#include "type.h"
#include "fonction.h"
#include "GhostH/GhostMove.h"
#include "GhostH/iaghost.h"
#include "GhostH/PhaseGhost.h"


using namespace std;


void game(){
    // Initialise le système
    MinGL window("PAC-MAN", nsGraphics::Vec2D(672, 744), nsGraphics::Vec2D(120, 120), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    Entity PacMan;
    Entity RedGhost;
    Entity OrangeGhost;
    Entity PinkGhost;
    Entity BlueGhost;

    PacMan.viewdirection = "Left";
    PacMan.ident = 'P';
    PacMan.SpriteMap = initSpriteMap("../sae102/res/sprites/pacman/spriteMap");
    RedGhost.state = "flee";
    RedGhost.viewdirection = "Left";
    RedGhost.ident = 'R';
    RedGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/redghost/spriteMap");
    OrangeGhost.state = "flee";
    OrangeGhost.viewdirection = "Top";
    OrangeGhost.ident = 'O';
    OrangeGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/orangeghost/spriteMap");
    PinkGhost.state = "flee";
    PinkGhost.viewdirection = "Bottom";
    PinkGhost.ident = 'K';
    PinkGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/pinkghost/spriteMap");
    BlueGhost.state = "flee";
    BlueGhost.viewdirection = "Bottom";
    BlueGhost.ident = 'B';
    BlueGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/blueghost/spriteMap");

    pair <CMat, map<char, CPos>> gridInfo = initEntityMaze("../sae102/res/mazeinitialmap");
    CMat entityGrid = gridInfo.first;
    map<char, CPos> posMap = gridInfo.second;
    CMat gumGrid = initGumMaze("../sae102/res/guminitialmap");

    PacMan.Pos = posMap[PacMan.ident];
    RedGhost.Pos = posMap[RedGhost.ident];
    OrangeGhost.Pos = posMap[OrangeGhost.ident];
    PinkGhost.Pos = posMap[PinkGhost.ident];
    BlueGhost.Pos = posMap[BlueGhost.ident];
    vector<bool> phase = {false,false,false,false,false,false,false};
    nsGui::Sprite maze("../sae102/res/sprites/maze0.si2", nsGraphics::Vec2D(0,0));
    //     On fait tourner la boucle tant que la fenêtre est ouverte
    for (unsigned short tick = 0; window.isOpen(); ++tick)
    {
        // Récupère l'heure actuelle
        chrono::time_point<chrono::steady_clock> start = chrono::steady_clock::now();

        // On efface la fenêtre
        window.clearScreen();

        window << maze; //afficher le labyrinthe à chaque fois fait bugger le programme

        showGumInMaze(window,gumGrid);
        pacManDirection(window, entityGrid, PacMan);
        pacManMovement(entityGrid, PacMan, tick);
        gumEating(PacMan,gumGrid);

        Phase(phase,tick,RedGhost);
        Phase(phase,tick,PinkGhost);
        Phase(phase,tick,OrangeGhost);
        Phase(phase,tick,BlueGhost);


        RedGhostMove(RedGhost,PacMan,gridInfo.first);
        PinkGhostMove(PinkGhost,PacMan,gridInfo.first);
        OrangeGhostMove(OrangeGhost,PacMan,gridInfo.first);
        BlueGhostMove(BlueGhost,PacMan,gridInfo.first);

        pacManMovement(entityGrid,RedGhost, tick);
        pacManMovement(entityGrid,BlueGhost, tick);
        pacManMovement(entityGrid,OrangeGhost, tick);
        pacManMovement(entityGrid,PinkGhost, tick);


        window << initSprite(PacMan, entityGrid, tick);
        window << initSprite(RedGhost, entityGrid, tick);
        window << initSprite(BlueGhost, entityGrid, tick);
        window << initSprite(OrangeGhost, entityGrid, tick);
        window << initSprite(PinkGhost, entityGrid, tick);

        //cout << RedGhost.viewdirection << "   " << RedGhost.state << endl;
        for (unsigned y = 0; y < entityGrid.size(); ++y)
                {
                    for (unsigned x = 0; x < entityGrid[y].size(); ++x)
                    {
                        cout << entityGrid[y][x];
                    }
                    cout << endl;
                }
        //        cout << PacMan.Pos.first << "," << PacMan.Pos.second << " " << PacMan.viewdirection << " Taille du Tableau :" << entityGrid.size()-2 << endl;
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
}
