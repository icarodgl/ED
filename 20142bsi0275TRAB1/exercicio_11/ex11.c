#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_d.h"


int main(int argc, char **argv){
	int i=0;
	list *li1, *li2, *li3;
	li1 = malloc(1*sizeof(list));
	li1->tamanho = 0;
	li2 = malloc(1*sizeof(list));
	li2->tamanho = 0;
	li3 = malloc(1*sizeof(list));
	li3->tamanho = 0;	
	
	while (i <1000){
		append_item(li1, i);
		i++;
		}
		i=0;
	while (i <1000){
		append_item(li2, i);
		i++;
		}
		i=0;
	while (i <2000){
		append_item(li3, i);
		i++;
		}
		
	printf("listas 1 e 2");
	imprime_lista(li1);
	imprime_lista(li2);
	printf("concatenadas:");
	concatena_listas(li1 ,li2 ,li3);
	imprime_lista(li3);
	set_me_free(li3);
	free(li1);
	free(li2);
	return 0;
}

