/**
 \file display.c
 \brief Affiche la grille
 \author Cousin Brandon Ngatchou Junior
 \version v0.32
 \date 05/11/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/random.h"
#include "../include/display.h"

/** 
 * \struct Définis une case par 4 caractéristiques
 * @param let Lettre à afficher
 * @param pts Nombre de points associé
 * @param boL Bonus sur la lettre
 * @param boM Bonus sur le mot
 */
t_Case alpha[26]= {
        {'A',1}, {'B',3}, {'C',2}, {'D',2},
        {'E',1}, {'F',3}, {'G',3}, {'H',3},
        {'I',1}, {'J',10}, {'K',12}, {'L',2}, 
        {'M',2}, {'N',1}, {'O',2}, {'P',2}, 
        {'Q',6}, {'R',1},{'S',1}, {'T',1},
        {'U',2}, {'V',4}, {'W',15}, {'X',10},
        {'Y',10}, {'Z',4}
    };

/** Initialise les bonus à zéros
 * @param grid Grille à initialiser
 */
void initGrid(t_Case grid[N][N]){
    int i, j ;

    for (i = 0; i < N; i++)
    {   
        for (j = 0; j < N; j++)
        {
            strcpy(grid[i][j].boL, "  ");
            strcpy(grid[i][j].boM, "  ");
        }
    }
}

/** Représente une case aléatoirement
 * 
 * @param grid Grille à remplir
 * @param line Ligne de la case à remplir
 * @param col Colonne de la case à remplir
 * @param nb_bonus Nombre de bonus lettre et mot dans la grille 
 */
void getCase(t_Case grid[N][N], int line, int col, int nb_bonus[]){
    int randLet;

    randLet = randCase();
    
    grid[line][col].let = alpha[randLet].let;
    grid[line][col].pts = alpha[randLet].pts;
    
    getBonus(grid[line][col].boL, grid[line][col].boM, &nb_bonus[0], 
        &nb_bonus[1]);
    
    printf(" %c - %i - %s - %s  ||  ", grid[line][col].let, grid[line][col].pts, grid[line][col].boL, 
        grid[line][col].boM);

}


/** Représente une grille
 * @param grid Grille à remplir
 */
void Grille(t_Case grid[N][N]){
    int i, j;
    int nb_bonus[2] = {0};

    initRand();
    initGrid(grid);
    
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {   
            getCase(grid, i, j, nb_bonus);
        }
        printf("\n\n\n\n");
    }
}

