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

#define N 4

/** 
 * \struct Définis une case par 4 caractéristiques
 * @param let Lettre à afficher
 * @param pts Nombre de points associé
 * @param boL Bonus sur la lettre
 * @param boM Bonus sur le mot
 */
typedef struct {char let; int pts; char boL[3]; char boM[3];}t_Case;

/** Représente une case aléatoirement
 * 
 * @param grid Grille à remplir
 * @param line Ligne de la case à remplir
 * @param col Colonne de la case à remplir
 */
void Case(t_Case grid[N][N], int line, int col){
    int randLet;
    t_Case alpha[27]= {
        {'A',1,"  ","  "}, {'B',3,"  ","  "}, {'C',2,"  ","  "}, {'D',2,"  ","  "},
        {'E',1,"  ","  "}, {'F',3,"  ","  "}, {'G',3,"  ","  "}, {'H',3,"  ","  "},
        {'I',1,"  ","  "}, {'J',10,"  ","  "}, {'K',12,"  ","  "}, {'L',2,"  ","  "}, 
        {'M',2,"  ","  "}, {'N',1,"  ","  "}, {'O',2,"  ","  "}, {'P',2,"  ","  "}, 
        {'Q',6,"  ","  "}, {'R',1,"  ","  "},{'S',1,"  ","  "}, {'T',1,"  ","  "},
        {'U',2,"  ","  "}, {'V',4,"  ","  "}, {'W',15,"  ","  "}, {'X',10,"  ","  "},
        {'Y',10,"  ","  "}, {'Z',4,"  ","  "}
    };

    randLet = randCase();
    grid[line][col].let = alpha[randLet].let;
    grid[line][col].pts = alpha[randLet].pts;
    strcpy(alpha[randLet].boL, grid[line][col].boL);
    strcpy(alpha[randLet].boM, grid[line][col].boM);
    printf(" %c ", grid[line][col].let);

}

/** Représente une grille
 * @param grid Grille à remplir
 */
void Grille(t_Case grid[N][N]){
    int i, j;

    initRand();
    
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {   
            Case(grid, i, j);
        }
        printf("\n\n");
    }
}

