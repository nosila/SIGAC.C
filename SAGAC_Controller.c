#include "SAGAC_Controller.h"

/// <summary>
/// Implementa um sistema de gestao de acesso condicionado a um centro historico de uma cidade,
/// incluindo varios pontos de acesso mediante apresentacao de um dispositivo identificador valido.
/// -------------------------------------------------------------------------------------------------
/// Projecto: SAGAC
/// Nome Completo: Sistema Automatizado para Gestao de Acesso condicionado 
///                ao centro historico de uma Cidade
/// -------------------------------------------------------------------------------------------------
/// Name: SAGAC.h
/// 
/// Date Created: 23/12/2010
/// Last Edited: 29/12/2010
/// 
/// Autor: Álison "NoSila" Fernandes, Hugo "HRuivo" Ruivo e João Pinto
/// 
/// -------------------------------------------------------------------------------------------------
/// TODO list SAGAC.h:
///		-Fazer catch do abort() nalgum lado;
///     -Guardar cliente novo numa lista
///		-Completar Utente_delete()
/// </summary>


int _initialized = _false;
int _sizeArvoreUtentes = 0; //Guarda o tamanho da arvore de Utentes
int _sizeListaPontos = 0; //Guarda o tamanho da lista de pontos de acesso
BST_Utentes * _arvoreUtentes;
ListaPontoAcesso * _listaPontoAcesso;


int _pontoNextId = 1;

// -------------
// Constructor
// -------------
void SAGAC_Controller_new(){
	if(!_initialized){ // Implementacao de Singleton Pattern.
		_arvoreUtentes = BST_Utentes_new();

		_listaPontoAcesso = ListaPontoAcesso_new();


		_initialized = _true;
		
	}
}


//========================
//========
//
// LER / GRAVAR
//
//========
//========================

Veiculo * _stringToVeiculo(char * linha){
	char * string = (char *)malloc(sizeof(CHARBUFFSIZE));
	char * resto = "";
	char token[] =":>";

	Veiculo * veiculoNovo = Veiculo_new();
	char * marca = (char *)malloc(sizeof(CHARBUFFSIZE));
	char * modelo= (char *)malloc(sizeof(CHARBUFFSIZE));
	char * matricula= (char *)malloc(sizeof(CHARBUFFSIZE));
	enum e_TipoVeiculo tipo = e_TipoVeiculo_null;

	//***************
	//IMPORTANTE
	//***************

	strcpy(string,linha); //E PRECISO FAZER ISTO SE NAO OS RESULTADOS NAO SERAO OS ESPERADOS

	marca = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	modelo = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	matricula = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	tipo = (enum e_TipoVeiculo)atoi(strtok_s(string,token,&resto));
	fflush(stdin);

	/*
	//=================
	//===TESTING
	//=================
	printf("\nMarca: %s", marca);
	printf("\nModelo: %s", modelo);
	printf("\nMatricula: %s", matricula);
	printf("\nTipo: %d\n\n", tipo);
	//=================
	//===TESTING
	//=================
	*/

	veiculo_setMarca(veiculoNovo, marca);
	veiculo_setModelo(veiculoNovo, modelo);
	veiculo_setMatricula(veiculoNovo, matricula);
	veiculo_setTipo(veiculoNovo,tipo);

	return veiculoNovo;

}

Utente * _stringToUtente(char * linha){
	char * string = (char *)malloc(sizeof(CHARBUFFSIZE));
		
	char * resto = "";
	char token[] =":>";

	Utente * utenteNovo = Utente_new();
	int BI = 0;
	char * nome = (char *)malloc(sizeof(CHARBUFFSIZE));
	char * profissao= (char *)malloc(sizeof(CHARBUFFSIZE));
	char * morada= (char *)malloc(sizeof(CHARBUFFSIZE));
	enum e_TipoUtente tipo = e_TipoUtente_null;

	//***************
	//IMPORTANTE
	//***************
	strcpy(string,linha);//E PRECISO FAZER ISTO SE NAO OS RESULTADOS NAO SERAO OS ESPERADOS

	nome = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	BI = atoi(strtok_s(string,token,&resto));
	string = resto;
	fflush(stdin);

	tipo = (enum e_TipoUtente)atoi(strtok_s(string,token,&resto));
	string = resto;
	fflush(stdin);

	profissao = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	morada = strtok_s(string,token,&resto);
	fflush(stdin);

	//=================
	//===TESTING
	//=================
	/*
	printf("\n***********************\n\n");

	printf("\nNome: %s", nome);
	printf("\nBI: %d", BI);
	printf("\nTipo: %d", tipo);
	printf("\nProfissao: %s", profissao);
	printf("\nMorada: %s\n\n", morada);
	*/
	//=================
	//===TESTING
	//=================

	utente_setNome(utenteNovo, nome);
	utente_setBI(utenteNovo, BI);
	utente_setTipo(utenteNovo,tipo);
	utente_setProfissao(utenteNovo,profissao);
	utente_setMorada(utenteNovo,morada);

	return utenteNovo;
}

