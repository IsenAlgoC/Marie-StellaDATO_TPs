#pragma once
#include <Windows.h>
#define NBMAxX 21
#define NBMAxY 21
#define CHENILLETAILLEMAX 20


typedef char grille[NBMAxX][NBMAxY];

typedef struct CHENILLE {

	int size;
	COORD tabChenille[CHENILLETAILLEMAX];
	char direction;
} CHENILLE;


// Création de le Feuille(grille)
void Tab(grille Tableau, int L, int C, char c, char p);
//choix des positions aléatoires (Pour x et pour y)
int Postion_Al_x(int L);
int Postion_Al_y(int C);
//void InitChenille(CHENILLE* Chenille);