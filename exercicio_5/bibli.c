#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli.h"



void append_item (list *lista, int numero){
	node *item, *rastro;
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
		
	item->caixa = numero;	
	}

void imprime_lista(list *lista){
	node *rastro;
	rastro = lista->inicio;
	printf("\n [");
	while (rastro != NULL){
		
		printf("%d ",rastro->caixa);
	
		rastro = rastro->proximo;
	}
	printf("]\n");
	
	
	}	

void inversor(list *lista){
	node *r1, *r2, *rg;
	int tam ,i=0 ,k=0;
	rg = lista->inicio;
	tam=lista->tamanho-1;
	while(i <= tam){
		/*inicio*/
		r1 = rg;
		r2 = rg;
		/*caminha até o ultimo menos quantas vezes andou*/
		while(k < tam-i ){
			r1=r1->proximo;
			k++;
			}
		k=0;
		/*caminha até o ante penultimo*/
		while(k < tam-(i+1)){
			r2=r2->proximo;
			k++;
			}
		k=0;
	if (i == 0){
		lista->inicio = r1;
		r1->proximo = r2;
		}
	if (i == tam){
		r1->proximo = NULL;
	}
	else{
		r1->proximo = r2;	
	}	
	i++;
	}
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
