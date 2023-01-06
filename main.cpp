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

using namespace std;

typedef std::vector <char> CVLine; // ligne
typedef std::vector <CVLine> CMat; // grille
typedef std::pair <unsigned, unsigned> CPos;

nsGraphics::Vec2D posPacMan;


//*****************************************************************************
//**********************    init animation sprite     *************************
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

//*****************************************************************************
//***************************     Direction     *******************************
//*****************************************************************************
string pacManviewdirection(MinGL & window, string viewdirection)
{
    if (window.isPressed({'z', false}))
        return "Top";
    if (window.isPressed({'s', false}))
        return "Bottom";
    if (window.isPressed({'q', false}))
        return "Left";
    if (window.isPressed({'d', false}))
        return "Right";
    return viewdirection;
}

void move_entity_in_mat(CMat Mat, Entity entity){
    Mat[entity.Pos.second][entity.Pos.first] = KEmpty;
    if (entity.viewdirection == "Top"){
        if (Mat[entity.Pos.second-1][entity.Pos.first]!= KMur){
            Mat[entity.Pos.second-1][entity.Pos.first] = entity.ident;
            entity.Pos.second -=1;
        }
    }
    if (entity.viewdirection == "Right"){
        if (Mat[entity.Pos.second][entity.Pos.first+1]!= KMur){
            if (entity.Pos.first+1 > Mat[entity.Pos.second].size()-1){
                Mat[entity.Pos.second][0]= entity.ident;
                entity.Pos.first = 0;
            }
            else {
                Mat[entity.Pos.second][entity.Pos.first+1] = entity.ident;
                entity.Pos.first +=1;
            }
        }
    }
    if (entity.viewdirection == "Bottom"){
        if (Mat[entity.Pos.second+1][entity.Pos.first]!= KMur){
            Mat[entity.Pos.second+1][entity.Pos.first] = entity.ident;
            entity.Pos.second +=1;
        }
    }
    if (entity.viewdirection == "Left"){
        if (Mat[entity.Pos.second][entity.Pos.first-1]!= KMur){
            if (entity.Pos.first-1 < 0){
                Mat[entity.Pos.second][Mat[entity.Pos.second].size()-1]= entity.ident;
                entity.Pos.first = Mat[entity.Pos.second].size()-1;
            }
            else {
                Mat[entity.Pos.second][entity.Pos.first-1] = entity.ident;
                entity.Pos.first -=1;
            }
        }
    }
}

//*****************************************************************************
//************************     animation sprite     ***************************
//*****************************************************************************
nsGui::Sprite initSprite (vector <string> & spriteList, unsigned short & tick)
{
    nsGui::Sprite spriteName (spriteList[tick % spriteList.size()], posPacMan);
    return spriteName;
}

nsGui::Sprite pacManComportment(Entity PacMan, short unsigned tick)
{
    // On vérifie si ZQSD est pressé, et met a jour la position
    if (PacMan.viewdirection == "Top")
    {
        posPacMan.setY(posPacMan.getY() - 12);
        return initSprite(PacMan.SpriteMap["Top"], tick);
    }
    if (PacMan.viewdirection == "Bottom")
    {
        posPacMan.setY(posPacMan.getY() + 12);
        return initSprite(PacMan.SpriteMap["Bottom"], tick);
    }
    if (PacMan.viewdirection == "Left")
    {
        posPacMan.setX(posPacMan.getX() - 12);
        return initSprite(PacMan.SpriteMap["Left"], tick);
    }
    if (PacMan.viewdirection == "Right")
    {
        posPacMan.setX(posPacMan.getX() + 12);
        return initSprite(PacMan.SpriteMap["Right"], tick);
    }
    return initSprite(PacMan.SpriteMap["Right"], tick);
}

//*****************************************************************************
//****************************     init maze     ******************************
//*****************************************************************************
pair <CMat, map<char, CPos>> initEntityMaze (const string & sourceFile)
{
    pair <CMat, map<char, CPos>> gridInfo;
    CVLine maze_line;
    string line;
    CMat mat_maze;
    map<char, CPos> posMap;
    CPos Pos;
    ifstream ifs (sourceFile);
    while (!ifs.eof())
    {
        getline(ifs,line);
        for (unsigned i = 0; i < line.size(); ++i)
        {
            maze_line.push_back(line[i]);
            if (line[i] == 'P' || line[i] == 'R' || line[i] == 'B' || line[i] == 'K' || line[i] == 'O')
            {
                Pos.first = maze_line.size()-1;
                Pos.second = mat_maze.size();
                posMap[line[i]] = Pos;
            }
        }
        mat_maze.push_back(maze_line);
        maze_line.clear();
    }
    gridInfo.first = mat_maze;
    gridInfo.second = posMap;
    return gridInfo;
}

