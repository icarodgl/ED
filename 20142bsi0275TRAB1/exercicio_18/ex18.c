#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli.h"


int main(int argc, char **argv){
	int i=0;
	list *lista;
	lista = malloc(1*sizeof(list));
	lista->tamanho=0;
	
	while (i < 20){
		append_item(lista, i*i);
		i++;
		}
		i=0;
		
	printf("\n criada: ");
	imprime_lista(lista);
	
	printf("\n kesimo=\"4\" maior número: %d\n",acha_kaesimo(lista, 4));
	set_me_free(lista);
	return 0;
}

