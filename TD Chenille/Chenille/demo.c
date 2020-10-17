#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "ConsoleTools.h"
#include <locale.h>
#include "demo.h"

//
//	Auteur : Pascal RICQ
//	version projet :  6.1
//  date 20-08-2020
//	remarque : d�veloppement � vocation p�dagogique


COORD org = { 0, 0};
char allKey[] = "()wW0123456789aAbBcCdDeEfFgGhHiIjJkKlLmMmNoOqQrRsStTuUwWyxXYzZ+-*/=<.\n\r";
COORD consoleSize;

int main(int argc, char* argv[]) {
	
	COORD pos = { 0,0 };
	char key;

	// pour la d�mo, fixer la taille de la console � 120 colonnes, 60 lignes
	// ouverture de la console
	openConsole();

	// limite de la zone d'�criture
	consoleSize.X = 120;
	consoleSize.Y = 60;

	// effacement de l'�cran
	clearScreen();
	  
	COORD centre = { 60,30};
	// changement de la couleur d'�criture
	setWriteColor(BRIGHTBLUE);
	cercle(centre, 25);
	setWriteColor(BRIGHTRED);
	ellipse(centre, 45, 15);
	setWriteColor(BRIGHTGREEN);
	lissajous(centre, 48 , 28, 3, 2);
	// place le curseur en bas � gauche de l'�cran
	moveCursor(0, 59);
	// clignotement d'une partie de l'�cran
	pos.X = centre.X - 5;
	pos.Y = centre.Y - 5;
	blink(pos, 10,10, 1000);
	// attente d'une touche pour continuer
	key=readChar(allKey);
	// fermeture de la console
	closeConsole();
 }





int plot(COORD coord) {
	//coord.Y = (short) ((double)coord.Y * 5.0 / 12.0 );
	int wasclipped = 0;
	if (!clipping) {
		moveCursor(coord.X, coord.Y);
		plotChar('*');
		wasclipped = 0;
	}
	else {
		if ((coord.X >= 0) && (coord.X < consoleSize.X) && (coord.Y >= 0) && (coord.Y < consoleSize.Y)) {
			moveCursor(coord.X, coord.Y);
			plotChar('*');
			wasclipped = 0;
		}
		else {
			wasclipped = 1;
		}
	}
	return(wasclipped);
}


int ellipse(COORD centre, double rayonX, double rayonY) {
	double deuxPi = 2 * Pi;
	double pasRad = deuxPi / 360;
	double anglerad = 0;
	COORD pt;
	for (anglerad = 0; anglerad <= deuxPi; anglerad += pasRad) {
		pt.X = centre.X + (int)(rayonX * cos(anglerad));
		pt.Y = centre.Y + (int)(rayonY * sin(anglerad));
		plot(pt);
	}

	return(EXIT_SUCCESS);

}

int cercle(COORD centre, double rayon) {
	elipse(centre, rayon, rayon);
	return(EXIT_SUCCESS);
}

int lissajous(COORD centre, double rayonX, double rayonY, double p, double q) {
	double deuxPi = 2 * Pi;
	double pasRad = deuxPi / 3600;
	double anglerad = 0;
	double phi = 0;
	COORD pt;
	for (anglerad = 0; anglerad <= deuxPi; anglerad += pasRad) {
		pt.X = centre.X + (int)(rayonX * sin(p * anglerad + phi));
		pt.Y = centre.Y + (int)(rayonY * sin(q * anglerad + phi));
		plot(pt);
	}

	return(EXIT_SUCCESS);

}
