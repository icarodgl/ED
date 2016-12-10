#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_est_enc.h"
/*
 typedef struct{
	int chave;
	int prox;
	}node;
	* 
typedef struct list{
	node **vetor;
	int primeiro;
	int ultimo;
	int disponivel;
	} list;
*/
void cria_lista(list *lista, int t){
	int i;
	lista->disponivel = t;
	lista->vetor=malloc(t*sizeof(node));
	for(i=0;i<t;i++){lista->vetor[i].prox=-1;}
	lista->primeiro=0;
	lista->ultimo=0;
	}
int acha_buraco(list *l){
	int i = 0, buraco;
	while (1){
		
		buraco = l->vetor[i].prox;
		if(buraco == -1){return i;}
		
	i++;
	}
	return i;
}
void remove_ind(list *l, int ind){
	int i=0,r, rr;
	node *vet;
	vet = l->vetor;
	r=l->primeiro;
	if(ind == l->primeiro){
		l->primeiro = vet[l->primeiro].prox;
		vet[ind].prox=-1;
		l->disponivel+=1;
		}
	else{
	while (i < ind-1) {
		r = l->vetor[r].prox;
		i++;
		}
		rr = vet[r].prox;
		if(rr == -2){
			vet[r].prox = -2;
			}
		else{
		vet[r].prox = vet[rr].prox;
		vet[rr].prox = -1;
		l->disponivel+=1;
	}
	}
	}
void append(list *l, int conteudo){
	int buraco;
	node *vet;
	vet = l->vetor;
	l->disponivel-=1;
	if(0 > (l->disponivel)){return;}
	buraco = acha_buraco(l);
	vet[l->ultimo].prox = buraco;
	l->ultimo = buraco;
	vet[buraco].chave = conteudo;
	vet[buraco].prox=-2;

	
}
void imprime(list *l){
	int i;
	printf("\n[");
	i=l->primeiro;
	while (1) {
	printf(" %d",l->vetor[i].chave);
	if(-2 == l->vetor[i].prox){
			printf(" ]\n");
			return;}
	i = l->vetor[i].prox;
	}

}
