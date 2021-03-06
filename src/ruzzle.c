/**
 @file ruzzle.c
 @brief Solver de Ruzzle
 @author Cousin Brandon Ngatchou Junior
 @version v1.00
 @date 05/11/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/display.h"
#include "../include/solver.h"
#include "../include/trie.h"

/** Programme principal */
int main(int argc, char * argv[]){
	t_Case grid[N][N];
	
	Grille(grid, argc, argv); // Affiche la grille

	fprintf(stdout,"La liste a été générée dans assets/listWords.txt\n");
	freopen("assets/listWords.txt", "w", stdout); // Redirige la sortie standard
	
	puts("La liste des mots est: \n");
	Solver(grid); // Résoud la grille
	printList();
	clearList();
	fclose(stdout);
	
	return 0;
}
