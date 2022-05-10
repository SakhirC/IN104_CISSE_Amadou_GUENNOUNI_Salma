#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

#define SIZE 9

void modification(int area[SIZE][SIZE]){
    int reponse;
    int x;
    int y;
    int n;

printf("Are you done ? (yes=1 no=other entier : ");
int d=scanf("%d",&reponse);
while(reponse!=1){
    affichage(area);
    printf("Entrez l'abcisse l'ordonnee et le nombre a positionner selon le format x,y,n : : ");
      d= scanf("%u,%u,%u",&x,&y,&n);
      while(x>=SIZE || y>=SIZE || n>=SIZE ){
          printf("Rentrez des cordonnees correcte  : ");
          int d= scanf("%u,%u,%u",&x,&y,&n);
      }
      area[x][y]=n;
      printf("Are you done ? (yes=1 no=other entier : " );
      int d=scanf("%d",&reponse);
    }
}

