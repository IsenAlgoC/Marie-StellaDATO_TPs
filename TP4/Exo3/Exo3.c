#include <stdlib.h>
#include <stdio.h>

int main()
{
	char nom[20];
	char prenom[20]; //Pour que le caractère soit entre 0 et 20 caractères
	char choix;
	printf("Ecrivez votre nom: ");
	fgets(nom, 20, stdin);
	printf("Ecrivez votre prenom: ");
	fgets(prenom, 20, stdin);
	printf("Etes-vous un homme(H) ou une femme(F) ?\n Tapez H ou F :");
	do {
		choix = _getch();
		choix = toupper(choix);
	} while ((choix != 'H') && (choix != 'F'));
	switch (choix)
	{
	case'H':
		printf("\nHey Monsieur %s %s !", nom, prenom);
		break;
	case'F':
		printf("\nHey Madame %s %s !", nom, prenom);
		break;
	default:
		break;
	}
}