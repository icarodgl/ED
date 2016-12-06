#ifndef __bibli_ex2_h__
#define __bibli_ex2_h__

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
void concatena_ordenado(list *li1,list *li2,list *li3);
void concatena_listas(list *li1,list *li2,list *li3);
void set_me_free(list *lista);
#endif