PontoAcesso * _stringToPontoAcesso(char * linha){
	char * string = (char *)malloc(sizeof(CHARBUFFSIZE));
	char * resto = "";
	char token[] =":>";

	PontoAcesso * PontoAcessoNovo;
	int ID = 0;
	char * nome = (char *)malloc(sizeof(CHARBUFFSIZE));
	char * desc = (char *)malloc(sizeof(CHARBUFFSIZE));
	int capacidade = 0;
	int ocupacao = 0;
	int numAmbu = 0;
	int numTaxi = 0;
	int numPass = 0;
	int numMota = 0;

	//***************
	//IMPORTANTE
	//***************

	strcpy(string,linha); //E PRECISO FAZER ISTO SE NAO OS RESULTADOS NAO SERAO OS ESPERADOS

	ID = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	nome = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	desc = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	capacidade = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	ocupacao = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	numAmbu = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	numPass = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	numTaxi = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	numMota = (int)atoi(strtok_s(string, token, &resto));
	string = resto;
	fflush(stdin);

	//tipo = (enum e_TipoVeiculo)atoi(strtok_s(string,token,&resto));
	//fflush(stdin);

	/*
	//=================
	//===TESTING
	//=================
	printf("\nNome: %s", nome);
	printf("\nDescricao: %s", desc);
	//=================
	//===TESTING
	//=================
	*/
	PontoAcessoNovo = PontoAcesso_newWithData(ID, nome, desc, capacidade);
	Parque_setOcupacao(pontoAcesso_getParque(PontoAcessoNovo), ocupacao);
	Parque_SetNumLugares(pontoAcesso_getParque(PontoAcessoNovo), numAmbu, numTaxi, numPass, numMota);

	return PontoAcessoNovo;
}

char* _stringToMatricula(char * linha){
	char * string = (char *)malloc(sizeof(CHARBUFFSIZE));
	char * resto = "";
	char token[] =":>";

	char * nome = (char *)malloc(sizeof(CHARBUFFSIZE));
	//char * mat = (char *)malloc(sizeof(CHARBUFFSIZE));
	//***************
	//IMPORTANTE
	//***************

	strcpy(string,linha); //E PRECISO FAZER ISTO SE NAO OS RESULTADOS NAO SERAO OS ESPERADOS

	nome = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);
	
	nome = strtok_s(string,token,&resto);
	string = resto;
	fflush(stdin);

	/*
	//=================
	//===TESTING
	//=================
	printf("\nNome: %s", nome);
	//=================
	//===TESTING
	//=================
	*/
	return nome;
}

