#ifndef TESTER_H
#define TESTER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "ListaPontoAcesso.h"
#include "Utente.h"
#include "BST_Utentes.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd


//Cria e retorna um veiculo
Veiculo * test_Veiculo(int silent_mode);

ListaVeiculo * test_ListaVeiculo(Veiculo * veiculo,int silent_mode);
void test_removerVeiculosLista(ListaVeiculo * lista, int silent_mode);
Utente *  test_Utente(ListaVeiculo * lista, int silent_mode);
void test_bst_Utentes(Utente * utente1, int silent_mode);

PontoAcesso * test_PontoAcesso(int silent_mode);
ListaPontoAcesso * test_ListaPontoAcesso(PontoAcesso * pontoAcesso,int silent_mode);

void AdicionarPontoAcesso();


#endif TESTER_H