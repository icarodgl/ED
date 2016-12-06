#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_dc.h"


int main(int argc, char **argv){
	int i=0;
	node *lista;
	lista = malloc(1*sizeof(node));
	cria_lista(lista);

	
	while (i < 10){
		append_item(lista, i);
		i++;
		}
		
	printf("\n criada: ");
	imprime_lista_circ(lista);
	printf("%d\n",len_lista_circ(lista));

	lista = elimina_valor(lista, 0);
	
	imprime_lista_circ(lista);

	return 0;
}

