#include <stdio.h>
#include <string.h>
#include "../include/display.h"
#include "../include/trie.h"

/**
 * Calcule le total de points de la case courante
 * @param  Case Case courante
 * @return Le nombre de points total
 */
int totCase(t_Case Case){
	if(strcmp(Case.boL, "LD") == 0) return Case.pts * 2;
	if(strcmp(Case.boL, "LT") == 0) return Case.pts * 3;
	return Case.pts;
}

/**
 * Trouve un mot dans la grille
 * @param grid Grille du jeu
 */
void findWord(t_Case grid[N][N]){

}

/**
 * Cherche un mot dans le dictionnaire
 * @param word Mot à chercher 
 * @return Retourne 0 si mot introuvable, 1 si mot possible, 2 si mot trouvé
 */
int searchWord(char word[]){
	FILE * file;
	char tmpWord[17] ="", cChar = '?';
	int i;

	file = fopen("../assets/dico.txt","r");
	if(file !=NULL){
		while(!feof(file)){
			for (i = 0; i < strlen(word)+1; i++)
			{
				// Lecture caractère par caractère du dictionnaire
				cChar = fgetc(file);

				/* 	Retourne faux si le caractère actuel ne match pas
					pas la première lettre du mot;
				*/ 
				if(tmpWord[0] > word[0]) return 0;

				// Test sur la fin du mot
				if(cChar != '\n'){
					printf("%c",cChar);
					tmpWord[i] = cChar;
					if(strcmp(word, tmpWord) == 0) return 1;
				}
				else{
					if(strcmp(word, tmpWord) == 0) return 2;
					strcpy(tmpWord,"");
					i--;
					printf("\n");
				} 
			}
		}
	}else{
		printf("Le fichier n'a pu être chargé.");
	}
	return -1;
}

int main(){
	searchWord("abaissa");
	return 0;
}