#include "Utente.h"

struct _utente{
	char * nome;
	int BI;
	enum e_TipoUtente tipo;
	char * profissao;
	char * morada;
	ListaVeiculo * veiculos;
	enum e_UtentePenalizado penalizacao;
};

/********
 *
 * Constructor
 *
 ********/

Utente * Utente_new(void) {
	Utente * novo;

	if ((novo = ( Utente*)malloc(sizeof( Utente))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( Utente));

	return novo;
}

Utente * Utente_newWithData(char * nome, int BI, enum e_TipoUtente tipo, char * profissao, char * morada){
	Utente * novoUtente = Utente_new();

	utente_setNome(novoUtente, nome);
	utente_setBI(novoUtente, BI);
	utente_setTipo(novoUtente,tipo);
	utente_setProfissao(novoUtente,profissao);
	utente_setMorada(novoUtente,morada);

	return novoUtente;
};
/********
 *
 * Destructor
 *
 ********/
void Utente_delete(Utente * utente) {
	
	free(utente->nome);
	//free(utente->BI);
	//free(utente->tipo);
	free(utente->profissao);
	free(utente->morada);

	/**********
	 *
	 *vvvvvvv FALTA vvvvv
	 *
	 */

	//ListaVeiculo_delete(utente->veiculos);
	//TODO: Completar isto
	memset(utente,0xdd,sizeof( Utente));
	free(utente);
}

/********
 *
 * GET'rs
 *
 ********/


char * utente_getNome( Utente * utente){
	return utente->nome;
}

int utente_getBI( Utente * utente){
	return utente->BI;
}

enum e_TipoUtente utente_getTipo( Utente * utente){
	return utente->tipo;
}

char * utente_getProfissao( Utente * utente){
	return utente->profissao;
}

char * utente_getMorada( Utente * utente){
	return utente->morada;
}

ListaVeiculo * utente_getListaVeiculos( Utente * utente){
	if (!utente_isNull(utente) )
		return utente->veiculos;
	return NULL;
}

 Veiculo * utente_getVeiculoByMatricula(Utente * utente, char * matricula){

	 return listaVeiculo_getVeiculoByMatricula(utente->veiculos, matricula);
 }

 enum e_UtentePenalizado utente_getPenalizacao(Utente * utente){
	 return utente->penalizacao;
 };

int utente_isNull(Utente * utente){
	return utente == NULL || 
		(unsigned int) utente == NEW ||
		(unsigned int)utente->morada ==NEW &&
		(unsigned int)utente->nome ==NEW &&
		(unsigned int)utente->profissao ==NEW &&
		listaVeiculo_isNull(utente->veiculos);
}




 /*********
 *
 * SET'rs
 *
 ********/

void utente_setNome( Utente * utente, char * nome){
	utente->nome = nome;
}

void utente_setBI( Utente * utente, int BI){
	utente->BI = BI;
}

void utente_setTipo( Utente * utente, enum e_TipoUtente tipo){
	utente->tipo = tipo;
};

void utente_setProfissao( Utente * utente, char * profissao){
	utente->profissao = profissao;
}

void utente_setMorada( Utente * utente, char * morada){
	utente->morada = morada;
}

void utente_setVeiculoNovo( Utente * utente,  Veiculo * veiculo){
	listaVeiculo_addLastVeiculo(utente->veiculos, veiculo);
}

void utente_setListaVeiculos( Utente * utente,  ListaVeiculo * lista){
	utente->veiculos = lista;
}

void utente_setPenalizacao(Utente * utente, enum e_UtentePenalizado penalizacao){
	utente->penalizacao = penalizacao;
};