int SAGAC_Controller_readFile(char * filename){
	if(_initialized){
		FILE * file;
		char * linhaFicheiro = (char *)malloc(CHARBUFFSIZE);
		char tokenTypeEnd[] ="#\n"; //Tag usado para diferenciar veiculos de utentes
		char tokenPartTerminator[] ="//>\n"; //Tag usado para indicar o fim da insercao de utentes
		char tokenpontoacessoTerminator[] = "///>\n";
				PontoAcesso * pontoAcesso = NULL;
		int biUtente = 0;
		fopen_s(&file,filename,"r");


		if(file != NULL){ //Caso consiga abrir o ficheiro
			
			

			strcpy(linhaFicheiro, "_");//Inicializa


			//==================
			//======
			//==    Inicia a leitura de veiculos e utentes
			//======
			//==================
			while(strcmp(linhaFicheiro,tokenPartTerminator) != 0){
				ListaVeiculo * listaVeiculos = ListaVeiculo_new();
				Utente * utente = NULL;
				while ((linhaFicheiro = fgets(linhaFicheiro, CHARBUFFSIZE, file)) != NULL && strcmp(linhaFicheiro,tokenTypeEnd) != 0){
					
					listaVeiculo_addLastVeiculo(listaVeiculos,_stringToVeiculo(linhaFicheiro));
				
				}
				
				utente = _stringToUtente(fgets(linhaFicheiro, CHARBUFFSIZE, file));
				
				utente_setListaVeiculos(utente, listaVeiculos);
				bst_Utentes_addUtente(_arvoreUtentes,utente);
				_sizeArvoreUtentes++;
				
				linhaFicheiro = fgets(linhaFicheiro, CHARBUFFSIZE, file); //Vai buscar o tag para verificar se ha mais utentes para adicionar ou se pode terminar
				
			}
			
			linhaFicheiro = fgets(linhaFicheiro, CHARBUFFSIZE, file);
			
			if(strcmp(linhaFicheiro,"-") != 0){
				//==================
				//======
				//==    Termina a leitura de veiculos e utentes
				//======
				//==================
				while (strcmp(linhaFicheiro, tokenpontoacessoTerminator) != 0)
				{
					ListaPontoAcesso * listaPontoAcesso = NULL;
					Veiculo * veiculo = NULL;


					if (strcmp(linhaFicheiro, "P\n") == 0)
					{

						listaPontoAcesso = ListaPontoAcesso_new();

						linhaFicheiro = fgets(linhaFicheiro, 100, file);
						// insere ponto de acesso
						pontoAcesso = _stringToPontoAcesso(linhaFicheiro);
						_listaPontoAcesso = listaPontoAcesso_addFirstPontoAcesso(_listaPontoAcesso, pontoAcesso);
					}
					else if (strcmp(linhaFicheiro, "V\n") == 0)
					{
						linhaFicheiro = fgets(linhaFicheiro, 100, file);
						pontoAcesso_RegistarEntrada(pontoAcesso, biUtente, _stringToMatricula(linhaFicheiro));
					}

					linhaFicheiro = fgets(linhaFicheiro, 100, file);
					printf("\n\nDEBUG: %s",linhaFicheiro);
				}
			}
			
			/*
			//=================
			//===TESTING
			//=================
			SAGAC_listarUtentes();
			SAGAC_listarVeiculos(1);
			SAGAC_listarVeiculos(2);
			printf("\n\n\tDEBUG: Teste 1 Final: %s\n\n",linhaFicheiro);
			//=================
			//===TESTING
			//=================
			*/
			fflush(file);
			//fclose(file);
			return _true;


		}
		else
			return _false; //Caso nao consiga abrir o ficheiro
	}
	else
		return _false; //Caso SAGAC nao tenha sido inicializado
}

//===private
//=USED in: _SAGAC_Controller_Savefile(...)
char * _veiculoToString(Veiculo * veiculo){
	char * string =(char *)malloc(CHARBUFFSIZE);
	char * bla = (char *)malloc(CHARBUFFSIZE_L);
	char separator[] = ":>";

	strcpy(string, veiculo_getMarca(veiculo));
	strcat(string,separator);

	strcat(string, veiculo_getModelo(veiculo));
	strcat(string,separator);

	strcat(string, veiculo_getMatricula(veiculo));
	
	strcat(string,separator);
	strcat(string, _itoa(veiculo_getTipo(veiculo),bla,10));
	//printf("\n\nDEBUG: String veiculo: %s", string); //Usado para verificar a integridade da string que ira ser escrita no ficheiro
	//strcat(string, "\n");

	return string;
}

//===private
//=USED in: _utenteToFile(...)
char * _utenteToString(Utente * utente){
	char * string = (char *)malloc(CHARBUFFSIZE);
	char * tipo = (char *)malloc(CHARBUFFSIZE_L);
	char * BI = (char *)malloc(CHARBUFFSIZE);
	char separator[] = ":>";

	strcpy(string, utente_getNome(utente));
	strcat(string,separator);

	strcat(string, _itoa(utente_getBI(utente), BI, 10));
	strcat(string,separator);

	strcat(string, _itoa(utente_getTipo(utente), tipo, 10));
	strcat(string,separator);


	strcat(string, utente_getProfissao(utente));
	strcat(string,separator);

	strcat(string, utente_getMorada(utente));
	//strcat(string, "\n");

	return string;

}

