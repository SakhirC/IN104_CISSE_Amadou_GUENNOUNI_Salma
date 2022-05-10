#include <stdlib.h>
#define SIZE 9
void level(int area[SIZE][SIZE]){

    int i;
    printf("Choisissez votre niveau 1=facile 2=intermediare 3=diffcile");
    scanf("%d",&i);
    while(i!=1 || i!=2 || i!=3){
        printf("Choisissez votre niveau 1=facile 2=intermediare 3=diffcile");
        scanf("%d",&i);
    };
    int K;
    if(i=1){
        K=20;
    }
    else if(i=2){
        K=26;
    }
    else {
        K=35;
    }
    

    for(int w=0;w<K;w++){
        int j=rand()%9+1;
        int i=rand()%9+1;

        while(area[i][j]==0){
             j=rand()%9+1;
             i=rand()%9+1;
        }
        area[i][j]=0;

    }

}