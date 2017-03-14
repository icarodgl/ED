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
	pilha *lista, *lista2;
	int i, tam=5;
	char C[tam], D[tam];
	
	/*--------criando estruturas----------*/
	lista = malloc(sizeof(pilha));
	cria_pilha(lista);
	lista2 = malloc(sizeof(pilha));
	cria_pilha(lista2);
	/*pilha 1*/
	C[0]='A';
	C[1]='B';
	C[2]='B';
	C[3]='B';
	C[4]='B';
	/*pilha 2*/
	D[0]='B';
	D[1]='B';
	D[2]='B';
	D[3]='B';
	D[4]='A';
	
	/*--------criando conteudo---------*/
	for (i=0; i < tam; i++){
		empilhadeira(lista,C[i]);
	}
	
	for (i=0; i < tam; i++){
		empilhadeira(lista2,D[i]);
	}
	/*---------imprime-----------*/
	printf("\nlistas: \n");
	imprime_c(lista);
	imprime_c(lista2);
	/*-----------confere---------------*/
	i = confere_xCy(lista, lista2);
	if(i){ printf("\n errado \n");}
	else{printf("\n correto!! \n");}
	/*----free-----------*/
	set_me_free(lista);
	
	return 0;
}

