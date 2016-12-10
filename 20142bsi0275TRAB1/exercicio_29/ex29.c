#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli.h"


int main(int argc, char **argv){
	int i=0;
	list *lista, *impar, *par;
	lista = malloc(1*sizeof(list));
	impar = malloc(1*sizeof(list));
	par = malloc(1*sizeof(list));
	
	while (i < 9999){
		append_item(lista, i);
		i++;
		}
		
	printf("\n criada: ");
	imprime_lista(lista);
	separa_par_impar(lista, par, impar);
	imprime_lista(impar);
	imprime_lista(par);
	
	set_me_free(impar);
	set_me_free(par);
	set_me_free(lista);
	return 0;
}

