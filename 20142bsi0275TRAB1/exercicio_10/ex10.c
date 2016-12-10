#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_d.h"


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
	printf("banir numero: 5");
	banir_num (lista, 5);
	imprime_lista(lista);
	printf("inserir: 5");
	insere_num(lista, 5);
	imprime_lista(lista);
	set_me_free(lista);
	return 0;
}

