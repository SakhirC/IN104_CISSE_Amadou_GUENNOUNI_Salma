#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 9
#define K 2

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

void affichage(int area[SIZE][SIZE]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",area[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

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

bool safe_number(int area[SIZE][SIZE],int i, int j, int n){
    bool A=true;
    for(int k=0;k<SIZE & k!= i;k++){
            if (area[k][j]==n){A=false;}
    }

    for(int l=0;l<SIZE & l!=j ;l++){
        if (area[i][l]==n){A=false;}
    }
    int l = i/3;
    int c = j/3;

    for(int m =3*l;m<3*l+3;m++){
        for(int p =3*c;p<3*c+3;p++){
            if (area[m][p]==n){A=false;}
        }

    }
    return A;
}
void  fill(int area[SIZE][SIZE], int i, int j){
      

        if(i<SIZE & j<SIZE & i>=0 & j>=0){

            if(area[i][j]==0){
                int a=rand()%9+1;
            if (safe_number(area,i,j,a)){

            fill(area,i+1,j-1);
            fill(area,i,j+1);
            fill(area,i+1,j);
            area[i][j]=a;
        }

        else{
            a=rand()%9+1;
            fill(area,i,j);

        }
        }else {
            fill(area,i+1,j-1);
            fill(area,i,j+1);
            fill(area,i+1,j);
        }

    
}
}


int main(){
    int area[SIZE][SIZE];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            area[i][j]=0;
        }
    }


    fill_diag(area);
    fill(area,0,0);

    for(int w=0;w<K;w++){
        int j=rand()%9+1;
        int i=rand()%9+1;

        while(area[i][j]==0){
             j=rand()%9+1;
             i=rand()%9+1;
        }
        area[i][j]=0;

    }



    affichage(area);

    int x;
    int y;
    int n;

    bool rempli=is_fill(area);

    while(rempli==false){
        affichage(area);
        printf("Entrez l'abcisse l'ordonnee et le nombre a positionner : ");
      int d= scanf("%u,%u,%u",&x,&y,&n);
      while(x>=SIZE || y>=SIZE || n>=SIZE || area[x][y]!=0){
          printf("Rentrez des cordonnees correctes libres : ");
          int d= scanf("%u,%u,%u",&x,&y,&n);
      }
      area[x][y]=n;
      rempli=is_fill(area);
    }

int reponse;

printf("Are you done ? (yes=1 no=other entier : ");
int d=scanf("%d",&reponse);
while(reponse!=1){
    affichage(area);
    printf("Entrez l'abcisse l'ordonnee et le nombre a positionner : ");
      d= scanf("%u,%u,%u",&x,&y,&n);
      while(x>=SIZE || y>=SIZE || n>=SIZE ){
          printf("Rentrez des cordonnees correcte  : ");
          int d= scanf("%u,%u,%u",&x,&y,&n);
      }
      area[x][y]=n;
      printf("Are you done ? (yes=1 no=other entier : " );
      int d=scanf("%d",&reponse);
    }



    return 0;

}

