#include <stdlib.h>
#include <stdio.h>
#define carre(x) x*x

int main()
{
	int Nb = 5;
	int Nb2 = 6;
	printf("c'est %d", carre(Nb)           );   // Ca donne 25
	printf("\nc'est %d", carre((Nb + 1))   ); // Ca donne sans () en plus 11  || 
	printf("\nc'est %d", carre((Nb + 2))   ); //17  --> sans ()  ||  

	//Le pb : la priorité des calculs
}