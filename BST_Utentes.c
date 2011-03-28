/*
 *  BST_Utentes.c
 *  Binary Search Tree Utentes
 */

#include "BST_Utentes.h"



struct _binSearchTreeUtente{
	 Utente * utente;
	 BST_Utentes * leftLeaf;
	 BST_Utentes * rightLeaf;
};


/********
 *
 * Constructor
 *
 ********/
BST_Utentes * BST_Utentes_new(void) {
	BST_Utentes * novo;

	if ((novo = ( BST_Utentes*)malloc(sizeof( BST_Utentes))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( BST_Utentes));

	return novo;
}

/********
 *
 * Destructor
 *
 ********/
void BST_Utentes_delete( BST_Utentes * bst_Utentes) {

	//Utente_delete(bst_Utentes->utente);
	free(bst_Utentes->leftLeaf);
	free(bst_Utentes->rightLeaf);

	memset(bst_Utentes,0xdd,sizeof( BST_Utentes));
	free(bst_Utentes);
}

/*********
 *
 * GET'rs
 *
 ********/
Utente * bst_Utentes_getUtenteFromNode(BST_Utentes * leafBST_Utentes){
	return leafBST_Utentes->utente;
}

BST_Utentes * bst_Utentes_getLeftNode( BST_Utentes * leafBST_Utentes){
	return leafBST_Utentes->leftLeaf;
}

BST_Utentes * bst_Utentes_getRightNode( BST_Utentes * leafBST_Utentes){
	return leafBST_Utentes->rightLeaf;
}

//RETURN Utente || NULL caso o utente nao seja encontrado
Utente * bst_Utentes_getUtenteByID(BST_Utentes * leaf, int ID){
	
	if(!bst_Utentes_isNull(leaf)){
		int utenteBI = utente_getBI(leaf->utente);

		if(utenteBI == ID){
			return leaf->utente; //Caso encontre, retorna o Utente
		}else if(utenteBI < ID){
			return bst_Utentes_getUtenteByID(leaf->rightLeaf, ID);
		}else
			return bst_Utentes_getUtenteByID(leaf->leftLeaf, ID);
	}
	return NULL; // Caso nao encontre nenhum utente
}

//RETURN True caso encontre um utente com o ID fornecido
int bst_Utentes_checkUtenteByID(BST_Utentes * leaf, int ID){

	if(!bst_Utentes_isNull(leaf)){
		int utenteBI = utente_getBI(leaf->utente);

		if(utenteBI == ID){
			return _true; //Caso encontre, retorna o Utente
		}else if(utenteBI < ID){
			return bst_Utentes_checkUtenteByID(leaf->rightLeaf, ID);
		}else
			return bst_Utentes_checkUtenteByID(leaf->leftLeaf, ID);
	}
	return _false; // Caso nao encontre nenhum utente
}

int bst_Utentes_isNull(BST_Utentes * leaf){
	return leaf == NULL ||
		(unsigned int) leaf == NEW ||
		(unsigned int)leaf->utente == NEW;
}


/********
 *
 * SET'rs
 *
 ********/

void bst_Utentes_setUtente( BST_Utentes * leafBST_Utentes,  Utente * utente){
	leafBST_Utentes->utente = utente;
}

void bst_Utentes_setLeftNode( BST_Utentes * bst_Utentes,  BST_Utentes * leafBST_Utentes){
	bst_Utentes->leftLeaf = leafBST_Utentes;
}

void bst_Utentes_setRightNode( BST_Utentes * bst_Utentes,  BST_Utentes * leafBST_Utentes){
	bst_Utentes->rightLeaf = leafBST_Utentes;
};

BST_Utentes * bst_Utentes_addLeaf( BST_Utentes * leaf,  BST_Utentes * novoLeaf ){
	if(bst_Utentes_isNull(leaf)) return novoLeaf;
	
	else if(utente_getBI(leaf->utente) < utente_getBI(novoLeaf->utente)){
		leaf->rightLeaf = bst_Utentes_addLeaf(leaf->rightLeaf, novoLeaf);
		return leaf;

	}
	else if(utente_getBI(leaf->utente) > utente_getBI(novoLeaf->utente)){
		leaf->leftLeaf = bst_Utentes_addLeaf(leaf->leftLeaf, novoLeaf);
		return leaf;
	}
	else //esta a adicionar um elemento que ja existe
		return leaf;
}

void bst_Utentes_addUtente( BST_Utentes * leafBST_Utentes,  Utente * utente){
	
	if(bst_Utentes_isNull(leafBST_Utentes)){ //Se for null adiciona no leafBST_Utentes
		leafBST_Utentes->utente=utente;
	}
	else{ //Se nao for adiciona procura onde deve adicionar
		BST_Utentes * bstLeaf_novo = BST_Utentes_new();
		bstLeaf_novo->utente = utente;
	
		//este metodo retorna!!
		bst_Utentes_addLeaf(leafBST_Utentes, bstLeaf_novo);
	}

}




