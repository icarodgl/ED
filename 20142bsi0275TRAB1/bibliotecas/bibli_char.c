#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_char.h"



void append_item (list *lista, char *numero){
	node *item, *rastro;
	char letra=numero[0];
	item = malloc(1*sizeof(node));
	rastro = lista->inicio;
	
	if (lista->tamanho == 0){
		lista->tamanho+=1;
		lista->inicio=item;
		item->proximo= NULL;
		}
	else{
		lista->tamanho+=1;
		item->proximo= NULL;
		while (1){
				if (rastro->proximo == NULL){
					rastro->proximo = item;
					break;
					}
				rastro= rastro->proximo;
			}
		}
		
	item->caixa = letra;	
	}

void imprime_lista(list *lista){
	node *rastro;
	rastro = lista->inicio;
	printf("\n [");
	while (rastro != NULL){
		
		printf("%c ",rastro->caixa);
	
		rastro = rastro->proximo;
	}
	printf("]\n");
	
	
	}


void set_me_free(list *lista){
	node *rastro, *lastro;
	rastro = lista->inicio;
	while(rastro != NULL){
		lastro=rastro;
		rastro=rastro->proximo;
		free(lastro);
	}
	free (lista);
}

void troca_palavra(list *lista1, list *lista2){
	node *rastro;
	rastro=lista1->inicio;
	lista1->inicio = lista2->inicio;
	lista2->inicio = rastro;
	
	
	
	}
