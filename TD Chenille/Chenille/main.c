#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "chenille.h"
#include "ConsoleTools.h"
#include <time.h>
#include <Windows.h>

typedef char grille[NBMAxX][NBMAxY];
//choix des positions aléatoires (Pour x et pour y)

/*int Postion_Al_x(int L) {
	int x = 0;
	x = rand() % (0 + L);
	return x;
}
int Postion_Al_y(int C) {
	int y = 0;
	y = rand() % (0 + C);
	return y;
}*/

// Création de le Feuille(grille) + placement d'une pomme si décidé
void Tab(grille Tableau, int L, int C)
{
	int x = 0; int y = 0;
	
	printf("\n");
	for (int i1 = 1; i1 < 15; i1++) {printf("______");}
	printf("\n");
	x = rangedRand(0, 20);
	y = rangedRand(0, 20);
	for (int i = 0; i < L + 1; i++) {
		printf("|");
		if (i == x) {
			for (int j = 0; j < C; j++) {
				if (j == y) {
					Tableau[i][j] = '@';
					printf(" %c ", Tableau[i][j]);
				}
				else {
					j = C - 1;
				}

			}
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
	for (int i1 = 1; i1 < 15; i1++) {printf("______");}

	/*for (int i2 = 0; i2 < L + 1; i2++) {
		for (int j2 = 0; j2 < C; j2++) {
			if (Tableau[i2][j2] != '@') {
				Tableau[i2][j2] = ' ';
				printf(" %c ", Tableau[i2][j2]);
			}
		}
	}*/
}


/*void InitChenille(CHENILLE* chenille) {

}*/



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