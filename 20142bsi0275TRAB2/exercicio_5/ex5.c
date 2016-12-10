/*
 * lista_encadeada.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli.h"


int main(int argc, char **argv){
	int tamanho=10, i, x;
	/*-----------*/
	list *lista, *lista2, *lista3, *lista4;
	
	lista = malloc(1*sizeof(list));
	cria_lista(lista, tamanho);

	lista2 = malloc(1*sizeof(list));
	cria_lista(lista2, tamanho);	
	
	lista3 = malloc(1*sizeof(list));
	cria_lista(lista3, tamanho*tamanho);
	
	lista4 = malloc(1*sizeof(list));
	cria_lista(lista4, tamanho*tamanho);
	/*-----------*/
	
	for (i=0; i< 9;i++){
		add_conteudo(lista, i*2);
	}
	x = verifica_ordenada(lista);
	if (x == 1){
		printf("\nlista crescente");
		}
	if(x == -1){
		printf("\nlista decrescente");
		}
	if(x == 0){
		printf("\nlista não ordenada");
		}
		
	imprime(lista);
		/*-------------*/
	copialista(lista, lista2);
	printf("\nlista2 copiada:");
	imprime(lista2);
	/*-------------*/
	limpa_lista(lista2);
	printf("\nlista2 copia sem repetição:");
	copia_sem_repetidas(lista, lista2);
	imprime(lista2);
	/*-------------*/
	printf("\nlista1 invertida:");
	inverte_lista(lista);
	imprime(lista);
	inverte_lista(lista);
	/*-------------*/
	limpa_lista(lista2);
	for (i=0; i< 5;i++){
		add_conteudo(lista2, i);
	}
	/*-------------*/
	printf("\nlista3 intercala !repetidas:");
	intercala_listas_n(lista,lista2, lista3);
	imprime(lista3);
	/*-------------*/
	printf("\nlista4 intercala:");
	intercala_listas(lista,lista2, lista4);
	imprime(lista4);
	/*------FREE-------*/
	set_me_free(lista);
	set_me_free(lista2);
	set_me_free(lista3);
	set_me_free(lista4);
	return 0;
}

