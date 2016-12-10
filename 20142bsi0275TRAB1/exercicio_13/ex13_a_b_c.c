#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_dc.h"


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
	printf("\nlen %d\n",len_lista_circ(lista));
	printf("\nelimina:");
	lista = elimina_valor(lista, 0);

	imprime_lista_circ(lista);
	set_me_free(lista);

	return 0;
}

