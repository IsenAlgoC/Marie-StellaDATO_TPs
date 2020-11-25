#pragma once
#include <Windows.h>
#define NBMAxX 21
#define NBMAxY 21
#define CHENILLETAILLEMAX 20
#define CHENILLETAILLEINIT 5


typedef char grille[NBMAxX][NBMAxY];

typedef struct Chenille {

	int size;
	COORD tabChenille[CHENILLETAILLEMAX];
	char direction;
} CHENILLE;


// Création de le Feuille(grille)
void Tab(grille Tableau, int L, int C);

//On initialise les paramètres de la chenille
void InitChenille(CHENILLE* Chenille);

//On affiche la chenille
//Renvoie un code d’erreur 0 si tout se passe bien, ou -1 en cas d'anomalie.
int DessineChenille(CHENILLE chenille);
