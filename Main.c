#include "SAGAC_GUI.h"
#include "SAGAC_Controller.h"


#define _true 1
#define _false 0
//#define CHARBUFFSIZE 50 //Maximo de caracteres numa string, para nom

/// <summary>
/// Codefile que ira demonstrar uma utilizacao do SAGAC.c
/// -------------------------------------------------------------------------------------------------
/// Projecto: SAGAC*
///
/// *Nome Completo: Sistema Automatizado para Gestao de Acesso condicionado 
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

// ListaPontoAcesso PontosAcesso;

int main(int argc, char **argv){
	int BI = 0;
	/*
	=======================TEST CODE======================
	int silent_mode = false;
	Veiculo * veiculo1 = test_Veiculo(silent_mode);
	ListaVeiculo * lista1 = test_ListaVeiculo(veiculo1,silent_mode);
	Utente * utente1 = test_Utente(lista1,silent_mode);
	
	
	test_bst_Utentes(utente1, silent_mode);
	//test_removerVeiculosLista(lista1, silent_mode);
	==================END OF TEST CODE======================
	*/

	WriteToLog("Inicio de Sessao");

	WriteToLog("Dados Carregados");
	
	SAGAC_Controller_new();
	
	SAGAC_Controller_readFile("database.dat");
	DrawMenuPrincipal();
	SAGAC_Controller_saveFile("database_save.dat");

	WriteToLog("Fecho de Sessao");

	//vou correr
	return 0;
}