#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#define height 60
#define width 30
#define nb_ghosts 11

void move(struct ghost allghosts[nb_ghosts], struct PacMan pacman, char area[width][height]){
    int reponse;
    printf("Entrez 1 pour aller en haut, 2 pour le bas,3 pour la gauche et 4 pour ladroite pour quitter: ");
    scanf("%d",&reponse);
    if(reponse==1){
        pacman.nx=0;
        pacman.ny=1;
    }
    else if(reponse==2){
        pacman.nx=0;
        pacman.ny=-1;
    }
    else if(reponse==3){
        pacman.nx=-1;
        pacman.ny=0;
    }
    else if(reponse==4){
        pacman.nx=1;
        pacman.ny=0;
    }
    else{
        pacman.nx=0;
        pacman.ny=0;
    }

    for (int i=0; i<nb_ghosts; i++){
        int a=allghosts[i].coord.x;
        int b=allghosts[i].coord.y;
        int newa=a;
        int newb=b;
        if((strcmp(&area[(a+1)/width ][b], "." )==0)|| (strcmp(&area[(a+1)/width ][b], " ")==0)){ 
            newa=a+1/width;
        }
        else if((strcmp(&area[(a-1)/width ][b] , ".")==0) || (strcmp(&area[(a-1)/width ][b], " ")==0 )){
            newa=a-1/width;
        }
        else if((strcmp(&area[a][(b-1)/height], "." )==0)|| (strcmp(&area[a][(b-1)/height], " ")==0)){
            newb=b-1/height;
        }
        else if((strcmp(&area[a][(b+1)/height], "." )==0)|| (strcmp(&area[a][(b+1)/height] , " ")==0) ){
            newb=b+1/height;
        }

        if(strcmp(&area[newa][newb],".")==0){
            strcpy(&area[newa][newb],"G.");
        }
        else{
            strcpy(&area[newa][newb],"G");
        }

        allghosts[i].coord.x=newa;
        allghosts[i].coord.y=newb;

    };

}