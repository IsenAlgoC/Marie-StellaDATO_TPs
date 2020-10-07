#include <stdlib.h>
#include <stdio.h>
#include "tp4.h"

int main()
{
	HEURE HeureDebut, HeureFin, Duree;
	int tmp;
	HeureDebut.heure = 12;
	HeureDebut.minute = 30;
	Duree.heure = 00;
	Duree.minute = 45;
	HeureFin.heure = (HeureDebut.heure + Duree.heure);
	HeureFin.minute = (HeureDebut.minute + Duree.minute);

	if (HeureFin.minute >= 60) {
		HeureFin.heure += 1;
		HeureFin.minute = HeureFin.minute - 60;
	}

	printf("L'heure de fin = %d : %d", HeureFin.heure, HeureFin.minute);
}