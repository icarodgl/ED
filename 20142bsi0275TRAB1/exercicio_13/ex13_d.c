#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_dc.h"


int main(int argc, char **argv){
	int i=0;
	node *lista1, *lista2, *lista3;
	lista1 = malloc(1*sizeof(node));
	cria_lista(lista1);
	lista2 = malloc(1*sizeof(node));
	cria_lista(lista2);
	lista3 = malloc(1*sizeof(node));
	cria_lista(lista3);
	
	while (i < 10){
		append_item(lista1, i);
		i++;
		}
		i=0;
	while (i < 10){
		append_item(lista2, i);
		i++;
		}
		
	printf("\n criada: ");
	imprime_lista_circ(lista1);
	imprime_lista_circ(lista2);
	imprime_lista_circ(lista3);
	printf("\n resultado: ");
	concatena_lista_circular(lista1, lista2, lista3);
	imprime_lista_circ(lista3);
	set_me_free(lista1);
	set_me_free(lista2);
	set_me_free(lista3);
	return 0;
}

