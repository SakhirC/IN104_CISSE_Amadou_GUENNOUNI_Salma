#include <stdbool.h>
#include <stdlib.h>
#define SIZE 9




void fill_diag(int area[SIZE][SIZE]){
for(int y=0;y<3;y++){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
           int a=rand()%9+1;
           bool A=true;
           for(int k=0;k<3;k++){
               for(int l=0;l<3;l++){
                   if(area[k+3*y][l+3*y]==a){A=false;}
               }
           }
            while(A==false){
                a=rand()%9+1;
                A=true;
                for(int k=0;k<3;k++){
                    for(int l=0;l<3;l++){
                        if(area[k+3*y][l+3*y]==a){A=false;}
                    }
                }
            }
            area[i+3*y][j+3*y]=a;
        }
    }
}
}