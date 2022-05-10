#ifndef __INIT_GHOSTS_H__
#define __INIT_GHOSTS_H__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#define height 60
#define width 30
#define nb_ghosts 11

void init_ghosts(struct ghost allghosts[nb_ghosts],char area[width][height]);

#endif

