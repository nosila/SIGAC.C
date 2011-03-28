/*
 *  Veiculo.h
 */

#ifndef VEICULO_H
#define VEICULO_H

#include <stdlib.h>
#include <string.h>

//#include "Utente.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd

typedef struct _veiculo Veiculo;



enum e_TipoVeiculo{
	e_TipoVeiculo_null = -1,
	e_tipoVeiculo_passageiros = 1,
	e_tipoVeiculo_mota,
	e_tipoVeiculo_ambulancia,
	e_tipoVeiculo_taxi
};


/********
 * Constructor
 ********/
Veiculo * Veiculo_new(void);
Veiculo * Veiculo_newWithData(char * marca, char * modelo, char * matricula, enum e_TipoVeiculo tipo);
/********
 * Destructor
 ********/
void Veiculo_delete(Veiculo * veiculo);

/********
 * GET'rs
 ********/
 //Utente * veiculo_getUtente( Veiculo * veiculo);
 char * veiculo_getMarca( Veiculo * veiculo);
 char * veiculo_getModelo( Veiculo * veiculo);
 char * veiculo_getMatricula( Veiculo * veiculo);
 enum e_TipoVeiculo veiculo_getTipo( Veiculo * veiculo);
 time_t veiculo_getHoraEntrada(Veiculo * veiculo);

/*********
 * SET'rs
 ********/

//void veiculo_setUtente( Veiculo * veiculo,  Utente * utente);
void veiculo_setMarca( Veiculo * veiculo, char * marca);
void veiculo_setModelo( Veiculo * veiculo, char * modelo);
void veiculo_setMatricula( Veiculo * veiculo, char * matricula);
void veiculo_setTipo( Veiculo * veiculo, enum e_TipoVeiculo tipo);
void veiculo_setHoraEntrada(Veiculo * veiculo, time_t horaEntrada);


#endif /* VEICULO_H */