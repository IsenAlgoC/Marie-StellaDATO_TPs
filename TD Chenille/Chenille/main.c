#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "chenille.h"
#include "ConsoleTools.h"
#define NBMAxX 30
#define NBMAxY 30
#define Rien ' '
#include <time.h>

typedef char grille[NBMAxX][NBMAxY];
//choix des positions aléatoires (Pour x et pour y)
int Postion_Al_x(int L) {
	srand(7);
	int x = 0;
	x = rand() % (0 + L);
	return x;
}
int Postion_Al_y(int C) {
	srand(14);
	int y = 0;
	y = rand() % (0 + C);
	return y;
}
// Création de le Feuille(grille) + placement des feuilles si décidé
void Tab(grille Tableau, int L, int C, char c, char p)
{
	//int x = 0; int y = 0;
	printf("\n");
	for (int i1 = 1; i1 < L; i1++) {printf("----");}
	printf("\n");

	for (int i = 0; i < L; i++) {
		printf("|");

		for (int j = 0; j < C; j++) {
			if (c == ' '){
				if (p == ' ') {						//Si p=' '
					Tableau[i][j] = c;
					printf(" %c ", Tableau[i][j]);
				}
				else {								//Si p='@'
					//x=Postion_Al_x(L);
					//y=Postion_Al_y(C);

					if ((i == Postion_Al_x(L)) && (j == Postion_Al_y(C))) {		//Je vérifie qe i et j conincident avec x et y
						Tableau[i][j] = p;
						printf(" %c ", Tableau[i][j]);}
					else {
						Tableau[i][j] = c;
						printf(" %c ", Tableau[i][j]);}	
				}
			}
		}
		printf("|");
		printf("\n");
	}
	
	for (int i1 = 1; i1 < L; i1++) {printf("----");}
}


int main() {
	int L = 0; int C = 0; grille Tableau = { 0 }; char c = ' '; char p;
	printf("Cration de la feuille !");
	printf("\nNombre de Ligne : ");
	scanf_s("%d", &L);
	printf("\nNombre de Colonnes : ");
	scanf_s("%d", &C);
	printf("\nVoulez vous placer les pommes ?\nSi oui, tapez '@'\nSinon, tapez ' '.\n --> : ");
	p = _getch();
	Tab(Tableau, L, C, c,p);
}