#include "Tester.h"


Veiculo * test_Veiculo(int silent_mode){
	Veiculo * novo = Veiculo_new();
	
	printf("\n*********************************************\n");
	printf("\n\n\t** DEBUG: Entrou Test_Veiculo. **\n\n\n");

	if(!silent_mode){
	printf("\n\nDEBUG: Criou uma lista e vai atribuir valores.\n");
	}

	veiculo_setMarca(novo, "Peugeot");
	veiculo_setModelo(novo, "206");
	veiculo_setTipo(novo,e_tipoVeiculo_taxi);
	veiculo_setMatricula(novo, "86-MR-10");
	
	if(!silent_mode){
	printf("\n\nDEBUG: Acabou de criar a viatura e atribuir dados\n");
	printf("\n\nDEBUG: Vai apresentar dados sobre o carro\n");

	printf("\n\tVeiculo marca: %s", veiculo_getMarca(novo));
	printf("\n\tVeiculo modelo: %s", veiculo_getModelo(novo));
	printf("\n\tVeiculo matricula: %s", veiculo_getMatricula(novo));
	printf("\n\tVeiculo tipo: %d\n", veiculo_getTipo(novo));
	}
	/*
	printf("\n\nDEBUG: Vai retirar o veiculo criado da memoria\n");
	Veiculo_delete(novo);
	printf("\n\nDEBUG: Retirou o veiculo da memoria.\n");
	*/


	printf("\n\n\t***************************************\n");
	printf(    "\t**   DEBUG: Saiu do test_Veiculo.    **\n");
	printf(    "\t***************************************\n\n\n");
	return novo;
}

ListaVeiculo * test_ListaVeiculo(Veiculo * veiculo1, int silent_mode){
	ListaVeiculo * novaLista = ListaVeiculo_new();
	Veiculo * veiculo2 = Veiculo_new();
	Veiculo * veiculo3 = Veiculo_new();
	ListaVeiculo * novaLista2 = ListaVeiculo_new();
	Veiculo * veiculo4;
	

	printf("\n*********************************************\n");
	printf("\n\n\t** DEBUG: Entrou no test_ListaVeiculo. **\n\n\n");
	if(!silent_mode){
	printf("\n\nDEBUG: Criou uma lista e vai adicionar o veiculo recebido como parametro na lista.\n");
	}

	listaVeiculo_setVeiculo(novaLista, veiculo1);

	if(!silent_mode){
	printf("\n\nDEBUG: Acabou de atribuir um veiculo ao node\n");
	
	printf("\n\nDEBUG: Vai buscar veiculo e imprime o seu nome\n");

	printf("\n\nMarca veiculo: %s\n", veiculo_getMarca(listaVeiculo_getVeiculoFromNode(novaLista)));

	printf("\n\nDEBUG: Imprimiu a marca do veiculo.\n");
	printf("\n\nDEBUG: Vai adicionar um veiculo novo usando o metodo dinamico de insercao.\n");
	}
	veiculo_setMarca(veiculo2, "Mazda");
	veiculo_setModelo(veiculo2, "RX7 FC");
	veiculo_setTipo(veiculo2,e_tipoVeiculo_passageiros);
	veiculo_setMatricula(veiculo2, "AB-00-ZZ");

	listaVeiculo_addLastVeiculo(novaLista,veiculo2);
	if(!silent_mode){
	printf("\n\n\tDEBUG: Adicionou um veiculo com sucesso!\n");
	printf("\n\nDEBUG: Vai listar a marca de todos os carros na lista\n");
	
	_listaVeiculos_imprimeLista(novaLista);

	printf("\n\nDEBUG: Acabou de listar as marcas dos carros\n");
	printf("\n\nDEBUG: Vai imprimir o tamanho da lista.\n");

	printf("\n\n\t\tTamanho da lista: %d\n", listaVeiculo_getSize( novaLista));

	printf("\n\nDEBUG: Vai adicionar um veiculo novo no inicio da lista.\n");
	}
	veiculo_setMarca(veiculo3, "Honda");
	veiculo_setModelo(veiculo3, "EK9");
	veiculo_setTipo(veiculo3,e_tipoVeiculo_passageiros);
	veiculo_setMatricula(veiculo3, "12-ABUNAI-55");
	
	novaLista = listaVeiculo_addFirstVeiculo(novaLista, veiculo3);

	if(!silent_mode){
	printf("\n\nDEBUG: Acabou de adicionar um veiculo ao inicio da lista.\n");
	printf("\n\nDEBUG: Vai listar a marca de todos os carros na lista\n");
	
	_listaVeiculos_imprimeLista(novaLista);

	printf("\n\nDEBUG: Acabou de listar as marcas dos carros\n");
	printf("\n\nDEBUG: Vai testar insercao de um veiculo (usando o metodo que adiciona no fim da lista) quando o head da lista e null\n");
	
	
	}

	listaVeiculo_addLastVeiculo(novaLista2, veiculo3);

	if(!silent_mode){
		printf("\n\nDEBUG: Vai buscar um carro a lista pela sua matricula\n");
	}
	veiculo4 = listaVeiculo_getVeiculoByMatricula(novaLista,"12-ABUNAI-55");

	if(!silent_mode){
		printf("\n\nDEBUG: Acabou e ir buscar o veiculo usando a matricula\n");
		
		printf("\n\n====Veiculo====\n");
		printf("Veiculo Marca: %s\n", veiculo_getMarca(veiculo4));
		printf("Veiculo Matricula: %s\n",veiculo_getMatricula(veiculo4));

		printf("\n\nDEBUG: Vai testar a remocao de veiculos\n");
	}
	

	printf("\n\n\t***************************************\n");
	printf("\t** DEBUG: Saiu do test_ListaVeiculo. **\n");
	printf("\t***************************************\n\n\n");
	return novaLista;
}

