#ifndef __bibli_d_h__
#define __bibli_d_h__

typedef struct node{
	int indice;
	int caixa;
	struct node *proximo;
	struct node *anterior;
	} node;
	
void cria_lista(node *lista);
void imprime_lista_circ(node *lista);
void append_item(node *lista,int i);
int len_lista_circ(node *lista);
node *busca_num(node *lista, int num);
node *elimina_valor(node *lista, int num);
void concatena_lista_circular(node *li1, node *li2, node *lir);
void intercala_lista_circular(node *li1, node *li2, node *lir);
node *caminha(node *lis, int pos);
void copia_lista(node *li1, node *li2);
void set_me_free(node *lista);
#endif
