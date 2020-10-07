#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
    // gestion des caractères accentués dans la console.
    setlocale(LC_ALL, "fr-FR");
    int annee = 0;
    printf("Année = ");
    scanf_s("%d", &annee);
    while (annee >= 10000)
    {
        printf("Redonnez l'année : ");
        scanf_s("%d", &annee);
    }

    printf("\n L'année est ");
    if (annee % 4 == 0)
    {
        if ((annee % 100 == 0) && (annee % 400 == 0))          // le 'ou' cest : ||
        {
            printf("bissextile");
        }
        else
        {
            printf("non bissextile");
        }
    }
    else
    {
        printf("non bissextile");
    }

}