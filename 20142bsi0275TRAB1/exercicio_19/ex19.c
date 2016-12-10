#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_d.h"


int main(int argc, char **argv){
	int i=0;
	list *lista;
	lista = malloc(1*sizeof(list));
	
	while (i < 20){
		append_item(lista, i*i);
		i++;
		}
		i=0;
		
	printf("\n criada: ");
	imprime_lista(lista);
	remove_direita(lista, 2);
	printf("\n removido item a direito do terceiro indice: ");
	imprime_lista(lista);
	set_me_free(lista);
	return 0;
}

