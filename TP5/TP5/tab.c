#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "tab.h"
#define TAB2SIZE 100 
#define TAILLEAJOUT 50

int initTab(int* tab, int size)
{
	int c = 0;
	if (tab == NULL || size < 0) { return -1; }
	else { 

		for (int i = 0; i < size; i++) {
			tab[i] = 0;
			printf(" %d ", tab[i]);
			c++;
			if (c == 10) { printf("\n"); c = 0; }
		}return size;
	}
}

int afficheTab(int* tab, int size, int nbElts) 
{
	int j = 0; int c = 0;
	if (tab == NULL || size < 0 || size<nbElts) { return -1; }
	else {
		for (j; j <= nbElts; j++) { printf(" %d ", tab[j]); }
	}return 0;
}

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element) 
{
	int* temp; 
	temp = realloc(tab, element * sizeof(int));
	if (temp == NULL)
	{
		return NULL;
	}
	else
	{
		//Si je suis à la position nbElts non vide/ différent de 0 et que size > nbElts+1:
		if (size > nbElts) {
			//	j'attribue à la position nbElts+1 mon entier element ;
			*nbElts = *nbElts + 1;
			tab[*nbElts] = element;
		}
		else {//Sinon :
				//Si temp==NULL, reallocation impossible
			if (temp == NULL) { printf("reallocation impossible"); }
				//sinon :
			else {
				//	j'augmente le size avec TAILLEAJOUT ;
				*size = *size + TAILLEAJOUT;
				//	j'attribue à la position nbElts+1 mon entier element ;
				*tab = *temp;
				*nbElts = *nbElts + 1;
				tab[*nbElts] = element;
			}
		}
	}
	return *nbElts; //tout est bon donc on retourne la nouvelle position
}

