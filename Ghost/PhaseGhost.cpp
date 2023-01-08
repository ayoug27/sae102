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
                    Entity RedGhost,
                    Entity PinkGhost,
                    Entity BlueGhost,
                    Entity OrangeGhost){
    if (tick == 175 && VecPhase[0] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        VecPhase[0] = true;
    }
    if (tick == 675 && VecPhase[1] == false)
    {
        RedGhost.state = "flee";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "flee";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "flee";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "flee";}
        VecPhase[1] = true;
    }
    if (tick == 850 && VecPhase[2] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        VecPhase[2] = true;
    }
    if (tick == 1350 && VecPhase[3] == false)
    {
        RedGhost.state = "flee";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "flee";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "flee";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "flee";}
        VecPhase[3] = true;
    }
    if (tick == 1475 && VecPhase[4] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        VecPhase[4] = true;
    }
    if (tick == 1975 && VecPhase[5] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "flee";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "flee";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "flee";}
        VecPhase[5] = true;
    }
    if (tick == 2100 && VecPhase[6] == false)
    {
        RedGhost.state = "hunt";
        if (not(PinkGhost.state == "hide")){PinkGhost.state = "hunt";}
        if (not(BlueGhost.state == "hide")){BlueGhost.state = "hunt";}
        if (not(OrangeGhost.state == "hide")){OrangeGhost.state = "hunt";}
        VecPhase[6] = true;
    }
}
