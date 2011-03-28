/*
 *  UtentePermissoes.h
 */

#ifndef UTENTE_PERMISSOES_H
#define UTENTE_PERMISSOES_H

#include "ListaVeiculo.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd

typedef struct _utentePermissoes UtentePermissoes;


/********
 * Constructor
 ********/

UtentePermissoes * UtentePermissoes_new(void);
UtentePermissoes * UtentePermissoes_newWithData(void);

/********
 * Destructor
 ********/
void UtentePermissoes_delete(UtentePermissoes * utentePermissoes);

/********
 * GET'rs
 ********/
int UtentePerms_PermiteMorador(UtentePermissoes * utentePerms);
int UtentePerms_PermiteTurista(UtentePermissoes * utentePerms);
int UtentePerms_PermiteFuncionarioCamara(UtentePermissoes * utentePerms);
int UtentePerms_PermiteMotorista(UtentePermissoes * utentePerms);
int UtentePerms_PermiteFuncionarioLimpeza(UtentePermissoes * utentePerms);


/*********
 * SET'rs
 ********/
void UtentePerms_SetPermiteMorador(UtentePermissoes * utentePerms, int permite);
void UtentePerms_SetPermiteTurista(UtentePermissoes * utentePerms, int permite);
void UtentePerms_SetPermiteFuncionarioCamara(UtentePermissoes * utentePerms, int permite);
void UtentePerms_SetPermiteMotorista(UtentePermissoes * utentePerms, int permite);
void UtentePerms_SetPermiteFuncionarioLimpeza(UtentePermissoes * utentePerms, int permite);


#endif /* UTENTE_PERMISSOES_H */