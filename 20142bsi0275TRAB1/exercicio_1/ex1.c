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
	int i=0;
	list *lista;
	lista = malloc(1*sizeof(list));
	lista->tamanho = 0;
	
	while (i <10){
		append_item(lista, rand() %10);
		i++;
		}
		
	/*imprimir uma lista*/
	imprime_lista(lista);
	printf("\n alterada: \n");
	
	insere_esq(lista,0, 999);
	
	insere_dir(lista,0, 999);
	
	troca_valor(lista, 5, 999);
	imprime_lista(lista);
	elimina_no (lista, 5);
	imprime_lista(lista);
	banir_num(lista, 1);
	imprime_lista(lista);
	printf("\n Tamanho: %d\n",return_num(lista));
	printf("\n busca sentilela num: 6 pos: %d\n",busca_true_sentinela(lista, 6));
	set_me_free(lista);
	return 0;
}

