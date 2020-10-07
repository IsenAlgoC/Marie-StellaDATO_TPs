#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#define MAX 1500

int main() {
	setlocale(LC_ALL, "fr-FR");
	char buffer[MAX]; int Longueur = 0; int taille = 0; int b = 0; int compteur = 0;

	printf("Ecrivez un texte : \n");
	fgets(buffer, MAX, stdin);

	Longueur = strlen(buffer) - 1;   // <------- correspond à la longueur du mot jusque \n car après \n se trouve \0
	taille = Longueur - 1;		   //le caractère avant le \n
	for (int i = 0; i <= Longueur; i++) {
		if ((buffer[i] == ' ') || (buffer[i] == "'") || (buffer[i] == '.') || (buffer[i] == '!') || (buffer[i] == ',') || (buffer[i] == '?') || (buffer[i] == '\n')) {
			compteur += 1;
		}
	}
	if ((buffer[taille] == '.') || (buffer[taille] == '!') || (buffer[taille] == '?')) {
		compteur -= 1;
	}
	printf("\nIl y a %d mots dans ce texte ", compteur);

}