/**
 \file trie.c
 \brief Met au point une liste chaînée d'ordre décroissant
 \author Cousin Brandon Ngatchou Junior
 \version v1.00
 \date 08/11/2015
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/trie.h"

element *root = NULL;

/**
 * Ajoute un élément dans la liste chaînée
 * @param elem Elément à ajouter
 */
void addElement(element * elem){
    element* new, * tmp, * tmpInsert;
    
    new = (element*)malloc(sizeof(element));
    strcpy(new->word, elem->word);
    new->pts = elem->pts;
    
    if(!root){
        /* La liste commence au nouvel élément 
        si aucun élément présent*/
        root = new;
    }else{
        tmp = (element*)malloc(sizeof(element));

        /*  Si la racine a un nombre de points 
            inférieur à l'élément on change la
            racine.
        */
        if(root->pts < new->pts){
            new->right = root;
            root = new;
        }
        tmp = root;

        // On parcourt la liste en triant à la volée
        while(tmp->right && tmp->right->pts > new->pts){
            tmp = tmp->right;
        }

        if(tmp->right){
            // On insère l'élément à la bonne place
            tmpInsert  = (element*)malloc(sizeof(element));
            tmpInsert  = tmp->right;
            tmp->right = new;
            new->right = tmpInsert;
        }else{
            // On ajoute l'élément à la fin
            tmp->right = new;
        }
    }
}

/**
 * Affiche la liste entière de la racine jusqu'à la fin
 */
void printList(){
    element* tmp;
    //On se place en début de liste
    tmp = (element*)malloc(sizeof(element));
    tmp = root;

    // On parcourt la liste
    while(tmp){
        printf("%s : %i\n",tmp->word, tmp->pts);
        tmp = tmp->right;
    }

    free(tmp);
}

/**
 * Supprime la liste
 */
void clearList(){
    element* tmp;
    
    //On se place en début de liste
    tmp = (element*)malloc(sizeof(element));
    tmp = root;

    // On parcourt la liste
    while(tmp->right){
        tmp = tmp->right;
        free(root);
        root = tmp;
    }
    free(tmp);
}