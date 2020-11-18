#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include "tab.h" 
#define TAB2SIZE 100 
#define TAB3SIZE 10
#define TAILLEAJOUT 50

int main()
{
	int myTab1[10];
	int* myTab2 = NULL; 
	int tab2Size = TAB2SIZE; 
	int nbElts = 0;

	myTab2 = (int*)malloc(TAB2SIZE * sizeof(int)); 
	//if (myTab2 != NULL) 
	//{ 
	//	initTab(myTab2, tab2Size); 
	//}
	//else { printf("mémoire insuffisante"); return(-1); }
	//for (int k = 0; k < 20; k++) {myTab2[k] = k+1;}
	//for (int l = 0; l < 5; l++);
	//afficheTab(myTab2, tab2Size, 20);
	
	//free(myTab2);

	int* mytab3 = NULL;
	int* tab3Size = TAB3SIZE;
	int* NbE = 5;
	mytab3 = (int*)malloc(TAB3SIZE * sizeof(int));
	if (mytab3 != NULL)
	{
		initTab(mytab3, tab3Size);
	}
	else { printf("mémoire insuffisante"); return(-1); }

	for (int k = 0; k <= 5; k++) { mytab3[k] = k + 1; }
	
	ajoutElementDansTableau(mytab3, &tab3Size, &NbE , 9);
	afficheTab(mytab3, tab3Size, 6);

}
