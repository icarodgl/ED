#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_dc.h"

void cria_lista(node *lista){
	lista->indice = -1;
	lista->proximo = lista;
	lista->anterior = lista;
	}
void append_item(node *lista,int i){
	node *rastro, *item;
	
	rastro=lista;
	if (rastro->proximo->indice == -1){
		lista->indice = 1;
		rastro->caixa = i;
		return;
		}
	else{
		item = malloc(1*sizeof(node));
		lista->indice +=1;
		rastro = lista->anterior;
		
		item->indice = 0;
		lista->anterior=item;
		item->proximo = lista;
		rastro->proximo=item;
		item->anterior= rastro;
		item->caixa = i;
	}
}
	
void imprime_lista_circ(node *lista){
	node *rastro;
	printf("\n[ ");
	if(lista->indice == -1){
		printf("vazio ]\n");
		return;
		}
	rastro=lista;
	printf("%d ",rastro->caixa);
	for (rastro=lista->proximo; rastro->indice <= rastro->proximo->indice; rastro = rastro->proximo){
		printf("%d ",rastro->caixa);
	}
	printf("]\n");
	}

int len_lista_circ(node *lista){
	return lista->indice;
	}

node *busca_num(node *lista, int num){
	node *rastro;
	if(lista->caixa == num){
		return lista;
		}
	for (rastro=lista->proximo; rastro->indice == 0; rastro = rastro->proximo){
		if(rastro->caixa == num){
			return rastro;
			}
	}
	return NULL;
	}

node *elimina_valor(node *lista, int num){
	node *bye, *ant, *pro;
	bye = busca_num(lista, num);
	if(bye == NULL){
		return lista;
		}
	lista->indice--;
	
	ant = bye->anterior;
	pro = bye->proximo;
	ant->proximo = pro;
	pro->anterior = ant;
	
	if (bye == lista){
		pro->indice = lista->indice;
		free(bye);
		return pro;
		}
	free(bye);
	return lista;
	}
void concatena_lista_circular(node *li1, node *li2, node *lir){
	int i;
	node *rastro;
	rastro=li1;
	for (i = li1->indice; i; i--){
		append_item(lir, rastro->caixa);
		rastro=rastro->proximo;
	}
	rastro=li2;
	for (i = li2->indice; i; i--){
		append_item(lir, rastro->caixa);
		rastro=rastro->proximo;
	}
	
}

node *caminha(node *lis, int pos){
	int i;
	node *rastro;
	rastro = lis;
	for (i = 0; i < pos ; i++){
		rastro=rastro->proximo;
	}
	return rastro;
	}
	
void intercala_lista_circular(node *li1, node *li2, node *lir){
	int a=0, b=0, i;
	node *ra, *rb;
	i = li1->indice;
	i+= li2->indice;
	
	ra=li1;
	rb=li2;
	
	while(a+b < i){
		if (a < li1->indice && b < li2->indice){
			if (ra->caixa <= rb->caixa){
				a++;
				append_item(lir, ra->caixa);
				}
			else{
				b++;
				append_item(lir, rb->caixa);
				}
			}
		else{
			if(a >= li1->indice){
				b++;
				append_item(lir, rb->caixa);
				}
			
			else{			
				a++;
				append_item(lir, ra->caixa);
				}
			
			}
		ra = caminha(li1, a);
		rb = caminha(li2, b);	
			
	}
}
void copia_lista(node *de, node *para){
	node *rastro;
	rastro = de;
	while(1){
		if(rastro->proximo != de){
			append_item(para, rastro->caixa);
			}
		else{
			append_item(para, rastro->caixa);
			return;
			}
		rastro=rastro->proximo;
		
		}
	
	}
void set_me_free(node *lista){
	int i;
	node *rastro, *lastro;
	rastro = lista;
	i = lista->indice;
	while(i){
		lastro=rastro;
		rastro=rastro->proximo;
		free(lastro);
		i--;
	}
	free (lista);
}
