#include "SAGAC_GUI.h"

ListaPontoAcesso * listaPontoAcesso;

void DrawTop() {
	int i = 0;
	printf("%c", 201);
	for (i = 0; i < 77; i++) {
		printf("%c", 205); }
	printf("%c\n", 187);
}

void DrawBottom() {
	int i = 0;
	printf("%c", 200);
	for (i = 0; i < 77; i++) {
		printf("%c", 205); }
	printf("%c\n", 188);
}

void DrawMiddle() {
	int i = 0;
	printf("%c", 204);
	for (i = 0; i < 77; i++) {
		printf("%c", 205); }
	printf("%c\n", 185);
}

void DrawMenuPrincipal() {
	int op = -1;

	listaPontoAcesso = ListaPontoAcesso_new();

	while (op != 0) {
		system("cls");

		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Menu Principal                                                            %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - UTENTES           - Gestao de Utentes                               %c\n", 186, 186);
		printf("%c   [2] - VEICULOS          - Gestao de Veiculos dos Utentes                  %c\n", 186, 186);
		printf("%c   [3] - PONTOS DE ACESSO  - Gestao de Pontos de Acesso                      %c\n", 186, 186);
		printf("%c   [4] - RELATORIOS        - Listagem de Relatorios                          %c\n", 186, 186);
		printf("%c   [5] - GRAVAR            - Gravar os dados da aplicacao                    %c\n", 186, 186);
		printf("%c   [6] - CARREGAR          - Carregar os dados da aplicacao                  %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - SAIR                                                                %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");
		scanf_s("%d", &op);
		fflush(stdin);

		switch (op) {
		case 1:
			DrawUtentes();
			break;

		case 2:
			DrawVeiculos(); 
			break;

		case 3:
			DrawPontosAcesso();
			break;

		case 4:
			DrawRelatorios();
			break;

		case 5:
			DrawGravado();
			break;
		case 6:
			DrawLoad();
			break;
		}
	}
}

void DrawUtentes() {
	int op = -1;

	while (op != 0)
	{
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Utente                                                                    %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - ADICIONAR     - Adiciona um novo Utente                             %c\n", 186, 186);
		printf("%c   [2] - REMOVER       - Remove um utente                                    %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [3] - ALTERAR       - Altera um utente                                    %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [4] - LISTAR        - Lista um determinado utente                         %c\n", 186, 186);
		printf("%c   [5] - LISTAR TODOS  - Lista todos os utentes registados                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - VOLTAR                                                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");
		scanf_s("%d", &op);
		fflush(stdin);

		switch (op) {
		case 1:
			DrawUtenteAdicionar();
			break;

		case 2:
			DrawUtenteRemover();
			break;

		case 3:
			DrawUtenteAlterar();
			break;

		case 4:
			DrawUtenteListar();
			break;

		case 5:
			DrawUtenteListarTodos();
			break;
		}
	}
}

void DrawVeiculos(){
	int op = -1;

	while (op != 0)
	{
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Veiculos                                                                  %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - ADICIONAR     - Adiciona novo veiculo a um Utente                   %c\n", 186, 186);
		printf("%c   [2] - REMOVER       - Remove um veiculo de um Utente                      %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [3] - LISTAR        - Lista veiculos de um determinado utente             %c\n", 186, 186);
		printf("%c   [4] - LISTAR TODOS  - Lista todos os veiculos de um utente                %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - VOLTAR                                                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");
		scanf_s("%d", &op);
		fflush(stdin);

		switch (op) {
		case 1:
			DrawVeiculoAdicionar();
			break;

		case 2:
			DrawVeiculoRemover();
			break;

		case 3:
			DrawVeiculoListar();
			break;

		case 4:
			DrawVeiculoListarTodos();
			break;
		}
	}
}

void DrawPontosAcesso() {
	int op = -1;

	while (op != 0) {
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Pontos de Acesso                                                          %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - ADICIONAR        - Adiciona um novo Ponto de Acesso                 %c\n", 186, 186);
		printf("%c   [2] - REMOVER          - Remove um Ponto de Acesso                        %c\n", 186, 186);
		printf("%c   [3] - ALTERAR          - Altera um Ponto de Acesso                        %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [4] - LISTAR           - Lista os dados de um determinado Ponto de Acesso %c\n", 186, 186);
		printf("%c   [5] - LISTAR TODOS     - Lista dos dados de todos os Pontos de Acesso     %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [6] - REGISTAR ENTRADA - Regista a entrada de um utente                   %c\n", 186, 186);
		printf("%c   [7] - LISTAR SAIDA     - Regista a saida de um utente                     %c\n", 186, 186);		
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - VOLTAR                                                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");

		scanf_s("%d", &op);
		switch (op) {
		case 1:
			DrawPontoAcessoAdicionar();
			break;

		case 2:
			DrawPontoAcessoRemover();
			break;

		case 3:
			DrawPontoAcessoAlterar();
			break;

		case 4:
			DrawPontoAcessoListar();
			break;

		case 5:
			DrawPontoAcessoListarTodos();
			break;

		case 6:
			DrawRegistarEntrada();
			break;

		case 7:
			DrawRegistarSaida();
			break;
		}
	}
}

