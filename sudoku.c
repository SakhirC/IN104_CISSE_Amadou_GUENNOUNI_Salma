#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 9

//fonction permettant d'affciher la frille
void affichage(int area[SIZE][SIZE]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ",area[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}


//permet de savoir si la grille est complete
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


//Permet de savoir si placer n a la position i,j est autorise
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

//fonction permettant de chosir le niveau du jeu
void level(int area[SIZE][SIZE]){

    int i;
    int K;
    printf("Choisissez votre niveau 1=facile 2=intermediare 3=diffcile : ");
    scanf("%d",&i);
    while(i!=1 && i!=2 && i!=3){
        printf("Choisissez votre niveau 1=facile 2=intermediare 3=diffcile : ");
        scanf("%d",&i);
    };
    if(i==1){
        K=20;
    }
    else if(i==2){
        K=26;
    }
    else {
        K=35;
    }
    
    //Suppression des chiffres de la grillle en fonction de la diffcifulte
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


//Permet de remplir la diagonale principale
void fill_diag(int area[SIZE][SIZE]){
    //Boucle sur les 3 carres diagonaux
    for(int y=0;y<3;y++){


    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){

           int a=rand()%9+1;

           //Verification que a n'a pas ete deja entree dans le carre
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


//rempli le reste de la grille de maniere recursive
bool fill(int area[SIZE][SIZE], int n){

        //verfie qu'on se trouve toujours dans la grille
        if(n>=SIZE*SIZE){
            return true;
        }

        int i=n/SIZE;
        int j=n%SIZE;


        //si la case n'est pas  vide on passe a la case suivante
        if(area[i][j]!=0){
            return fill(area,n+1);
        }

        //sinon on essaie de le remplir avec les chiffres de 1 a 10 de sorte a ce qu'on puisse egalement rremplir la prochaine
        for(int a=1;a<10;a++){
            if(safe_number(area,i,j,a)){
                area[i][j]=a;

                if(fill(area,n+1)){
                    return true;
                }
                
            }
        }
    //en cas d'echec du remplissage precedent on met la case a 0 
    area[i][j]=0;

    return false;
}

//demande a ce que l'utilisateur rempli les parties vides de la grile jusqua ce qu'elle soit complete
void remplissage(int area[SIZE][SIZE]){
    int x;
    int y;
    int n;

    bool rempli=is_fill(area);

    while(rempli==false){
        affichage(area);
        printf("Entrez l'abcisse l'ordonnee et le nombre a positionner selon le format x,y,n: ");
      int d= scanf("%u,%u,%u",&x,&y,&n);
      while(x>=SIZE || y>=SIZE || n>=SIZE || area[x][y]!=0){
          printf("Rentrez des cordonnees correctes libres : ");
          int d= scanf("%u,%u,%u",&x,&y,&n);
      }
      area[x][y]=n;
      rempli=is_fill(area);
    }

}


//Propose a l'utilisateur de mofier des cases remplies 
void modification(int area[SIZE][SIZE]){
    int reponse;
    int x;
    int y;
    int n;
    printf("Are you done ? (yes=1 no=other entier : ");
    int d=scanf("%d",&reponse);
    while(reponse!=1){
        affichage(area);
        printf("Entrez l'abcisse l'ordonnee et le nombre a positionner selon le format x,y,n : : ");
        d= scanf("%u,%u,%u",&x,&y,&n);
        while(x>=SIZE || y>=SIZE || n>=SIZE ){
            printf("Rentrez des cordonnees correcte  : ");
            int d= scanf("%u,%u,%u",&x,&y,&n);
            }
        area[x][y]=n;
        printf("Are you done ? (yes=1 no=other entier : " );
        int d=scanf("%d",&reponse);
    }
}



int play_sudoku(){

    //Mise a zero du temps pour eviter la repetition des sequences aleatoires
    srand(time(NULL));



    //Initialisation de la grille
    int area[SIZE][SIZE];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            area[i][j]=0;
        }
    }


    //Rempllisage de la diagonale
    fill_diag(area);

    //Remplissage de la grille entiere
    bool A=fill(area,0);
    if(A==false){
        printf("bug \n");

    }

    //affichage(area)

    //definition du niveau de la grille
     level(area);
    
    //remplissage progressif de la grille par l'utilisateur
    remplissage(area);
    
    //modification de la grille par l'utilisateur
    modification(area);


    //Verification
    


    return 0;

}

