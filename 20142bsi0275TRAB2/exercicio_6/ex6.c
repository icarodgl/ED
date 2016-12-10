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
	/*------CRIA LISTA-----*/
	list *lista;
	
	lista = malloc(1*sizeof(list));
	cria_lista(lista, tamanho);
	
	for (i=0; i< 9;i++){
		add_conteudo(lista, i*2);
	}
	/*-----EXERCICIO------*/
	
	
	inicio_para_fim(lista,3);
	imprime(lista);

	/*------FREE-------*/
	set_me_free(lista);
	return 0;
}

