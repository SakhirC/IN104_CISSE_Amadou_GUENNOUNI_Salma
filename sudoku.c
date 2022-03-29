#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 9


int area[SIZE][SIZE];


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

/*bool safe_number(int i, int j; int n; int * area){
    bool A=true
    for(int k=0;k<SIZE & k!= i;k++){
        for(int l=0;l<SIZE & l!=j ;l++){
            if (area[k])[l]==n){A=false;}
        }
    }
    return A;
}
*/
int main(){
    int area[SIZE][SIZE];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            area[i][j]=0;
        }
    }
    fill_diag(area);
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",area[i][j]);
        }
        printf("\n");
    }
    return 0;

}


/*
void fill(int * area;int i;int j){
    if(i<SIZE & j<SIZE & area[i][j]==NULL){
        int a=rand()%9+1;
        while(safe_number(area,i,j)==false){
            a=rand()%9+1;
        }
        area[i][j]=a;
        fill(area;i+1;j+1);
        fill(area;i;j+1);
        fill()
    }

}
*/