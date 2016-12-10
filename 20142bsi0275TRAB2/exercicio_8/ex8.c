#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../bibliotecas/bibli_enc.h"
int main(int argc, char **argv){
	int i=0, *resp;
	list *lista;
	resp = malloc(2*sizeof(int));
	lista = malloc(1*sizeof(list));
	srand(clock());
	lista->tamanho = 0;
	while (i < 10){
		append_item(lista, rand() %2);
		i++;
		}
		
	/*imprimir as listas 1,2 */
	imprime_lista(lista);
	resp = acha_cadeia(lista,0, resp);
	
	printf("\ninicio: %d  fim: %d\n",resp[0], resp[1]);
	/*imprime a lista recursivamente */
	free(resp);
	set_me_free(lista);
	
	return 0;
}
