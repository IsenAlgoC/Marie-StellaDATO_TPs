#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

//e fameux PALINDROME !
int main() {
	setlocale(LC_ALL, "fr-FR");
	char mot[20];
	char tmp;
	char tmpMot[20] = { 0 };
	char CopieMot[20] = { 0 };
	int Longueur = 0; int i = 0; int j = 0; int k = 0;

	printf("Ecrivez un mot : ");
	//fgets(mot, 20, stdin);

	//Cette partie enl�ve le \n qui se trouve � la fin de la chaine de caract�re et le transforme en 0 
	//pour qu'il n'y ait plus de probl�me !
	char* Position = NULL;
	if (fgets(mot, 20, stdin) != NULL)  // Pas d'erreur de saisie ?
	{
		Position = strchr(mot, '\n'); // On recherche l'"Entr�e"
		if (Position != NULL) // Si on a trouv� le retour � la ligne
		{
			*Position = '\0'; // On remplace ce caract�re par \0
		}
	}

	Longueur = strlen(mot) - 1;
	//printf("longueur = %d", Longueur);
	do { tmp = *(mot + k); *(CopieMot + k) = tmp; k++; } while (tmp != 0);  //je copie mot dans tmpMot
	//printf("\nMot = %s  et CopieMot = %s ", mot,CopieMot);

	//Maintenant, je vais inerser tmpMot 
	while (Longueur != -1) {			//Le faire jusqu� ce que la longueur soit nulle
		tmp = tmpMot[i];          // Le 1er caract�re de tmpMot va dans tmp
		tmpMot[i] = mot[Longueur];	//Le premier caract�re devient le dernier caract�re de mot
		mot[Longueur] = tmp;		//Le 1er caract�re de tmpMot devient le dernier caract�re de mot
		i++;
		Longueur--;					//La longueur du mot diminue
	}
	//printf("\ntmpMot = %s ", tmpMot);
	int valeur;
	valeur = strcmp(CopieMot, tmpMot);
	if (valeur == 0) {
		printf("\nCe mot est un palindrome ");
	}
	else {
		printf("\nCe mot n'est pas un palindome ");
	}

}