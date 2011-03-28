#ifndef SAGAC_H
#define SAGAC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaPontoAcesso.h"
#include "Utente.h"
#include "BST_Utentes.h"
#include "ListaVeiculo.h"

#define CHARSIZE sizeof(char)
#define CHARBUFFSIZE 70*CHARSIZE
#define CHARBUFFSIZE_L 50*CHARSIZE
enum {_false,_true};

/// <summary>
/// Header file do codefile SAGAC.c
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
///		-
/// </summary>



// -------------
// Constructor
// -------------
void SAGAC_Controller_new();

//========================
//========
//
// LER / GRAVAR
//
//========
//========================

int SAGAC_Controller_readFile(char * filename);
int SAGAC_Controller_saveFile(char * filename);

//========================
//========
//
// SET'rs
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
int SAGAC_getNumUtentesAdicionados();
int SAGAC_isInicialized();
int SAGAC_hasUsers();
int SAGAC_getNumPontosAdicionados();
enum e_UtentePenalizado SAGAC_getPenalizacaoUtente(int BI);
//========================
//========
//
//  LISTAGENS
//
//========
//========================

//RETURN: 1 se a operacao executar com sucesso || 0 caso contrario
int SAGAC_listarUtentes(void);

//RETURN: 1 se a operacao executar com sucesso || (0 Caso a operacao falhe || nao encontre o utente)
int SAGAC_listarUtente(int BI);

//RETURN: 1 se a operacao executar com sucesso || 0 caso contrario
int SAGAC_listarVeiculos(int BI);

//RETURN: 1 se a operacao executar com sucesso || (0 Caso a operacao falhe || nao encontre o utente)
int SAGAC_listarVeiculo(int BI, char * matricula);

//========================
//========
//
//  Adicionar
//
//========
//========================

//REQUIRES: SAGAC_istInicialized();
//RETURN 1 se o utente for bem introduzido
int SAGAC_adicionarUtente(char *nome, int BI, enum e_TipoUtente tipo, char *profissao, char *morada, ListaVeiculo * listaVeiculos);

//REQUIRES: SAGAC_istInicialized();
//RETURN 1 se o veiculo for bem introduzido
int SAGAC_adicionarVeiculo(int BI, char * marca, char * modelo, char * matricula, enum e_TipoVeiculo tipo );


//========================
//========
//
//  Alterar
//
//========
//========================

//Altera apenas os dados que nao estiverem a null
//REQUIRES: BI_Utente != Null
//RETURN: 1 se a alteracao for efectuada com sucesso
//ENSURES: Caso encontre o utente, todos os parametros != NULL serao alterados 
int SAGAC_alterarDadosUtente(int BI_Utente, char * nomeNovo, enum e_TipoUtente tipoNovo, char * profissaoNova, char * moradaNova);
int SAGAC_alterarPenalizacaoUtente(int BI, enum e_UtentePenalizado penalizacao);

//========================
//========
//
//  Remover
//
//========
//========================

int SAGAC_removeVeiculo(int BI, char * matricula);

Utente * SAGAC_GetUtenteByID(int BI);
int SAGAC_CheckUtenteByID(int BI);
int SAGAC_CheckMatricula(int BI,char * matricula);

ListaPontoAcesso * SAGAH_GetListaPontoAcesso();
void SAGAC_SetListaPontoAcesso(ListaPontoAcesso * lista);


#endif //SAGAC_H