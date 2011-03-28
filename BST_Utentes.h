/*
 *  BST_Utentes.h
 *  Binary Search Tree Utentes
 */

#ifndef BST_UTENTES_H
#define BST_UTENTES_H


#include "Utente.h"
#include "SAGAC_Controller.h"


typedef struct _binSearchTreeUtente BST_Utentes;



/********
 * Constructor
 ********/
BST_Utentes * BST_Utentes_new(void);

/********
 * Destructor
 ********/
void BST_Utentes_delete(BST_Utentes * bst_Utentes);

/********
 * GET'rs
 ********/
Utente * bst_Utentes_getUtenteFromNode( BST_Utentes * leafBST_Utentes);
BST_Utentes * bst_Utentes_getLeftNode( BST_Utentes * leafBST_Utentes);
BST_Utentes * bst_Utentes_getRightNode( BST_Utentes * leafBST_Utentes);
Utente * bst_Utentes_getUtenteByID(BST_Utentes * leaf, int ID);
int bst_Utentes_checkUtenteByID(BST_Utentes * leaf, int ID);

/*********
 * SET'rs
 ********/

void bst_Utentes_setUtente( BST_Utentes * leafBST_Utentes,  Utente * utente);
void bst_Utentes_setLeftNode( BST_Utentes * bst_Utentes,  BST_Utentes * leafBST_Utentes);
void bst_Utentes_setRightNode( BST_Utentes * bst_Utentes,  BST_Utentes * leafBST_Utentes);
void bst_Utentes_addUtente( BST_Utentes * leafBST_Utentes,  Utente * utente);

void bst_Utentes_addUtente( BST_Utentes * leafBST_Utentes,  Utente * utente);
BST_Utentes * bst_Utentes_addLeaf( BST_Utentes * leaf,  BST_Utentes * novoLeaf );
int bst_Utentes_isNull(BST_Utentes * leaf);


#endif /* BST_UTENTES_H */