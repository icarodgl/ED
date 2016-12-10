#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/bibli_char.h"


int main(int argc, char **argv){
	char letra[1], *pal = argv[1];
	int i;
	list *palavra, *trocar;
	palavra = malloc(1*sizeof(list));
	trocar = malloc(1*sizeof(list));
	for(i=0; pal[i] != 0 ; i++){
		letra[0] = pal[i];
		append_item(palavra, letra);
	}
	for(i=0; pal[i] != 0 ; i++){
		letra[0] = argv[2][i];
		append_item(trocar, letra );
	}
	
			
	printf("\n palavra: ");
	imprime_lista(palavra);
	printf("\n trocar por: ");
	imprime_lista(trocar);
	printf("\n resultado: ");
	troca_palavra(palavra, trocar);
	imprime_lista(palavra);
	
	
	set_me_free(palavra);
	set_me_free(trocar);
	return 0;
}

