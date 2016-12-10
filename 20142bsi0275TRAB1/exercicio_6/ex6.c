#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli.h"
int main(int argc, char **argv){
	int i=0;
	list *lista;
	lista = malloc(1*sizeof(list));

	lista->tamanho = 0;
	while (i < 10){
		append_item(lista, rand() %110);
		i++;
		}
		
	/*imprimir as listas 1,2 */
	printf("\nnormal\n");
	imprime_lista(lista);
	/*imprime a lista recursivamente */
	printf("\nrecursivo\n");
	imprime_lista_recursiva(lista, NULL);
	printf("\n");
	set_me_free(lista);
	
	return 0;
}
