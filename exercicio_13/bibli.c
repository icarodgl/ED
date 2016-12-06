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

void insere_esq (list *lista, int k, int v){
	node *nk, *item, *atraso;
	nk = caminha(lista, k-1);
	item = malloc(1*sizeof(node));
	if (nk == lista->inicio){
		lista->inicio = item;
		item->proximo = nk;
	}
	else{	
		atraso = caminha(lista, k-2);
		atraso->proximo = item;
		item->proximo = nk;
	}
	item->caixa = v;
	lista->tamanho++;
}

void insere_dir(list *lista, int k, int v){
	node *nk, *item;
	nk = caminha(lista, k);
	item = malloc(1*sizeof(node));
	item->proximo = nk->proximo;
	nk->proximo = item;
	item->caixa = v;
	lista->tamanho++;
}

int return_num(list *lista){
	return lista->tamanho;
}

void troca_valor(list *lista, int k, int num){
	node *rastro;
	
	rastro = caminha(lista, k);
	rastro->caixa = num;
	}
void elimina_no (list *lista, int k){
	node *nk, *nv, *atraso;
	nk = caminha(lista, k);
	nv = caminha(lista, k+1);

	if (nk == lista->inicio){
		lista->inicio = nv;
	}
	else{
		atraso = caminha(lista,k-1);
		atraso->proximo = nv;
	}
	free(nk);
	lista->tamanho--;
}
int busca_true_sentinela(list *lista, int num){
	int i=0 ;
	node *nk;
	nk = lista->inicio;
	while (i < lista->tamanho){
		if (nk->caixa == num){
			return i;
			}
		nk= nk->proximo;
		i++;
	}
	
	return -1;
	}
	
int busca_true(list *lista, int num){
	int i=0 ;
	node *nk;
	nk = lista->inicio;
	while (i < lista->tamanho){
		if (nk->caixa == num){
			return 1;
			}
		nk= nk->proximo;
		i++;
	}
	
	return 0;
	}

void insere_num (list *lista, int num){
	if (busca_true(lista, num)){
		return;
		}
		
	else{
		append_item(lista, num);
		}
	}
void exclui_num (list *lista, int num){
	/*continuar daqui*/
	int i;
	i = busca_true_sentinela(lista, num);
	if (i != -1){
		elimina_no(lista, i);
		}
	}
void banir_num(list *lista, int num){
	/*continuar daqui*/
	int i=0;
	while (i != -1){
		i = busca_true_sentinela(lista, num);
		if (i != -1){
			elimina_no(lista, i);
			}
	}
}
