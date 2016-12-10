#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../bibliotecas/bibli_enc.h"
int main(int argc, char **argv){
	int i=0;
	list *lista;
	lista = malloc(1*sizeof(list));
	srand(clock());
	lista->tamanho = 0;
	while (i < 10){
		append_item(lista, i);
		i++;
		}
		
	/*imprimir as listas 1,2 */
	
	imprime_lista(lista);
	move_node(lista,2,5);
	imprime_lista(lista);
	/*imprime a lista recursivamente */
	set_me_free(lista);
	
	return 0;
}
