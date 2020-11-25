#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "chenille.h"
#include "ConsoleTools.h"
#include <time.h>
#include <Windows.h>
#define NBMAxX 21
#define NBMAxY 21
#define CHENILLETAILLEMAX 20
#define CHENILLETAILLEINIT 5

typedef char grille[NBMAxX][NBMAxY];

// Création de le Feuille(grille) avec les pommes 
void Tab(grille Tableau, int L, int C)
{
	int x = 0; int y = 0;
	
	printf("\n");
	for (int i1 = 1; i1 < 10; i1++) {printf("______");}
	printf("\n");
	
	for (int i = 0; i < L + 1; i++) {
		printf("|");
		x = rangedRand(0, 20);
		y = rangedRand(0, 20);
		if (i==x)
		for (int j = 0; j < C; j++) {
			if (i==x && j == y) { Tableau[i][j] = '@'; }
			else { Tableau[i][j] = ' ';}
			printf(" %c ", Tableau[i][j]);
		}
		else {
			for (int j = 0; j < C; j++) { 
				Tableau[i][j] = ' ';
				printf(" %c ", Tableau[i][j]);
			}
		}
		printf("|");
		printf("\n");
	}
	
	for (int i2 = 1; i2 < 10; i2++) {printf("______");}
}


void InitChenille(CHENILLE* chenille) {
	chenille->direction = 'D';
	chenille->size = CHENILLETAILLEINIT;
	for (int i = 0; i < chenille->size; i++) {
		chenille->tabChenille[i].X = i;
		chenille->tabChenille[i].Y = 0;
	}
}
int DessineChenille(CHENILLE chenille) {

}



int main() {

	srand(7);
	int L = 0; int C = 0; grille Tableau = { 0 }; char c = ' '; char p;
	printf("Creation de la feuille !\n");
	printf("\nNombre de Ligne : ");
	scanf_s("%d", &L);
	printf("\nNombre de Colonnes : ");
	scanf_s("%d", &C);
	
	Tab(Tableau, L, C);
}