#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#define height 20
#define width 20
#define number 4



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


