#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "fill.h"
#include "fill_diag.h"
#include "level.h"
#include "remplissage.h"
#include "modification.h"
#include "affichage.h"
#define SIZE 9
#define K 20

int main(){

    //Mise a zero du temps pour eviter la repetition des sequences aleatoires
    srand(time(NULL));



    //Initialisation de la grille
    int area[SIZE][SIZE];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            area[i][j]=0;
        }
    }


    //Rempllisage de la diagonale
    fill_diag(area);

    //Remplissage de la grille entiere
    bool A=fill(area,0);
    if(A==false){
        printf("bug \n");

    }

    //affichage(area)

    //definition du niveau de la grille
     level(area);
    
    //remplissage progressif de la grille par l'utilisateur
    remplissage(area);
    
    //modification de la grille par l'utilisateur
    modification(area);


    //Verification


    return 0;

}