void _utenteToFile(FILE * file, BST_Utentes * arvore){
	Utente * utente = bst_Utentes_getUtenteFromNode(arvore);
	ListaVeiculo * curr = utente_getListaVeiculos(utente);

	while(!listaVeiculo_isNull(curr)){
		Veiculo * veiculo = listaVeiculo_getVeiculoFromNode(curr);
		fprintf_s(file,"%s\n",_veiculoToString(veiculo));
		curr = listaVeiculo_getNextNode(curr);
	}

	fprintf_s(file,"#\n");

	fprintf_s(file,"%s", _utenteToString(utente));

	if(!bst_Utentes_isNull(bst_Utentes_getLeftNode(arvore))){
		fprintf_s(file,"#\n");
		_utenteToFile(file,bst_Utentes_getLeftNode(arvore));
	}
	if(!bst_Utentes_isNull(bst_Utentes_getRightNode(arvore))){
		fprintf_s(file,"#\n");
		_utenteToFile(file,bst_Utentes_getRightNode(arvore));
	}
}

int SAGAC_Controller_saveFile(char * filename){
	if(_initialized){
		FILE * file = NULL;
		char * linhaFicheiro = (char *)malloc(CHARBUFFSIZE);
		char tokenTypeEnd[] ="#\n"; //Tag usado para diferenciar veiculos de utentes
		char tokenPartTerminator[] ="//>\n"; //Tag usado para indicar o fim da insercao de utentes
		
		
		//===================
		//=======
		//==   GRAVA UTENTES E VEICULOS
		//=======
		//===================
		if (_sizeArvoreUtentes != 0){
			if(fopen_s(&file,filename,"w") != 0) return _false; //Caso aconteca algum erro a abrir/criar o ficheiro
		
			//TEM BUG
			//O final da primeira linha do ficheiro nao é bem escrito
			_utenteToFile(file,_arvoreUtentes);
			fprintf_s(file,"\n");
			fprintf_s(file,tokenPartTerminator);
			fprintf_s(file,"-");
			fclose(file);
		}

		return _true;
	}
	else
		return _false;
}



//========================
//========
//
// Fim   LER / GRAVAR
//
//========
//========================


//========================
//========
//
// GET'rs
//
//========
//========================
int SAGAC_isInicialized(){
		return _initialized;
}

int SAGAC_hasUsers(){
	return !bst_Utentes_isNull(_arvoreUtentes);
}

int SAGAC_getNumUtentesAdicionados(){
	if(_initialized){
		return _sizeArvoreUtentes;
	}else
		return -1;
	
	
}
int SAGAC_getNumPontosAdicionados(){
	if(_initialized){
		return _sizeListaPontos; 
	}else
		return -1;
}

enum e_UtentePenalizado SAGAC_getPenalizacaoUtente(int BI){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes, BI);
		if(utente == NULL) return e_UtentePenalizado_null; //Caso o utente não seja encontrado

		return utente_getPenalizacao(utente); 
	}else
		return e_UtentePenalizado_null;
};

//========================
//========
//
// Fim GET'rs
//
//========
//========================



//========================
//========
//
//  INICIO LISTAGENS
//
//========
//========================

//===private
//=USED in: _imprimeUtente(...)
char * utenteTipoToString(enum e_TipoUtente tipo){
	switch(tipo){
	case e_TipoUtente_morador:
		return "Morador";
		break;
	case e_TipoUtente_turista:
		return "Turista";
		break;
	case e_TipoUtente_funcionarioCamara:
		return "Funcionario da Camara";
		break;
	case e_TipoUtente_motorista:
		return "Motorista";
		break;
	case e_TipoUtente_funcionarioLimpeza:
		return "Funcionario(a) da Limpeza";
		break;
	};
	return "";
};

//===private
//=USED in: _imprimeListaVeiculos(...)
char * _veiculoTipoToString(enum e_TipoVeiculo tipo){
	switch(tipo){
	case e_tipoVeiculo_passageiros:
		return "Passageiros";
		break;
	case e_tipoVeiculo_mota:
		return "Motociclo";
		break;
	case e_tipoVeiculo_ambulancia:
		return "Ambulancia";
		break;
	case e_tipoVeiculo_taxi:
		return "Taxi";
		break;
	};
	return "";
};



