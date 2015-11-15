/**
 * @file trie.h
 * @brief Prototype de la liste chaînée
 */

/** 
 * @struct element trie.h
 * Définis un élément de la liste.
 */
typedef struct element
{	char word[17]; /**< Mot à stocker */
    int pts; /**< Nombre de points associé */
    struct element *right; /**< *right Pointeur sur l'élément suivant */
} element;/**< Définis un élément de la liste. */

void addElement(element * elem);
void printList();
void clearList();