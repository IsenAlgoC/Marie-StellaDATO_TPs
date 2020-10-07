#include<math.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	unsigned long nbre = 2868838400;
	printf("La taille en octets est %d", sizeof(nbre));
	printf("\nLa taille en bit est %d\n\n", sizeof(nbre) * 8);

	// expliquez le principe de fonctionnement de l'expression : variable = condition ? valeur1 : valeur2 
	// A quoi sert l'opérateur bit à bit ‘&’ de dans ce contexte ?  ---> le connecteur logique 'et'
	//qui verifie que les deux valeurs sont vraies en ^m tempsmais bit à bit et le '&&' compare si les deux valeurs sont vraies en même temps
	// A quoi sert l'opérateur << ? 
	for (int i = 0; (i <= 32); i++)
	{
		printf("\n %d  -->  ", (nbre & (int)(pow(2, 31))) == 0 ? 0 : 1); //Si (nbre & 128) est faux, afficher 0-->OFF. Sinon, afficher 1-->ON
		if ((nbre & (int)(pow(2, 31))) == 0)
		{
			printf("bit %d : OFF", i);
		}
		else
		{
			printf("bit %d : ON", i);
		}
		nbre <<= 1;								// Décaler le la valeur nbre (1 ou 0) d'un bit à gauche
	}
	printf("\n\nBye \n");
}