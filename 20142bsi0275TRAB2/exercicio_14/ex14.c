#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../bibliotecas/bibli_enc.h"
int main(int argc, char **argv){
	int i=0;
	list *lista,*lista2, *lista3, *lista4;
	
	/*-------criando listas--------*/
	lista = malloc(1*sizeof(list));
	lista->tamanho = 0;
	
	lista2 = malloc(1*sizeof(list));
	lista2->tamanho = 0;
	
	lista3 = malloc(1*sizeof(list));
	lista3->tamanho = 0;
	
	lista4 = malloc(1*sizeof(list));
	lista4->tamanho = 0;
	while (i < 10){
		append_item(lista, i*i);
		i++;
		}
		i=0;
	while (i < 10){
		append_item(lista2, i*2);
		i++;
		}
		
	/*-------funções--------*/
	conjunto_uniao(lista, lista2, lista3);
	conjunto_intersec(lista, lista2, lista4);
	imprime_lista(lista);
	imprime_lista(lista2);
	imprime_lista(lista3);
	imprime_lista(lista4);


	/*-------frees--------*/
	set_me_free(lista);
	set_me_free(lista2);
	set_me_free(lista3);
	set_me_free(lista4);
	
	return 0;
}
