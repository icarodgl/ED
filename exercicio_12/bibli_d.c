#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_d.h"

void append_item (list *lista, int numero){
	node *item;
	item = malloc(1*sizeof(node));
	
	if (lista->tamanho == 0){
		lista->tamanho+=1;
		item->proximo= NULL;
		item->anterior=NULL;
		lista->inicio=item;
		lista->fim=item;
		}
	else{
		lista->tamanho+=1;
		item->proximo= NULL;
		item->anterior=lista->fim;
		lista->fim->proximo=item;
		lista->fim=item;
		}
		
	item->caixa = numero;	
	}

int tamanho(list *lista){
	int pega;
	pega = lista->tamanho;
	return pega;
	}
void troca_valor(list *lista, int k, int v){
	int i=0 ;
	node *nk;
	/*buscando o nó */
	
	nk = lista->inicio;
	while (i<k){
		nk= nk->proximo;
		i++;
		}
	nk->caixa = v;
	
	}
void troca(list *lista,int k,int v){
	int i=0 ;
	node *nk, *nv, naux[1], *aponta;
	
	/*buscando os nós a serem trocados */
	nk = lista->inicio;
	while (i<k){
		nk= nk->proximo;
		i++;
		}
	i=0;
	nv = lista->inicio;
		while (i<v){
		nv = nv->proximo;
		i++;
		}
	/*trocando os nós lista duplamente encadeada*/
	
	aponta = nk->anterior;
	aponta->proximo = nv;
	
	aponta = nk->proximo;
	aponta->anterior = nv;
	
 	naux->proximo = nk->proximo;
 	naux->anterior = nk->anterior;
 	
 	aponta = nv->anterior;
	aponta->proximo = nk;
	
	aponta = nv->proximo;
	aponta->anterior = nk;
	
 	nk->proximo = nv->proximo;
 	nk->anterior = nv->anterior;

 	nv->proximo = naux->proximo;
 	nv->anterior = naux->anterior;	
 	
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
	
void insere_esq (list *lista, int k, int v){
	int i=0 ;
	node *nk, *item;
	/*buscando o nó */
	nk = lista->inicio;
	while (i<k){
		nk= nk->proximo;
		i++;
	}
	
	item = malloc(1*sizeof(node));
	lista->tamanho+=1; 
	item->proximo= nk;
	item->anterior=nk->anterior;
	
	nk->anterior->proximo= item;
	nk->anterior= item;
	
	item->caixa = v;	
	
	}
	
void insere_dir (list *lista, int k, int v){
	int i=0 ;
	node *nk, *item;
	/*buscando o nó */
	nk = lista->inicio;
	while (i<k){
		nk= nk->proximo;
		i++;
	}
	
	item = malloc(1*sizeof(node));
	lista->tamanho+=1;
	
	item->anterior= nk;
	item->proximo=nk->proximo;
	
	
	nk->proximo= item;
	nk->proximo->anterior= item;
	
	item->caixa = v;	
	
	}
void excluir(list *lista, int k){
	int i=0 ;
	node *nk;
	/*buscando o nó */
	nk = lista->inicio;
	while (i<k){
		nk= nk->proximo;
		
		i++;
	}
	if (i != 0 || i != lista->tamanho){
		nk->anterior->proximo = nk->proximo;
		nk->proximo->anterior = nk->anterior;
		lista->tamanho--;
		free(nk);
	}
	if (i == 0){
		nk->proximo->anterior = nk->anterior;
		lista->tamanho--;
		free(nk);
		}
	if (i == lista->tamanho){
		nk->anterior->proximo = nk->proximo;
		lista->tamanho--;
		free(nk);
		
		}
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
	
node* busca_pos(list *lista, int num){
	int i=0, pega;
	
	node *nk;
	nk = lista->inicio;
	while (nk != NULL){
		pega = nk->caixa;
		if (num == pega){
			return nk;
			}
		nk= nk->proximo;
		i++;
	}
	return NULL;
	}
void excluir_pos(list *lista, node *nk){

	if (nk->anterior != NULL && nk->proximo != NULL){
		nk->anterior->proximo = nk->proximo;
		nk->proximo->anterior = nk->anterior;
		lista->tamanho--;
		free(nk);
		return;
	}
	if (nk->anterior == NULL){
		nk->proximo->anterior = NULL;
		lista->inicio = nk->proximo;
		lista->tamanho--;
		free(nk);
		return;
		}
	if (nk->proximo == NULL){
		lista->fim = nk->anterior;
		nk->anterior->proximo = nk->proximo;
		lista->tamanho--;
		free(nk);
		return;
		}
	}
void exclui_num (list *lista, int num){
	/*continuar daqui*/
	node *pos;
	pos = busca_pos(lista, num);
	if (pos!= NULL){
			excluir_pos(lista, pos);
		}
	}
	
void banir_num (list *lista, int num){
	/*continuar daqui*/
	node *pos;
	pos = busca_pos(lista, num);
	while (pos != NULL){
		pos = busca_pos(lista, num);
		if (pos!= NULL){
				excluir_pos(lista, pos);
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
void concatena_listas(list *li1,list *li2,list *li3){
	int i;
	node *rastro;
	i = li1->tamanho;
	i+= li2->tamanho;
	
	li3->tamanho = i;
	li3->inicio = li1->inicio;
	for (rastro= li3->inicio; rastro->proximo != NULL; rastro=rastro->proximo);
	li2->inicio->anterior=rastro;
	rastro->proximo = li2->inicio;
	li3->fim = li2->fim;

	}
