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
	/*---------inserir item na posição----------*/
	i = insere_ret(lista, 7 ,88);	
	/*imprimir uma lista*/
	
	/*---------excluir chave----------*/	
	excluir_chave(lista, 3);
	imprime_lista(lista);	


	set_me_free(lista);
	return 0;
}

