#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "exo2.h"
#define TAILLEINITIALE 100


TABLEAU newArray() {
	
	int* elt; int size = TAILLEINITIALE;
	int eltsCount = 0;
	elt = (int*)malloc(size * sizeof(int));
	if (elt != NULL)
	{
		int c = 0;
		for (int i = 0; i < size; i++) {
			elt[i] = 0;
			printf(" %d ", elt[i]);
			c++;
			if (c == 10) { printf("\n"); c = 0; }
		}
	}
}

int incrementArraySize(TABLEAU* tab, int incrementValue) 
{
	int* tmp; int newsize = 0;
	tmp=realloc(tab, incrementValue * sizeof(int));
	if (tmp == NULL)
	{
		return -1;
	}
	else
	{	tab = tmp;	newsize = tab->size + incrementValue;}
	return newsize;
}

int setElement(TABLEAU* tab, int pos, int element)
{
	int increment = pos - tab->size;
	if (tab == NULL || pos<1) { return 0;}
	else {
		if (*(tab->elt + pos) > tab->elt[tab->size]) {				// si on est en dehors du tableau
			incrementArraySize(tab, increment);					//on augmente la taille de
				//on met à 0 les nouvelles places disponibles
			for (int i = tab->size; i < increment; i++) {
				tab->elt[i] = 0;
			}
			tab->size += increment;
			pos = tab->size;
			*(tab->elt + pos) = element;
		}
		else {
			*(tab->elt + pos) = element;
		}
	}
	return pos;
}

int displayElements(TABLEAU* tab, int startPos, int endPos)
{
	int c = 0; int tmp = 0;
	if (tab == NULL) { return -1; }
	else {
		if (startPos <= endPos) {
			for (int i = startPos; i < endPos; i++) {
				printf(" %d ", tab->elt[i]);
				c++;
				if (c == 10) { printf("\n"); c = 0; }
			}
		}
		else			//j'intervertie les deux valeurs
		{
			tmp = startPos; startPos = endPos; endPos = tmp;
		}
	}
}

int deleteElements(TABLEAU* tab, int startPos, int endPos) 
{
	int tmp = 0;
	if (tab == NULL) { return -1; }
	else {
		if (startPos <= endPos) {			//j'affiche de 0 à start 
			for (int i = 0; i < endPos; i++) {
				printf(" %d ", tab->elt[i]);
			}
			for (int j = endPos; j < tab->size; j++) {		//puis de end à size
				printf(" %d ", tab->elt[j]);
			}
		}
		else {			//j'intervertie les deux valeurs
			tmp = startPos; startPos = endPos; endPos = tmp;

		}
		tab->size = tab->size - endPos + startPos;		//on met à jour la taille
	}
	return (tab->size);
}
