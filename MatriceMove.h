#ifndef MATRICEMOVE_H
#define MATRICEMOVE_H
#include "type.h"
#include <vector>
#include <string>
#include <map>
#include "mingl/mingl.h"

std::string pacManviewdirection(MinGL & window, std::string viewdirection);

void move_entity_in_mat(CMat Mat, Entity entity);

#endif // MATRICEMOVE_H
