/*
 *  Utente.h
 */


#ifndef UTENTE_H
#define UTENTE_H

#include "ListaVeiculo.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd

typedef struct _utente Utente;

//Usado na restricao do acesso a lugares de estacionamento
enum e_TipoUtente{
	e_TipoUtente_null = -1,
	e_TipoUtente_morador = 1,
	e_TipoUtente_turista,
	e_TipoUtente_funcionarioCamara,
	e_TipoUtente_motorista,
	e_TipoUtente_funcionarioLimpeza
};

enum e_UtentePenalizado{
	e_UtentePenalizado_null = -1,
	e_UtentePenalizado_nao = 1,
	e_UtentePenalizado_sim
};

/********
 * Constructor
 ********/

Utente * Utente_new(void);
Utente * Utente_newWithData(char * nome, int BI, enum e_TipoUtente tipo, char * profissao, char * morada);

/********
 * Destructor
 ********/
void Utente_delete(Utente * utente);

/********
 * GET'rs
 ********/
char * utente_getNome( Utente * utente);
int utente_getBI( Utente * utente);
enum e_TipoUtente utente_getTipo( Utente * utente);
char * utente_getProfissao( Utente * utente);
char * utente_getMorada( Utente * utente);
ListaVeiculo * utente_getListaVeiculos( Utente * utente);
Veiculo * utente_getVeiculoByMatricula(Utente * utente, char * matricula);
enum e_UtentePenalizado utente_getPenalizacao(Utente * utente);

int utente_isNull(Utente * utente);

/*********
 * SET'rs
 ********/
void utente_setNome( Utente * utente, char * nome);
void utente_setBI( Utente * utente, int BI);
void utente_setTipo( Utente * utente, enum e_TipoUtente tipo);
void utente_setProfissao( Utente * utente, char * profissao);
void utente_setMorada( Utente * utente, char * morada);
void utente_setVeiculoNovo( Utente * utente,  Veiculo * veiculo);
void utente_setListaVeiculos( Utente * utente,  ListaVeiculo * lista);
void utente_setPenalizacao(Utente * utente, enum e_UtentePenalizado penalizacao);



#endif /* UTENTE_H */