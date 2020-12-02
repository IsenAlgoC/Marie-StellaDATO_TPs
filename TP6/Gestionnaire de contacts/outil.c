#include <stdio.h>   /* pour les entr�es-sorties */
#include <string.h>  /* pour les manipulations de cha�nes de caract�res */
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

#define VERSION 3.0
#define SQUELET
/**************************************************************************/
/* Compl�ter votre nom ici                                                */
/*   Nom : DATO                Pr�nom : Marie-Stella                      */
/**************************************************************************/

extern bool modif;


/**********************************************************************/
/*  Ajout d'un contact dans le r�pertoire stock� en m�moire           */
/**********************************************************************/

int ajouter_un_contact_dans_rep(Repertoire *rep, Enregistrement enr)
{
#ifdef IMPL_TAB
	// compl�ter code ici pour tableau
	int idx = rep->nb_elts;

	if (rep->nb_elts < MAX_ENREG)
	{
		
		rep->tab[idx] = enr;	//A l'indixe idx du tableau tab dans la structure R�pertoire, j'associe la syntaxe nom;prenom;contact qui se regroupe dans enr
		rep->nb_elts += 1;		//y a un �l�ment en plus
		compact(rep->tab->tel);
		return 1;
		
	}
	else {
		return(ERROR);
	}
	
	
#else
#ifdef IMPL_LIST

	bool inserted = false;
	if (rep->nb_elts == 0) {
		if (InsertElementAt(rep->liste, rep->liste->size, enr) != 0) {
			rep->nb_elts += 1;
			modif = true;
			rep->est_trie = true;
			return(OK);
		}

	}
	else {
			// compl�ter code ici pour Liste
	}

#endif
	
#endif

	return(OK);

} /* fin ajout */
  /**********************************************************************/
  /* supprime du r�pertoire l'enregistrement dont l'indice est donn� en */
  /*   param�tre       et place modif = true                            */
  /**********************************************************************/
#ifdef IMPL_TAB
void supprimer_un_contact_dans_rep(Repertoire *rep, int indice) {
	int i;
	// compl�ter code ici pour tableau
	if (rep->nb_elts >= 1)		/* s'il y a au moins un element ds le tableau */
	{						/* et que l'indice pointe a l'interieur */
		//Je parcours le tableau 
		for (i = indice - 1; i < rep->nb_elts - 1; i++) {
			rep->tab[i] = rep->tab[i + 1];
		}
		
		rep->nb_elts -= 1;		/* ds ts les cas, il y a un element en moins */
		modif = true;
	}

	return;
} /* fin supprimer */

#else
#ifdef IMPL_LIST
  /************************************************************************/
  /* supprime du r�pertoire l'enregistrement contenu dans le maillon elem */
  /*                   et fixe modif � vrai                              */
  /************************************************************************/
  // complet

	int supprimer_un_contact_dans_rep_liste(Repertoire *rep, SingleLinkedListElem *elem) {
	
	int ret=DeleteLinkedListElem(rep->liste, elem);
	if (ret == 1) {
		rep->nb_elts--;
		modif = true;
	}

	return (0); 
	}
#endif
#endif


  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement sur une ligne � l'�cran  */
  /* ex Dupont, Jean                 0320304050                         */
  /**********************************************************************/
void affichage_enreg(Enregistrement enr)
{
	// code � compl�ter ici
	//Ici on affiche enr.nom etc
	printf("\n%s, %s			%s", enr.nom,enr.prenom,enr.tel);
	return;
	
} /* fin affichage_enreg */
  /**********************************************************************/
  /*  fonction d'affichage d'un enregistrement avec alignement des mots */
  /* pour les listes                                                    */
  /* ex | Dupont                |Jean                  |0320304050      */
  /**********************************************************************/
void affichage_enreg_frmt(Enregistrement enr)
{
	// code � compl�ter ici
	// comme fonction affichage_enreg, mais avec pr�sentation align�es des infos
	printf("\n| %10s | %10s  | %10s", enr.nom, enr.prenom, enr.tel);
	return;
} /* fin affichage_enreg */