//===private
//=USED in: _imprimeArvoreUtentes(...)
void _imprimeUtente(Utente * utente){
	printf("\nBI: %d", utente_getBI(utente));
	printf("\nNome: %s",utente_getNome(utente));
	printf("\nTipo Utente: %s",utenteTipoToString(utente_getTipo(utente)));
	printf("\nProfissao: %s",utente_getProfissao(utente));
	printf("\nMorada: %s\n",utente_getMorada(utente));
}

//===private
//=USED in: SAGAC_listarUtentes()
void _imprimeArvoreUtentes(BST_Utentes * current ){
	if(!bst_Utentes_isNull(current)){
		_imprimeUtente(bst_Utentes_getUtenteFromNode(current));

		printf("\n*************************\n");
		_imprimeArvoreUtentes(bst_Utentes_getLeftNode(current));
		_imprimeArvoreUtentes(bst_Utentes_getRightNode(current));
	}
}

//===private
//=USED in: _impriveListaVeiculos(...) && SAGAC_listarVeiculo(...)
void _imprimeVeiculo(Veiculo * veiculo){
	printf("\n\tMarca veiculo: %s", veiculo_getMarca(veiculo));
	printf("\n\tModelo: %s\n", veiculo_getModelo(veiculo));
	printf("\n\tMatricula: %s\n", veiculo_getMatricula(veiculo));
	printf("\n\tTipo: %s", _veiculoTipoToString(veiculo_getTipo(veiculo)));
	
}

//===private
//=USED in: SAGAC_listarVeiculos(...)
void _imprimeListaVeiculos(ListaVeiculo * lista){
	ListaVeiculo * curr = lista;
	Veiculo * veiculo;
	while(!listaVeiculo_isNull(curr)){
		veiculo = listaVeiculo_getVeiculoFromNode(curr);

		_imprimeVeiculo(veiculo);

		printf("\n*************************\n");
		curr = listaVeiculo_getNextNode(curr);
	}

}


//RETURN: 1 se a operacao executar com sucesso || 0 caso contrario
int SAGAC_listarUtentes(){
	if(_initialized){
		_imprimeArvoreUtentes(_arvoreUtentes);
		return _true; 
	}else
		return _false;
}

//RETURN: 1 se a operacao executar com sucesso || (0 Caso a operacao falhe || nao encontre o utente)
int SAGAC_listarUtente(int BI){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes, BI);
		if(utente == NULL) return _false; //Caso o utente não seja encontrado

		_imprimeUtente(utente);
		return _true; 
	}else
		return _false;
}

//RETURN: 1 se a operacao executar com sucesso || 0 caso contrario
int SAGAC_listarVeiculos(int BI){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes, BI);
		ListaVeiculo *lista;
		if(utente == NULL ) return _false; //Caso o utente não seja encontrado
		lista =utente_getListaVeiculos(utente);
		if(listaVeiculo_isNull(lista)) return _false; //Caso o utente nao tenha veiculos
		
		_imprimeListaVeiculos(lista);
		return _true; 
	}else
		return _false;
}

//RETURN: 1 se a operacao executar com sucesso || (0 Caso a operacao falhe || nao encontre o utente)
int SAGAC_listarVeiculo(int BI, char * matricula){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes, BI);
		ListaVeiculo * lista;
		if(utente == NULL) return _false; //Caso o utente não seja encontrado
		
		lista = utente_getListaVeiculos(utente);
		if(listaVeiculo_isNull(lista))
			return _false;
		else{
			

			_imprimeVeiculo(listaVeiculo_getVeiculoByMatricula(lista,matricula));
		}
		return _true; 
	}else
		return _false;
}


//========================
//========
//
// FIM  LISTAGENS
//
//========
//========================



//========================
//========
//
//  INICIO Adicionar
//
//========
//========================


//REQUIRES: _initialized = 1;
//RETURN 1 se o utente for bem introduzido
int SAGAC_adicionarUtente(char *nome, int BI, enum e_TipoUtente tipo, char *profissao, char *morada, ListaVeiculo * listaVeiculos){

	if(_initialized){ //So adiciona se SAGAC_Controller tiver sido inicializado
		Utente * novoUtente = Utente_newWithData(nome,BI,tipo,profissao,morada);

		//caso haja uma lista de veiculos, adiciona-a
		if(!listaVeiculo_isNull(listaVeiculos) || listaVeiculos != NULL)
			utente_setListaVeiculos(novoUtente, listaVeiculos);
		utente_setPenalizacao(novoUtente,e_UtentePenalizado_null);
		bst_Utentes_addUtente(_arvoreUtentes, novoUtente);
		_sizeArvoreUtentes++;

		return _true; 
	}else
		return _false;
}

