/**
 @file random.c
 @brief Fonctions aléatoires
 @author Cousin Brandon Ngatchou Junior
 @version v1.00
 @date 05/11/2015
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

/**
 * Initialise le tirage aléatoire.
 */
void initRand(){
	srand(time(NULL));
}

/**	
 * 	Tire une lettre au hasard en prenant en 
 *	compte leur fréquence d'apparition
 *	dans la langue française.
 *	@return e par défaut
*/
char randChar(){
	int iCase = rand() % 1486387;

	if(iCase < 745) return 'k';
	if(iCase < 2492) return 'w';
	if(iCase < 4585) return 'z';
	if(iCase < 9310) return 'y';
	if(iCase < 15238) return 'x';
	if(iCase < 23589) return 'j';
	if(iCase < 34887) return 'h';
	if(iCase < 48175) return 'g';
	if(iCase < 61997) return 'b';
	if(iCase < 78348) return 'f';
	if(iCase < 99237) return 'q';
	if(iCase < 124212) return 'v';
	if(iCase < 169733) return 'm';
	if(iCase < 216068) return 'p';
	if(iCase < 266071) return 'c';
	if(iCase < 322340) return 'd';
	if(iCase < 405102) return 'o';
	if(iCase < 488770) return 'l';
	if(iCase < 585555) return 'u';
	if(iCase < 686055) return 'r';
	if(iCase < 794867) return 'n';
	if(iCase < 905970) return 't';
	if(iCase < 1021435) return 'i';
	if(iCase < 1138545) return 'a';
	if(iCase < 1260440) return 's';
	return 'e';
}

/**	
 * 	Permet de récupérer l'indice dans la matrice 
 *	de la lettre tirée au hasard.
 *	@param c Caractère à convertir en indice
*/
int getIChar(char c){
	return c - 97;
}

/** 
 * 	Permet de tirer une lettre aléatoirement.
 *	@return Renvoie l'indice de la lettre tirée
 */
int randCase(){
	return getIChar(randChar());
}

/** 
 * Attribue un bonus.
 * @param boCharL[] Bonus lettre de la case courante
 * @param boCharM[] Bonus mot de la case courante
 * @param nb_boL Nombre de bonus lettre dans la grille
 * @param nb_boM Nombre de bonus mot dans la grille
 */
void getBonus(char boCharL[], char boCharM[], int *nb_boL, int *nb_boM){
	int randBonus = rand() % 70;

	if(randBonus <= 8 && *nb_boL != 2){
		strcpy(boCharL, "LD");
		*nb_boL = *nb_boL + 1;
	}

	if(randBonus <= 11 && *nb_boL != 2){
		strcpy(boCharL, "LT");
		*nb_boL = *nb_boL + 1;
	}

	if(strcmp(boCharL,"  ") == 0){
		randBonus = rand() % 70;
		
		if(randBonus <= 5 && *nb_boM !=2){
			strcpy(boCharM, "MD");
			*nb_boM = *nb_boM + 1;
		}

		if(randBonus <= 8 && strcmp(boCharM,"  ") == 0 && *nb_boM !=2){
			strcpy(boCharM, "MT");
			*nb_boM = *nb_boM + 1;
		}
	}

}