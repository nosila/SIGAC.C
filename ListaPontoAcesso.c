#include "ListaPontoAcesso.h"
#include "Parque.h"
#include "SAGAC_GUI.h"
#include <stdio.h>
#include <string.h>
#include "UtentePermissoes.h"
#include "VeiculoPermissoes.h"
#include "PontoAcesso.h"

//#define CHARBUFFSIZE 50
#define CHARSIZE sizeof(char)
#define CHARBUFFSIZE 70*CHARSIZE
#define CHARBUFFSIZE_L 50*CHARSIZE


int pontoAcessoID = 1;
int count = 0;

struct _nodeListaPontoAcesso {
	ListaPontoAcesso * nextNode;
	PontoAcesso * pontoAcesso;
};


// -------------
//
// Constructor
//
// -------------
ListaPontoAcesso * ListaPontoAcesso_new(void) {
	ListaPontoAcesso * novo;

	if ((novo = ( ListaPontoAcesso*)malloc(sizeof( ListaPontoAcesso))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( ListaPontoAcesso));

	return novo;
}

// -------------
//
// Destructor
//
// -------------

void ListaPontoAcesso_delete( ListaPontoAcesso * listaPontoAcesso) {
	free(listaPontoAcesso->nextNode);

	memset(listaPontoAcesso,0xdd,sizeof( ListaPontoAcesso));
	free(listaPontoAcesso);
}

// -------------
//
// GET'rs
//
// -------------

// PONTO ACESSO FROM NODE
PontoAcesso * listaPontoAcesso_getPontoAcessoFromNode( ListaPontoAcesso * nodeListaPontoAcesso){
	return nodeListaPontoAcesso->pontoAcesso;
}

// PROXIMO NODE
ListaPontoAcesso * listaPontoAcesso_getNextNode( ListaPontoAcesso * nodeListaPontoAcesso){
	return nodeListaPontoAcesso->nextNode;
}

// LISTAR LUGARES LOTADOS
void listaPontoAcesso_ListarLugaresLotados(ListaPontoAcesso * lista) {
	ListaPontoAcesso * aux = lista;
	PontoAcesso * current = NULL;
	int numLotados = 0;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
		{
			current = aux->pontoAcesso;

			if (Parque_Lotado(pontoAcesso_getParque(aux->pontoAcesso)))
			{
				printf("LOTADO: %s\n", pontoAcesso_getNome(aux->pontoAcesso));
				numLotados++;
			}
		}

		if (listaPontoAcesso_isNull(aux->nextNode))
			break;
		else
			aux = aux->nextNode;
	}

	if (numLotados == 0)
		printf("NAO EXISTEM PONTOS DE ACESSO LOTADOS!\n\n");
}

void listaPontoAcesso_ListarLugaresVagos(ListaPontoAcesso * listaPontoAcesso) {
	ListaPontoAcesso * aux = listaPontoAcesso;
	PontoAcesso * current = NULL;
	int numVagos = 0;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
		{
			current = aux->pontoAcesso;

			if (Parque_Vago(pontoAcesso_getParque(aux->pontoAcesso)))
			{
				printf("VAGO: %s\n", pontoAcesso_getNome(aux->pontoAcesso));
				numVagos++;
			}
		}

		if (listaPontoAcesso_isNull(aux->nextNode))
			break;
		else
			aux = aux->nextNode;
	}

	if (numVagos == 0)
		printf("NAO EXISTEM PONTOS DE ACESSO COM VAGA!\n\n");
}

void listaPontoAcesso_ListarEntradasSaidas(ListaPontoAcesso * listaPontoAcesso) {
	// TODO:
}

int listaPontoAcesso_GetCount(void) {
	return count;
}


// -------------
//
// SET'rs
//
// -------------

void listaPontoAcesso_setPontoAcesso( ListaPontoAcesso * nodeListaPontoAcesso,  PontoAcesso * pontoAcesso){
	nodeListaPontoAcesso->pontoAcesso = pontoAcesso;
}

void listaPontoAcesso_setNextNode( ListaPontoAcesso * listaPontoAcesso,  ListaPontoAcesso * nextListaPontoAcesso){
	listaPontoAcesso->nextNode = nextListaPontoAcesso;
}

