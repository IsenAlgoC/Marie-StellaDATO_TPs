#pragma once

#define NbChiffresMax 30
typedef int GrandEntier[NbChiffresMax];

/* Procedure d'initialisation d'un grand entier a zero */
/* *********************************************************** */
void Initialise(GrandEntier Nombre);
/* Procedure d'affichage d'un grand entier à l'ecran */
/* *********************************************************** */
void Affiche(GrandEntier Nombre);
/* Procedure d'ajout d'un chiffre à droite dans un grand entier*/
int AjouteADroite(GrandEntier Nb, int Chiffre);
/* Procedure de saisie d'un grand entier au clavier */
/* ***********************************************************/
/* FONCTION COMPLETE : NE DOIT PAS ETRE MODIFIEE */
int EntreeClavier(GrandEntier Nombre);
