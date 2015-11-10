#include <stdio.h>
#include <string.h>
#include "../include/display.h"
#include "../include/solver.h"
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
void findWords(t_Case grid[N][N], int i, int j, char word[]){
	int dx, dy;
	grid[i][j].visited = 1;

	word[strlen(word)] = grid[i][j].let;
	word[strlen(word)+1] = '\0';

			// Parcours des cases voisines
			for (dx = (i <= 0 ? 0 : -1); dx <= (i >= N-1 ? 0 : 1); dx++) { 
				for (dy = (j <= 0 ? 0 : -1); dy <= (j >= N-1 ? 0 : 1); dy++) {
					
					if (!grid[dx+i][dy+j].visited && searchWord(word) == 1){
						findWords(grid, i+dx, j+dy, word); 
					}else if(strlen(word) >= 2 && searchWord(word) == 2){
						printf("%s\n", word);
						//findWords(grid, i+dx, j+dy, word);
					}else{
						word[strlen(word)-1] = '\0';
						grid[i+dx][j+dy].visited = 0;
					}

				} 
			}
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

	char dir[15]= "assets/";
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
		//printf("Le fichier n'a pu être chargé.");
	}
	return 0;
}

/**
 * Crée les dictionnaires pour optimiser le traitement
 * @param dir Indique le dossier dans lequel chercher le dictionnaire
 * @param filename Indique le nom du dictionnaire
 */
void createDict(char dir[], char filename[]){
	FILE * dirDic;
	FILE * dest;
	char let = 97; // Code ASCII de la lettre a
	char word[70] = "";
	int sizeFilename = strlen(filename);

	strcat(dir, filename);
	dirDic = fopen(dir, "r");
	dir[strlen(dir)-sizeFilename] = '\0'; // Nettoie le chemin

	if(dirDic != NULL){
		while(!feof(dirDic)){
			
			// Change de dictionnaire
			filename[0] = let;
			filename[1]='\0';
			strcat(&filename[1], ".txt");
			if(let != 97){
				dir[strlen(dir)-5] = '\0';
			}
			strcat(dir, filename);

			
			dest = fopen(dir,"w");

			fscanf(dirDic, "%s", word);
			while((word[0] == let || word[0] == let-32) && !feof(dirDic)){
				fprintf(dest, "%s\n", word);
				fscanf(dirDic, "%s", word);
			}
			fclose(dest);
			let++;
		}
		fclose(dirDic);
	}else printf("Le fichier n'a pu être chargé !");

}

void Solver(t_Case grid[N][N]){
	int i, j;
	char word[17];

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{	
			findWords(grid, i, j, word);
		}
	}
}