#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int d, i;
	i = d = 0;
	printf("Donnez un entier : ");
	scanf_s("%d", &d);
	// On commence par initialiser le g�n�rateur de nombre pseudo-al�atoires.
	srand(time(NULL));
	int valeur = rand() % 101;
	printf("Valeur = %d", valeur);
	//La boucle s'arr�te quand v=d 
	while (valeur = !d)
	{
		if (valeur < d)
		{
			printf("Trop petit");
		}
		else
		{
			printf("Trog grand");
		}
		d = 0;
		printf("Donnez un entier : ");
		scanf_s("%d", &d);
		i += 1;
	}
	if ((valeur = d) && (valeur = i))
	{
		printf("C'est bon");
	}
}