/*
 * lista_encadeada.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_est_enc.h"


int main(int argc, char **argv){
	int tamanho=10, i;
	/*------CRIA LISTA-----*/
	list *lista;
	
	lista = malloc(1*sizeof(list));
	cria_lista(lista, tamanho);
	
	for (i=0; i< 10;i++){
		append(lista, i+i);
	}
	/*-----EXERCICIO------*/

	imprime(lista);
	remove_ind(lista, 9);
	imprime(lista);
	append(lista, 99);
	imprime(lista);
	/*------FREE-------*/
	return 0;
}

