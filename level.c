#include <stdlib.h>
#define SIZE 9
void level(int K,int area[SIZE][SIZE]){
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