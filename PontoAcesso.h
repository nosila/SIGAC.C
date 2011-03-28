/*
 *  PontoAcesso.h
 */

#ifndef PONTOACESSO_H
#define PONTOACESSO_H

#include <stdlib.h>
#include <string.h>
#include "Parque.h"
#include "UtentePermissoes.h"
#include "VeiculoPermissoes.h"


typedef struct _pontoAcesso PontoAcesso;



/********
 * Constructor
 ********/
PontoAcesso * PontoAcesso_new(void);
PontoAcesso * PontoAcesso_newWithData(int id, char * nome, char * descricao, int capacidade);

/********
 * Destructor
 ********/
void PontoAcesso_delete(PontoAcesso * pontoAcesso);

/********
 * GET'rs
 ********/

int pontoAcesso_getID(PontoAcesso * pontoAcesso);
char * pontoAcesso_getNome(PontoAcesso * pontoAcesso);
char * pontoAcesso_getDescricao(PontoAcesso * pontoAcesso);
//enum e_TipoUtente * pontoAcesso_getPerms(PontoAcesso * pontoAcesso);
Parque * pontoAcesso_getParque(PontoAcesso * pontoAcesso);
int pontoAcesso_PermiteUtente(PontoAcesso * pontoAcesso, enum e_TipoUtente tipo);
int pontoAcesso_PermiteVeiculo(PontoAcesso * pontoAcesso, enum e_TipoVeiculo tipo);
UtentePermissoes * pontoAcesso_GetUtentePerms(PontoAcesso * pontoAcesso);
VeiculoPermissoes * pontoAcesso_GetVeiculoPerms(PontoAcesso * pontoAcesso);

/*********
 * SET'rs
 ********/

void pontoAcesso_setID(PontoAcesso * pontoAcesso, int ID);
void pontoAcesso_setNome(PontoAcesso * pontoAcesso, char * nome);
void pontoAcesso_setDescricao(PontoAcesso * pontoAcesso, char * descricao);

int pontoAcesso_RegistarEntrada(PontoAcesso * pontoAcesso, int BI, char * matricula);
int pontoAcesso_RegistarSaida(PontoAcesso * pontoAcesso, int BI, char * matricula);

void pontoAcesso_setUtentePerms(PontoAcesso * pontoAcesso, int morador, int turista, int funcCamara, int motorista, int funcLimpeza);
void pontoAcesso_setVeiculoPerms(PontoAcesso * pontoAcesso, int ambu, int taxi, int pass, int mota);

#endif /* PONTOACESSO_H */
