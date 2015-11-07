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