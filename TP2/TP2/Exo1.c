#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	//EXO1
	//Somme des n premiers entiers > 0
	int S, n;
	S = 0;
	for (n = 0; (n <= 100); n++)
	{
		S += n;
	}
	printf("1ere Methode\nLa somme des 100 premiers entiers est %d\n ", S);

	S = 0;
	n = 0;
	while (n <= 100)
	{
		S += n; n += 1;
	}
	printf("2e Methode\nLa somme des 100 premiers entiers est %d\n ", S);

	S = 0;
	n = 0;
	do { S += n; n += 1; } while (n <= 100);
	printf("3e Methode\nLa somme des 100 premiers entiers est %d\n ", S);
}
//Trouver la valeur maximum de n sans dépassement de capacité
/*int main()
{
	unsigned short int S, n;
	int i, B;
	S = i = 0;
	B = 65535;
	while (S <= B)
	{
		i += 1;
		S += i;
	}
	printf("La valeur maximum sans dépassement de capacité du unsigned short est %d\n", i);

	//On demande la valeur de n à l’utilisateur
	n = S = 0;
	printf("\nEcrivez une valeur n : ");
	scanf_s("%hu", &n);
	for (i = 0; (i <= n); i++)
	{
		S += i;
	}
	printf("1ere Methode\nLa somme des %hu premiers entiers est %hu\n ", n, S);

	//Recommencer tant que n est trop grand
	n = S = 0;
	printf("\nEcrivez une valeur n : ");
	scanf_s("%hu", &n);
	while (n > 362)
	{
		printf("\nRedonnez une valeur n : ");
		scanf_s("%hu", &n);
	}

	for (i = 0; (i <= n); i++)
	{
		S += i;
	}
	printf("1ere Methode\nLa somme des %hu premiers entiers est %hu\n ", n, S);
}*/