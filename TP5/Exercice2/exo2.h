#pragma once

typedef struct Tableau {
	int* elt; // le tableau d’entiers
	int size; // la taille de ce tableau d’entiers
	int eltsCount; // le nombre d’éléments dans le tableau
} TABLEAU;


//Crée un nouveau TABLEAU en allouant une taille initiale pour les données.
TABLEAU newArray();

//modifie la taille du tableau  et  renvoie -1 si erreur, ou la nouvelle taille si OK
int incrementArraySize(TABLEAU* tab, int incrementValue);