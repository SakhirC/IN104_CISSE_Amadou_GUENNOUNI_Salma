#ifndef __MOVE_H__
#define __MOVE_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#define height 60
#define width 30
#define nb_ghosts 11

void move(struct ghost allghosts[nb_ghosts], struct PacMan pacman, char area[width][height]);

#endif
