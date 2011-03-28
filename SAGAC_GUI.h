#ifndef SAGAC_GUIHEADER
#define SAGAC_GUIHEADER

#include <stdio.h>
#include <stdlib.h>

#include "SAGAC_Controller.h"

#include "ListaPontoAcesso.h"




void LimparEcra(void);

void DrawTop(void);
void DrawBottom(void);
void DrawMiddle(void);

void DrawMenuPrincipal(void);
void DrawUtentes(void);
void DrawVeiculos(void); 
void DrawPontosAcesso(void);
void DrawRelatorios(void);
void DrawGravado(void);
void DrawLoad(void);

void DrawPontoAcessoAdicionar();
void DrawPontoAcessoRemover();
void DrawPontoAcessoAlterar(void);
void DrawPontoAcessoAlterarCapacidade(void);
void DrawPontoAcessoAlterarDescricao(void);
void DrawPontoAcessoAlterarPermissoes(void);
void DrawPontoAcessoAlterarLugares(void);
void DrawPontoAcessoListar(void);
void DrawPontoAcessoListarTodos(void);

void DrawRegistarEntrada(void);
void DrawRegistarSaida(void);

void DrawPontoAcessoLotados(void);
void DrawLugaresOcupadosVagos(void);
void DrawEntrasSaidas(void);

void DrawUtenteAdicionar(void);
void DrawUtenteRemover(void);
void DrawUtenteAlterar(void);
void DrawUtenteListar(void);
void DrawUtenteListarTodos(void);

void DrawVeiculoAdicionar(void);
void DrawVeiculoRemover(void);
void DrawVeiculoListar(void);
void DrawVeiculoListarTodos(void);

void WriteToLog(char* text);

#endif
