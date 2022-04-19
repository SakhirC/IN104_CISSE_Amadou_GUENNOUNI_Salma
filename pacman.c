#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define height 20
#define width 20
#define number 4
#define nb_lives 3
#define nb_obstacles 50



struct coor{
    int x;
    int y;
}

struct PacMan{
    struct coor coord;
    int nx;
    int ny;
    int lives;
    int food;
    bool chase;
}

struct ghost{
    struct coor coord;
    int nx;
    int ny;
    bool chase;
}



int main{
    struct ghost inighost=malloc(sizeof(struc ghost));

    struct Pacman pacman=malloc(sizeof(struct PacMan));
    pacman.coord.x=rand()/width;
    pacman.coord.y=rand()/height;
    pacman.chase=false;
    pacman.lives=nb_lives;
    pacman.food=0;
    pacman.nx=0;
    pacman.ny=0;
    
    char area [width][height];
    for (int i=0; i<nb_obstacles; ++i) {
        a=rand()/width;
        b=rand()/height;
        while area[a][b] != NULL {
        area[a][b]="#";
        }
    }
}
