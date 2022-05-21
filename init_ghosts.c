#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#define height 60
#define width 30
#define nb_ghosts 40

void init_ghosts(struct ghost allghosts[nb_ghosts], char area[width][height]) {
    struct ghost g;
    



    for (int i=0; i<nb_ghosts; i++){
    g.chase= true;
    int a=rand()%width;
    int b=rand()%height;
    while (area[a][b]=='#'  /* ||  area[a][b]=='G.' */ || area[a][b]=='G'  ){
    a=rand()%width;
    b=rand()%height;       
    }
    g.coord.x=a;
    g.coord.y=b;
    allghosts[i]=g;
    area[a][b]='G';
    }

      for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                
            if(area[i][j]==' '  /* &&   area[i][j]='G.' */ ){
                area[i][j]='.';
            }
            }

        };  





}