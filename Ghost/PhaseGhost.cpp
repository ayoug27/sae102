//*****************************************************************************
//*************************     Initialisation     ****************************
//*****************************************************************************
#include <iostream>
#include <thread>
#include <fstream>
#include <map>
#include <vector>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"
#include "GhostH/PhaseGhost.h"
#include "type.h"
#include <cmath>
using namespace std;


void Phase (vector<bool> VecPhase, unsigned short tick,
                    Entity & entity){

    if (tick == 125 && VecPhase[0] == false)
    {
        if (not(entity.state == "hide")){entity.state = "hunt";}
        VecPhase[0] = true;
    }
    if (tick == 675 && VecPhase[1] == false)
    {
        if (not(entity.state == "hide")){entity.state = "flee";}
        VecPhase[1] = true;
    }
    if (tick == 850 && VecPhase[2] == false)
    {
        if (not(entity.state == "hide")){entity.state = "hunt";}
        VecPhase[2] = true;
    }
    if (tick == 1350 && VecPhase[3] == false)
    {
        if (not(entity.state == "hide")){entity.state = "flee";}
        VecPhase[3] = true;
    }
    if (tick == 1475 && VecPhase[4] == false)
    {
        if (not(entity.state == "hide")){entity.state = "hunt";}
        VecPhase[4] = true;
    }
    if (tick == 1975 && VecPhase[5] == false)
    {
        if (not(entity.state == "hide")){entity.state = "flee";}
        VecPhase[5] = true;
    }
    if (tick == 2100 && VecPhase[6] == false)
    {
        if (not(entity.state == "hide")){entity.state = "hunt";}
        VecPhase[6] = true;
    }
}