/*Cette fonction met tout les termes en micuscule d'une cha�ne mise en param�tre, en majuscule*/
char* maj(unsigned char str[])
{
	int i;
	for (i = 0; i < strlen(str); i++)
	{
		if (str[i] >= 97 && str[i] <= 122) /* Si le carract�re est compris entre 92 et 122 */
			str[i] -= 32; /* On retire 32 */
	}
	return str;
}

  /**********************************************************************/
  /* test si dans l'ordre alphabetique, un enregistrement est apres     */
  /* un autre                                                           */
  /**********************************************************************/
bool est_sup(Enregistrement enr1, Enregistrement enr2)
{
	int N = 0; int P = 0; int T = 0;

	//on compare les noms en 1e	ou on ne compare que les noms en les supposant prioritaires aux pr�noms et t�l�phones
	//unsigned char e1nom = maj(enr1.nom);
	//unsigned char e2nom = maj(enr2.nom);
	if (_strcmpi(enr1.nom, enr2.nom) > 0) { return (true); }
	else { return(false); }
	
	/*{ N=1; }
	else {N=0;}

	//on compare les pr�noms en 2e
	unsigned char e1prenom = maj(enr1.prenom);
	unsigned char e2prenom = maj(enr2.prenom);
	if (strcmp(e1prenom, e2prenom) > 0) { P=1; }
	else { P=0; }

	//on compare les tel en 3e
	if (strcmp(enr1.tel, enr2.tel) > 0) { T = 1; }
	else { T = 0; }

	if (N == 1 && P == 1 && T == 1) {return (true);}
	else {retrun(false);}*/

}
 
/*********************************************************************/
/*   Tri Alphabetique du tableau d'enregistrements                   */
/*********************************************************************/

void trier(Repertoire *rep)
{

#ifdef IMPL_TAB		//tri � bulle
	/*int idx; 
	char tmp;
	
	for (int j = 0; j < rep->nb_elts; j++) {
		if (est_sup(rep->tab[j], rep->tab[j + 1]) == false)		//si le premier nom est inf au second
		{
			tmp = rep->tab[j + 1].nom;											//j'inverse les deux
			*rep->tab[j + 1].nom = rep->tab[j].nom;
			*rep->tab[j].nom = tmp;
		}
	}*/
	int k = 0;			//code de Floran
	Enregistrement tmp;
	Enregistrement min; 
		for (int i = 0; i < rep->nb_elts - 1; i++) {
			min = rep->tab[i];
			for (int j = 0; j < rep->nb_elts; j++) {
				if (est_sup(min, rep->tab[j])) {
					k = j;
					min = rep->tab[j];
				}
			}
			tmp = rep->tab[i];
			rep->tab[i] = min;
			rep->tab[k] = tmp;
		}
	return;
	
	
#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
	// rien � faire !
	// la liste est toujours tri�e
#endif
#endif


	rep->est_trie = true;

} /* fin trier */

  /**********************************************************************/
  /* recherche dans le r�pertoire d'un enregistrement correspondant au  */
  /*   nom � partir de l'indice ind                                     */
  /*   retourne l'indice de l'enregistrement correspondant au crit�re ou*/
  /*   un entier n�gatif si la recherche est n�gative				    */
  /**********************************************************************/

int rechercher_nom(Repertoire *rep, char nom[], int ind)
{
	int i = ind;		    /* position (indice) de d�but de recherche dans tableau/liste rep */
	int ind_fin;			/* position (indice) de fin de tableau/liste rep */

	char tmp_nom[MAX_NOM];	/* 2 variables temporaires dans lesquelles */
	char tmp_nom2[MAX_NOM];	/* on place la chaine recherchee et la chaine lue dans le */
							/* tableau, afin de les convertir en majuscules et les comparer */
	bool trouve = false;		

#ifdef IMPL_TAB
	for (i; i < rep->nb_elts; i++) {			//on parcours le tableau
		if (strcmp(rep->tab[i].nom, nom) == 0) {	//si le nom � l'indice est pareil que celui indiqu� dans la fonction
			ind_fin = i;						//l'indice de fin devient l'indice du nom
			return ind_fin;
		}
		else {
			return -1;
		}
	}
	
#else
#ifdef IMPL_LIST
							// ajouter code ici pour Liste
	
#endif
#endif

	return((trouve) ? i : -1);
} /* fin rechercher_nom */

  /*********************************************************************/
  /* Supprimer tous les caracteres non num�riques de la chaine         */
  /*********************************************************************/