void test_removerVeiculosLista(ListaVeiculo * lista, int silent_mode){
	printf("\n*********************************************\n");
	printf("\n\n\t** DEBUG: Entrou no test_removerVeiculosLista. **\n\n\n");
	
	_listaVeiculos_imprimeLista(lista);
	listaVeiculo_removeVeiculo(lista, "AB-00-ZZ");
	if(!silent_mode){
		printf("\n\nDEBUG: Vai testar a remocao do 2o veiculo\n");
	}

	//REMOVE O 2o
	listaVeiculo_removeVeiculo(lista, "86-MR-10");
	if(!silent_mode){
		printf("\n\nDEBUG: Vai listar a marca de todos os carros na lista\n");

		_listaVeiculos_imprimeLista(lista);
	}

	if(!silent_mode){
		printf("\n\nDEBUG: Vai testar a remocao do 1o veiculo\n");
	}

	//REMOVE O ULTIMO
	lista = listaVeiculo_removeVeiculo(lista, "12-ABUNAI-55");

	if(!silent_mode){
		printf("\n\nDEBUG: Vai listar a marca de todos os carros na lista\n");

		_listaVeiculos_imprimeLista(lista);
	}

	printf("\n\n\t***************************************\n");
	printf("\t** DEBUG: Saiu do test_removerVeiculosLista. **\n");
	printf("\t***************************************\n\n\n");
}

Utente *  test_Utente(ListaVeiculo * lista, int silent_mode){
	Utente * novoUtente = Utente_newWithData("Alison Fernandes",2,e_TipoUtente_turista, "Being BOSS!", "Urbanizations S.Joseph" );
	Utente * novoUtente2 = Utente_new();
	Veiculo * veiculo1;

	utente_setListaVeiculos(novoUtente,lista);
	utente_setListaVeiculos(novoUtente2,lista);
	

	printf("\n*********************************************\n");
	printf("\n\n\t** DEBUG: Entrou no test_Utente. **\n\n\n");

	if(!silent_mode){
		printf("\n\n DEBUG: Criou um Utente, ja com dados. \n\n");
		printf("\n\n DEBUG: Vai apresentar os dados do utente criado. \n\n");


		printf("\n\n\tNome: %s", utente_getNome(novoUtente));
		printf("\n\tBI: %d", utente_getBI(novoUtente));
		printf("\n\tTipo: %d", utente_getTipo(novoUtente));
		printf("\n\tProfissao: %s", utente_getProfissao(novoUtente));
		printf("\n\tMorada: %s", utente_getMorada(novoUtente));
		printf("\n\t===Veiculos===");
		_listaVeiculos_imprimeLista(utente_getListaVeiculos(novoUtente));
	
		printf("\n\n\t ======NULL TESTING ======\n\n");
		printf("\n\n DEBUG: Vai verificar se o utente já criado e com dados e null. \n\n");
		printf("\tUtente e null? %s",utente_isNull(novoUtente)==1? "Sim e null": "NAO e null");
		printf("\n\n DEBUG:Acabou de verificar se utente e null. \n\n");
	
		printf("\n\n DEBUG: Verifica se um utente inicializado, mas que tem apenas veiculos, e null. \n\n");
		printf("\tNovo utente e null? %s",utente_isNull(novoUtente2)==1? "Sim e null": "NAO e null");
	
		printf("\n\n\t ======!!! NULL TESTING END!!!======\n\n");

		printf("\n\n DEBUG: Vai buscar o carro ao utente pela matricula \n\n");
	}
	veiculo1 = utente_getVeiculoByMatricula(novoUtente, "AB-00-ZZ");

	if(!silent_mode){
		printf("\n\n DEBUG: Acabou de ir buscar veiculo pela matricula. \n\n");
		printf("\n\n====Veiculo====\n");
		printf("Veiculo Marca: %s\n", veiculo_getMarca(veiculo1));
		printf("Veiculo Matricula: %s\n",veiculo_getMatricula(veiculo1));
	}
	

	printf("\n\n\t***************************************\n");
	printf(    "\t**    DEBUG: Saiu do test_Utente.    **\n");
	printf(    "\t***************************************\n\n\n");

	return novoUtente;
}

