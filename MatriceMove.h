#ifndef MATRICEMOVE_H
#define MATRICEMOVE_H
#include "type.h"
#include <vector>
#include <string>
#include <map>
#include "mingl/mingl.h"
#include "mingl/gui/sprite.h"


    /**
     * @bried this is ghost
    */
    /**
     * @brief RedGhostMove : blablka
     * @param RedGhost : test
     * @param PacMan : pacman
     * @param map
     */

std::string pacManviewdirection(MinGL & window, std::string viewdirection);

void move_entity_in_mat(CMat Mat, Entity entity);

nsGui::Sprite pacManComportment(Entity PacMan, short unsigned tick);

nsGui::Sprite initSprite (std::vector <std::string> & spriteList, unsigned short & tick);

#endif // MATRICEMOVE_H
