/*
 * bibli_pilha.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_pilha.h"

node *cria_node(int chave){
	node *no;
	no = malloc(sizeof(node));
	no->chave = chave; 
	no->proximo = NULL;
	return no;
}

pilha *cria_pilha(pilha *p){
	p->tamanho = 0;
	p->inicio = NULL;
	p->fim = NULL;
	return p;
}
	

int desempilhador(pilha *l){
	int chave;
	node *pega;
	pega = l->inicio;
	chave=pega->chave;
	l->inicio = l->inicio->proximo;
	free(pega);
	l->tamanho --;
	return chave;
	
}	
void empilhadeira(pilha *l, int chave){
	node *novo;
	novo = cria_node(chave);
	
	if (l->tamanho != 0){novo->proximo = l->inicio;}
	else{ l->fim = novo;}
		
	l->inicio = novo;	
	l->tamanho++;
	}
		

	
void imprime(pilha *p){
	node *rastro = p->inicio;
	while (rastro != NULL){
		printf("conteudo -> %d \n ", rastro->chave);
		rastro = rastro->proximo;
		}
}



void set_me_free(pilha *p){
	int i;
	node *rastro;
	i= p->tamanho;
	while (i-- != 0){
		rastro = p->inicio->proximo;
		free(p->inicio);
		p->inicio = rastro;
	}
	free(p);
}

int confere_parenteses(pilha *p){
	node *no;
	int i=0,j=0, k=0, ok=0;
	no = p->inicio;
	
	while(i < p->tamanho-1){
		if((i == 0) && (no->chave == ')')){	ok = 0;}
		
		if((no->chave == '(')){j++;}
		
		if((no->chave == ')')){k++;}
		no = no->proximo;
		i++;
	}
	
	if(no->chave == '('){ ok = 0;}
	if(no->chave == ')'){ k++;}
	if(j == k){ok = 1;}
	return ok;
}
void imprime_c(pilha *p){
	int i;
	node *rastro;
	rastro = p->inicio;
	i = (p->tamanho-1);
	printf("\n[");
	while (i >= 0){
		printf(" %c", rastro->chave);
		rastro = rastro->proximo;
		i--;
	}
	printf(" ]\n");
}
int confere_xCy(pilha *p1,pilha *p2){
	int i, x,y;
	pilha *aux;
	aux = malloc(sizeof(pilha));
	cria_pilha(aux);
	/*desempilha p2 em aux*/
	for(i=0; i<p1->tamanho; i++){
		empilhadeira(aux, desempilhador(p2));
		}
	/*desempilha aux e p1 comparando*/
	for (i=0;i<p1->tamanho;i++){
		x = desempilhador(p1);
		y = desempilhador(aux);
		if(x != y){
			return 1;
			}
		}
	return 0;
	}
	
	
/*-------------------------pilhas deque--------------------------------*/




noded *cria_node_d(int chave){
	noded *no;
	no = malloc(sizeof(noded));
	no->chave = chave; 
	no->proximo = NULL;
	return no;
}

pilhad *cria_pilha_d(pilhad *p){
	p->tamanho = 0;
	p->inicio = NULL;
	p->fim = NULL;
	p->aux = NULL;
	return p;
}
void empilhadeira_d(pilhad *p, int chave){
	noded *novo;
	novo = cria_node_d(chave);
	
	p->aux = p->inicio;
	if(p->fim == NULL){p->inicio = novo;p->fim = novo;}
	else{
		p->fim->proximo = novo;
		p->fim = novo;
		}
	p->tamanho+=1;

	}
	
void set_me_free_d(pilhad *p){
	noded *rastro;
	rastro = p->inicio->proximo;
	while (rastro != NULL){
		free(p->inicio);
		rastro = p->inicio->proximo;
		p->inicio = rastro;
	}
	free(p);
}

void imprime_d(pilhad *p){
	noded *rastro;
	rastro = p->inicio;
	printf("\n[");
	while (rastro != NULL){
		printf(" %c", rastro->chave);
		rastro = rastro->proximo;
	}
	printf(" ]\n");
}
int desempilhador_d(pilhad *l){
	int chave;
	noded *pega, *rastro;
	pega = l->fim;
	chave=pega->chave;
	rastro=l->inicio;
	while (rastro->proximo->proximo != NULL){rastro=rastro->proximo;}
	l->fim = rastro;
	rastro->proximo=NULL;
	free(pega);
	l->tamanho --;
	return chave;
	
}	
int eject_d(pilhad *l){
	int chave;
	noded *pega;
	pega = l->inicio;
	chave=pega->chave;
	l->inicio= l->inicio->proximo;
	free(pega);
	l->tamanho --;
	return chave;
	
}	
void inject_d(pilhad *p, int chave){
	noded *novo;
	novo = cria_node_d(chave);
	novo->proximo = p->inicio;
	p->inicio = novo;
	p->tamanho+=1;
	}
