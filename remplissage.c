#include <stdlib.h>
#include <stdio.h>

#include <stdbool.h>
#include "is_fill.h"
#include "affichage.h"
#define SIZE 9


void remplissage(int area[SIZE][SIZE]){
    int x;
    int y;
    int n;

    bool rempli=is_fill(area);

    while(rempli==false){
        affichage(area);
        printf("Entrez l'abcisse l'ordonnee et le nombre a positionner selon le format x,y,n: ");
      int d= scanf("%u,%u,%u",&x,&y,&n);
      while(x>=SIZE || y>=SIZE || n>=SIZE || area[x][y]!=0){
          printf("Rentrez des cordonnees correctes libres : ");
          int d= scanf("%u,%u,%u",&x,&y,&n);
      }
      area[x][y]=n;
      rempli=is_fill(area);
    }

}