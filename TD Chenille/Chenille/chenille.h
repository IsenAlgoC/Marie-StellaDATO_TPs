#pragma once

#define NBMAxX 30
#define NBMAxY 30


typedef char grille[NBMAxX][NBMAxY];

// Création de le Feuille(grille)
void Tab(grille Tableau, int L, int C, char c, char p);
//choix des positions aléatoires (Pour x et pour y)
int Postion_Al_x(int L);
int Postion_Al_y(int C);