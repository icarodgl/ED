#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/conjuntoteca.h"


int main(int argc, char **argv){
	int i=0;
	list *A, *B, *R;
	A = malloc(1*sizeof(list));
	B = malloc(1*sizeof(list));
	R = malloc(1*sizeof(list));
	while (i < 6){
		append_item(A, i);
		i++;
		}
		i=0;
	while (i < 6){
		append_item(B, i*i);
		i++;
		}
		i=0;
		
	printf("\n conjunto A: ");
	imprime_lista(A);
	printf("\n conjunto B: ");
	imprime_lista(B);
	printf("\n interseção: ");
	conjunto_diferenca(A,B,R);
	imprime_lista(R);
	
	
	set_me_free(A);
	set_me_free(B);
	set_me_free(R);
	return 0;
}