int SAGAC_adicionarVeiculo(int BI, char * marca, char * modelo, char * matricula, enum e_TipoVeiculo tipo ){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes,BI);
		Veiculo * veiculoNovo;

		if(utente == NULL) return _false; //Nao conseguiu encontrar o utente;

		veiculoNovo = Veiculo_newWithData(marca,modelo,matricula, tipo);

		if(listaVeiculo_isNull(utente_getListaVeiculos(utente))){ //Caso o utente nao tenha uma lista criada
			ListaVeiculo * listaNova = ListaVeiculo_new();

			listaNova = listaVeiculo_addFirstVeiculo(listaNova,veiculoNovo);

			utente_setListaVeiculos(utente,listaNova);

		}
		else{ //Caso o utente ja tenha uma lista criada
			listaVeiculo_addLastVeiculo(utente_getListaVeiculos(utente),veiculoNovo);
		}
		return _true; 
	}else
		return _false;
}

int SAGAC_adicionaPontoAcesso(){
	if(_initialized){


		return _true;
	}
	else
		return _false;

}

//========================
//========
//
//  FIM Adicionar
//
//========
//========================

//========================
//========
//
//  INICIO Alterar
//
//========
//========================

//Altera apenas os dados que nao estiverem a null
//REQUIRES: BI_Utente != Null
//RETURN: 1 se a alteracao for efectuada com sucesso
//ENSURES: Caso encontre o utente, todos os parametros != NULL serao alterados 
int SAGAC_alterarDadosUtente(int BI_Utente, char * nomeNovo, enum e_TipoUtente tipoNovo, char * profissaoNova, char * moradaNova){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes,BI_Utente);

		if(utente == NULL) return _false; //Caso o utente nao seja encontrado
		else{
			if (nomeNovo != NULL){
				utente_setNome(utente, nomeNovo);
			}

			if (tipoNovo != e_TipoUtente_null){
				utente_setTipo(utente,tipoNovo);
			}

			if (profissaoNova != NULL){
				utente_setProfissao(utente, profissaoNova);
			}

			if (moradaNova != NULL){
				utente_setMorada(utente,moradaNova);
			}
			return _true;  //Encontrou o utente e efectuou todas as alteracoes com sucesso
		}
	}else
		return _false;
}

int SAGAC_alterarPenalizacaoUtente(int BI, enum e_UtentePenalizado penalizacao){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes,BI);

		if(utente == NULL) return _false; //Caso o utente nao seja encontrado
		else{
			utente_setPenalizacao(utente, penalizacao);

			return _true;  //Encontrou o utente e efectuou todas as alteracoes com sucesso
		}
	}else
		return _false;
};
//========================
//========
//
//  FIM Alterar
//
//========
//========================


//========================
//========
//
//  INICIO Remover
//
//========
//========================

int SAGAC_removeVeiculo(int BI, char * matricula){
	if(_initialized){
		Utente * utente = bst_Utentes_getUtenteByID(_arvoreUtentes, BI);
		ListaVeiculo * listaNova;
		
		if(utente == NULL) return _false; //Caso o utente nao seja encontrado
		listaNova = listaVeiculo_removeVeiculo(utente_getListaVeiculos(utente),matricula);

		utente_setListaVeiculos(utente,listaNova);
		_sizeArvoreUtentes--;

		return _true;
	}
	else
		return _false;
}

//========================
//========
//
//  FIM Remover
//
//========
//========================


Utente * SAGAC_GetUtenteByID(int BI) {
	return bst_Utentes_getUtenteByID(_arvoreUtentes, BI);
}

int SAGAC_CheckUtenteByID(int BI){
	return bst_Utentes_checkUtenteByID(_arvoreUtentes, BI);
}

int SAGAC_CheckMatricula(int BI,char * matricula){
	return listaVeiculo_checkVeiculoByMatricula(utente_getListaVeiculos(SAGAC_GetUtenteByID(BI)), matricula);
}

ListaPontoAcesso * SAGAH_GetListaPontoAcesso() {
	return _listaPontoAcesso;
}

void SAGAC_SetListaPontoAcesso(ListaPontoAcesso * lista) {
	_listaPontoAcesso = lista;
}