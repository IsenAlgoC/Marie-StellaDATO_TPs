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

//Ecrit un élément à une position donnée sans insertion
//Le paramètre pos indique la position d’insertion, la première valeur est en position 1.
//Si l'élément inséré n'est pas après le dernier élément, il faut agrandir le tableau et créer des éléments à zéros entre les deux.
// renvoie 0 si erreur, sinon position de l’élément inséré
int setElement(TABLEAU* tab, int pos, int element);

//Affiche une portion du tableau de l’indice début à l’indice fin
// renvoie -1 si erreur, sinon 0
// startPos >= EndPos n’est pas un cas d’erreur et doit être traité.
int displayElements(TABLEAU* tab, int startPos, int endPos);

//Supprime des éléments avec compactage du tableau
//Met à jour le nombre d'éléments dans le tableau et diminue la taille du tableau
// renvoie -1 si erreur, sinon la nouvelle taille du tableau
// startPos >= EndPos n’est pas un cas d’erreur et doit être traité.
int deleteElements(TABLEAU * tab, int startPos, int endPos);

