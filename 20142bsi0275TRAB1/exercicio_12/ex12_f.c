#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_dc.h"


int main(int argc, char **argv){
	int i=0;
	node *lista1, *lista3;
	lista1 = malloc(1*sizeof(node));
	cria_lista(lista1);
	lista3 = malloc(1*sizeof(node));
	cria_lista(lista3);
	
	while (i < 4){
		append_item(lista1, i*i);
		i++;
		}
		i=0;
		
	printf("\n criada: ");
	imprime_lista_circ(lista1);
	imprime_lista_circ(lista3);
	printf("\n copia: ");
	copia_lista(lista1, lista3);
	imprime_lista_circ(lista3);
	set_me_free(lista1);
	set_me_free(lista3);
	return 0;
}

