#ifndef __MOVE_PAC_H__
#define __MOVE_PAC_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#include "move.h"

#define height 60
#define width 30
#define nb_ghosts 40

void move_pac(struct ghost allghosts[nb_ghosts],struct PacMan pacman, char area[width][height]);


#endif
