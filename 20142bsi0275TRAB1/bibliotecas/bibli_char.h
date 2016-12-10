#ifndef __bibli_char_h__
#define __bibli_char_h__

typedef struct node{
	char caixa;
	struct node *proximo;
	} node;
	
typedef struct list{
	struct node *inicio;
	int tamanho;
	} list;

void append_item (list *lista, char *numero);
void imprime_lista(list *lista);
void set_me_free(list *lista);
void troca_palavra(list *lista1, list *lista2);
#endif
