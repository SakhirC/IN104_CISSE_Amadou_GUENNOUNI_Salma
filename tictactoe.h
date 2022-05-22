#ifndef __TICTACTOE_H__
#define __TICTACTOE_H__


#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int* creer_grille();

void afficher(int* grille);

void placer(int* grille, int chiffre, int joueur);

void placer_alea(int* grille, int joueur);

int a_gagne(int* grille, int joueur);

int est_plein(int* grille);

int play_tictactoe();

#endif
