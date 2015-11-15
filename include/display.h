/**
 * @file display.h
 * @brief Prototype de la grille
 */

#define N 4 /**< Constante du nombre de lignes / colonnes */

/** 
 * @struct t_Case display.h
 * Définis une case par 4 caractéristiques.
 */
typedef struct {
	char let; /**< Lettre à afficher */
	int pts; /**< Nombre de points associé */
	char boL[3]; /**< Bonus sur la lettre */
	char boM[3]; /**< Bonus sur le mot */
	int visited; /**< Définis si une case a déjà été visitée */
}t_Case;
void Grille(t_Case grid[N][N], int argc, char * gridStr[]);
