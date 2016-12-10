#ifndef __conjuntoteca_h__
#define __conjuntoteca_h__

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
void conjunto_uniao(list *lisa,list *lisb,list *lisr);
void conjunto_intersec(list *lisa,list *lisb,list *lisr);
void conjunto_diferenca(list *lisa,list *lisb,list *lisr);
int conjunto_pertence(list *lista, int num);
#endif
