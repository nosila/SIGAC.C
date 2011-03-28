#include "Parque.h"
#include "ListaVeiculo.h"
#include "Veiculo.h"
#include <stdio.h>


struct _parque {
	int Capacidade;
	int Ocupacao;
	ListaVeiculo * veiculos;

	int NumAmbulancia;
	int NumTaxi;
	int NumPassageiros;
	int NumMota;
};


// -------------
//
// Constructor
//
// -------------
Parque * Parque_new(void) {
	Parque * novo;

	if ((novo = ( Parque*)malloc(sizeof( Parque))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( Parque));

	novo->Capacidade = 0;
	novo->Ocupacao = 0;
	novo->NumAmbulancia = 0;
	novo->NumMota = 0;
	novo->NumPassageiros = 0;
	novo->NumTaxi = 0;

	return novo;
}

Parque * Parque_newWithData(int capacidade) {
	Parque * novoParque = Parque_new();
	Parque_setCapacidade(novoParque, capacidade);
	novoParque->NumPassageiros = capacidade;

	return novoParque;
}

// -------------
//
// Destructor
//
// -------------
void Parque_delete( Parque * parque) {
	memset(parque,0xdd,sizeof( Parque));
	free(parque);
}

// -------------
//
// GET'rs
//
// -------------

int Parque_getCapacidade(Parque * parque) {
	return parque->Capacidade;
}

int Parque_getOcupacao(Parque * parque) {
	return parque->Ocupacao;
}

int Parque_Lotado(Parque * parque) {
	if (parque->Ocupacao >= parque->Capacidade)
		return 1;
	else
		return 0;
}

int Parque_Vago(Parque * parque) {
	if (parque->Ocupacao < parque->Capacidade)
		return 1;
	else return 0;
}

ListaVeiculo * Parque_getListaVeiculos(Parque * parque) {
	return parque->veiculos;
}

int Parque_Vagas(Parque * parque, enum e_TipoVeiculo tipo) {
	switch (tipo) {
	case e_tipoVeiculo_ambulancia:
		return parque->NumAmbulancia > 0;
	case e_tipoVeiculo_mota:
		return parque->NumMota > 0;
	case e_tipoVeiculo_passageiros:
		return parque->NumPassageiros > 0;
	case e_tipoVeiculo_taxi:
		return parque->NumTaxi > 0;
	}

	return 0;
}

int Parque_GetNumLugar(Parque * parque, enum e_TipoVeiculo tipo) {
	switch (tipo) {
	case e_tipoVeiculo_ambulancia:
		return parque->NumAmbulancia;
	case e_tipoVeiculo_mota:
		return parque->NumMota;
	case e_tipoVeiculo_passageiros:
		return parque->NumPassageiros;
	case e_tipoVeiculo_taxi:
		return parque->NumTaxi;
	default:
		return 0;
	}
}

int Parque_GetVagasTipos(Parque * parque, enum e_TipoVeiculo tipo) {
	int ignore = 0;

	switch (tipo) {
	case e_tipoVeiculo_ambulancia:
		ignore = parque->NumAmbulancia;
	case e_tipoVeiculo_mota:
		ignore = parque->NumMota;
	case e_tipoVeiculo_passageiros:
		ignore = parque->NumPassageiros;
	case e_tipoVeiculo_taxi:
		ignore = parque->NumTaxi;
	}

	if (parque != NULL)
		return (parque->Capacidade - (parque->NumAmbulancia + parque->NumPassageiros + parque->NumTaxi + parque->NumMota)) - ignore;
	
	return 0;
}

// -------------
//
// SET'rs
//
// -------------

void Parque_setCapacidade(Parque * parque, int capacidade) {
	parque->Capacidade = capacidade;
}

void Parque_setOcupacao(Parque * parque, int ocupacao) {
	parque->Ocupacao = ocupacao;
}

void Parque_IncOcupacao(Parque * parque) {
	if ((parque->Ocupacao + 1) <= parque->Capacidade)
		parque->Ocupacao++;
}

void Parque_DecOcupacao(Parque * parque) {
	if (parque->Ocupacao > 0) parque->Ocupacao--;
}

void Parque_RegistarEntrada(Parque * parque, Veiculo * veiculo) {
	Parque_IncOcupacao(parque);
	parque->veiculos = listaVeiculo_addFirstVeiculo(parque->veiculos, veiculo);
	switch (veiculo_getTipo(veiculo)) {
	case e_tipoVeiculo_ambulancia:
		parque->NumAmbulancia--;
		break;
	
	case e_tipoVeiculo_mota:
		parque->NumMota--;
		break;

	case e_tipoVeiculo_passageiros:
		parque->NumPassageiros--;
		break;

	case e_tipoVeiculo_taxi:
		parque->NumTaxi--;
	}
}

void Parque_RegistarSaida(Parque * parque, char * matricula) {
	Parque_DecOcupacao(parque);
	switch (veiculo_getTipo(listaVeiculo_getVeiculoByMatricula(parque->veiculos, matricula))) {
		case e_tipoVeiculo_ambulancia:
			parque->NumAmbulancia++;
			break;
	
		case e_tipoVeiculo_mota:
			parque->NumMota++;
			break;

		case e_tipoVeiculo_passageiros:
			parque->NumPassageiros++;
			break;

		case e_tipoVeiculo_taxi:
			parque->NumTaxi++;
	}
	listaVeiculo_removeVeiculo(Parque_getListaVeiculos(parque), matricula);
}

void Parque_SetNumLugares(Parque * parque, int numAmbu, int numTaxi, int numPass, int numMota) {
	parque->NumAmbulancia = numAmbu;
	parque->NumTaxi = numTaxi;
	parque->NumPassageiros = numPass;
	parque->NumMota = numMota;
}