CMat initGumMaze(const string & sourceFile)
{
    ifstream ifs (sourceFile);
    vector<char> maze_line;
    string line;
    CMat mat_maze;
    while (!ifs.eof())
    {
        getline(ifs,line);
        for (unsigned i = 0; i < line.size(); ++i)
            maze_line.push_back(line[i]);
        mat_maze.push_back(maze_line);
        maze_line.clear();
    }
    return mat_maze;
}

//*****************************************************************************
//******************************     Main     *********************************
//*****************************************************************************
int main()
{
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
    // PacMan.Pos.first = 13;  //coordonnee X
    // PacMan.Pos.second = 23; //coordonnee Y
    PacMan.viewdirection = "Right"; //etat
    PacMan.SpriteMap = initSpriteMap("../sae102/res/sprites/pacman/spriteMap"); //sprite
    
    // RedGhost
    Entity RedGhost;
    // RedGhost.Pos.first = 13;  //coordonnee X
    // RedGhost.Pos.second = 11; //coordonnee Y
    RedGhost.state = "hunt";  //etat
    RedGhost.SpriteMap = initSpriteMap("../sae102/res/sprites/redghost/spriteMap"); //sprite
    
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

    pair <CMat, map<char, CPos>> gridInfo = initEntityMaze("../sae102/res/mazeinitialmap");
    CMat entityGrid = gridInfo.first;
    map<char, CPos> posMap = gridInfo.second;

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

    //*************************************************************************
    //***************************     Phase     *******************************
    //*************************************************************************
    if (tick == 175 && phase[0] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        phase[0] = true;
    }
    if (tick == 675 && phase[1] == false)
    {
        RedGhost.state = "flee";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "flee";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "flee";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "flee";}
        phase[1] = true;
    }
    if (tick == 850 && phase[2] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        phase[2] = true;
    }
    if (tick == 1350 && phase[3] == false)
    {
        RedGhost.state = "flee";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "flee";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "flee";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "flee";}
        phase[3] = true;
    }
    if (tick == 1475 && phase[4] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        phase[4] = true;
    }
    if (tick == 1975 && phase[5] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "flee";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "flee";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "flee";}
        phase[5] = true;
    }
    if (tick == 2100 && phase[6] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        phase[6] = true;
    }

    //*************************************************************************
    //****************************     RED     ********************************
    //*************************************************************************
//    if (RedGhost.state == "hunt"){
//        vector<bool> intersection;
//        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
//        vector<unsigned> coordonnee;
//        coordonnee = REDMOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,PacMan.Pos.second,PacMan.Pos.first);
//        RedGhost.Pos.first = coordonnee[1];
//        RedGhost.Pos.second = coordonnee[0];
//    }
//    if (RedGhost.state == "flee"){
//        vector<bool> intersection;
//        intersection = nbsortie(RedGhost.Pos.second,RedGhost.Pos.first,map);
//        vector<unsigned> coordonnee;
//        coordonnee = REDMOVE(intersection,RedGhost.Pos.second,RedGhost.Pos.first,28,0);
//        RedGhost.Pos.first = coordonnee[1];
//        RedGhost.Pos.second = coordonnee[0];
//    }
    if (RedGhost.state == "kill"){

    }
    //*************************************************************************
    //****************************     PINK     *******************************
    //*************************************************************************
    if (RedGhost.state == "hunt"){

    }

    if (RedGhost.state == "hide"){

    }
    if (RedGhost.state == "flee"){

    }
    if (RedGhost.state == "kill"){

    }

    //*************************************************************************
    //**************************     Orange     *******************************
    //*************************************************************************
    if (RedGhost.state == "hunt"){

    }
    if (RedGhost.state == "hide"){

    }
    if (RedGhost.state == "flee"){

    }
    if (RedGhost.state == "kill"){

    }

    //*************************************************************************
    //***************************     Blue     ********************************
    //*************************************************************************
    if (RedGhost.state == "hunt"){

    }
    if (RedGhost.state == "hide"){

    }
    if (RedGhost.state == "flee"){

    }
    if (RedGhost.state == "kill"){

    }





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
