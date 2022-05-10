#include <stdbool.h>
#define SIZE 9


bool safe_number(int area[SIZE][SIZE],int i, int j, int n){
    bool A=true;
    for(int k=0;k<SIZE ; k++){
            if (area[k][j]==n){A=false;}
    }

    for(int l=0;l<SIZE  ;l++){
        if (area[i][l]==n){A=false;}
    }
    int l = i/3;
    int c = j/3;

    for(int m =3*l;m<3*l+3;m++){
        for(int p =3*c;p<3*c+3 ;p++){
            if (area[m][p]==n  ){A=false;}
        }

    }
    return A;
}