/*
 * lista_encadeada.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli_ex2.h"

int main(int argc, char **argv){
	int i=0;
	list *prim, *sec, *terc;
	prim = malloc(1*sizeof(list));
	sec = malloc(1*sizeof(list));
	terc = malloc(1*sizeof(list));
	prim->tamanho = 0;
	sec->tamanho = 0;
	terc->tamanho = 0;
	while (i <6){
		append_item(prim, i+(i%3));
		i++;
		}
		
	i=0;
	while (i <8){
		append_item(sec, i+(i/2));
		i++;
		}
		
	/*imprimir as listas 1,2 */
	imprime_lista(prim);
	imprime_lista(sec);
	/*gera a lista3 */
	
	/*questão A*/
	concatena_ordenado(prim, sec, terc);
	/*questão B*/
	//~ concatena_listas(prim, sec, terc);
	
	/*imprime lista 3*/
	imprime_lista(terc);
	set_me_free(prim);
	set_me_free(sec);
	set_me_free(terc);
	return 0;
}
