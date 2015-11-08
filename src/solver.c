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
	fpos_t position;

	int sizeW = strlen(word);
	char tmpWord[sizeW+1], cChar;
	int i = 0;

	char dir[15]= "../assets/";
	char filename[6] = "";
	
	// Définis le dictionnaire à utiliser
	filename[0] = word[0];
	strcat(filename, ".txt");
	strcat(dir, filename);

	file = fopen(dir,"r");

	if(file !=NULL){
		cChar=fgetc(file);
		while(cChar != EOF){
		    
		    // Si le mot courant est trop long on passe au suivant
		    if(i == sizeW){
		    	while(cChar != '\n'){
		    		cChar = fgetc(file);
		    	}
		    }

		    // Parcours tout les mots
		    if(cChar != '\n'){
		        tmpWord[i] = cChar;
		        i++;
		        tmpWord[i]='\0';

		        /*  On regarde si le mot est possible tout en s'assurant
					que le mot formé n'est pas un mot complet
		        */
		       	fgetpos(file, &position);
		        cChar = fgetc(file);
		        if(cChar != '\n' && strcmp(word,tmpWord) == 0){
		        	fclose(file);
		        	return 1;
		        }
		        fsetpos(file, &position);

		    }else{

		        tmpWord[i]='\0';
		        // Le mot a été trouvé
		        if(strcmp(word,tmpWord) == 0){
		            fclose(file);
		            return 2;
		        }
		        i=0;
		        
		    }

		    cChar=fgetc(file);
		}
		fclose(file);

	}else{
		printf("Le fichier n'a pu être chargé.");
	}
	return 0;
}