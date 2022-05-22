#ifndef __PACMAN_H__
#define __PACMAN_H__


#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#define height 60
#define width 30
#define nb_ghosts 40
#define nb_lives 5
#define nb_obstacles 50


void affichage_pac(char area[width][height]);


bool check(struct PacMan pacman, char area[width][height]);


void init_ghosts(struct ghost allghosts[nb_ghosts], char area[width][height]);


void move();


void move_pac();

int play_pacman();

#endif






