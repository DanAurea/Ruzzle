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
	int sizeW = strlen(word);
	char tmpWord[sizeW+1], cChar, tmp;
	int i = 0, nbCharLeft = 0;

	file = fopen("../assets/dico.txt","r");
	if(file !=NULL){
		cChar=fgetc(file);
		while(cChar != EOF){
			printf("%c - %i ",cChar, i);
		    
		    if(tmpWord[0] > word[0]) return 0;
		    
		    if(i == sizeW){
		    	while(cChar != '\n'){
		    		cChar = fgetc(file);
		    		//if(cChar != '\n' && strcmp(word,tmpWord) == 0) return 1;
		    	}
		    }

		    if(cChar != '\n'){
		        tmpWord[i] = cChar;
		        i++;     
		    }else{

		        tmpWord[i]='\0';
		        if(strcmp(word,tmpWord) == 0){
		        	printf("%s", tmpWord);
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
	return -1;
}

int main(){
	if(searchWord("abaiss")== 2)printf("test");
	return 0;
}