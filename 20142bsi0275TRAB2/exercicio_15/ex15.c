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
	pilha *lista;
	int i, tam=5;
	char C[tam];
	C[0]=')';
	C[1]='A';
	C[2]='+';
	C[3]='B';
	C[4]='(';
	
	/*--------criando estruturas----------*/
	lista = malloc(sizeof(pilha));
	cria_pilha(lista);
	
	/*--------criando conteudo---------*/
	for (i=0; i < tam; i++){
		empilhadeira(lista,C[i]);
	}
	/*---------imprime-----------*/
	printf("\n*lista: *\n");
	imprime_c(lista);
	/*-----------confere---------------*/
	i = confere_parenteses(lista);
	if(!i){ printf("\n errado \n");}
	else{printf("\n correto!! \n");}
	/*----free-----------*/
	set_me_free(lista);
	
	return 0;
}

