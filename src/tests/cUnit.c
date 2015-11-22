/**
 @file cUnit.c
 @brief Gestions de tout les tests unitaires
 @author Cousin Brandon Ngatchou Junior
 @version v1.00
 @date 20/11/2015
 */
#include "include/randomUnit.h"
#include "CUnit/Basic.h"


int main(){
	CU_pSuite pSuite = NULL; 
 	 
 	/* Initialisation CUnit (Registre) */ 
 	if (CUE_SUCCESS != CU_initialize_registry()) 
 		return CU_get_error(); 
 
 
 	/* On prépare CUnit à lancer des tests */ 
 	pSuite = CU_add_suite("Tests sur le solver de Ruzzle", NULL, NULL); 
 	if (NULL == pSuite) { 
 		CU_cleanup_registry(); 
 		return CU_get_error(); 
 	} 
 
 
 	/* On prépare les tests */ 
 	if ( (NULL == CU_add_test(pSuite, "Test sur caractère tiré aléatoirement", testRandChar)) || 
		(NULL == CU_add_test(pSuite, "Tests sur l'indice d'une lettre", testGetIChar)))
	{ 
 		CU_cleanup_registry(); 
 		return CU_get_error(); 
 	} 

 
	/* Run all tests using the CUnit Basic interface */ 
 	CU_basic_set_mode(CU_BRM_VERBOSE); 
 	CU_basic_run_tests(); 
 	CU_cleanup_registry(); 
     
	return CU_get_error(); 

}	