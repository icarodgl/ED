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
	pilhad *lista, *lista2;
	int i, tam=5;
	char C[tam], D[tam];
	
	/*--------criando estruturas----------*/
	lista = malloc(sizeof(pilhad));
	cria_pilha_d(lista);
	lista2 = malloc(sizeof(pilhad));
	cria_pilha_d(lista2);
	/*pilha 1*/
	C[0]='A';
	C[1]='B';
	C[2]='C';
	C[3]='D';
	C[4]='E';
	/*pilha 2*/
	D[0]='E';
	D[1]='D';
	D[2]='C';
	D[3]='B';
	D[4]='A';
	
	/*--------criando conteudo---------*/

	for (i=0; i < tam; i++){
		empilhadeira_d(lista,C[i]);
	}
	for (i=0; i < tam; i++){
		empilhadeira_d(lista2,D[i]);
	}
	/*---------imprime-----------*/
	printf("\nlistas: \n");
	imprime_d(lista);
	imprime_d(lista2);
	/*-----------confere---------------*/
	i= desempilhador_d(lista);
	printf("pop: %c", i);
	imprime_d(lista);
	printf("analize:\n Como há n deslocamentos o tempo de push é de tempo*elementos, o pop tem tempo 1\n");
	/*----free-----------*/
	set_me_free_d(lista);
	set_me_free_d(lista2);
	
	return 0;
}

