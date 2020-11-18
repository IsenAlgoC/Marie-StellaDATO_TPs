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