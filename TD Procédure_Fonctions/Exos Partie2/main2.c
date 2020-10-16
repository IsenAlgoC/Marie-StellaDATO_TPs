#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "calculatrice.h"
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>

int main() {
	GrandEntier Nbre = {1,2,3,1};
	
	Initialise(Nbre);
	
	Affiche( Nbre );

	int Chiffre = 9;
	printf("\n\n");
	//printf("\n En ajoutant %d a droite de %d, on a : ", Chiffre, Nbre);
	Affiche(AjouteADroite(Nbre, Chiffre));
}