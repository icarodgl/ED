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
	int tamanho=10, i;
	list *lista;
	lista = malloc(1*sizeof(list));
	cria_lista(lista, tamanho);
	
	for (i=0; i< 10;i++){
		add_conteudo(lista, i*i);
	}
	nremove(lista, 3, 6);
	imprime(lista);
	set_me_free(lista);
	return 0;
}

