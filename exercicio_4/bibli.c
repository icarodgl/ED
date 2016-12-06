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

	
void concatena_ordenado(list *li1,list *li2,list *li3){
	int tam;
	node *r1, *r2, *ra;
	tam = li1->tamanho;
	tam+= li2->tamanho;

	r1 = li1->inicio;
	r2 = li2->inicio;
	
	if (r1->caixa < r2->caixa){
		li3->tamanho++;
		ra = r1;
		li3->inicio = ra;
		r1=r1->proximo;
	}
	else{
		li3->tamanho++;
		ra = r2;
		li3->inicio = ra;
		r2=r2->proximo;
		}
	
	while (li3->tamanho < tam){ /*continua até acabar as duas listas*/
		if(r1 != NULL && r2 != NULL){ /*nenhuma lista está no fim*/
			if (r1->caixa <= r2->caixa){
				ra->proximo = r1;
				ra = r1;
				r1 = r1->proximo;
				li3->tamanho++;
			}
			else{
				ra->proximo = r2;
				ra = r2;
				r2 = r2->proximo;
				li3->tamanho++;
				}	
		
		}/*else >> if (r1 != NULL || r2 != NULL)*/
		else{
			if (r1 == NULL){
					if (ra == NULL) break;
					ra->proximo = r2;
					ra = r2;
					r2 = r2->proximo;
					li3->tamanho++;
				}/*if (r1 == NULL)*/

			else{
					if (ra == NULL) break;
					ra->proximo = r1;
					ra=r1;
					r1= r1->proximo;
					li3->tamanho++;
				} /*( r2 == NULL) */
			}
		}/*while*/

}/*concatena_ordenado*/

void concatena_listas(list *li1,list *li2,list *li3){
	int i;
	node *rastro;
	i = li1->tamanho;
	i+= li2->tamanho;
	/*cria lista do tamanho total das duas nateriores*/
	li3->inicio = li1->inicio;
	for (rastro = li1->inicio; rastro->proximo != NULL; rastro=rastro->proximo);
	rastro->proximo = li2->inicio;
	li3->tamanho = i;
	}
