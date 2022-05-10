#include <stdlib.h>
#include <stdio.h>
#define SIZE 9

void affichage(int area[SIZE][SIZE]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",area[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}