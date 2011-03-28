#include "VeiculoPermissoes.h"

struct _veiculoPermissoes {
	int passageiros;
	int mota;
	int ambulancia;
	int taxi;
};

/********
 *
 * Constructor
 *
 ********/

VeiculoPermissoes * VeiculoPerms_new(void) {
	VeiculoPermissoes * novo;

	if ((novo = ( VeiculoPermissoes*)malloc(sizeof( VeiculoPermissoes))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( VeiculoPermissoes));

	novo->ambulancia = 1;
	novo->mota = 1;
	novo->passageiros = 1;
	novo->taxi = 1;

	return novo;
}

VeiculoPermissoes * VeiculoPerms_newWithData(void){
	VeiculoPermissoes * novoUtente = VeiculoPerms_new();

	return novoUtente;
};
/********
 *
 * Destructor
 *
 ********/
void VeiculoPerms_delete(VeiculoPermissoes * perms) {
	memset(perms,0xdd,sizeof( VeiculoPermissoes));
	free(perms);
}

/********
 *
 * GET'rs
 *
 ********/
int VeiculoPerms_PermitePassageiros(VeiculoPermissoes * utentePerms) {
	return utentePerms->passageiros;
}

int VeiculoPerms_PermiteAmbulancia(VeiculoPermissoes * utentePerms) {
	return utentePerms->ambulancia;
}

int VeiculoPerms_PermiteTaxi(VeiculoPermissoes * utentePerms) {
	return utentePerms->taxi;
}

int VeiculoPerms_PermiteMota(VeiculoPermissoes * utentePerms) {
	return utentePerms->mota;
}


 /*********
 *
 * SET'rs
 *
 ********/
void VeiculoPerms_SetPermitePassageiros(VeiculoPermissoes * perms, int permite) {
	perms->passageiros = permite;
}

void VeiculoPerms_SetPermiteAmbulancia(VeiculoPermissoes * perms, int permite) {
	perms->ambulancia = permite;
}

void VeiculoPerms_SetPermiteTaxi(VeiculoPermissoes * perms, int permite) {
	perms->taxi = permite;
}

void VeiculoPerms_SetPermiteMota(VeiculoPermissoes * perms, int permite) {
	perms->mota = permite;
}
