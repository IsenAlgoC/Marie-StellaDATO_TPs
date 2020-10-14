#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include "td5_util.h"
#include <stdbool.h>
#define TAILLETAB 100
#define sizeCarre 3


int main()
{
	/*int n = 4;
	int reponse = somme(n);
	printf("\nEXO1\nLa somme des %d premiers entiers = %d \n",n,reponse);
	srand(time(NULL));

	printf("\nEXO3");
	int c = 0; char chaine[1020];
	printf("\nEcrivez un texte : \n");
	fgets(chaine, 1020, stdin);
	c = compterCar(chaine, 1020);
	printf("\nCette chaine de caractère contient %d caractères.", c);

	printf("\nEXO4");
	int cp = 0; char mot[100] = { 0 }; char car[3] = { 0 }; char car0[100] = { 0 }; int taille = 0; char tmp; int k = 0;
	printf("\nEcrivez un texte : \n");
	fgets(mot, 100, stdin);
	printf("Que recherchez vous ?");
	fgets(car0, 100, stdin);

	taille = strlen(car0);
	do { tmp = *(car0 + k); *(car + k) = tmp; k++; } while (k < taille - 2);

	cp = occur(mot, 100, car);
	printf("\nIl y a %d fois %s dans %s", cp, car, mot);

	printf("\nEXO6");
	int carre[sizeCarre][sizeCarre] = {
	{2,7,6},
	{9,5,1},
	{4,3,8}
	};

	if (isMagic(carre)) {
		printf("\nVrai");
	}
	else{
		printf("\nFaux");
	}*/

	printf("\nEXO5");
	int A = 3; int B = 18;
	swap(&A, &B);
	printf("A devient %d, B devient %d\n", A, B);
	return (EXIT_SUCCESS);
}