#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_d.h"


int main(int argc, char **argv){
	int i=0;
	node *no;
	list *lista;
	lista = malloc(1*sizeof(list));
	lista->tamanho = 0;
	while (i <10){
		append_item(lista, i);
		i++;
		}
		
	/*imprimir uma lista*/
	imprime_lista(lista);	
	/*---------caminhar----------*/
	no = caminha(lista, 8);
	if(no != NULL){
	printf("\nconteúdo do no: %d\n",no->caixa);
	}
	else{
		printf("NULL\n");
		}
	/*---------acrescentar----------*/
	i=insere_ret(lista, 5, 99);
	if(!i){printf("\ninserido\n");}
	else{printf("\nerro\n");}
	imprime_lista(lista);
	/*---------excluir----------*/
	i=excluir_pos(lista, 5);
	if(!i){printf("\nexcluido\n");}
	else{printf("\nerro\n");}
	imprime_lista(lista);
	
	set_me_free(lista);
	return 0;
}