int listaPontoAcesso_isNull(ListaPontoAcesso * listaPontoAcesso){
	return (unsigned int)listaPontoAcesso == NEW ||  //este teste e necessario para quando se chega ao penultimo node e tenta-se aceder a node->nextNode
		(unsigned int)listaPontoAcesso->nextNode == NEW && 
		(unsigned int)listaPontoAcesso->pontoAcesso == NEW;
}

ListaPontoAcesso * listaPontoAcesso_addFirstPontoAcesso( ListaPontoAcesso * listaPontoAcesso,  PontoAcesso * pontoAcesso) {
	ListaPontoAcesso * newNode = ListaPontoAcesso_new();

	newNode->pontoAcesso = pontoAcesso;
	newNode->nextNode = listaPontoAcesso;

	return newNode;
}

ListaPontoAcesso * listaPontoAcesso_Adicionar(ListaPontoAcesso * listaPontoAcesso) {
	PontoAcesso * novo = NULL;

	char * nome = (char *)malloc(CHARBUFFSIZE);
	char * desc = (char *)malloc(CHARBUFFSIZE);
	int capacidade = 0;

	char *lixo = "";
	char token[] ="\n";
	char pontonome[50] = "";

	fflush(stdin);
	printf("\nNome: ");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	if (listaPontoAcesso_Existe(listaPontoAcesso, nome))
	{
		printf("            JA EXISTE UM PONTO DE ACESSO COM O NOME INDICADO                \n");
		system("pause");
		return;
	}

	printf("\nDescricao: ");
	fgets(desc, CHARBUFFSIZE, stdin);
	strtok_s(desc,token,&lixo);
	fflush(stdin);

	printf("\nCapacidade: ");
	scanf_s("%d", &capacidade);

	novo = PontoAcesso_newWithData(pontoAcessoID++, nome, desc, capacidade);

	SAGAC_SetListaPontoAcesso(listaPontoAcesso_addFirstPontoAcesso(listaPontoAcesso, novo));
	
	strcat(pontonome, "Ponto de Acesso: ");
	strcat(pontonome, nome);
	strcat(pontonome, " Criado");
	WriteToLog(pontonome);

	printf("\n");
	printf("                            PONTO DE ACESSO INSERIDO!                          \n");

	
	return NULL;
}

int listaPontoAcesso_Remover(ListaPontoAcesso * listaPontoAcesso, char* nome) {
	ListaPontoAcesso * aux = listaPontoAcesso;
	ListaPontoAcesso * ant = NULL;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
			if (strcmp( pontoAcesso_getNome(aux->pontoAcesso), nome ) == 0)
			{
				if (ant != NULL)
				{
					ant->nextNode = aux->nextNode;
				}
				else
				{
					if (!listaPontoAcesso_isNull(aux->nextNode))
						listaPontoAcesso = aux->nextNode;
					else {
						listaPontoAcesso->nextNode = NULL;
						listaPontoAcesso->pontoAcesso = NEW; }
				}

				ListaPontoAcesso_DecCount();

				return 1;
			}

		if (listaPontoAcesso_isNull(aux->nextNode))
		{
			break;
		}
		else
		{
			ant = aux;
			aux = aux->nextNode;
		}
	}

	return 0;
}

int listaPontoAcesso_AlterarCapacidade(ListaPontoAcesso * listaPontoAcesso, char* nome, int capacidade) {
	ListaPontoAcesso * aux = listaPontoAcesso;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
			if (strcmp( pontoAcesso_getNome(aux->pontoAcesso), nome ) == 0)
			{
				Parque_setCapacidade(pontoAcesso_getParque(aux->pontoAcesso), capacidade);

				return 1;
			}

		if (listaPontoAcesso_isNull(aux->nextNode))
			break;
		else
			aux = aux->nextNode;
	}

	return 0;
}

