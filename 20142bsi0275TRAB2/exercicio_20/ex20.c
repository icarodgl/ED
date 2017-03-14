/*
 * lista_encadeada.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void pop_pilha(int *pilha){
	
	}
int eject_pilha(int *pilha){
	int i = 0,item;
	item = pilha[0];
	
	return item;
	}
void cria_pilha_vazia(int *pilha,int tam){
	int i;
	
	for (i=0;i < tam; i++){
		pilha[i]= -1;
		}
	}
int main(int argc, char **argv){
	int tamanho=10, i;
	int *pilha;
	pilha = malloc(tamanho*sizeof(int));
	cria_pilha_vazia(pilha, tamanho);
	/*----------*/
	
	pop_pilha(pilha);
	i = eject_pilha(pilha);
	
	printf("\n%d",i);
	
	return 0;
}

