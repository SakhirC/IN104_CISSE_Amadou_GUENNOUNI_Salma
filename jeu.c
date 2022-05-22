#include <stdio.h>
#include "pacman.h"
#include "tictactoe.h"
#include "sudoku.h"


int main(){
    int i=0;
    int a;
    do{
        printf("Choisissez le jeu auquel vous voulez jouer 1=Pacman 2=Sudoku 3=ticactoe : ");
        scanf("%d",&i);
        } while(i!=1 && i!= 2 && i!= 3);


    if(i==1){
        a=play_pacman();

    }

    if(i==2){
        a=play_sudoku();
    }

    if(i==3){
        a=play_tictactoe();
    }

    return a;
}