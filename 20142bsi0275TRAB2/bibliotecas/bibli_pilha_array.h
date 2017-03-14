#ifndef __bibli_pilha_array_h__
#define __bibli_pilha_array_h__

typedef struct node{
	int caixa;
	} node;
	
typedef struct list{
	node **vetor;
	int tamanho, cont;
	} list;

void cria_lista(list *lista,int tamanho);
void remove_ini(list *lista);
void remove_fim(list *lista);
void set_me_free(list *lista);
void limpa_lista(list *lista);
void add_conteudo(list *lista, int conteudo);
void imprime(list *lista);
void move_node(list *lista, int ant, int dep);
void ncopias(list *lista, int dado, int pos, int copias);
void removedor(list *lista,int indice);
void nremove(list *lista, int partida, int quant);
int verifica_ordenada(list *lista);
void copialista(list *lista, list *lista2);
void copia_sem_repetidas(list *lista, list *lista2);
void inverte_lista(list *lista);
void intercala_listas(list *lista,list *lista2,list *lista3);
void intercala_listas_n(list *lista,list *lista2,list *lista3);
void inicio_para_fim(list *lista, int val);
#endif
