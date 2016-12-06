/*
 * lista_encadeada.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli.h"


int main(int argc, char **argv){
	int i=0;
	list *lista;
	lista = malloc(1*sizeof(list));
	lista->tamanho = 0;
	
	while (i <10){
		append_item(lista, i);
		i++;
		}
		
	/*imprimir uma lista*/
	imprime_lista(lista);
	printf("\n Tamanho: %d\n",return_num(lista));;
	set_me_free(lista);
	return 0;
}

