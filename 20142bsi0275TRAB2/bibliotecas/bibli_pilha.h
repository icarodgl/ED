#ifndef _bibli_pilha__h
#define _bibli_pilha__h

/*-----------estruturas de pilhas---------*/
typedef struct node{
	int chave;
	struct node *proximo;
}node;

typedef struct pilha{
		int tamanho;
		node *inicio;
		node *fim;
}pilha;
/*----------pilha dupla-----------------*/
typedef struct noded{
	int chave;
	struct noded *proximo;
}noded;

typedef struct pilhad{
		int tamanho;
		noded *inicio;
		noded *fim;
		noded *aux;
}pilhad;

/*-------funções-pilhas--------*/
node *cria_node(int chave);
pilha *cria_pilha(pilha *p);
int desempilhador(pilha *l);
void empilhadeira(pilha *l, int chave);
void imprime(pilha *p);
void set_me_free(pilha *p);
int confere_parenteses(pilha *p);
void imprime_c(pilha *p);
int confere_xCy(pilha *lista,pilha *lista2);
/*-------funções pilha deque aux-------*/

noded *cria_node_d(int chave);
pilhad *cria_pilha_d(pilhad *p);
void empilhadeira_d(pilhad *p, int chave);
void set_me_free_d(pilhad *p);
void imprime_d(pilhad *p);
int desempilhador_d(pilhad *l);
int eject_d(pilhad *l);
void inject_d(pilhad *p, int chave);

#endif

