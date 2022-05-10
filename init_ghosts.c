#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#define height 60
#define width 30
#define nb_ghosts 11

void init_ghosts(struct ghost allghosts[nb_ghosts],char area[width][height]) {
    struct ghost g;
    



    for (int i=0; i<nb_ghosts; i++){
    g.chase= true;
    int a=rand()%width;
    int b=rand()%height;
    while ((strcmp(&area[a][b],"#" )==0)  || (strcmp(&area[a][b],"G.")==0) || (strcmp(&area[a][b],"G")==0)  || (a == 1 && b == 1) ){
    a=rand()%width;
    b=rand()%height;       
    }
    g.coord.x=a;
    g.coord.y=b;
    allghosts[i]=g;
    strcpy(&area[a][b],"G ");
    }

     /* for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                
            if((strcmp(&area[i][j],&area[0][0] )!=0)  && (strcmp(&area[i][j],"G.")!=0)   && (i != 1 && j != 1)){
                strcpy(&area[i][j],".");
            }
            }

        };  */





}