int listaPontoAcesso_AlterarDescricao(ListaPontoAcesso * listaPontoAcesso, char* nome, char* desc) {
	ListaPontoAcesso * aux = listaPontoAcesso;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
			if (strcmp( pontoAcesso_getNome(aux->pontoAcesso), nome ) == 0)
			{
				pontoAcesso_setDescricao(aux->pontoAcesso, desc);

				return 1;
			}

		if (listaPontoAcesso_isNull(aux->nextNode))
			break;
		else
			aux = aux->nextNode;
	}

	return 0;
}

int listaPontoAcesso_AlterarPermissoes(ListaPontoAcesso * listaPontoAcesso, char* nome, int utente) {
	PontoAcesso * ponto = listaPontoAcesso_getPontoAcesso(listaPontoAcesso, nome);
	int tu = 0;
	int fc = 0;
	int fl = 0;
	int mo = 0;
	int mr = 0;

	int ambu = 0;
	int taxi = 0;
	int pass = 0;
	int mota = 0;

	if (utente)
	{
		printf("  Morador: ");
		scanf("%d", &mr);

		printf("  Turista: ");
		scanf_s("%d", &tu);

		printf("  Funcionario da Camara: ");
		scanf_s("%d", &fc);

		printf("  Motorista: ");
		scanf_s("%d", &mo);

		printf("  Funcionario de Limpeza: ");
		scanf_s("%d", &fl);

		pontoAcesso_setUtentePerms(ponto, mr, tu, fc, mo, fl);
	}
	else
	{
		printf("  Passageiros: ");
		scanf("%d", &pass);

		printf("  Mota: ");
		scanf_s("%d", &mota);

		printf("  Ambulancia: ");
		scanf_s("%d", &ambu);

		printf("  Taxi: ");
		scanf_s("%d", &taxi);

		pontoAcesso_setVeiculoPerms(ponto, ambu, taxi, pass, mota);
	}

	return 1;
}

int listaPontoAcesso_AlterarTipoLugares(ListaPontoAcesso * listaPontoAcesso, char * nome, int numPass, int numAmbu, int numTaxi, int numMota) {
	Parque * parque = NULL;
	PontoAcesso * ponto = listaPontoAcesso_getPontoAcesso(listaPontoAcesso, nome);
	if (ponto == NULL)
		return 0;

	parque = pontoAcesso_getParque(ponto);
	Parque_SetNumLugares(parque, numAmbu, numTaxi, numPass, numMota);

	return 1;
}

void listaPontoAcesso_Listar(ListaPontoAcesso * nodeListaPontoAcesso) {
	ListaPontoAcesso * aux = nodeListaPontoAcesso;
	Parque * parque = NULL;
	int count = 0;
	UtentePermissoes * uPerms = NULL;
	VeiculoPermissoes * vPerms = NULL;

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("NULO PAH!!!");
		return;
	}

	DrawTop();

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW && aux->pontoAcesso != NULL)
		{
			//uPerms = pontoAcesso_GetUtentePerms(aux->pontoAcesso);

			printf("%c                                                                             %c\n", 186, 186);
			printf("   ID: %d\n", pontoAcesso_getID(aux->pontoAcesso));
			printf("   Nome: %s\n", pontoAcesso_getNome(aux->pontoAcesso));
			printf("   Descricao: %s\n", pontoAcesso_getDescricao(aux->pontoAcesso));

			parque = pontoAcesso_getParque(aux->pontoAcesso);
			printf("   Capacidade: %d\n", Parque_getCapacidade(parque));
			printf("   Ocupacao: %d\n", Parque_getOcupacao(parque));
			if (Parque_Lotado(parque)) printf("   Lotado: SIM\n"); else printf("   Lotado: NAO\n");

			printf("   Lugares:       Livre \n");
			printf("    - Passageiros: %d\n", Parque_GetNumLugar(parque, e_tipoVeiculo_passageiros));
			printf("    - Ambulancias: %d\n", Parque_GetNumLugar(parque, e_tipoVeiculo_ambulancia));
			printf("    - Taxis:       %d\n", Parque_GetNumLugar(parque, e_tipoVeiculo_taxi));
			printf("    - Motas:       %d\n\n", Parque_GetNumLugar(parque, e_tipoVeiculo_mota));

			uPerms = pontoAcesso_GetUtentePerms(aux->pontoAcesso);

			printf("  Permissoes:   Utentes\n");
			printf("   - Morador:             %d\n", UtentePerms_PermiteMorador(uPerms));
			printf("   - Turista:             %d\n", UtentePerms_PermiteTurista(uPerms));
			printf("   - Motorista:           %d\n", UtentePerms_PermiteMotorista(uPerms));
			printf("   - Funcionario Camara:  %d\n", UtentePerms_PermiteFuncionarioCamara(uPerms));
			printf("   - Funcionario Limpeza: %d\n", UtentePerms_PermiteFuncionarioLimpeza(uPerms));

			vPerms = pontoAcesso_GetVeiculoPerms(aux->pontoAcesso);
			printf("  Permissoes:   Veiculos\n");
			printf("   - Passageiros:         %d\n", VeiculoPerms_PermitePassageiros(vPerms));
			printf("   - Ambulancia:          %d\n", VeiculoPerms_PermitePassageiros(vPerms));
			printf("   - Taxi:                %d\n", VeiculoPerms_PermitePassageiros(vPerms));
			printf("   - Mota:                %d\n", VeiculoPerms_PermitePassageiros(vPerms));


			count ++;
			printf("%c                                                                             %c\n", 186, 186);			
			DrawMiddle();
		}

		if (listaPontoAcesso_isNull(aux->nextNode))
		{
			break;
		}
		else
		{
			aux = aux->nextNode;
		}
	}

	printf("%c                       %d PONTOS DE ACESSO LISTADOS!                        %c\n", 186, count, 186);
	DrawBottom();
}