void test_bst_Utentes(Utente * utente1, int silent_mode){
	BST_Utentes * arvoreUtentes = BST_Utentes_new();
	Utente * utente2 = Utente_newWithData("Vanessa D.",1,e_TipoUtente_morador, "Being BOSS! too", "Chelas" );
	Utente * utente3 = Utente_newWithData("Paulo A.",3,e_TipoUtente_funcionarioCamara, "Autarquia", "Barcelos" );
	Utente * utente4 = Utente_newWithData("Antonieta",4,e_TipoUtente_motorista, "Motorista", "Fim do mundo" );
	Utente * utente5 = Utente_newWithData("Zebedeu Arvoredo",5,e_TipoUtente_funcionarioLimpeza, "SeiLA", "Alialem" );
	
	if(!silent_mode){
		printf("\n*********************************************\n");
		printf("\n\n\t** DEBUG: Entrou no test_bst_Utentes. **\n\n\n");
		printf("\n\n DEBUG: Vai tentar adicionar um utente a arvore . \n\n");

	}
	bst_Utentes_addUtente(arvoreUtentes,utente1);

	if(!silent_mode){
		printf("\n\n DEBUG: Adicionou um utente com sucesso . \n\n");
		printf("\n\n DEBUG: Vai tentar adicionar 4 utentes para ver como fica a disposicao da arvore. \n\n");

	}
	bst_Utentes_addUtente(arvoreUtentes, utente2);
	bst_Utentes_addUtente(arvoreUtentes, utente3);
	bst_Utentes_addUtente(arvoreUtentes, utente5);
	bst_Utentes_addUtente(arvoreUtentes, utente4);

	if(!silent_mode){
		printf("\n\n DEBUG: 4 Utentes adicionados com sucesso, arvore encontra-se como esperado.\n\n");
		
	}
	printf("\n\n\t***************************************\n");
	printf(    "\t**    DEBUG: Saiu do test_bst_Utentes.    **\n");
	printf(    "\t***************************************\n\n\n");


}
PontoAcesso * test_PontoAcesso(int silent_mode) {
	PontoAcesso * novo = PontoAcesso_new();

	pontoAcesso_setID(novo, 12345);
	pontoAcesso_setNome(novo, "Ponto A");
	pontoAcesso_setDescricao(novo, "Descricao Ponto A");

	return novo;
};

void AdicionarPontoAcesso() {
ListaPontoAcesso * listaPontos = ListaPontoAcesso_new();
	char * nome = "Banana";

	printf("%s\n", nome);
	printf("%d\n", nome);

	nome = "Laranja";
	printf("%d\n", nome);
	

	listaPontos = listaPontoAcesso_Adicionar(listaPontos);
	listaPontos = listaPontoAcesso_Adicionar(listaPontos);

	listaPontoAcesso_Remover(listaPontos, "Ponto A");

	listaPontoAcesso_Listar(listaPontos);

//	system("pause");
}

