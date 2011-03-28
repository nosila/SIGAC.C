#include "Veiculo.h"

struct _veiculo{
	//Utente * dono;
	char * marca;
	char * modelo;
	char * matricula;
	enum e_TipoVeiculo tipo;
	time_t horaEntrada;
};



// -------------
//
// Constructor
//
// -------------
Veiculo * Veiculo_new(void) {
	Veiculo * novo;

	if ((novo = ( Veiculo*)malloc(sizeof(Veiculo))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( Veiculo));

	return novo;
}

Veiculo * Veiculo_newWithData(char * marca, char * modelo, char * matricula, enum e_TipoVeiculo tipo){
	Veiculo * veiculoNovo;

	if ((veiculoNovo = ( Veiculo*)malloc(sizeof( Veiculo))) == NULL) { 
		exit(1);
	}
	veiculo_setMarca(veiculoNovo, marca);
	veiculo_setModelo(veiculoNovo, modelo);
	veiculo_setMatricula(veiculoNovo, matricula);
	veiculo_setTipo(veiculoNovo,tipo);

	return veiculoNovo;
}

// -------------
//
// Destructor
//
// -------------
void Veiculo_delete( Veiculo * veiculo) {
	
	//free(veiculo->dono);
	free(veiculo->marca);
	free(veiculo->modelo);
	free(veiculo->matricula);
	//free(veiculo->tipo);
	
	memset(veiculo,0xdd,sizeof( Veiculo));
	free(veiculo);
}

// -------------
//
// GET'rs
//
// -------------

/*
Utente * veiculo_getUtente( Veiculo * veiculo){
	return veiculo->dono;
}
*/

char * veiculo_getMarca( Veiculo * veiculo){
	return veiculo->marca;
}

char * veiculo_getModelo( Veiculo * veiculo){
	return veiculo->modelo;
}

char * veiculo_getMatricula( Veiculo * veiculo){
	if (veiculo != NULL)
		return veiculo->matricula;

	return NULL;
}


enum e_TipoVeiculo veiculo_getTipo( Veiculo * veiculo){
	return veiculo->tipo;
}

time_t veiculo_getHoraEntrada(Veiculo * veiculo){
	return veiculo->horaEntrada;
}

// -------------
//
// SET'rs
//
// -------------

/*
void veiculo_setUtente( Veiculo * veiculo,  Utente * utente){
	veiculo->dono = utente;
}
*/
void veiculo_setMarca( Veiculo * veiculo, char * marca){
	veiculo->marca = marca;
}

void veiculo_setModelo( Veiculo * veiculo, char * modelo){
	veiculo->modelo = modelo;
}

void veiculo_setMatricula( Veiculo * veiculo, char * matricula){
	veiculo->matricula = matricula;
}

void veiculo_setTipo( Veiculo * veiculo, enum e_TipoVeiculo tipo){
	veiculo->tipo = tipo;
}

void veiculo_setHoraEntrada(Veiculo * veiculo, time_t horaEntrada){
	veiculo->horaEntrada = horaEntrada;
}
