#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#define SEPARATEUR '/'
#define TAILLETAB1 20

int main() {
	int MyTab1[TAILLETAB1]; int i = 1; int j = 20; int b = 0; int c = 0;
	int* MyPtr;
	int LastValeur = 20;
	MyPtr = &LastValeur;
	// remplir MyTab1[] avec les nombres de 1 à 20 separés de '/'
	printf("\n");
	b = 1;
	for (i; i < 20; i++) {
		MyTab1[i] = b++;
		printf("%d /", MyTab1[i]);
		c++;
		if (c == 5) {
			printf("\n\n");
			c = 0;
		}
	}
	//afficher le tableau de la fin au début en décrémentant le pointeur MyPtr
	/*/jusqu’à arriver au premier élément
	printf("\n");
	for (j; j>0; j--) {
		MyPtr = &MyTab1[j];				//J'associe à la variable MyPtr le dernier élément du tableau

		printf("%d /", *MyPtr);      //J'affiche la valeur associé à MyPtr
		c++;
		if (c == 5) {
			printf("\n\n");
			c = 0;
		}
	}*/
}