void compact(char *s)
{
	/*Soit N un tableau qui comporte tous les chiffres de 0 � 9
	Si dans s, il y a un caract�re diff�rent des �l�ments de N, on l'enl�ve
	*/
	
	for (int j = 0; j < sizeof(s); j++) {
		if  (s[j] < 0 || s[j]> 9) //Si on est avant le 0 ou apr�s le 9
		{
			s[j] = s[j+1];			//j'�crase ce caract�re avec le suivant
							        //i.e que je d�cale la suite de nombre vers la gauche
		}
	}

	/*OU ON FAIT MAYBE CECI
	for (int j = 0; j < sizeof(s); j++) {
		if (s[j] != 0 || s[j] != 1 || s[j] != 2 || s[j] != 3 || s[j] != 4 || s[j] != 5 || s[j] != 6 || s[j] != 7 || s[j] != 8 || s[j] != 9)
		{
			s[j] = s[j + 1];
		}
	}*/

	return 1;
}

/**********************************************************************/
/* sauvegarde le r�pertoire dans le fichier dont le nom est pass� en  */
/* argument                                                           */
/* retourne OK si la sauvegarde a fonctionn� ou ERROR sinon           */
/**********************************************************************/
int sauvegarder(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;							/* le fichier */

#ifdef IMPL_TAB
	errno_t err;
	
	char buffer[sizeof(Enregistrement) + 1];
	
	_set_errno(0);
	if (((err = fopen_s(&fic_rep, nom_fichier, "w")) != 0) || (fic_rep == NULL))	//s'il n'y a rien dans le fichier
	{
		return err;			//erreur
	}
	else {
		//on �crit nos �l�ments dans le buffer
		sprintf_s(buffer,_countof(buffer), "%s",rep->tab);	//countof s'utilise pour les variables. C'est comme sizeof mais sizeof est pour les types (int, char etc)
		fputs(buffer, fic_rep); //puis on mets dans le ficchier fic_rep, le buffer
	}

#else
#ifdef IMPL_LIST
	// ajouter code ici pour Liste
#endif
#endif

	return(OK);
} /* fin sauvegarder */


  /**********************************************************************/
  /*   charge dans le r�pertoire le contenu du fichier dont le nom est  */
  /*   pass� en argument                                                */
  /*   retourne OK si le chargement a fonctionn� et ERROR sinon         */
  /**********************************************************************/

int charger(Repertoire *rep, char nom_fichier[])
{
	FILE *fic_rep;					/* le fichier */
	errno_t err;
	int num_rec = 0;						/* index sur enregistrements */
	int long_max_rec = sizeof(Enregistrement);
	char buffer[sizeof(Enregistrement) + 1];
	int idx = 0;

	char *char_nw_line;
	
	_set_errno(0);
	if ( ((err = fopen_s(&fic_rep, nom_fichier, "r")) != 0) || (fic_rep == NULL) )
	{
		return(err);
	}
	else
	{
		while (!feof(fic_rep) && (rep->nb_elts < MAX_ENREG))
		{
			if (fgets(buffer, long_max_rec, fic_rep) != NULL)
			{
				/* memorisation de l'enregistrement lu dans le tableau */
				buffer[long_max_rec] = 0;			/* en principe il y a deja un fin_de_chaine, cf fgets */

				if ((char_nw_line = strchr(buffer, '\n')) != NULL)
					*char_nw_line = '\0';			/* suppression du fin_de_ligne eventuel */

				idx = 0;							/* analyse depuis le debut de la ligne */
#ifdef IMPL_TAB
				if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].nom, MAX_NOM, SEPARATEUR) == OK)
				{
					idx++;							/* on saute le separateur */
					if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].prenom, MAX_NOM, SEPARATEUR) == OK)
					{
						idx++;
						if (lire_champ_suivant(buffer, &idx, rep->tab[num_rec].tel, MAX_TEL, SEPARATEUR) == OK)
							num_rec++;		/* element � priori correct, on le comptabilise */
					}
				}
#else
#ifdef IMPL_LIST
														// ajouter code implemention liste
#endif
#endif

			}

		}
		rep->nb_elts = num_rec;
		fclose(fic_rep);
		return(OK);
	}


} /* fin charger */