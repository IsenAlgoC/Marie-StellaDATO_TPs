#pragma once

typedef struct Tableau {
	int* elt; // le tableau d�entiers
	int size; // la taille de ce tableau d�entiers
	int eltsCount; // le nombre d��l�ments dans le tableau
} TABLEAU;


//Cr�e un nouveau TABLEAU en allouant une taille initiale pour les donn�es.
TABLEAU newArray();

//modifie la taille du tableau  et  renvoie -1 si erreur, ou la nouvelle taille si OK
int incrementArraySize(TABLEAU* tab, int incrementValue);

//Ecrit un �l�ment � une position donn�e sans insertion
//Le param�tre pos indique la position d�insertion, la premi�re valeur est en position 1.
//Si l'�l�ment ins�r� n'est pas apr�s le dernier �l�ment, il faut agrandir le tableau et cr�er des �l�ments � z�ros entre les deux.
// renvoie 0 si erreur, sinon position de l��l�ment ins�r�
int setElement(TABLEAU* tab, int pos, int element);

//Affiche une portion du tableau de l�indice d�but � l�indice fin
// renvoie -1 si erreur, sinon 0
// startPos >= EndPos n�est pas un cas d�erreur et doit �tre trait�.
int displayElements(TABLEAU* tab, int startPos, int endPos);

//Supprime des �l�ments avec compactage du tableau
//Met � jour le nombre d'�l�ments dans le tableau et diminue la taille du tableau
// renvoie -1 si erreur, sinon la nouvelle taille du tableau
// startPos >= EndPos n�est pas un cas d�erreur et doit �tre trait�.
int deleteElements(TABLEAU * tab, int startPos, int endPos);

