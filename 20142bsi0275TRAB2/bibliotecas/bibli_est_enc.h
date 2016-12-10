#ifndef __bibli_est_enc_h__
#define __bibli_est_enc_h__

typedef struct{
	int chave;
	int prox;
	}node;
	
typedef struct list{
	node *vetor;
	int primeiro;
	int ultimo;
	int disponivel;
	} list;

void imprime(list *l);
void append(list *l, int conteudo);
int acha_buraco(list *l);
void cria_lista(list *lista, int t);
void remove_ind(list *l, int ind);

#endif
