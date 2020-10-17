#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "fr-FR");

	int tableau[100] = { 0 };
	int* Curseur;

	int c = 0; int position = 0; int nbre = 0; int J = 0; int position1 = 0;
	srand(time(NULL));

	printf("\n");
	for (int i = 0; i < 100; i++) {
		tableau[i] = rand() % (20 + 1);  //un nombre aléatoire entre 0 et 20
		printf("%d  ", tableau[i]);
		c++;
		if (c == 10) { printf("\n\n"); c = 0; }
	}

	printf("Entrer la valeur recherchée : ");
	scanf_s("%d", &nbre);

	Curseur = &tableau[0];

	for (int j = 0; j < 100; j++) {

		if (tableau[j] == nbre) {

			Curseur = &tableau[j];
			position = j;
			position1 = j;
			printf("\n La valeur %d a été trouvé en %d ", nbre, position+1);

			for (J = j; J < 100; J++) {		//Je reprends ma boucle à J=j
				if (tableau[J] == nbre) {
					Curseur = &tableau[J];
					position = J;
					if (position != position1) { printf("puis en %d ", position+1); }	//Si la nouvelle position est différente de la première
																						//afficher la position   || le position + 1 c'est pour faciliter la lecture à l'utilisateur
				}
			}
			j = 99;  //Je force la fin de ma boucle
		}
	}

}