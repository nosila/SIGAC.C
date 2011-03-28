/*
 *  ListaVeiculo.h
 */

#ifndef LISTA_VEICULO_H
#define LISTA_VEICULO_H

#include <stdlib.h>
#include "Veiculo.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd
//#define CHARBUFFSIZE 50
#define CHARSIZE sizeof(char)
#define CHARBUFFSIZE 70*CHARSIZE
#define CHARBUFFSIZE_L 50*CHARSIZE

typedef struct _nodeListaVeiculo ListaVeiculo;



// -------------
// Constructor
// -------------

ListaVeiculo * ListaVeiculo_new(void);

// -------------
// Destructor
// -------------

void ListaVeiculo_delete(ListaVeiculo * listaVeiculo);

// -------------
// GET'rs
// -------------

Veiculo * listaVeiculo_getVeiculoFromNode( ListaVeiculo * nodeListaVeiculo);

ListaVeiculo * listaVeiculo_getNextNode( ListaVeiculo * nodeListaVeiculo);

int listaVeiculo_getSize(ListaVeiculo * nodeListaVeiculo);

Veiculo * listaVeiculo_getVeiculoByMatricula( ListaVeiculo * lista, char * matricula);
int listaVeiculo_checkVeiculoByMatricula( ListaVeiculo * lista, char * matricula);

// -------------
// SET'rs
// -------------
void listaVeiculo_setVeiculo( ListaVeiculo * nodeListaVeiculo,  Veiculo * veiculo);
//void listaVeiculo_setNextNode( ListaVeiculo * listaVeiculo,  ListaVeiculo * nextListaVeiculo);

//Adiciona o veiculo no fim da lista
void listaVeiculo_addLastVeiculo( ListaVeiculo * listaVeiculo,  Veiculo * newVeiculo);

//Adiciona o veiculo no inicio da lista e retorna a nova lista
ListaVeiculo * listaVeiculo_addFirstVeiculo( ListaVeiculo * listaVeiculo,  Veiculo * newVeiculo);




ListaVeiculo * listaVeiculo_removeVeiculo(ListaVeiculo * listaVeiculo, char * matricula);

//---------------
// Functions
//---------------
int listaVeiculo_isNull(ListaVeiculo * listaVeiculo);


#endif /* LISTA_VEICULO_H */