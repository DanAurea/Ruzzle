/**
 @file solver.c
 @brief Résoud la grille
 @author Cousin Brandon Ngatchou Junior
 @version v1.00
 @date 08/11/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/display.h"
#include "../include/solver.h"
#include "../include/trie.h"

 char gridWord[17] = "\0"; /**< Mot formé à partir de la grille*/

/**
 * Calcule le total de points de la case courante.
 * @param  Case Case courante
 * @return Le nombre de points total
 */
int totCase(t_Case Case){
	if(strcmp(Case.boL, "LD") == 0) return Case.pts * 2;
	if(strcmp(Case.boL, "LT") == 0) return Case.pts * 3;
	return Case.pts;
}

/**
 * Retourne le coefficient multiplicateur pour le mot entier.
 * @param  Case Case courante
 * @return 1 si pas de bonus, 2 si bonus double, 3 si bonus triple
 */
int mulWord(t_Case Case){
	if(strcmp(Case.boM, "MD") == 0) return 2;
	if(strcmp(Case.boM, "MT") == 0) return 3;
	return 1;
}

/**
 * Récupère un mot dans le dictionnaire
 * @param  dict Dictionnaire dans lequel regarder
 * @return 		Retourne un mot dans l'ordre séquentiel
 */
char* getWord(FILE * dict) {
    char* word = NULL;
    
    word = malloc(17 * sizeof(char));
    fscanf(dict, "%s", word);
    
    return word;
}

/**
 * Cherche un point de départ à partir de la case courante
 * @param  Case Case courante
 * @param  word Mot récupéré dans le dictionnaire
 * @return      Retourne 1 si point de départ trouvé sinon 0
 */
int searchStart(t_Case Case, char word[]){
	return (Case.let == word[0]);
}

/**
 * Permet de confirmer que les deux mots sont identiques si 
 * c'est le cas alors on le rajoute dans la liste chaînée
 * @param gridWord Mot formé à partir de la grille
 * @param word     Mot tiré du dictionnaire
 * @param pts 	   Nombre de points total pour le mot formé
 */
void confirmWord(char gridWord[], char word[], int pts){
	element current;

	if(strcmp(word, gridWord) == 0){
		strcpy(current.word, word);
		current.pts = 0;
		addElement(&current);
	}

}

/**
 * Forme un mot en parcourant la grille
 * @param grid  Grille à résoudre
 * @param i     Point de départ vertical
 * @param j     Point de départ horizontal
 * @param word  Mot à chercher
 */
void formWord(t_Case grid[N][N], int i, int j, char word[]){
	int row, col;
	int sizeW;

	grid[i][j].visited = 1; // Permet de ne pas repasser sur une même case
	

	gridWord[strlen(gridWord)] = word[strlen(gridWord)]; // On initialise le mot formé
	sizeW = strlen(gridWord);
	gridWord[sizeW+1] = '\0';

	confirmWord(gridWord, word, 0);

	for ( row=i-1; row<=i+1 && row<N; row++){
    	for (col=j-1; col<=j+1 && col<N; col++){
        	if (row>=0 && col>=0 && !grid[row][col].visited && grid[row][col].let == word[sizeW])
          		formWord(grid,row, col, word);
  		}
  	}

  	gridWord[sizeW-1] = '\0'; // Enlève le dernier caractère en cas d'incompatibiltié
  	grid[i][j].visited = 0;

}

/**
 * Cherche le mot dans la grille
 * @param grid Grille à résoudre
 * @param word Mot récupéré dans le dictionnaire
 */
void searchWord(t_Case grid[N][N], char word[]){
	int i, j;

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			if(searchStart(grid[i][j], word)){
				formWord(grid, i, j, word);
			}
		}
	}
}

/**
 * 	Résoud la grille.
 * 	@param grid Grille à résoudre
 */
void Solver(t_Case grid[N][N]){
	FILE * dict;
	char word[17];
	
	dict = fopen("assets/dict.txt","r");
	if(dict != NULL){
		
		strcpy(word, getWord(dict));
		while(!feof(dict)){
			searchWord(grid, word);
			strcpy(word, getWord(dict));
		}
		fclose(dict);

	}else{
		printf("Erreur fichier introuvable ou droit insuffisant !");
	}
	
}
