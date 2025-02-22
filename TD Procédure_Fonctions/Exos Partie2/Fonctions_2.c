#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

#define NbChiffresMax 30
// taille max pour representer un grand entier
typedef int GrandEntier[NbChiffresMax];
/* representation des grands entiers � l'aide d'un tableau */
/* les positions qui ne contiennent pas de chiffres significatifs */
/* sont initialis�es � zero */
/* *********************************************************** */
/* Procedure d'initialisation d'un grand entier a zero */
/* *********************************************************** */
void Initialise(GrandEntier Nombre)
{
	int i = 0;
	for (i, i < NbChiffresMax; i++;) {
		Nombre[i] = 0;
	}
}
/* *********************************************************** */
/* Procedure d'affichage d'un grand entier � l'ecran */
/* *********************************************************** */
void Affiche(GrandEntier Nombre)
{
	/* affichage d'espace � la place des z�ros � gauche
	Sauf s'il s'agit du digit de droite, au cas ou GrandEntier vaut 0,
	il faut afficher 0 */
	printf("\nOn a : ");
	int i = NbChiffresMax - 1; int c = 0; int j = 0;

	/*for (i=NbChiffresMax - 1; i>0; i--){
		if (Nombre[i] == 0) {
			printf(" ");
			c++;
			if (c == 3) { printf("  "); c = 0; }
		}
	}*/							//Traduction  |
								// 		     \|/
								//			  |

	//Je parcours le nombre de droite � gauche			
	while ((i>0)&&(Nombre[i] == 0)) {		//Tant que le nombre=0
		printf("|");
		i--;
		c++;
		if (c == 3) { printf("  "); c = 0; }
	}
	
	for (j;j<=i;j++){						//Je reprends du d�but jusque i (l� o� commence les 0)
		printf("%d", Nombre[j]);		//ou %u pour unsigned
		c++;
		if (c == 3) { printf("  "); c = 0; }  // apr�s trois chiffres, je mets un espace
	}
}

/* ***************************************************************/
/* Procedure d'ajout d'un chiffre � droite dans un grand entier 
	//D�callage � gauche des chiffres 
	//Ecriture du nouveau chiffre dans la case de droite ainsi lib�r�e*/
/* ***************************************************************/
int AjouteADroite(GrandEntier Nb, int Chiffre)
{
	int taille = 0; taille = sizeof(Nb);
	for (int j=1; j <NbChiffresMax; j++) {
		Nb[j - 1]=Nb[j];
	}
	//Je vais tout � droite de mon Nb --> i
		//Je remplace Nb[i] par Chiffre
	Nb[taille - 1] = Chiffre;
	return Nb;
}
	
/* *********************************************************** */
/* Procedure de saisie d'un grand entier au clavier */
/* ***********************************************************/
/* FONCTION COMPLETE : NE DOIT PAS ETRE MODIFIEE */
int EntreeClavier(GrandEntier Nombre)
{
	int NbChiffresLus = 0;
	wchar_t car; // touche frapp�e en entr�e
	wchar_t chiffre[2]; // variable type chaine de caract�re Wide pour conversion
	// de car en entier avec _wtoi
	bool EstUnChiffre = false;
	Initialise(Nombre); // Nombre prend la valeur zero
	do
	{
		while ((car = _getwch()) == 0) {
			car = _getwch(); // touche de fonction ou direction enfonc�e
		}; // lire la touche frappee au clavier
		if (EstUnChiffre = (bool)isdigit(car)) // s'il s'agit bien d'un chiffre
		{
			wprintf(L"%c", car); // echo ecran du chiffre valide
			chiffre[0] = car; // conversion du caractere en chaine null terminated pour _wtoi()
			chiffre[1] = 0;
			AjouteADroite(Nombre, _wtoi(chiffre)); // conversion du caractere en valeur numerique et
			NbChiffresLus++; // affectation dans le tableau qui contient le grand entier
		}
		else { // s'il s'agit d'un caract�re de controle CLEAR (touche 'C' )
			if ((car == 'C') || (car == 'c')) {
				Initialise(Nombre); // effacement des caract�res saisies
				printf("\nClear\n");
				EstUnChiffre = true; // pour continuer la saisie de ce nombre
			}
		}
	} while (EstUnChiffre && (NbChiffresLus < NbChiffresMax));
	printf("\n");
	if ((car == 'X') || (car == 'x')) return -1;
	return 0;
}
/* *********************************************************** */
/* Procedure de calcul de la somme de deux grands entiers */
/* *********************************************************** 
int Addition(GrandEntier Nb1, GrandEntier Nb2, GrandEntier Result)
{
}

/* *********************************************************** */
/* Programme principal: COMPLET : rien � modifier */
/* *********************************************************** *
int main()
{
	GrandEntier Nb1, Nb2, Nb3;
	int i;
	bool Fin = false;
	int Code; // valeur de retour de la fonction EntreeClavier
	while (!Fin)
	{
		if ((Code = EntreeClavier(Nb1)) < 0) Fin = true;
		if (!Fin && (Code = EntreeClavier(Nb2) < 0)) Fin = true;
		if (!Fin)
		{
			printf("\n ");
			Affiche(Nb1);
			printf("+ ");
			Affiche(Nb2);
			printf(" ");
			for (i = 0; i < NbChiffresMax; i++)
			{
				if ((NbChiffresMax - i) % 3 == 0) printf("-");
				printf("-");
			}
			printf("\n= ");
			Addition(Nb1, Nb2, Nb3);
			Affiche(Nb3);
			printf("\n");
		}
		else
		{
			printf("\n Bye !\n");
		}
	}
	return (EXIT_SUCCESS);
}*/