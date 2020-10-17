#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>
#define NBMAXNOTES 4

int main()
{
	// gestion des caractères accentués dans la console.
	setlocale(LC_ALL, "fr-FR");
	int i = 0; int Note = 0; char choix; int abscence = 0; float valid = 0; int t;
	float somme = 0; float moyenne; int min = 0; int MAX = 0; int tableau[4] = { -2 };

	while (i != 4)
	{

		printf("\nEntrez la note no %d : ", i);
		scanf_s("%d", &Note);
		i++;
		printf("\nNiveau de remplissage du tableau = %d", i);
		tableau[i] = Note;
		somme = somme + Note;
		valid++;
		//printf("\nNote no %d = %d ", i, note);

		if ((Note < 0) || (Note > 20)) {
			somme -= Note;    //On retire de la somme la mauvaise note insérée
			valid -= 1;       //On enlève 1 pour qu'il ne compte pas la mauvaise note insérée parmiles notes valides
			printf("Elève absent ? ou voulez-vous arrêter la saisie des notes ?\nTapez A ou O ou N");
			do {
				choix = _getch();
				choix = toupper(choix);
			} while ((choix != 'A') && (choix != 'O') && (choix != 'N'));  //tant qu'on tape une lettre différente de A,N,O, 
																		   //on redemande à l'utilisatteur de taper un caractère

			switch (choix) {
			case 'A':
				abscence++;
				tableau[i] = -1;
				somme -= tableau[i];			//Je ne compte pas les notes =-1 dans le calcul de la moyenne
				//Note = 0;						//j'initialise la note à 0
				i;								//je continue mes entrées de notes 
				break;
			case 'O':
				i = 4;
				break;
			case 'N':
				Note = 0;						//j'initialise la note à 0
				i = i - 1;						//je retape la note avant de passer à la note suivante
				break;
			default:
				valid -= 1;
				Note = 0;
				break;
			}
		}
		if (tableau[i] == 30) {tableau[i] = NBMAXNOTES;}
		//Ici je compare toutes notes pour avoir mon max et mon min
		if (Note < min)
		{
			min = Note;
		}
		if (Note > MAX)
		{
			MAX = Note;
		}
	}
	//printf("\nSomme= %f", somme);
	moyenne = (somme / valid);
	printf("\n\nLe nombre total de notes valides = %.2f ", valid);
	printf("\nLe nombre total d'absence = %d ", abscence);
	printf("\nLa moyenne des notes valides = %.2f", moyenne);
	printf("\nLe MAX = %d et le min = %d", MAX, min);

}