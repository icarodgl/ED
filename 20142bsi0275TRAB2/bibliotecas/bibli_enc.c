#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_enc.h"



void append_item(list *lista, int numero){
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
	if(pos >= lista->tamanho){return NULL;}
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
void imprime_lista_recursiva(list *lista, node *rastro){
		if (rastro == NULL){
			rastro = lista->inicio;
			printf("[ ");
			}
		printf("%d ",rastro->caixa);
		if (rastro->proximo != NULL){
			rastro= rastro->proximo;
			imprime_lista_recursiva(lista, rastro);
		}
		else {
		printf("]\n");
		return;
		}
	}
int acha_kaesimo(list *lista,int k){
	int i=0, aux;
	node *rastro;

	if (lista->tamanho < k || k == 0){
		return 0;
		}
	rastro=lista->inicio;
	aux=rastro->caixa;

	while (rastro != NULL){
		if (aux < rastro->caixa){
				aux = rastro->caixa;
			}
		rastro = rastro->proximo;
	}
	i=aux;

		while (k-1){
			i--;
			rastro = lista->inicio;

			while (rastro != NULL){

				if (rastro->caixa == i ){
						aux = rastro->caixa;

						k--;
					}

				rastro = rastro->proximo;
			}


	}
	return aux;
}
void appini_item (list *lista, int numero){
	node *item, *rastro;
	item = malloc(1*sizeof(node));
	rastro = lista->inicio;
	
		lista->tamanho+=1;
		lista->inicio=item;
		item->proximo= rastro;
		item->caixa = numero;
	}

void separa_par_impar(list *lista,list *par,list *impar){
	node *rastro, *rimpar=NULL, *rpar=NULL;
	
	
	for (rastro= lista->inicio; rastro != NULL; rastro=rastro->proximo){
			if (rastro->caixa%2 == 0){
				if (rpar == NULL){
					rpar = rastro;
					par->inicio = rpar;
					}
				else{
					rpar->proximo =  rastro;
					rpar = rastro;
					}
				}
			else{
				if (rimpar == NULL){
					rimpar = rastro;
					impar->inicio = rimpar;
					}
				else{
					rimpar->proximo =  rastro;
					rimpar = rastro;
					}				
				
				
				}
		}
	rpar->proximo= NULL;
	rimpar->proximo=NULL;
	}
int* acha_cadeia(list *lista, int de, int *resp){
	int i=0,j, guarda[2];
	node *rastro, *rastro2;
	guarda[0]=0;
	guarda[1]=0;
	resp[0]=0;
	resp[1]=0;

	for (rastro = lista->inicio; rastro != NULL; rastro=rastro->proximo){
		
		if(rastro->caixa == de){
			j=i;
			for(rastro2 = rastro; rastro2 != NULL && rastro2->caixa == de; rastro2=rastro2->proximo){
				j++;
				}
			guarda[0]=i;
			guarda[1]=j-1;
			}
			i++;
		if(resp[1]-resp[0] < guarda[1]-guarda[0]){
			resp[1]=guarda[1];
			resp[0]=guarda[0];
			}
		}
	
	return resp;
	}
void move_node(list *lista, int pos, int pos2){
	node *rastro;
	int i;
	
	rastro = caminha(lista, pos);
	i = rastro->caixa;
	elimina_no(lista, pos);
	insere_dir(lista, pos2, i);
	}
	
void append_item_c (listc *lista, char letra){
	noc *item, *rastro;
	item = malloc(1*sizeof(noc));
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
void imprime_lista_c(listc *lista){
	noc *rastro;
	rastro = lista->inicio;
	printf("\n [");
	while (rastro != NULL){
		
		printf("%c ",rastro->caixa);
	
		rastro = rastro->proximo;
	}
	printf("]\n");
	
	
	}
void set_me_free_c(listc *lista){
	noc *rastro, *lastro;
	rastro = lista->inicio;
	while(rastro != NULL){
		lastro=rastro;
		rastro=rastro->proximo;
		free(lastro);
	}
	free (lista);
}
void inversor_c(listc *lista){
	noc *r1, *r2, *rg;
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
void conjunto_intersec(list *lisa,list *lisb,list *lisr){
	node *arastro;
	
	for(arastro=lisa->inicio; arastro != NULL; arastro= arastro->proximo){
		if(busca_true(lisb, arastro->caixa)){
			append_item(lisr, arastro->caixa);
		}
	}	
	}
void conjunto_uniao(list *lisa,list *lisb,list *lisr){
	node *arastro;
	
	for(arastro = lisa->inicio; arastro != NULL; arastro= arastro->proximo){
			append_item(lisr, arastro->caixa);
			}
	for(arastro=lisb->inicio; arastro != NULL; arastro= arastro->proximo){
		if(busca_true(lisr, arastro->caixa) == 0){
			append_item(lisr, arastro->caixa);
		}
	}	
	}
int conjunto_pertence(list *lista, int num){
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
void conjunto_diferenca(list *lisa,list *lisb,list *lisr){
	node *arastro;
	
	for(arastro=lisa->inicio; arastro != NULL; arastro= arastro->proximo){
		if(conjunto_pertence(lisb, arastro->caixa) == 0){
			append_item(lisr, arastro->caixa);
		}
	}	
	for(arastro=lisb->inicio; arastro != NULL; arastro= arastro->proximo){
		if(conjunto_pertence(lisa, arastro->caixa) == 0){
			append_item(lisr, arastro->caixa);
		}
	}	
	}
