#ifndef __bibli_d_h__
#define __bibli_d_h__

typedef struct node{
	int caixa;
	struct node *proximo;
	struct node *anterior;
	} node;
	
typedef struct list{
	struct node *inicio;
	struct node *fim;
	int tamanho;
	} list;
	
void append_item (list *lista, int numero);
int tamanho(list *lista);
void troca_valor(list *lista, int k, int v);
void troca(list *lista,int k,int v);
void imprime_lista(list *lista);
void insere_esq (list *lista, int k, int v);
void insere_dir (list *lista, int k, int v);
void excluir(list *lista, int k);
int busca_true(list *lista, int num);
void insere_num (list *lista, int num);
void exclui_num (list *lista, int num);
void banir_num (list *lista, int num);
void set_me_free(list *lista);
void concatena_listas(list *li1,list *li2,list *li3);
void remove_direita(list *lista, int k);
void inversor(list *lista);
#endif
