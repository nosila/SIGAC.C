#include "PontoAcesso.h"
#include "Parque.h"
#include "Utente.h"
#include "Veiculo.h"
#include "ListaVeiculo.h"
#include "ListaPontoAcesso.h"
#include "UtentePermissoes.h"
#include "VeiculoPermissoes.h"
#include "BST_Utentes.h"
#include "SAGAC_Controller.h"
#include <stdio.h>
#include <time.h>

#define CUSTO_MORADOR 10
#define CUSTO_TURISTA 50

struct _pontoAcesso{
	int id;
	char * nome;
	char * descricao;
	Parque * parque;
	UtentePermissoes * utentePerms;
	VeiculoPermissoes * veiculoPerms;
};


// -------------
//
// Constructor
//
// -------------
PontoAcesso * PontoAcesso_new(void) {
	PontoAcesso * novo;

	if ((novo = ( PontoAcesso*)malloc(sizeof( PontoAcesso))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( PontoAcesso));

	novo->parque = Parque_new();
	novo->utentePerms = UtentePermissoes_new();
	novo->veiculoPerms = VeiculoPerms_new();

	ListaPontoAcesso_IncCount();

	return novo;
}

PontoAcesso * PontoAcesso_newWithData(int id, char * nome, char * descricao, int capacidade) {
	PontoAcesso * novoPonto = PontoAcesso_new();
	Parque * parque = NULL;

	pontoAcesso_setID(novoPonto, id);
	pontoAcesso_setNome(novoPonto, nome);
	pontoAcesso_setDescricao(novoPonto, descricao);

	parque = pontoAcesso_getParque(novoPonto);
	Parque_setCapacidade(parque, capacidade);

	return novoPonto;
}

// -------------
//
// Destructor
//
// -------------
void PontoAcesso_delete( PontoAcesso * pontoAcesso) {
	
	free(pontoAcesso->nome);
	free(pontoAcesso->descricao);
	
	memset(pontoAcesso,0xdd,sizeof( PontoAcesso));
	free(pontoAcesso);

	ListaPontoAcesso_DecCount();
}

// -------------
//
// GET'rs
//
// -------------

int pontoAcesso_getID(PontoAcesso * pontoAcesso) {
	return pontoAcesso->id;
}

char * pontoAcesso_getNome(PontoAcesso * pontoAcesso) {
	return pontoAcesso->nome;
}

char * pontoAcesso_getDescricao(PontoAcesso * pontoAcesso) {
	return pontoAcesso->descricao;
}

Parque * pontoAcesso_getParque(PontoAcesso * pontoAcesso) {
	return pontoAcesso->parque;
}


// -------------
//
// SET'rs
//
// -------------

void pontoAcesso_setID(PontoAcesso * pontoAcesso, int ID) {
	pontoAcesso->id = ID;
}

void pontoAcesso_setNome(PontoAcesso * pontoAcesso, char * nome) {
	pontoAcesso->nome = nome;
}

void pontoAcesso_setDescricao(PontoAcesso * pontoAcesso, char * descricao) {
	pontoAcesso->descricao = descricao;
}

int pontoAcesso_RegistarEntrada(PontoAcesso * pontoAcesso, int BI, char * matricula) {
	PontoAcesso * ponto = pontoAcesso;
	Utente * utente = NULL;
	Veiculo * veiculo = NULL;
	time_t horaEntrada = time(NULL);
	char log[500] = "";
	utente = SAGAC_GetUtenteByID(BI);
	veiculo = listaVeiculo_getVeiculoByMatricula(utente_getListaVeiculos(utente), matricula);

	if (utente == NULL || veiculo == NULL || (unsigned int) utente == NEW || (unsigned int)  veiculo == NEW || (unsigned int) utente == DELETED || (unsigned int) veiculo == DELETED)
		return 0;

	if (pontoAcesso_PermiteUtente(ponto, utente_getTipo(utente)) && 
		pontoAcesso_PermiteVeiculo(ponto, veiculo_getTipo(veiculo)) && 
		Parque_Vagas(pontoAcesso_getParque(ponto), veiculo_getTipo(veiculo)) && 
		utente_getPenalizacao(utente) != e_UtentePenalizado_nao)
	{
		Parque_RegistarEntrada(pontoAcesso->parque, veiculo);
		veiculo_setHoraEntrada(veiculo, horaEntrada);

		strcat(log, "Entrada->Veiculo: ");
		strcat(log, veiculo_getMarca(veiculo));
		strcat(log, ", ");
		strcat(log, veiculo_getModelo(veiculo));
		strcat(log, " - Utente: ");
		strcat(log, utente_getNome(utente));
		strcat(log, " - No Ponto de Acesso: ");
		strcat(log, pontoAcesso_getNome(ponto));
		WriteToLog(log);

		return 1;
	}

	return 0;
}

int pontoAcesso_RegistarSaida(PontoAcesso * pontoAcesso, int BI, char * matricula) {
	PontoAcesso * ponto = pontoAcesso;
	Utente * utente = SAGAC_GetUtenteByID(BI);
	Veiculo * veiculo = NULL;
	int minutos = 0;
	time_t dif = time(NULL);
	struct tm *ptm = NULL;
	enum e_TipoUtente tp;
	char log[500] = "";
	veiculo = listaVeiculo_getVeiculoByMatricula(utente_getListaVeiculos(utente), matricula);

	if (veiculo == NULL || (unsigned int) veiculo == NEW || (unsigned int) veiculo == DELETED)
	{
		printf("             NAO FOI ENCONTRADO O VEICULO                \n");
		system("pause");
		return 0;
	}

	dif = dif - veiculo_getHoraEntrada(veiculo);
	ptm = localtime(&dif);	
	minutos = ptm->tm_min;

	if (utente == NULL || pontoAcesso == NULL)
		return 0;

	tp = utente_getTipo(utente);

	switch (tp) {
	case e_TipoUtente_morador:
		printf("Valor a pagar-> %f Euros", CUSTO_MORADOR * minutos);
		break;
	case e_TipoUtente_turista:
		printf("Valor a pagar-> %f Euros", CUSTO_TURISTA * minutos);
		break;
	}

	Parque_RegistarSaida(pontoAcesso->parque, matricula);

	strcat(log, "Saida->Veiculo: ");
	strcat(log, veiculo_getMarca(veiculo));
	strcat(log, ", ");
	strcat(log, veiculo_getModelo(veiculo));
	strcat(log, " - Utente: ");
	strcat(log, utente_getNome(utente));
	strcat(log, " - No Ponto de Acesso: ");
	strcat(log, pontoAcesso_getNome(ponto));
	WriteToLog(log);

	return 1;
}

int pontoAcesso_PermiteUtente(PontoAcesso * pontoAcesso, enum e_TipoUtente tipo) {
	switch (tipo) {
	case e_TipoUtente_funcionarioCamara:
		return UtentePerms_PermiteFuncionarioCamara(pontoAcesso->utentePerms);
	case e_TipoUtente_funcionarioLimpeza:
		return UtentePerms_PermiteFuncionarioLimpeza(pontoAcesso->utentePerms);
	case e_TipoUtente_morador:
		return UtentePerms_PermiteMorador(pontoAcesso->utentePerms);
	case e_TipoUtente_motorista:
		return UtentePerms_PermiteMotorista(pontoAcesso->utentePerms);
	case e_TipoUtente_turista:
		return UtentePerms_PermiteTurista(pontoAcesso->utentePerms);
	
	default:
		return 0;
	}
}

int pontoAcesso_PermiteVeiculo(PontoAcesso * pontoAcesso, enum e_TipoVeiculo tipo) {
		switch (tipo) {
		case e_tipoVeiculo_ambulancia:
			return VeiculoPerms_PermiteAmbulancia(pontoAcesso->veiculoPerms);
		case e_tipoVeiculo_mota:
			return VeiculoPerms_PermiteMota(pontoAcesso->veiculoPerms);
		case e_tipoVeiculo_passageiros:
			return VeiculoPerms_PermitePassageiros(pontoAcesso->veiculoPerms);
		case e_tipoVeiculo_taxi:
			return VeiculoPerms_PermiteTaxi(pontoAcesso->veiculoPerms);
		default:
			return 0;
	}
}

void pontoAcesso_setUtentePerms(PontoAcesso * pontoAcesso, int morador, int turista, int funcCamara, int motorista, int funcLimpeza) {
	UtentePerms_SetPermiteFuncionarioCamara(pontoAcesso->utentePerms, funcCamara);
	UtentePerms_SetPermiteFuncionarioLimpeza(pontoAcesso->utentePerms, funcLimpeza);
	UtentePerms_SetPermiteMorador(pontoAcesso->utentePerms, morador);
	UtentePerms_SetPermiteMotorista(pontoAcesso->utentePerms, motorista);
	UtentePerms_SetPermiteTurista(pontoAcesso->utentePerms, turista);
}

void pontoAcesso_setVeiculoPerms(PontoAcesso * pontoAcesso, int ambu, int taxi, int pass, int mota) {
	VeiculoPerms_SetPermiteAmbulancia(pontoAcesso->veiculoPerms, ambu);
	VeiculoPerms_SetPermiteTaxi(pontoAcesso->veiculoPerms, taxi);
	VeiculoPerms_SetPermiteMota(pontoAcesso->veiculoPerms, mota);
	VeiculoPerms_SetPermitePassageiros(pontoAcesso->veiculoPerms, pass);
}

UtentePermissoes * pontoAcesso_GetUtentePerms(PontoAcesso * pontoAcesso) {
	return pontoAcesso->utentePerms;
}

VeiculoPermissoes * pontoAcesso_GetVeiculoPerms(PontoAcesso * pontoAcesso) {
	return pontoAcesso->veiculoPerms;
}
