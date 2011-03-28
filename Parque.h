/*
 *  Parque.h
 */

#ifndef PARQUE_H
#define PARQUE_H

#include <stdlib.h>
#include <string.h>

#include "ListaVeiculo.h"
#include "Veiculo.h"


typedef struct _parque Parque;



/********
 * Constructor
 ********/
Parque * Parque_new(void);
Parque * Parque_newWithData(int capacidade);

/********
 * Destructor
 ********/
void Parque_delete(Parque * parque);

/********
 * GET'rs
 ********/

int Parque_getCapacidade(Parque * parque);
int Parque_getOcupacao(Parque * parque);
int Parque_Lotado(Parque * parque);
int Parque_Vago(Parque * parque);
ListaVeiculo * Parque_getListaVeiculos(Parque * parque);
int Parque_Vagas(Parque * parque, enum e_TipoVeiculo tipo);
int Parque_GetNumLugar(Parque * parque, enum e_TipoVeiculo tipo);
int Parque_GetVagasTipos(Parque * parque, enum e_TipoVeiculo tipo);

// -------------
//
// SET'rs
//
// -------------

void Parque_setCapacidade(Parque * parque, int capacidade);
void Parque_setOcupacao(Parque * parque, int ocupacao);
void Parque_IncOcupacao(Parque * parque);
void Parque_DecOcupacao(Parque * parque);

void Parque_RegistarEntrada(Parque * parque, Veiculo * veiculo);
void Parque_RegistarSaida(Parque * parque, char * matricula);

void Parque_SetNumLugares(Parque * parque, int numAmbu, int numTaxi, int numPass, int numMota);

#endif /* PARQUE_H */
