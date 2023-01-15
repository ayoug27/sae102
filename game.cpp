#define FPS_LIMIT 120
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
#include "affichage.h"


using namespace std;


void game(){

    unsigned score = 0;
    unsigned niveau = 1;
    unsigned vies = 3;

    // Initialise le système
    MinGL window("PAC-MAN", nsGraphics::Vec2D(672, 790), nsGraphics::Vec2D(120, 120), nsGraphics::KBlack);
    window.initGlut();
    window.initGraphic();

    // Variable qui tient le temps de frame
    chrono::microseconds frameTime = chrono::microseconds::zero();

    Entity PacMan;
    Entity RedGhost;
    Entity OrangeGhost;
    Entity PinkGhost;
    Entity BlueGhost;

    bool peutmanger = false;

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
    bool test = false;
    bool WinRound = false;
    bool Dead = false;
    pair <CMat, map<char, CPos>> gridInfo = initEntityMaze("../sae102/res/mazeinitialmap");
    CMat entityGrid = gridInfo.first;
    map<char, CPos> posMap = gridInfo.second;
    CMat gumGrid = initGumMaze("../sae102/res/guminitialmap");
    int tick2 = 0;
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
        unsigned NbGum;
        if (WinRound == true) {
            this_thread::sleep_for(chrono::milliseconds(500000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
            ChangementNiveau(PacMan, RedGhost, OrangeGhost, PinkGhost, BlueGhost, posMap, gumGrid);
        }
        if (Dead)
        {
            window << nsGui::Sprite (PacMan.SpriteMap["Dead"][tick % PacMan.SpriteMap["Dead"].size()], nsGraphics::Vec2D(24*PacMan.Pos.first-12,24*PacMan.Pos.second-12));
            if (tick % PacMan.SpriteMap["Dead"].size() == PacMan.SpriteMap["Dead"].size()-1)
            {
                this_thread::sleep_for(chrono::milliseconds(50000 / FPS_LIMIT) - chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start));
                reinitLevel(PacMan, RedGhost, PinkGhost, OrangeGhost, BlueGhost, posMap);
                Dead = false;
                --vies;
            }
        }
        else {
            showGumInMaze(window,gumGrid,NbGum);
            pacManDirection(window, entityGrid, PacMan);
            pacManMovement(entityGrid, PacMan, tick);

            if(gumGrid[PacMan.Pos.second][PacMan.Pos.first] == KSuperGum){
                peutmanger = true;
                test = true;
            }

            gumEating(PacMan,gumGrid, NbGum);//*************************************************************************
            if (peutmanger == false){
            Dead = isDead(PacMan, RedGhost, BlueGhost, OrangeGhost, PinkGhost);
            }
            if (peutmanger == true && tick2 == 0){
                tick2 = 150;
            }
            if (peutmanger == true && tick2 != 0){
                tick2 -= 1;
            }
            if (peutmanger == true && tick2 == 1){
                peutmanger = false;
            }

            Phase(phase,tick,RedGhost);
            Phase(phase,tick,PinkGhost);
            Phase(phase,tick,OrangeGhost);
            Phase(phase,tick,BlueGhost);


            if (peutmanger == true)
            {

                RedGhost.state = "hide";
                PinkGhost.state = "hide";
                BlueGhost.state = "hide";
                OrangeGhost.state = "hide";

                if (PacMan.Pos == RedGhost.Pos){
                    score += 100;
                    RedGhost.Pos.first = 13;
                    RedGhost.Pos.second = 11;
                }
                if( PacMan.Pos == PinkGhost.Pos){
                    score += 100;
                    PinkGhost.Pos.first = 13;
                    PinkGhost.Pos.second = 11;
                }
                if(PacMan.Pos == BlueGhost.Pos){
                    score += 100;
                    BlueGhost.Pos.first = 13;
                    BlueGhost.Pos.second = 11;
                }
                if (PacMan.Pos == OrangeGhost.Pos){
                    score += 100;
                    OrangeGhost.Pos.first = 13;
                    OrangeGhost.Pos.second = 11;
                }
            }
            if (tick%2 == 0){
                RedGhostMove(RedGhost,PacMan,gridInfo.first);
                PinkGhostMove(PinkGhost,PacMan,gridInfo.first);
                OrangeGhostMove(OrangeGhost,PacMan,gridInfo.first);
                BlueGhostMove(BlueGhost,PacMan,gridInfo.first);

                GhostMovement(entityGrid,RedGhost, tick);
                GhostMovement(entityGrid,BlueGhost, tick);
                GhostMovement(entityGrid,OrangeGhost, tick);
                GhostMovement(entityGrid,PinkGhost, tick);
            }

            window << initSprite(PacMan, entityGrid, tick);
            window << initSprite(RedGhost, entityGrid, tick);
            window << initSprite(BlueGhost, entityGrid, tick);
            window << initSprite(OrangeGhost, entityGrid, tick);
            window << initSprite(PinkGhost, entityGrid, tick);

            affichageScore(window, score);
            affichageVies(PacMan.SpriteMap, window, vies);
            affichageNiveau(window, niveau);
        }
        //cout << RedGhost.viewdirection << "   " << RedGhost.state << endl;
        //        for (unsigned y = 0; y < entityGrid.size(); ++y)
        //                {
        //                    for (unsigned x = 0; x < entityGrid[y].size(); ++x)
        //                    {
        //                        cout << entityGrid[y][x];
        //                    }
        //                    cout << endl;
        //                }
        //        cout << PacMan.Pos.first << "," << PacMan.Pos.second << " " << PacMan.viewdirection << " Taille du Tableau :" << entityGrid.size()-2 << endl;
        if (tick == 65535)
            tick = 0;
        if (NbGum == 0){
            affichageNiveauGagne(window);
            niveau +=1;
            tick = 0;
            WinRound = true;
        }

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
