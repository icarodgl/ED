#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_pilha_array.h"

void cria_lista(list *lista,int tamanho){
	node **vet;
	vet = malloc(tamanho*sizeof(long unsigned int));
	lista->tamanho = tamanho;
	lista->cont = 0;
	lista->vetor = vet;
	
	}
void remove_ini(list *lista){
	int i;
	removedor(lista, 0);
	for (i=0; i < lista->cont; i++){
		move_node(lista, i+1, i);
		}
	lista->cont-=1;
	}
void remove_fim(list *lista){
	removedor(lista, lista->cont);
	lista->cont-=1;
	}
void add_conteudo(list *lista, int conteudo){
	node *no;

	int i;
	if (lista->tamanho == lista->cont){
		return;
		}
	no = malloc(1*sizeof(node));
	
	i = lista->cont;
	no->caixa = conteudo;
	lista->vetor[i] = no;	
	lista->cont++;
	}
void set_me_free(list *lista){
	int i;
	node **vet;
	node *rastro;
	vet = lista->vetor;
	for (i = 0; i < lista->cont ;i++){
		rastro = vet[i];
		free(rastro);
		
		}
	free(lista);	
	}
void imprime(list *lista){
	int i;
	node **vet;
	node *rastro;
	vet = lista->vetor;
	printf("\n[");
	for (i = 0; i < lista->cont ;i++){
		rastro = vet[i];
		printf(" %d",rastro->caixa);
		
		}
	printf(" ]\n");
	}
void move_node(list *lista, int ant, int dep){
	node *rastro;
	node **vet;
	if(ant < 0 || dep > lista->cont){
		return;
	}
	
	vet = lista->vetor;
	
	rastro=vet[ant];
	vet[ant] = vet[dep];
	vet[dep] = rastro;
	
	}
void subistitui_conteudo(list *lista, int indice, int conteudo){
	lista->vetor[indice]->caixa = conteudo;
	}
void ncopias(list *lista, int dado, int pos, int copias){
	int i;
	if( pos+copias > lista->tamanho){
		return;
	}
	
	for (i=pos; i < pos+copias; i++){
		subistitui_conteudo(lista, i,dado);
		}
	}
void removedor(list *lista,int indice){
	free(lista->vetor[indice]);
	}
void nremove(list *lista, int partida, int quant){
	int i,j;
	if(partida+quant > lista->cont){
		return;
		}
	for (i=partida; i < partida+quant; i++){
		removedor(lista, i);
		}
	for (j=quant; j ; j--){
	for (i=partida; i < lista->cont; i++){
		move_node(lista, i+1, i);
		}
	}
	lista->cont-=quant;
	}
void limpa_lista(list *lista){
	int i;

	for (i=0; i < lista->cont; i++){
		removedor(lista, i);
		}
	lista->cont=0;
	}
int verifica_ordenada(list *lista){
	int i=0, c=1,d=1;
	node **vet;
	vet = lista->vetor;
	for (i=0; i< (lista->cont-1); i++){
		if (vet[i]->caixa > vet[i+1]->caixa){
			c=0;
			break;
		}
	}
	for (i=0; i< (lista->cont-1); i++){
		if (vet[i]->caixa < vet[i+1]->caixa){
			d=0;
			break;
		}
	}
	if (d == 1 && c == 0){
		return -1;
		}
	if (c == 1 && d == 0){
		return 1;
		}
	return 0;
}
void copialista(list *lista, list *lista2){
	int i;
	
	if(lista->cont > lista2->tamanho ){
		return;
		}
	for (i=0;i < lista->cont;i++){
		add_conteudo(lista2, lista->vetor[i]->caixa);
		}
	}
void copia_sem_repetidas(list *lista, list *lista2){
		int i,j,t;
		lista2->cont=0;
	if(lista->cont > lista2->tamanho ){
		return;
		}
	for (i=0;i < lista->cont;i++){
		t=0;
		for (j=i+1;j < lista->cont;j++){
			if (lista->vetor[i]->caixa == lista->vetor[j]->caixa){
				t=1;
				}
			}
		if(!t){
			add_conteudo(lista2, lista->vetor[i]->caixa);
		}
		}
	}
void inverte_lista(list *lista){
	node **vet, *nox;
	int i, j;
	vet = lista->vetor;
	i=0;
	j=lista->cont-1;
	while(i < j){
		nox = vet[i];
		vet[i] = vet[j];
		vet[j]=nox;
		i++;
		j--;
	}
}

void intercala_listas_n(list *lista,list *lista2,list *lista3){
	int i=0,j=0,t=1;
	node **vet1, **vet2;
	vet1 = lista->vetor;
	vet2 = lista2->vetor;
	
	while (t){
		if (j < lista2->cont && i < lista->cont){
			if(vet1[i]->caixa > vet2[j]->caixa){
				if(vet1[i]->caixa == vet2[j]->caixa){
					j++;
					}
				else{
				add_conteudo(lista3, vet2[j]->caixa);
				j++;
				}
				}
			else{
				if(vet1[i]->caixa == vet2[j]->caixa){
					i++;
					}
				else{
				add_conteudo(lista3, vet1[i]->caixa);
				i++;
				}
				}
			}
		else{
			if(j == lista2->cont && i == lista->cont){
				t=0;
				}
			else{
				if (j == lista2->cont){
					if(vet1[i]->caixa == vet2[j]->caixa){
						i++;
						}
					else{
						add_conteudo(lista3, vet1[i]->caixa);
						i++;
						}	
					}
				else{
					if(vet1[i]->caixa == vet2[j]->caixa){
						j++;
						}
					else{
						add_conteudo(lista3, vet2[j]->caixa);
						j++;
						}
					}
			}
			}

		}
	}
void intercala_listas(list *lista,list *lista2,list *lista3){
	int i=0,j=0,t=1;
	node **vet1, **vet2;
	vet1 = lista->vetor;
	vet2 = lista2->vetor;
	
	while (t){
		if (j < lista2->cont && i < lista->cont){
			if(vet1[i]->caixa > vet2[j]->caixa){
				add_conteudo(lista3, vet2[j]->caixa);
				j++;
				}
			else{
				add_conteudo(lista3, vet1[i]->caixa);
				i++;
				}
			}
		else{
			if(j == lista2->cont && i == lista->cont){
				t=0;
				}
			else{
				if (j == lista2->cont){
						add_conteudo(lista3, vet1[i]->caixa);
						i++;
					}
				else{
						add_conteudo(lista3, vet2[j]->caixa);
						j++;
					}
				}
			}

		}
	}
void inicio_para_fim(list *lista, int val){
	node **vet;
	int i, segura;
	vet = lista->vetor;
	
	for (i=0; i < val; i++){
		segura = vet[0]->caixa;
		remove_ini(lista);
		add_conteudo(lista, segura);
		
		}
	
	}
