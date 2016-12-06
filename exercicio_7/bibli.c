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
node *caminha(list *lista, int pos){
	int i;
	node *ra;
	ra=lista->inicio;
	for (i=0; i < pos; i++){
	ra=ra->proximo;
	}
	return ra;
}	
void troca(list *lista,node *nk, node *nv){
	node *aponta;
	aponta = lista->inicio;
	if (aponta != nk){
		while(aponta->proximo != nk){
			aponta = aponta->proximo;
			}
		aponta->proximo= nv;
		nk->proximo=nv->proximo;
		nv->proximo = nk;
		
	}
	else{
		lista->inicio = nv;
		nk->proximo = nv->proximo;
		nv->proximo = nk;
		
		
		}
 	
	}
void ordenador(list *lista){
	int i=1, k;
	node *r1, *r2;
	
	while (i){
		i=0;
		for (k=0;k != lista->tamanho;k++){
			r1 = caminha(lista,k);
			r2 = caminha(lista,k-1);
			if (r1->caixa < r2->caixa){
				troca(lista, r2, r1);
				i=1;
				}

	}
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
