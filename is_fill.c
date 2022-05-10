#include <stdbool.h>
#define SIZE 9

bool is_fill(int area[SIZE][SIZE]){
    int somme =0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(area[i][j]!=0){
                somme=somme+1;
            }
        }
    }
    return(somme==81);
}
