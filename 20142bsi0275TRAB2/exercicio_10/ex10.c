#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../bibliotecas/bibli_enc.h"
int main(int argc, char **argv){
	listc *lista;
	lista = malloc(1*sizeof(listc));
	srand(clock());
	lista->tamanho = 0;
	
	append_item_c(lista, 'a');
	append_item_c(lista, 'e');
	append_item_c(lista, 'i');
	append_item_c(lista, 'o');
	append_item_c(lista, 'u');	
		
	/*imprime*/
	imprime_lista_c(lista);
	/*modifica e imprime*/
	inversor_c(lista);
	imprime_lista_c(lista);
	
	/*free*/
	set_me_free_c(lista);
	
	return 0;
}
