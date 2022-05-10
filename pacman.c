#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "structure.h"
#include "init_ghosts.h"
 #include "move.h"
#include "move_pac.h"  
#define height 60
#define width 30
#define nb_ghosts 40
#define nb_lives 3
#define nb_obstacles 50



void check(struct PacMan pacman, char area[width][height]){
    if(pacman.lives<0){
        printf("Vous avez perdu en ayant %d comme score \n",pacman.lives);

    }
    else{
        for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                printf("%c",area[i][j]);
            }
            printf("\n");
        }
    }
}

void affichage(char area[width][height]){
    for(int i=0;i<width;i++){
            for(int j=0;j<height;j++){
                printf("%c",area[i][j]);
            }
            printf("\n");
        };


}




int main(){
    struct ghost allghosts[nb_ghosts];


    struct PacMan pacman;
    pacman.coord.x=1;
    pacman.coord.y=1;
    pacman.chase=false;
    pacman.lives=nb_lives;
    pacman.food=0;
    pacman.nx=0;
    pacman.ny=0;
    
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


//affichage(area);
   

init_ghosts(allghosts,area);
area[1][1]='P';


affichage(area); 

while(1){
    move(allghosts,pacman,area);
    move_pac(allghosts,pacman,area);
    check(pacman, area);
   // Sleep( 1000 / 30 );

}


}
