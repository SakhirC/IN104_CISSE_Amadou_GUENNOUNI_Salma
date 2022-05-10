#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"

#define height 60
#define width 30
#define nb_ghosts 11


void move_pac(struct ghost allghosts[nb_ghosts], struct PacMan pacman, char area[width][height]){
    strcpy(&area[pacman.coord.x][pacman.coord.y]," ");
    move(allghosts,  pacman, area);
        if(strcmp(&area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny],"#")==0 || (strcmp(&area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny],"G")==0 )||(strcmp(&area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny],"G.")==0)){
            pacman.coord.x=1;
            pacman.coord.y=1;
            pacman.lives=pacman.lives-1;

        }
        else{
            pacman.coord.x=pacman.coord.x+pacman.nx;
            pacman.coord.y=pacman.coord.y+pacman.ny;
            if(strcmp(&area[pacman.coord.x][pacman.coord.y],".")==0){
                pacman.food=pacman.food+1;
            }
            strcpy(&area[pacman.coord.x][pacman.coord.y],"P");
        }
    
}

