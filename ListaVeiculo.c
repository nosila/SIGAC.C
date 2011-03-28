/*
 *
 *
 */

#include "ListaVeiculo.h"


struct _nodeListaVeiculo{
	Veiculo * veiculo;
	ListaVeiculo * nextNode;
	
};


// -------------
//
// Constructor
//
// -------------
ListaVeiculo * ListaVeiculo_new(void) {
	ListaVeiculo * novo;
	if ((novo = ( ListaVeiculo*)malloc(sizeof( ListaVeiculo))) == NULL) { 
		
		exit(1);
	}
	memset(novo,0xda,sizeof( ListaVeiculo));
	return novo;
}

// -------------
//
// Destructor
//
// -------------

void ListaVeiculo_delete( ListaVeiculo * listaVeiculo) {
	
	//Veiculo_delete(listaVeiculo->veiculo);
	free(listaVeiculo->nextNode);

	memset(listaVeiculo,0xdd,sizeof( ListaVeiculo));
	free(listaVeiculo);
}

//Faz free a lista toda
void ListaVeiculo_deleteR( ListaVeiculo * listaVeiculo) {
	ListaVeiculo * curr = listaVeiculo;
	ListaVeiculo * next = curr;
	

	while(!listaVeiculo_isNull(next)){
		next = curr->nextNode;
		Veiculo_delete(curr->veiculo);
		free(curr);
		curr = next;
	}


	memset(listaVeiculo,0xdd,sizeof( ListaVeiculo));
}
// -------------
//
// GET'rs
//
// -------------


Veiculo * listaVeiculo_getVeiculoFromNode( ListaVeiculo * nodeListaVeiculo){
	return nodeListaVeiculo->veiculo;

}

//Requires: !isNull(lista)
Veiculo * listaVeiculo_getVeiculoByMatricula( ListaVeiculo * lista, char * matricula){
		ListaVeiculo * curr = lista;
	//char* mat = "";
	while(!listaVeiculo_isNull(curr))
	{
		//mat = veiculo_getMatricula(curr->veiculo);
		//strcat(mat, "\n");

		if (strcmp(veiculo_getMatricula(curr->veiculo), matricula) != 0)
			curr = curr->nextNode;
		else
			break;
	}

	return listaVeiculo_isNull(curr) ? (Veiculo *)NEW : curr->veiculo;

	/*ListaVeiculo * curr = lista;

	while(strcmp(veiculo_getMatricula(curr->veiculo), matricula) != 0 &&
		!listaVeiculo_isNull(curr))
		curr = curr->nextNode;

	return listaVeiculo_isNull(curr) ? (Veiculo *)NEW : curr->veiculo;
	*/
}

int listaVeiculo_checkVeiculoByMatricula( ListaVeiculo * lista, char * matricula){
	ListaVeiculo * curr = lista;
	if(!listaVeiculo_isNull(lista)){
		while(!listaVeiculo_isNull(curr))
		{
			if (strcmp(veiculo_getMatricula(curr->veiculo), matricula))
				return 1;
		}
	}

	return 0;
}

ListaVeiculo * listaVeiculo_getNextNode( ListaVeiculo * nodeListaVeiculo){
	return nodeListaVeiculo->nextNode;
}

int listaVeiculo_getSize(ListaVeiculo * nodeListaVeiculo){
	ListaVeiculo * curr = nodeListaVeiculo;
	int i = 0;
	while(!listaVeiculo_isNull(curr)){
		i++;
		curr = curr->nextNode;
	}

	return i;
}

// -------------
//
// SET'rs
//
// -------------

void listaVeiculo_setVeiculo( ListaVeiculo * nodeListaVeiculo,  Veiculo * veiculo){
	nodeListaVeiculo->veiculo = veiculo;
}
/*
void listaVeiculo_setNextNode( ListaVeiculo * listaVeiculo,  ListaVeiculo * nextListaVeiculo){
	listaVeiculo->nextNode = nextListaVeiculo;
}

*/

//Adiciona veiculo ao fim da lista
void listaVeiculo_addLastVeiculo( ListaVeiculo * listaVeiculo,  Veiculo * veiculo){
	ListaVeiculo * newNode = ListaVeiculo_new();
	ListaVeiculo * curr;

	
	if((unsigned int)listaVeiculo_getVeiculoFromNode(listaVeiculo) == NEW){
		listaVeiculo->veiculo = veiculo;
	}
	else{
		curr = listaVeiculo;
		newNode->veiculo = veiculo;

		while(!listaVeiculo_isNull(curr) && !listaVeiculo_isNull(curr->nextNode)){
			//Caso exista um carro na lista com a mesma matricula
			if (strcmp(veiculo_getMatricula(veiculo),veiculo_getMatricula(curr->veiculo)) == 0) 
				return;
			
			curr = curr->nextNode;
		}
		curr->nextNode = newNode;
	}
	//Pode ser preciso retornar o listaVeiculo


}

ListaVeiculo * listaVeiculo_addFirstVeiculo( ListaVeiculo * listaVeiculo,  Veiculo * veiculo){
	ListaVeiculo * newNode = ListaVeiculo_new();

	newNode->veiculo = veiculo;
	newNode->nextNode = listaVeiculo;
	listaVeiculo = newNode;
	return newNode;
}

//Verifica se toda a struct e  == null
int listaVeiculo_isNull(ListaVeiculo * listaVeiculo){
	return listaVeiculo == NULL || //este teste e necessario para quando se chega ao penultimo node e tenta-se aceder a node->nextNode
		(unsigned int)listaVeiculo == NEW ||  
		(unsigned int)listaVeiculo->veiculo == NEW;
}

//Caso a seja o primeiro veiculo, retorna o resto da lista
ListaVeiculo * listaVeiculo_removeVeiculo(ListaVeiculo * listaVeiculo, char * matricula) {
	//
	char * matriculaCurr = veiculo_getMatricula(listaVeiculo->veiculo);
	int found = 0;

	if(strcmp(matriculaCurr, matricula) == 0){ //Caso seja o primeiro
		if((unsigned int)listaVeiculo->nextNode == NEW){ //Caso nao existam mais veiculos
			 listaVeiculo->veiculo =(Veiculo *) NEW; //Apaga o veiculo
			 return listaVeiculo; //retorna lista vazia
		}
		else
			return listaVeiculo->nextNode; //Retorna o resto da lista
	}
	else{
		ListaVeiculo * curr = listaVeiculo;

		while(!found && !listaVeiculo_isNull(curr->nextNode)){
			matriculaCurr = veiculo_getMatricula(curr->nextNode->veiculo) ;
			if (strcmp(matriculaCurr, matricula) == 0){
				
				if(!listaVeiculo_isNull(curr->nextNode->nextNode)) //Verifica se existe um veiculo a seguir ao que vai ser removido
					curr->nextNode = curr->nextNode->nextNode;
				else
					curr->nextNode = (ListaVeiculo *) NEW;
				found=1;
			}
			else
				curr = curr->nextNode;
		}
	}
	return listaVeiculo; //Retorna a lista visto que se retornasse o curr podia perder os elementos para tras...

}
