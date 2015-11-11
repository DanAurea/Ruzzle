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
        {'a',1}, {'b',3}, {'c',2}, {'d',2},
        {'e',1}, {'f',3}, {'g',3}, {'h',3},
        {'i',1}, {'j',10}, {'k',12}, {'l',2}, 
        {'m',2}, {'n',1}, {'o',2}, {'p',2}, 
        {'q',6}, {'r',1},{'s',1}, {'t',1},
        {'u',2}, {'v',4}, {'w',15}, {'x',10},
        {'y',10}, {'z',4}
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
            grid[i][j].let = ' ';
            grid[i][j].pts = 0;
            strcpy(grid[i][j].boL, "  ");
            strcpy(grid[i][j].boM, "  ");
            grid[i][j].visited = 0;        }
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
    
    printf(" %c %i %s %s", grid[line][col].let - 32, grid[line][col].pts, grid[line][col].boL, 
        grid[line][col].boM);

    if(grid[line][col].pts < 10){
        printf("  |");
    }else{
        printf(" |");
    }

}

/** Représente une case en fonction de la chaîne tapée en paramètre de main
 * 
 * @param grid Grille à remplir
 * @param nb_bonus Nombre de bonus lettre et mot dans la grille
 * @param gridStr Chaîne de caractère passé en paramètre
 * @parama strIndex Indice courant de la chaîne passée en paramètre 
 */
void getCaseFromStr(t_Case grid[N][N], int nb_bonus[], char gridStr[], int strIndex){
    int line = 0, col = 0;
    
    // Conversion en minuscule pour le traitement
    if(gridStr[strIndex] < 97){
        gridStr[strIndex] += 32;
    }

    strIndex = getIChar(gridStr[strIndex]);

    while(grid[line][col].pts !=0){
        col++;
    }

    while(grid[line][col].pts !=0){
        line++;
    }

    grid[line][col].let = alpha[strIndex].let;
    grid[line][col].pts = alpha[strIndex].pts;

    getBonus(grid[line][col].boL, grid[line][col].boM, &nb_bonus[0], 
        &nb_bonus[1]);
    
    printf(" %c %i %s %s", grid[line][col].let - 32, grid[line][col].pts, grid[line][col].boL, grid[line][col].boM );

    if(grid[line][col].pts < 10){
        printf("  |");
    }else{
        printf(" |");
    }
}


/** Représente une grille
 * @param grid Grille à remplir
 * @param argc Nombres d'arguments du main
 * @param gridStr Grille sous forme de chaîne
 */
void Grille(t_Case grid[N][N],int argc, char * gridStr[]){
    int i, j;
    int nb_bonus[2] = {0};

    initRand();
    initGrid(grid);

    // Affichage grille aléatoire ou définis par l'utilisateur
    printf("----------------------------------------------------\n");
    printf("|");
    if(argc == 1){
    
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {   
                getCase(grid, i, j, nb_bonus);
            }
            printf("\n----------------------------------------------------\n");
            if(i < N-1 )printf("|");
        }
    }else if(argc == 2){

        if(strlen(gridStr[1]) >= 16){
            gridStr[16] = '\0';
            
            for (i = 0; i < 16; i++)
            {   
                getCaseFromStr(grid, nb_bonus, gridStr[1], i);
                if((i - 3) % 4 == 0){ 
                    printf("\n----------------------------------------------------\n");
                     if(i < 12)printf("|");
                }
            }

        }else{
            printf("Chaîne de caractère trop courte.");
        }

    }else{
        printf("Erreur nombre d'arguments incorrect !\nNormal usage: ruzzleSolver [a-z]*16\n");
        exit(0);
    }
}