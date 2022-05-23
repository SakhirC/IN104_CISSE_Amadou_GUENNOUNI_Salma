#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 9

//fonction permettant d'afficher la grille
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
    printf("Choisissez votre niveau 1=facile 2=intermediaire 3=difficile : ");
    scanf("%d",&i);
    while(i!=1 && i!=2 && i!=3){
        printf("Choisissez votre niveau 1=facile 2=intermediaire 3=difficile : ");
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
    
    //Suppression des chiffres de la grille en fonction de la difficulte
    for(int w=0;w<K;w++){
        int j=rand()%9;
        int i=rand()%9;

        while(area[i][j]==0){
             j=rand()%9;
             i=rand()%9;
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


//remplit le reste de la grille de maniere recursive
bool fill(int area[SIZE][SIZE], int n){

        //verifie qu'on se trouve toujours dans la grille
        if(n>=SIZE*SIZE){
            return true;
        }

        int i=n/SIZE;
        int j=n%SIZE;


        //si la case n'est pas vide on passe a la case suivante
        if(area[i][j]!=0){
            return fill(area,n+1);
        }

        //sinon on essaie de le remplir avec les chiffres de 1 a 10 de sorte a ce qu'on puisse egalement remplir la prochaine
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

//copie de la grille pour verification a la fin
void copie(int area[SIZE][SIZE], int grille_complete[SIZE][SIZE]){
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            grille_complete[i][j]=area[i][j];
        }
    }
}

//demande a ce que l'utilisateur remplisse les parties vides de la grille jusqu'a ce qu'elle soit complete
void remplissage(int area[SIZE][SIZE]){
    int x;
    int y;
    int n;

    bool rempli=is_fill(area);

    while(rempli==false){
        affichage(area);
        printf("Entrez l'abscisse, l'ordonnee et le nombre a positionner selon le format x,y,n: ");
      int d= scanf("%d,%d,%d",&x,&y,&n);
      while(x>=SIZE || y>=SIZE || n>SIZE || area[x][y]!=0){
          printf("Rentrez des coordonnees correctes libres : ");
          int d= scanf("%d,%d,%d",&x,&y,&n);
      }
      area[x][y]=n;
      rempli=is_fill(area);
    }

}


//Propose a l'utilisateur de modifier des cases remplies 
void modification(int area[SIZE][SIZE]){
    int reponse;
    int x;
    int y;
    int n;
    printf("Are you done ? yes=1 no=other int ");
    int d=scanf("%d",&reponse);
    while(reponse!=1){
        affichage(area);
        printf("Entrez l'abcisse l'ordonnee et le nombre a positionner selon le format x,y,n : ");
        d= scanf("%d,%d,%d",&x,&y,&n);
        while(x>=SIZE || y>=SIZE || n>SIZE ){
            printf("Rentrez des coordonnees correctes  : ");
            int d= scanf("%u,%u,%u",&x,&y,&n);
            }
        area[x][y]=n;
        printf("Are you done ? yes=1 no=other int" );
        int d=scanf("%d",&reponse);
    }
}

void verification(int area[SIZE][SIZE], int grille_complete[SIZE][SIZE]){   
    int compteur=0;
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            if (grille_complete[i][j]!=area[i][j]){
                printf("erreur aux coordonnées (%d,%d)",i,j);
                compteur ++;

            }
        }
    }
    if (compteur==0) {
        printf("vous avez gagné !\n");
    }
        affichage(area);
}


int play_sudoku(){

    //Mise a zero du temps pour eviter la repetition des sequences aleatoires
    srand(time(NULL));

    int grille_complete[SIZE][SIZE];



    //Initialisation de la grille
    int area[SIZE][SIZE];
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            area[i][j]=0;
        }
    }


    //Remplissage de la diagonale
    fill_diag(area);

    //Remplissage de la grille entiere
    bool A=fill(area,0);
    if(A==false){
        printf("bug \n");

    }

    //copie
    copie(area,grille_complete);



    //definition du niveau de la grille
     level(area);

    //remplissage progressif de la grille par l'utilisateur
    remplissage(area);
    

    //modification de la grille par l'utilisateur
    modification(area);
    

    //Verification
    verification(area,grille_complete);
    


    return 0;

}

