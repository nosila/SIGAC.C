/*
 *  VeiculoPermissoes.h
 */

#ifndef Veiculo_PERMISSOES_H
#define Veiculo_PERMISSOES_H

#include "ListaVeiculo.h"

#define NEW 0xdadadada
#define DELETED 0xdddddddd

typedef struct _veiculoPermissoes VeiculoPermissoes;


/********
 * Constructor
 ********/

VeiculoPermissoes * VeiculoPerms_new(void);
VeiculoPermissoes * VeiculoPerms_newWithData(void);

/********
 * Destructor
 ********/
void VeiculoPerms_delete(VeiculoPermissoes * utentePermissoes);

/********
 * GET'rs
 ********/
int VeiculoPerms_PermitePassageiros(VeiculoPermissoes * utentePerms);
int VeiculoPerms_PermiteAmbulancia(VeiculoPermissoes * utentePerms);
int VeiculoPerms_PermiteTaxi(VeiculoPermissoes * utentePerms);
int VeiculoPerms_PermiteMota(VeiculoPermissoes * utentePerms);


/*********
 * SET'rs
 ********/
void VeiculoPerms_SetPermitePassageiros(VeiculoPermissoes * perms, int permite);
void VeiculoPerms_SetPermiteAmbulancia(VeiculoPermissoes * perms, int permite);
void VeiculoPerms_SetPermiteTaxi(VeiculoPermissoes * perms, int permite);
void VeiculoPerms_SetPermiteMota(VeiculoPermissoes * perms, int permite);

#endif /* UTENTE_PERMISSOES_H */