void DrawRelatorios() {
	int op = -1;

	while (op != 0) {
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Relatorios                                                                %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - PONTOS DE ACESSO LOTADOS     - Lista os pontos de acesso lotados    %c\n", 186, 186);
		printf("%c   [2] - TOTAL LUGARES OCUPADOS/VAGOS - Total lugares ocupados/vagos         %c\n", 186, 186);
		printf("%c   [3] - LISTAR ENTRADAS/SAIDAS       - Lista as ultimas entradas e saidas   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - VOLTAR                                                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");

		scanf_s("%d", &op);
		switch (op) {
		case 1:
			DrawPontoAcessoLotados();
			break;

		case 2:
			DrawLugaresOcupadosVagos();
			break;

		case 3:
			DrawEntrasSaidas();
			break;
		}
	}
}

void DrawGravado() {
	char * lixo = "";
	char token[] ="\n";

	int actionStatus = 0;
	char * filename = (char *)malloc(CHARBUFFSIZE);

	system("cls");
	
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Gravar                                                                    %c\n", 186, 186);
	DrawMiddle();
	printf("%c                                                                             %c\n", 186, 186);
	
	printf("\nIndique o nome do ficheiro: ");
	fgets(filename, CHARBUFFSIZE, stdin);
	strtok_s(filename,token,&lixo);
	fflush(stdin);
	strcat(filename,".dat");

	actionStatus =  SAGAC_Controller_saveFile(filename);

	if (actionStatus) printf("%c   DADOS GRAVADOS COM SUCESSO!                                               %c\n", 186, 186);
	else printf("%c   ERRO AO GRAVAR OS DADOS!                                                  %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	system("pause");
}
void DrawLoad(void){
	char * lixo = "";
	char token[] ="\n";

	int actionStatus = 0;
	char * filename = (char *)malloc(CHARBUFFSIZE);

	system("cls");

	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Load                                                                      %c\n", 186, 186);
	DrawMiddle();
	printf("%c                                                                             %c\n", 186, 186);

	printf("\nIndique o nome do ficheiro: ");
	fgets(filename, CHARBUFFSIZE, stdin);
	strtok_s(filename,token,&lixo);
	fflush(stdin);
	strcat(filename,".dat");

	actionStatus =  SAGAC_Controller_readFile(filename);

	if (actionStatus) printf("%c   DADOS CARREGADOS COM SUCESSO!                                               %c\n", 186, 186);
	else printf("%c   ERRO AO CARREGAR OS DADOS!                                                  %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	system("pause");
}

void DrawPontoAcessoAdicionar() {
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Adicionar                                                                 %c\n", 186, 186);
	DrawBottom();
	printf("\n");
	
	listaPontoAcesso_Adicionar(SAGAH_GetListaPontoAcesso());

	printf("\n");
	printf("                            PONTO DE ACESSO INSERIDO!                          \n");

	system("pause");
}

void DrawPontoAcessoRemover() {
	char * nome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int removido = 0;
	
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Remover                                                                   %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("   Nome do Ponto de Acesso a ser removido: ");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	removido = listaPontoAcesso_Remover(SAGAH_GetListaPontoAcesso(), nome);

	printf("\n");
	if (removido)
		printf("                            PONTO DE ACESSO REMOVIDO!                          \n");
	else
		printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
	system("pause");
}

void DrawPontoAcessoAlterar(void) {
	int op = -1;

	if (listaPontoAcesso_GetCount() <= 0)
	{
		system("cls");
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	while (op != 0) {
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Alterar                                                                   %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - DESCRICAO  -  Descricao do Ponto de Acesso                          %c\n", 186, 186);
		printf("%c   [2] - PERMISSOES - Tipo de Utente/Veiculo permitidos                      %c\n", 186, 186);
		printf("%c   [3] - CAPACIDADE - Quantidade de lugares de estacinamento                 %c\n", 186, 186);
		printf("%c   [4] - LUGARES    - Defenicao dos tipos de lugar(ambulangia, ligeiro, etc) %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - VOLTAR                                                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");

		scanf_s("%d", &op);
		switch (op) {
		case 1:
			DrawPontoAcessoAlterarDescricao();
			break;

		case 2:
			DrawPontoAcessoAlterarPermissoes();
			break;

		case 3:
			DrawPontoAcessoAlterarCapacidade();
			break;

		case 4:
			DrawPontoAcessoAlterarLugares();
			break;
		}
	}
}

void DrawPontoAcessoAlterarCapacidade(void) {
	char * nome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int alterado = 0;
	int capacidade = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Capacidade                                                        %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("   Ponto de Acesso (Nome) ->");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	printf("   Capacidade->");
	scanf_s("%d", &capacidade);

	alterado = listaPontoAcesso_AlterarCapacidade(SAGAH_GetListaPontoAcesso(), nome, capacidade);

	printf("\n");
	if (alterado)
		printf("                            PONTO DE ACESSO ALTERADO!                          \n");
	else
		printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
	system("pause");
}

void DrawPontoAcessoAlterarDescricao(void) {
	char * nome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int alterado = 0;
	char * desc = (char *)malloc(CHARBUFFSIZE);

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Descricao                                                         %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("   Ponto de Acesso (Nome) ->");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	fflush(stdin);
	printf("   Descricao ->");
	fgets(desc, CHARBUFFSIZE, stdin);
	strtok_s(desc,token,&lixo);
	fflush(stdin);

	alterado = listaPontoAcesso_AlterarDescricao(SAGAH_GetListaPontoAcesso(), nome, desc);

	printf("\n");
	if (alterado)
		printf("                            PONTO DE ACESSO ALTERADO!                          \n");
	else
		printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
	system("pause");
}

void DrawPontoAcessoAlterarPermissoes(void) {
	int op = -1;
	char * nome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int alterado = 0;

	while (op != 0) {
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Alterar Permissoes                                                        %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - UTENTES  - Tipos de Utente permitidos                               %c\n", 186, 186);
		printf("%c   [2] - VEICULOS - Tipos de veiculo permitidos                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - CANCELAR                                                            %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");

		if (listaPontoAcesso_GetCount() <= 0)
		{
			printf("                             A LISTA ESTA VAZIA                             \n");
			system("pause");
			return;
		}

		scanf_s("%d", &op);
		switch (op) {
		case 1:
			fflush(stdin);
			printf("   Ponto de Acesso (Nome) ->");
			fgets(nome, CHARBUFFSIZE, stdin);
			strtok_s(nome,token,&lixo);
			fflush(stdin);

			alterado = listaPontoAcesso_AlterarPermissoes(SAGAH_GetListaPontoAcesso(), nome, 1);

			printf("\n");
			if (alterado)
				printf("                            PONTO DE ACESSO ALTERADO!                          \n");
			else
				printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
			system("pause");

			break;

		case 2:
			fflush(stdin);
			printf("   Ponto de Acesso (Nome) ->");
			fgets(nome, CHARBUFFSIZE, stdin);
			strtok_s(nome,token,&lixo);
			fflush(stdin);

			alterado = listaPontoAcesso_AlterarPermissoes(SAGAH_GetListaPontoAcesso(), nome, 0);

			printf("\n");
			if (alterado)
				printf("                            PONTO DE ACESSO ALTERADO!                          \n");
			else
				printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
			system("pause");

			break;
		}
	}
}

void DrawPontoAcessoAlterarLugares(void) {
	char * nome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int alterado = 0;
	char * desc = (char *)malloc(CHARBUFFSIZE);
	int numPass = -1;
	int numAmbu = -1;
	int numTaxi = -1;
	int numMota = -1;
	PontoAcesso * pontoAcesso = NULL;
	int max = -1;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Tipo de Lugar                                                     %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("   Ponto de Acesso (Nome) ->");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	pontoAcesso = listaPontoAcesso_getPontoAcesso(SAGAH_GetListaPontoAcesso(), nome);
	if (pontoAcesso == NULL)
	{
		printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
		system("pause");
		return;
	}

	if (Parque_getCapacidade(pontoAcesso_getParque(pontoAcesso)) == 0)
	{
		printf("                             O PARQUE ESTA VAZIO                               \n");
		system("pause");
		return;
	}

	max = Parque_getCapacidade(pontoAcesso_getParque(pontoAcesso));
	while (numAmbu < 0 || numAmbu > max) {
		printf("   Numero de lugares para Ambulancias (CHARBUFFSIZE: %d) ->", max);
		scanf_s("%d", &numAmbu);
	}

	max = max - numAmbu;
	do {
		printf("   Numero de lugares para Ligeiros (CHARBUFFSIZE: %d) ->", (unsigned int)max);
		scanf_s("%d", &numPass);
	} while (numPass < 0 || numPass > max);
	
	max = max - numPass;
	do {
		printf("   Numero de lugares para Taxis (CHARBUFFSIZE: %d) ->", (unsigned int)max);
		scanf_s("%d", &numTaxi);
	} while (numTaxi < 0 || numTaxi > max);
	
	max = max - numTaxi;
	do {
		printf("   Numero de lugares para Motas (CHARBUFFSIZE: %d) ->", (unsigned int)max);
		scanf_s("%d", &numMota);
	} while (numMota < 0 && numMota > max);
	
	alterado = listaPontoAcesso_AlterarTipoLugares(SAGAH_GetListaPontoAcesso(), nome, numPass, numAmbu, numTaxi, numMota);

	printf("\n");
	if (alterado)
		printf("                            PONTO DE ACESSO ALTERADO!                          \n");
	else
		printf("                  NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO                \n");
	system("pause");
}

void DrawPontoAcessoListar() {
	char * nome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Listar Ponto de Acesso                                                    %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("   Nome do Ponto de Acesso a ser listado: ");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	printf("\n\n");
	// SAGAC_ListarPontoAcesso(nome);
	listaPontoAcesso_ListarPontoAcesso(SAGAH_GetListaPontoAcesso(), nome);

	system("pause");
}

void DrawPontoAcessoListarTodos() {
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Listar Ponto de Acesso                                                    %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	listaPontoAcesso_Listar(SAGAH_GetListaPontoAcesso());

	system("pause");
}

void DrawRegistarEntrada(void) {
	int BI = 0;
	char * nomePonto = (char *)malloc(CHARBUFFSIZE);
	char * matricula = (char *)malloc(CHARBUFFSIZE_L);
	char *lixo = "";
	char token[] ="\n";
	PontoAcesso * ponto = NULL;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Registar Entrada                                                          %c\n", 186, 186);
	DrawBottom();
	printf("\n\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("Ponto de Acesso ->");
	fgets(nomePonto, CHARBUFFSIZE, stdin);
	strtok_s(nomePonto,token,&lixo);
	fflush(stdin);

	if (listaPontoAcesso_getPontoAcesso(SAGAH_GetListaPontoAcesso(), nomePonto) == NULL)
	{
		printf("                NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO             \n");
		system("pause");
		return;
	}

	printf("Utente (BI) ->");
	scanf_s("%d", &BI);

	if (SAGAC_GetUtenteByID(BI) == NULL)
	{
		printf("                   NAO FOI ENCONTRADO O UTENTE INDICADO                  \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("Viatura (Matricula) ->");
	fgets(matricula, CHARBUFFSIZE, stdin);
	strtok_s(matricula,token,&lixo);
	fflush(stdin);

	if ( !pontoAcesso_RegistarEntrada(listaPontoAcesso_getPontoAcesso(SAGAH_GetListaPontoAcesso(), nomePonto), BI, matricula))
	{
		printf("                  OCORREU UM ERRO AO REGISTAR A ENTRADA                \n");
		system("pause");
		return;
	}

	printf("                         ENTRADA REGISTADA COM SUCESSO                     \n");
	system("pause");
	return;
}

void DrawRegistarSaida(void) {
	int BI = 0;
	char * nomePonto = (char *)malloc(CHARBUFFSIZE);
	char * matricula = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	PontoAcesso * ponto = NULL;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Registar Saida                                                            %c\n", 186, 186);
	DrawBottom();
	printf("\n\n");

	if (listaPontoAcesso_GetCount() <= 0)
	{
		printf("                             A LISTA ESTA VAZIA                             \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("Ponto de Acesso ->");
	fgets(nomePonto, CHARBUFFSIZE, stdin);
	strtok_s(nomePonto,token,&lixo);
	fflush(stdin);

	if (listaPontoAcesso_getPontoAcesso(SAGAH_GetListaPontoAcesso(), nomePonto) == NULL)
	{
		printf("                NAO FOI ENCONTRADO O PONTO DE ACESSO INDICADO             \n");
		system("pause");
		return;
	}

	printf("Utente (BI) ->");
	scanf_s("%d", &BI);

	if (SAGAC_GetUtenteByID(BI) == NULL)
	{
		printf("                   NAO FOI ENCONTRADO O UTENTE INDICADO                  \n");
		system("pause");
		return;
	}

	fflush(stdin);
	printf("Viatura (Matricula) ->");
	fgets(matricula, CHARBUFFSIZE, stdin);
	strtok_s(matricula,token,&lixo);
	fflush(stdin);

	if (!pontoAcesso_RegistarSaida(listaPontoAcesso_getPontoAcesso(SAGAH_GetListaPontoAcesso(), nomePonto), BI, matricula))
	{
		printf("                   OCORREU UM ERRO AO REGISTAR A SAIDA                \n");
		system("pause");
		return;
	}

	printf("                          SAIDA REGISTADA COM SUCESSO                     \n");
	system("pause");
	return;

	system("pause");
}

void DrawPontoAcessoLotados(void) {
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Pontos de Acesso Lotados                                                  %c\n", 186, 186);
	DrawBottom();
	printf("\n\n");

	listaPontoAcesso_ListarLugaresLotados(SAGAH_GetListaPontoAcesso());

	system("pause");
}

void DrawLugaresOcupadosVagos(void) {
		system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Lugares Ocupados/Vagos                                                    %c\n", 186, 186);
	DrawBottom();
	printf("\n\n");

	listaPontoAcesso_ListarLugaresVagos(SAGAH_GetListaPontoAcesso());

	system("pause");
}

void DrawEntrasSaidas(void) {
		system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Registo de Entradas/Saidas                                                %c\n", 186, 186);
	DrawBottom();
	printf("\n\n");

	listaPontoAcesso_ListarEntradasSaidas(SAGAH_GetListaPontoAcesso());

	system("pause");
}

//===private
//=USED in: DrawUtenteAdicionar() && DrawUtenteAlterar();
enum e_TipoUtente inputGetTipoUtente(){
	enum e_TipoUtente tipo = e_TipoUtente_null;

	printf("\nTipos: ");
	printf("\n\t1- Morador");
	printf("\n\t2- Turista");
	printf("\n\t3- Funcionario da Camara");
	printf("\n\t4- Motorista");
	printf("\n\t5- Funcionario(a) das Limpezas");

	while(tipo <1 || tipo > 5){
		printf("\nIndique o tipo do utente: ");
		scanf_s("%d", &tipo);
		fflush(stdin);
	}

	return tipo;
}

//===private
//=USED in: DrawUtenteAdicionar() && DrawUtenteAlterar();
int inputGetBIBetween(int min, int max){
	int num = 0;

	while(num <min || num > max){
		printf("\nIndique um numero entre %d e %d: ",min,max);
		scanf_s("%d", &num);
		fflush(stdin);
	}

	return num;
}

//===private
//=USED in: DrawUtenteAdicionar() && DrawUtenteAlterar();
int inputGetBI(){
	int num = 0;

	while(num < 1){
		printf("\nIndique o BI (tem que ser um numero maior do que 0): ");
		scanf_s("%d", &num);
		fflush(stdin);
	}

	return num;
}
void DrawUtenteAdicionar() {
	char * lixo = "";
	char token[] ="\n";
	int actionStatus = 0;

	char * nome = (char*)malloc(sizeof(CHARBUFFSIZE));
	char * morada = (char*)malloc(sizeof(CHARBUFFSIZE));
	char * profissao = (char*)malloc(sizeof(CHARBUFFSIZE));
	int BI = 0;
	enum e_TipoUtente tipo = e_TipoUtente_null;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Adicionar                                                                 %c\n", 186, 186);
	DrawBottom();
	printf("\n");
	
	// ========== UserInput ==========

	// ==== Nome ====
	//fflush(stdin);
	printf("\nNome: ");
	fgets(nome, CHARBUFFSIZE, stdin);
	strtok_s(nome,token,&lixo);
	fflush(stdin);

	// === END Nome ===

	// ==== BI ====

	BI = inputGetBI();

	if(!SAGAC_CheckUtenteByID(BI)){
			// ==== END BI ====

			// ==== Tipo Utente ====

			tipo = inputGetTipoUtente();

			// ==== END Tipo Utente ====

			// ==== Morada ====

			printf("\nMorada: ");
			fgets(morada, CHARBUFFSIZE, stdin);
			strtok_s(morada,token,&lixo);
			fflush(stdin);

			// ==== END Morada ====

			// ==== Profissao ====

			printf("\nProfissao: ");
			fgets(profissao, CHARBUFFSIZE, stdin);
			strtok_s(profissao,token,&lixo);
			fflush(stdin);

			// ==== END Profissao====

			// ======= END OF UserInput ========

			actionStatus = SAGAC_adicionarUtente(nome, BI, tipo, profissao, morada, NULL);
	}
	else
		printf("\n\tJa existe um utilizador com o BI inserido!");
	printf("\n");
	if(actionStatus)
		printf("\n\n\n                        UTILIZADOR INSERIDO COM SUCESSO!                          \n");
	else
		printf("\n\n\n                    >>>     UTILIZADOR NAO FOI INSERIDO!      <<<                \n");
	system("pause");
}

void DrawUtenteRemover() {
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Remover                                                                   %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("\n\n\n                       OPERACAO NAO SUPORTADA PELO SISTEMA                       \n");

	system("pause");
}

//===private
//=USED in: void DrawUtenteAlterar();
//FALTA TESTAR ISTO
void DrawUtenteAlterarMorada(){
	char * moradaNova = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int BI;
	int actionStatus = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Morada do Utente                                                  %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("\nIndique o BI do utente: ");
	scanf_s("%d",&BI);
	fflush(stdin);

	printf("\nIndique a nova morada do utente: ");
	fgets(moradaNova, CHARBUFFSIZE, stdin);
	strtok_s(moradaNova,token,&lixo);
	fflush(stdin);

	//TESTAR BEM ISTO!!!!!
	actionStatus = SAGAC_alterarDadosUtente(BI,NULL,e_TipoUtente_null,NULL,moradaNova);

	if(actionStatus)
		printf("\n\n\n                          MORADA ALTERADA COM SUCESSO!                     \n");
	else
		printf("\n\n\n                      >>>      MORADA NAO FOI ALTERADA!       <<<                \n");
	system("pause");
}

//===private
//=USED in: void DrawUtenteAlterar();
//FALTA TESTAR ISTO
void DrawUtenteAlterarProfissao(){
	char * profissaoNova = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int BI;
	int actionStatus = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Profissao do Utente                                               %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("\nIndique o BI do utente: ");
	scanf_s("%d",&BI);
	fflush(stdin);

	printf("\nIndique a nova profissao do utente: ");
	fgets(profissaoNova, CHARBUFFSIZE, stdin);
	strtok_s(profissaoNova,token,&lixo);
	fflush(stdin);

	//TESTAR BEM ISTO!!!!!
	actionStatus = SAGAC_alterarDadosUtente(BI,NULL,e_TipoUtente_null,profissaoNova,NULL);

	if(actionStatus)
		printf("\n\n\n                          PROFISSAO ALTERADA COM SUCESSO!                     \n");
	else
		printf("\n\n\n                     >>>>       PROFISSAO NAO FOI ALTERADA!         <<<<              \n");
	system("pause");
}

//===private
//=USED in: void DrawUtenteAlterar();
//FALTA TESTAR ISTO
void DrawUtenteAlterarTipo(){
	enum e_TipoUtente tipo = e_TipoUtente_null;
	int BI;
	int actionStatus = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Tipo do Utente                                                    %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("\nIndique o BI do utente: ");
	scanf_s("%d",&BI);
	fflush(stdin);

	printf("\nIndique o novo tipo do utente: ");
	tipo = inputGetTipoUtente();

	//TESTAR BEM ISTO!!!!!
	actionStatus = SAGAC_alterarDadosUtente(BI,NULL,tipo,NULL,NULL);

	if(actionStatus)
		printf("\n\n\n                          TIPO ALTERADO COM SUCESSO!                     \n");
	else
		printf("\n\n\n                    >>>        TIPO NAO FOI ALTERADO!        <<<               \n");
	system("pause");
}

//===private
//=USED in: void DrawUtenteAlterar();
//FALTA TESTAR ISTO
void DrawUtenteAlterarNome(){
	char * novoNome = (char *)malloc(CHARBUFFSIZE);
	char *lixo = "";
	char token[] ="\n";
	int BI;
	int actionStatus = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Nome do Utente                                                    %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("\nIndique o BI do utente: ");
	scanf_s("%d",&BI);
	fflush(stdin);

	printf("\nIndique o novo nome do utente: ");
	fgets(novoNome, CHARBUFFSIZE, stdin);
	strtok_s(novoNome,token,&lixo);
	fflush(stdin);

	
	actionStatus = SAGAC_alterarDadosUtente(BI,novoNome,e_TipoUtente_null,NULL,NULL);

	if(actionStatus)
		printf("\n\n\n                          NOME ALTERADO COM SUCESSO!                     \n");
	else
		printf("\n\n\n                  >>>          NOME NAO FOI ALTERADO!       <<<               \n");
	
	system("pause");
}
void DrawUtenteAlterarPenalizacao(){
	char *lixo = "";
	char token[] ="\n";
	int BI;
	int actionStatus = 0;
	enum e_UtentePenalizado penalizacao = e_UtentePenalizado_null;
	enum e_UtentePenalizado penalizacaoInput = e_UtentePenalizado_null;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Alterar Penalizacao do Utente                                             %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("\nIndique o BI do utente: ");
	scanf_s("%d",&BI);
	fflush(stdin);

	penalizacao = SAGAC_getPenalizacaoUtente(BI);
	if (penalizacao == e_UtentePenalizado_null){
		printf("\n\n\n                  >>>           UTENTE NAO ENCONTRADO!       <<<               \n");
	}
	else{
		while(penalizacaoInput <1 || penalizacaoInput > 2){
			if(penalizacao == e_UtentePenalizado_sim)
				printf("\nUtente está penalizado, ");
			else
				printf("\nUtente nao está penalizado, ");

			printf("deseja penalizar?\n\t1-Nao\n\t2-Sim\n\nOpcao>  ");
			scanf_s("%d",&penalizacaoInput);
		}
		
		actionStatus = SAGAC_alterarPenalizacaoUtente(BI, penalizacaoInput);

		

		if(actionStatus)
			printf("\n\n\n                          PENALIZACAO ALTERADA COM SUCESSO!                     \n");
		else
			printf("\n\n\n                  >>>          PENALIZACAO NAO FOI ALTERADA!       <<<               \n");

	}


	system("pause");
}


void DrawUtenteAlterar() {
	int op = -1;

	while (op != 0) {
		system("cls");
		DrawTop();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                     SAGAC                                   %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c - Alterar dados Utente                                                      %c\n", 186, 186);
		DrawMiddle();
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [1] - Nome                                                                %c\n", 186, 186);
		printf("%c   [2] - Tipo                                                                %c\n", 186, 186);
		printf("%c   [3] - Profissao                                                           %c\n", 186, 186);
		printf("%c   [4] - Morada                                                              %c\n", 186, 186);
		printf("%c   [5] - Penalizacao                                                         %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c   [0] - VOLTAR                                                              %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		printf("%c                                                                             %c\n", 186, 186);
		DrawBottom();
		printf("\n");
		printf(" OPCAO> ");

		scanf_s("%d", &op);
		fflush(stdin);

		switch (op) {
		case 1:
			DrawUtenteAlterarNome();
			break;

		case 2:
			DrawUtenteAlterarTipo();
			break;

		case 3:
			DrawUtenteAlterarProfissao();
			break;
		case 4:
			DrawUtenteAlterarMorada();
			break;
		case 5:
			DrawUtenteAlterarPenalizacao();
			break;
		}
	}


}

//FALTA
void DrawUtenteListar() {
	int BI = 0;
	int actionStatus = 0;
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Listar Utente                                                             %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("Indique o BI do utente> ");
	scanf_s("%d", &BI);
	fflush(stdin);

	actionStatus = SAGAC_listarUtente(BI);


	if(!actionStatus)
		printf("\n\n\n                 >>>     NAO EXISTE INFORMACAO PARA MOSTRAR!     <<<                \n");
	

	printf("\n\n");
	system("pause");
}

void DrawUtenteListarTodos() {
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Listar Utentes                                                            %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	SAGAC_listarUtentes();
	printf("\n\n");
	system("pause");
}

//===private
//=USED in: DrawVeiculoAdicionar();
enum e_TipoVeiculo inputGetTipoVeiculo(){
	enum e_TipoVeiculo tipo = e_TipoVeiculo_null;

	printf("\nTipos: ");
	printf("\n\t1- Passageiros");
	printf("\n\t2- Motociclo");
	printf("\n\t3- Ambulancia");
	printf("\n\t4- Taxi");

	while(tipo <1 || tipo > 4){
		printf("\nIndique o tipo do veiculo> ");
		scanf_s("%d", &tipo);
		fflush(stdin);
	}

	return tipo;
}

void DrawVeiculoAdicionar(void){
	char * lixo = "";
	char token[] ="\n";
	int actionStatus = 0;

	int BI = 0;
	char * marca = (char*)malloc(sizeof(CHARBUFFSIZE));
	char * modelo = (char*)malloc(sizeof(CHARBUFFSIZE));
	char * matricula = (char*)malloc(sizeof(CHARBUFFSIZE));
	enum e_TipoVeiculo tipo = e_TipoVeiculo_null;


	
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Adicionar                                                                 %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	// ========== UserInput ==========
	
	// ==== BI ====

	printf("\nInsira o BI do utente> ");
	scanf_s("%d", &BI);
	fflush(stdin);
	// ==== END BI ====

	if(SAGAC_CheckUtenteByID(BI)){
		// ==== Matricula ====
		printf("\nMatricula> ");
		fgets(matricula, CHARBUFFSIZE, stdin);
		strtok_s(matricula,token,&lixo);
		fflush(stdin);
		// ==== END Matricula ====
		if(!SAGAC_CheckMatricula(BI,matricula)){
			// ==== Marca ====
			printf("\nMarca do veiculo> ");
			fgets(marca, CHARBUFFSIZE, stdin);
			strtok_s(marca,token,&lixo);
			fflush(stdin);

			// === END Marca ===

			// ==== Modelo ====
			printf("\nModelo do veiculo> ");
			fgets(modelo, CHARBUFFSIZE, stdin);
			strtok_s(modelo,token,&lixo);
			fflush(stdin);
			// === END Modelo ===



			// ==== Tipo Veiculo ====
			tipo = inputGetTipoVeiculo();
			// ==== END Tipo Veiculo ====

			// ======= END OF UserInput ========
			actionStatus = SAGAC_adicionarVeiculo( BI,  marca,  modelo,  matricula, tipo );
		}
		else
			printf("\n\tO utilizador ja tem um veiculo com a mesma matricula!");
	}
	else
		printf("\n\tNao existe nenhum utilizador com o BI inserido!");
	printf("\n");
	if(actionStatus)
		printf("\n\n\n                        VEICULO INSERIDO COM SUCESSO!                          \n");
	else
		printf("\n\n\n                 >>>        VEICULO NAO FOI INSERIDO!      <<<                     \n");
	system("pause");
}

void DrawVeiculoRemover(void){
	char *lixo = "";
	char token[] ="\n";

	char * matricula = (char *)malloc(CHARBUFFSIZE);
	int BI = 0;
	int actionStatus = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Remover Veiculo                                                           %c\n", 186, 186);
	DrawBottom();
	printf("\n");
	
	printf("\nIndique o BI do utente> ");
	scanf_s("%d", &BI);
	fflush(stdin);
	
	printf(" Indique a matricula do veiculo> ");
	fgets(matricula, CHARBUFFSIZE, stdin);
	strtok_s(matricula,token,&lixo);
	fflush(stdin);

	actionStatus = SAGAC_removeVeiculo(BI, matricula);

	printf("\n");
	if (actionStatus)
		printf("                            VEICULO REMOVIDO!                          \n");
	else
		printf("                <<<   NAO FOI POSSIVEL REMOVER O VEICULO   >>>                \n");
	system("pause");
}

void DrawVeiculoListar(void){
	char * lixo = "";
	char token[] ="\n";

	char * matricula = (char*)malloc(sizeof(CHARBUFFSIZE));

	int BI = 0;
	int actionStatus = 0;

	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Listar Veiculo do Utente                                                  %c\n", 186, 186);
	DrawBottom();
	printf("\n");

	printf("Indique o BI do utente> ");
	scanf_s("%d", &BI);
	fflush(stdin);

	// ==== Modelo ====
	printf("\nMatricula do veiculo> ");
	fgets(matricula, CHARBUFFSIZE, stdin);
	strtok_s(matricula,token,&lixo);
	fflush(stdin);
	// === END Modelo ===

	actionStatus = SAGAC_listarVeiculo(BI, matricula);


	if(!actionStatus)
		printf("\n\n\n                 >>>     NAO EXISTE INFORMACAO PARA MOSTRAR!     <<<                \n");


	printf("\n\n");
	system("pause");
}

void DrawVeiculoListarTodos(void){
	int BI = 0;
	system("cls");
	DrawTop();
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c                                     SAGAC                                   %c\n", 186, 186);
	printf("%c                                                                             %c\n", 186, 186);
	printf("%c - Listar Veiculos do Utente                                                 %c\n", 186, 186);
	DrawBottom();
	printf("\n");
	printf("Indique o BI do utente> ");
	
	scanf_s("%d", &BI);
	fflush(stdin);

	SAGAC_listarVeiculos(BI);

	printf("\n\n");
	system("pause");
}

void WriteToLog(char* text) {
	FILE *file;
	char str1[500] = "";
	time_t time1;
	time(&time1);

	strcat(str1, text);
	strcat(str1, " - ");
	strcat(str1, ctime(&time1));

	fopen_s(&file, "log.dat", "a");
	fprintf_s(file, str1);
	fclose(file);
	/*
	FILE *file;
	char * str1 = (char *) malloc(200*CHARBUFFSIZE);
	time_t time1;
	time(&time1);
	
	strcpy(str1,text);
	
	strcpy(str1, " - ");
	strcpy(str1, ctime(&time1));
	
	fopen_s(&file, "log.txt", "a");
	
	fprintf_s(file, str1);
	
	fclose(file);
	free(str1);*/
	
}