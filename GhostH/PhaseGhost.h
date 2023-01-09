#ifndef PHASEGHOST_H
#define PHASEGHOST_H
#include "../type.h"
#include <vector>
#include <string>
#include <map>

/**
 * @bried this is ghost
*/
/**
 * @brief RedGhostMove : blablka
 * @param RedGhost : test
 * @param PacMan : pacman
 * @param map
 */


void Phase (std::vector<bool> VecPhase, unsigned short tick,
                    Entity RedGhost,
                    Entity PinkGhost,
                    Entity BlueGhost,
                    Entity OrangeGhost);



#endif // PHASEGHOST_H
