/*
 *  ListaPontoAcesso.h
 */

#ifndef LISTA_PONTOACESSO_H
#define LISTA_PONTOACESSO_H


#include "PontoAcesso.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd

typedef struct _nodeListaPontoAcesso ListaPontoAcesso;


// -------------
// Constructor
// -------------
ListaPontoAcesso * ListaPontoAcesso_new(void);

// -------------
// Destructor
// -------------
void ListaPontoAcesso_delete(ListaPontoAcesso * listaPontoAcesso);

// -------------
// GET'rs
// -------------
PontoAcesso * listaPontoAcesso_getPontoAcessoFromNode( ListaPontoAcesso * nodeListaPontoAcesso);
ListaPontoAcesso * listaPontoAcesso_getNextNode( ListaPontoAcesso * nodeListaPontoAcesso);
void listaPontoAcesso_Listar(ListaPontoAcesso * nodeListaPontoAcesso);
void listaPontoAcesso_ListarPontoAcesso(ListaPontoAcesso * listaPontoAcesso, char * nome);
PontoAcesso * listaPontoAcesso_getPontoAcesso(ListaPontoAcesso * lista, char* nome);
void listaPontoAcesso_ListarLugaresLotados(ListaPontoAcesso * lista);
void listaPontoAcesso_ListarLugaresVagos(ListaPontoAcesso * listaPontoAcesso);
void listaPontoAcesso_ListarEntradasSaidas(ListaPontoAcesso * listaPontoAcesso);
int listaPontoAcesso_GetCount(void);

// -------------
// SET'rs
// -------------
void listaPontoAcesso_setPontoAcesso( ListaPontoAcesso * nodeListaPontoAcesso,  PontoAcesso * pontoAcesso);
void listaPontoAcesso_setNextNode( ListaPontoAcesso * listaPontoAcesso,  ListaPontoAcesso * nextListaPontoAcesso);
ListaPontoAcesso * listaPontoAcesso_addFirstPontoAcesso( ListaPontoAcesso * listaPontoAcesso,  PontoAcesso * pontoAcesso);

int listaPontoAcesso_isNull(ListaPontoAcesso * listaPontoAcesso);

ListaPontoAcesso * listaPontoAcesso_Adicionar(ListaPontoAcesso * listaPontoAcesso);
int listaPontoAcesso_Remover(ListaPontoAcesso * listaPontoAcesso, char* nome);
int listaPontoAcesso_AlterarCapacidade(ListaPontoAcesso * listaPontoAcesso, char* nome, int capacidade);
int listaPontoAcesso_AlterarDescricao(ListaPontoAcesso * listaPontoAcesso, char* nome, char* desc);
int listaPontoAcesso_AlterarPermissoes(ListaPontoAcesso * listaPontoAcesso, char* nome, int utente);
int listaPontoAcesso_AlterarTipoLugares(ListaPontoAcesso * listaPontoAcesso, char * nome, int numPass, int numAmbu, int numTaxi, int numMota);

int listaPontoAcesso_GetIDByName(ListaPontoAcesso * listaPontoAcesso, char* nome);

void ListaPontoAcesso_DecCount(void);
void ListaPontoAcesso_IncCount(void);

int listaPontoAcesso_Existe(ListaPontoAcesso * lista, char* nome);


#endif /* LISTA_PONTOACESSO_H */