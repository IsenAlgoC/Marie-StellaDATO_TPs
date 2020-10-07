#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void Valide_ou_Non()
{
	//EXO2
	float a, b, c;
	printf("Donnez des dimensions de gagages a, b et c respectivement: ");
	scanf_s("%f", &a);
	scanf_s("%f", &b);
	scanf_s("%f", &c);

	while ((a > 150) && (b > 150) && (c > 150))
	{
		printf("Redonnez des dimensions de gagages a, b et c respectivement: ");
		scanf_s("%f", &a);
		scanf_s("%f", &b);
		scanf_s("%f", &c);
	}
	if ((a <= 55) && (b <= 35) && (c <= 25))
	{
		printf("VALIDE");
		printf("\nCOLIS SUIVANT\n");
		Valide_ou_Non();
	}
	else
	{
		printf("NON VALIDE");
		printf("\nCOLIS SUIVANT\n");
		Valide_ou_Non();
	}
}

int main()
{
	Valide_ou_Non();
}