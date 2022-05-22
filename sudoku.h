#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define SIZE 9

void affichage(int area[SIZE][SIZE]);


bool is_fill(int area[SIZE][SIZE]);


bool safe_number(int area[SIZE][SIZE],int i, int j, int n);


void level(int K,int area[SIZE][SIZE]);


void fill_diag(int area[SIZE][SIZE]);


bool fill(int area[SIZE][SIZE], int n);


void remplissage(int area[SIZE][SIZE]);


void modification(int area[SIZE][SIZE]);

int play_sudoku();

#endif



