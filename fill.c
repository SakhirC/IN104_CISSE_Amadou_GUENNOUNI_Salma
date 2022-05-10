
#include <stdbool.h>
#include "safe_number.h"
#define SIZE 9



bool fill(int area[SIZE][SIZE], int n){

        if(n>=SIZE*SIZE){
            return true;
        }

        int i=n/SIZE;
        int j=n%SIZE;

        if(area[i][j]!=0){
            return fill(area,n+1);
        }

        //int a=rand()%9+1;
        //while(safe_number(area,i,j,a)==false){
        for(int a=1;a<10;a++){
            if(safe_number(area,i,j,a)){
                area[i][j]=a;

                if(fill(area,n+1)){
                    return true;
                }
                
            }
        }
    area[i][j]=0;

    return false;
 }