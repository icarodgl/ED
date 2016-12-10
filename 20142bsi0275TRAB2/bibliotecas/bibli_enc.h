#ifndef __bibli_enc_h__
#define __bibli_enc_h__

/*-------lista int--------*/	
typedef struct node{
	int caixa;
	struct node *proximo;
	} node;
	
typedef struct list{
	struct node *inicio;
	int tamanho;
	} list;
	
/*-------lista char--------*/	

typedef struct listc{
	struct noc *inicio;
	int tamanho;
	} listc;
typedef struct noc{
	char caixa;
	struct noc *proximo;
	} noc;

/*-------funções-int-------*/	

node *caminha(list *lista, int pos);
int* acha_cadeia(list *lista, int de, int *guarda);
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
void append_item (list *lista, int numero);
void inversor(list *lista);
void imprime_lista_recursiva(list *lista, node *rastro);
int acha_kaesimo(list *lista,int k);
void appini_item (list *lista, int numero);
void separa_par_impar(list *lista,list *par,list *impar);
void move_node(list *lista, int pos, int pos2);
/*-------funções-char--------*/	
void append_item_c (listc *lista, char letra);
void imprime_lista_c(listc *lista);
void set_me_free_c(listc *lista);
void inversor_c(listc *lista);
#endif
