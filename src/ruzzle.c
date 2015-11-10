/**
 \file ruzzle.c
 \brief Solver de Ruzzle
 \author Cousin Brandon Ngatchou Junior
 \version v0.32
 \date 05/11/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/display.h"
#include "../include/solver.h"
#define N 4

/* Programme principal */
int main(int argc, char * argv[]){
	t_Case grid[N][N];
	
	Grille(grid, argc, argv);
	//Solver(grid);
	return 0;
}