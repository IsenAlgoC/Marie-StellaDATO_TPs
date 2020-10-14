#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#define sizeCarre 3


//EXO1
void somme(int n) {
	int SoM = 0; int i = 1;
	if (n > 0) {
		while ((i < n) && (_I32_MAX - SoM >= i)) {
			SoM += i;
			i++;
		}
	}
	else {
		return -1;
	}
	if (i != n) { return -1; }  // si dépassement de capacité
	return SoM;
}

//EXO2
int rangedRand(float range_min, float range_max) {
	float valeur = (float)((double)rand() / ((double)RAND_MAX + 1) * ((double)range_max - (double)range_min)) + range_min;
	return valeur;
}

int remplirTab(float tab[], int tabSize, int nbVal, float min, float max) {
	if (nbVal > tabSize || nbVal == 0 || tabSize == 0) { return-1; }
	for (int i = 0; i < tabSize && i < nbVal; i++) {
		tab[i] = rangedRand(min, max);
	}
	return nbVal;
}
int afficherTab(float tab[], int tabSize, int nbVal) {
	int c = 0;
	for (int i = 0; i < tabSize; i++) {

		printf("  ");
		printf("%.2f", tab[i]);
		c++;
		if (c == 10) {
			printf("\n\n");
			c = 0;
		}
	}
}
int maxTab(float tab[], int tabSize, int nbVal) {
	int MAx = tab[0]; int posMax = 0; int tmp = 0; int j = 0;

	if (nbVal > tabSize || nbVal == 0 || tabSize == 0) { return-1; }

	while (j < tabSize && j < nbVal) {
		for (int j = 0; j < tabSize; j++) {
			if (MAx < tab[j]) {
				MAx = tab[j];
				posMax = j;
				j++;
			}
		}
	}

	return posMax;
}

//EXO 3
int compterCar(char chaine[], int tailleMax) {
	int Longueur = 0; int b = 0; int compteur = 0;
	Longueur = strlen(chaine);   // <------- correspond à la longueur du mot jusque \0 (Ex: chaine = Moi\n\0)
	for (int i = 0; i <= Longueur; i++) {
		compteur += 1;
	}
	return compteur;
}

//EXO4
//compte le nombre d'occurrences, c'est-à-dire d'apparitions, d'un caractère dans une chaîne de caractères. 
//Par exemple, occur("toto", 5, 'o') renvoie la valeur 2.
int occur(char mot[], int tailleMax, char car) {
	int Longueur = 0; int b = 0; int compteur = 0; int valeur; char val;
	char car0[3] = { 0 }; char tmp; int k = 0;

	Longueur = strlen(mot) - 2;   //<------- correspond à la longueur du mot jusque avant \n
	printf("Que recherchez vous ?");
	fgets(car0, 100, stdin);
	car = *car0;

	for (int i = 0; i <= Longueur; i++) {
		val = mot[i];
		if (car != '0') {
			if (strcmp(val, car) == 0) {
				compteur += 1;
			}
		}
		else {
			return "Erreur";
		}
	}
	return compteur;
}

//EXO5
int swap(int* A, int* B) {
	if (*A == 'NULL' || *B == 'NULL') {
		return -1;
	}
	int tmp;
	tmp = *A; *A = *B; *B = tmp;
	return 0;
}

//EXO6
bool isMagic(int carre[sizeCarre][sizeCarre]) {

	int somL = 0; int somC = 0; int somD1 = 0; int somD2 = 0; //int varL = 0;
	int l = 0; int c = 0; int d1 = 0; int d2 = 0;
	int ligne_fin = sizeCarre; int i = 0; int j = 0;//incréments i et j

	while (j != sizeCarre) {
		for (l; l < sizeCarre; l++) {		//parcours une colonne
			somL += carre[0][l];
		}
		for (c; c < sizeCarre; c++) {			//parcours une ligne
			somC += carre[c][0];
		}
		if (somL == somC) {
			j++;
		}
	}
	printf("\nsomC=%d et somL=%d ", somC, somL);

	for (d1; d1 < sizeCarre; d1++) {		//parcourir la diagonal en partant de gauche
		somD1 += carre[d2][d1];
		d2++;
	}
	while (i < sizeCarre) {				//parcourir la diagonal en partant de droite
		somD2 += carre[i][ligne_fin - 1];
		ligne_fin--;
		i++;
	}
	printf("\nsomD1=%d et somD2=%d ", somD1, somD2);
	if ((somD1 == somD2) & (somD2 == somC) & (somC == somL)) {
		return true;
	}
	else {
		return false;
	}
}

//EXO7 (facultatif)