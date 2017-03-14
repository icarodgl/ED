/*
 * ex15.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
 * 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "../bibliotecas/bibli_pilha.h"


int main(int argc, char **argv){
	pilhad *lista;
	int i, tam=5;
	char C[tam];
	
	/*--------criando estruturas----------*/
	lista = malloc(sizeof(pilhad));
	cria_pilha_d(lista);
	/*pilha 1*/
	C[0]='A';
	C[1]='B';
	C[2]='C';
	C[3]='D';
	C[4]='E';
	
	/*--------criando conteudo---------*/

	for (i=0; i < tam; i++){
		empilhadeira_d(lista,C[i]);
	}
	/*---------imprime-----------*/
	printf("\nlista criada: \n");
	imprime_d(lista);
	/*-----------funções-------------*/
	printf("\nfunções");
	i= desempilhador_d(lista);
	printf("\ndesempilha %c", i);
	empilhadeira_d(lista, 'X');
	printf("\nempilhado X");
	i = eject_d(lista);
	printf("\npop %c", i);
	inject_d(lista, 'X');
	printf("\npush x");
	imprime_d(lista);
	/*----free-----------*/
	set_me_free_d(lista);
	
	return 0;
}

