#include "UtentePermissoes.h"

struct _utentePermissoes {
	int morador;
	int turista;
	int funcionarioCamara;
	int motorista;
	int funcionarioLimpeza;
};

/********
 *
 * Constructor
 *
 ********/

UtentePermissoes * UtentePermissoes_new(void) {
	UtentePermissoes * novo;

	if ((novo = ( UtentePermissoes*)malloc(sizeof( UtentePermissoes))) == NULL) { 
		exit(1);
	}
	memset(novo,0xda,sizeof( UtentePermissoes));

	novo->funcionarioCamara = 1;
	novo->funcionarioLimpeza = 1;
	novo->morador = 1;
	novo->motorista = 1;
	novo->turista = 1;

	return novo;
}

UtentePermissoes * UtentePermissoes_newWithData(void){
	UtentePermissoes * novoUtente = UtentePermissoes_new();

	return novoUtente;
};
/********
 *
 * Destructor
 *
 ********/
void UtentePermissoes_delete(UtentePermissoes * perms) {
	memset(perms,0xdd,sizeof( UtentePermissoes));
	free(perms);
}

/********
 *
 * GET'rs
 *
 ********/
int UtentePerms_PermiteMorador(UtentePermissoes * utentePerms) {
	return utentePerms->morador;
}

int UtentePerms_PermiteTurista(UtentePermissoes * utentePerms) {
	return utentePerms->turista;
}

int UtentePerms_PermiteFuncionarioCamara(UtentePermissoes * utentePerms) {
	return utentePerms->funcionarioCamara;
}

int UtentePerms_PermiteMotorista(UtentePermissoes * utentePerms) {
	return utentePerms->motorista;
}

int UtentePerms_PermiteFuncionarioLimpeza(UtentePermissoes * utentePerms) {
	return utentePerms->funcionarioLimpeza;
}


 /*********
 *
 * SET'rs
 *
 ********/
void UtentePerms_SetPermiteMorador(UtentePermissoes * utentePerms, int permite) {
	utentePerms->morador = permite;
}

void UtentePerms_SetPermiteTurista(UtentePermissoes * utentePerms, int permite) {
	utentePerms->turista = permite;
}

void UtentePerms_SetPermiteFuncionarioCamara(UtentePermissoes * utentePerms, int permite) {
	utentePerms->funcionarioCamara = permite;
}

void UtentePerms_SetPermiteMotorista(UtentePermissoes * utentePerms, int permite) {
	utentePerms->motorista = permite;
}

void UtentePerms_SetPermiteFuncionarioLimpeza(UtentePermissoes * utentePerms, int permite) {
	utentePerms->funcionarioLimpeza = permite;
}
