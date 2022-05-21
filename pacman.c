#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#include "init_ghosts.h"
 /*#include "move.h"
#include "move_pac.h"  */
#define height 60
#define width 30
#define nb_ghosts 40
#define nb_lives 5
#define nb_obstacles 50



bool check(struct PacMan pacman, char area[width][height]){
    if(pacman.lives<0){
        printf("Vous avez perdu en ayant %d comme score \n",pacman.food);
        return false;
    }
    else{
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                printf("%c",area[i][j]);
            }
            printf("\n");
        }
    }
    return true;
}

void affichage(char area[width][height]){
    for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                printf("%c",area[i][j]);
            }
            printf("\n");
        };


}

struct ghost allghosts[nb_ghosts];


    struct PacMan pacman = {
                           {
                              .x = 1,
                              .y = 1,
                           },
                           .nx = 0,
                           .ny = 0,
                           .lives = 3,
                           .food=0,
                           .chase= false
                         };

    char area [width][height]=
    {
   { "############################################################" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        # # # # #          #             # # # # # #      #" },
   { "#        #       #         # #            #                #" },
   { "#        #       #        #   #           #                #" },
   { "#        # # # # #       #     #          #                #" },
   { "#        #              # # # # #         #                #" },
   { "#        #             #         #        #                #" },
   { "#        #            #           #       #                #" },
   { "#        #           #             #      #                #" },
   { "#        #          #               #     # # # # # #      #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#        ##        ##           #          ##        #     #" },
   { "#        # #      # #          # #         # #       #     #" },
   { "#        #  #    #  #         #   #        #  #      #     #" },
   { "#        #    # #   #        #     #       #   #     #     #" },
   { "#        #     #    #       # # # # #      #    #    #     #" },
   { "#        #          #      #         #     #     #   #     #" },
   { "#        #          #     #           #    #      #  #     #" },
   { "#        #          #    #             #   #       # #     #" },
   { "#        #          #   #               #  #        ##     #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "#                                                          #" },
   { "############################################################" }};





void move(){
        int reponse;
    
        printf("Entrez 1 pour aller en haut, 2 pour le bas, 3 pour la gauche et 4 pour la droite : ");
        scanf("%d",&reponse); 
        if(reponse==1){
        pacman.nx=-1;
        pacman.ny=0;
        }
        else if(reponse==2){
        pacman.nx=1;
        pacman.ny=0;
        }
        else if(reponse==3){
        pacman.nx=0;
        pacman.ny=-1;
        }
        else if(reponse==4){
        pacman.nx=0;
        pacman.ny=1;
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
        if(area[(a+1)%width ][b]=='.' || area[(a+1)%width ][b]==' '){ 
            newa=(a+1)%width;
        }
        else if(area[(a-1)%width ][b]=='.' || area[(a-1)%width ][b]== ' ' ){
            newa=(a-1)%width;
        }
        else if(area[a][(b-1)%height]=='.'|| area[a][(b-1)%height]==' '){
            newb=(b-1)%height;
        }
        else if(area[a][(b+1)%height]=='.'|| area[a][(b+1)%height]==' ' ){
            newb=(b+1)%height;
        }

        /* if(area[newa][newb]=='.'){
            area[newa][newb]='G.';
        }
        else{ */
            area[a][b]='.';
            area[newa][newb]='G';
        //}

        allghosts[i].coord.x=newa;
        allghosts[i].coord.y=newb;

    };
    
    
}


 void move_pac(){
    area[pacman.coord.x][pacman.coord.y]=' ';


        if(area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny]=='#' || area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny]=='G' /*|| area[pacman.coord.x+pacman.nx][pacman.coord.y+pacman.ny]=='G.' */ ){
            pacman.coord.x=1;
            pacman.coord.y=1;
            pacman.lives=pacman.lives-1;

        }
        else{
            pacman.coord.x=pacman.coord.x+pacman.nx;
            pacman.coord.y=pacman.coord.y+pacman.ny;
            if(area[pacman.coord.x][pacman.coord.y]=='.'){
                pacman.food=pacman.food+1;
            }
            
        }
    area[pacman.coord.x][pacman.coord.y]='P';
};




int main(){
    


//affichage(area);
   

init_ghosts(allghosts,area);
area[1][1]='P';


affichage(area); 
bool A=true;

while(A){
    move();
    move_pac();
    A=check(pacman,area);
   //Sleep( 1000 / 30 );

}


}
