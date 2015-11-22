/**
 @file randomUnit.c
 @brief Tests unitaires fonctions aléatoires
 @author Cousin Brandon Ngatchou Junior
 @version v1.00
 @date 20/11/2015
 */

#include <ctype.h>
#include "include/random.h"
#include "CUnit/Basic.h"


/* Test sur le retour du caractère tiré aléatoirement */
void testRandChar(void){
	CU_ASSERT(islower(randChar()));
	CU_ASSERT(!isalpha(randChar()));
	CU_ASSERT(isupper(randChar()));
}

/* Test sur le retour de l'indice d'une lettre */
void testGetIChar(void){
	CU_ASSERT(getIChar('a') >= 0 && getIChar('a') <= 25);
	CU_ASSERT(getIChar('z') >= 0 && getIChar('z') <= 25);
	CU_ASSERT(getIChar('0') >= 0 && getIChar('0') <= 25);
}