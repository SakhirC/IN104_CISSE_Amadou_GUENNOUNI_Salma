#ifndef __STRUCTURE_H__
#define __STRUCTURE_H__

struct coor{
    int x;
    int y;
};

struct PacMan{
    struct coor coord;
    int nx;
    int ny;
    int lives;
    int food;
    bool chase;
};

struct ghost{
    struct coor coord;
    int nx;
    int ny;
    bool chase;
};




#endif