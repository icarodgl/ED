#ifndef __bibli_h__
#define __bibli_h__

typedef struct node{
	int caixa;
	struct node *proximo;
	} node;
	
typedef struct list{
	int tamanho;
	struct node *inicio;

	} list;

void append_item (list *lista, int numero);
void imprime_lista(list *lista);
node *caminha(list *lista, int pos);
void troca(list *lista,node *nk, node *nv);
void ordenador(list *lista);
void set_me_free(list *lista);
void insere_esq(list *lista, int k, int v);
void insere_dir(list *lista, int k, int v);
int return_num(list *lista);
void troca_valor(list *lista, int k, int num);
void elimina_no (list *lista, int k);
int busca_true_sentinela(list *lista, int num);
int busca_true(list *lista, int num);
void insere_num (list *lista, int num);
void banir_num(list *lista, int num);
void exclui_num (list *lista, int num);
int acha_kaesimo(list *lista,int k);
#endif
