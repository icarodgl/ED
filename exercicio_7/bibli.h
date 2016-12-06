#ifndef __bibli_h__
#define __bibli_h__

typedef struct node{
	int caixa;
	struct node *proximo;
	} node;
	
typedef struct list{
	struct node *inicio;
	int tamanho;
	} list;

void append_item (list *lista, int numero);
void imprime_lista(list *lista);
node *caminha(list *lista, int pos);
void troca(list *lista,node *nk, node *nv);
void ordenador(list *lista);
void set_me_free(list *lista);
#endif