void listaPontoAcesso_ListarPontoAcesso(ListaPontoAcesso * listaPontoAcesso, char * nome) {
	ListaPontoAcesso * aux = listaPontoAcesso;
	Parque * parque = NULL;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
		{
			if (strcmp( pontoAcesso_getNome(aux->pontoAcesso), nome ) == 0)
			{
				printf("\nID: %d", pontoAcesso_getID(aux->pontoAcesso));
				printf("\nNome: %s", pontoAcesso_getNome(aux->pontoAcesso));
				printf("\nDescricao: %s", pontoAcesso_getDescricao(aux->pontoAcesso));

				parque = pontoAcesso_getParque(aux->pontoAcesso);
				printf("\nCapacidade: %d", Parque_getCapacidade(parque));
				printf("\nOcupacao: %d", Parque_getOcupacao(parque));
				if (Parque_Lotado(parque)) printf("\nLotado: SIM\n"); else printf("\nLotado: NAO\n");
				printf("\n");

				return;
			}
		}

		if (listaPontoAcesso_isNull(aux->nextNode))
		{
			break;
		}
		else
		{
			aux = aux->nextNode;
		}
	}
}

int listaPontoAcesso_GetIDByName(ListaPontoAcesso * lista, char* nome) {
	ListaPontoAcesso * aux = lista;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
		{
			if (strcmp( pontoAcesso_getNome(aux->pontoAcesso), nome ) == 0)
			{
				return pontoAcesso_getID(aux->pontoAcesso);
			}
		}

		aux = aux->nextNode;
	}
	
	return 0;
}

PontoAcesso * listaPontoAcesso_getPontoAcesso(ListaPontoAcesso * lista, char* nome) {
	ListaPontoAcesso * aux = lista;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
		{
			if (strcmp( pontoAcesso_getNome(aux->pontoAcesso), nome ) == 0)
			{
				return aux->pontoAcesso;
			}
		}

		aux = aux->nextNode;
	}
	
	return NULL;
}

void ListaPontoAcesso_DecCount(void) {
	count--;
}

void ListaPontoAcesso_IncCount(void) {
	count++;
}

int listaPontoAcesso_Existe(ListaPontoAcesso * lista, char* nome) {
	ListaPontoAcesso * aux = lista;

	while (!listaPontoAcesso_isNull(aux))
	{
		if ((unsigned int)aux->pontoAcesso != NEW)
		{
			if (strcmp(pontoAcesso_getNome(aux->pontoAcesso), nome) == 0)
				return 1;
		}

		aux = aux->nextNode;
	}

	return 0;
}
