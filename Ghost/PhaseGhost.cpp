#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include <vector>
#include "mingl/mingl.h"
/*
 * @date : 15 jav 2023
 * @author : Essalhi Ayoub, Lerouge Robin, Lestrelin Valentin, Brahmi Moundir, Ditlecadet Michael
 * @synopsis: changement de phase
*/

#include "mingl/gui/sprite.h"
#include "GhostH/PhaseGhost.h"
#include "type.h"
#include <cmath>
using namespace std;


void Phase (vector<bool> VecPhase, unsigned short tick,
                    Entity & entity){

    if (tick == 125 && VecPhase[0] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Hunt";}
        VecPhase[0] = true;
    }
    if (tick == 675 && VecPhase[1] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Flee";}
        VecPhase[1] = true;
    }
    if (tick == 850 && VecPhase[2] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Hunt";}
        VecPhase[2] = true;
    }
    if (tick == 1350 && VecPhase[3] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Flee";}
        VecPhase[3] = true;
    }
    if (tick == 1475 && VecPhase[4] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Hunt";}
        VecPhase[4] = true;
    }
    if (tick == 1975 && VecPhase[5] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Flee";}
        VecPhase[5] = true;
    }
    if (tick == 2100 && VecPhase[6] == false)
    {
        if (not(entity.state == "Hide")){entity.state = "Hunt";}
        VecPhase[6] = true;
    }
}
