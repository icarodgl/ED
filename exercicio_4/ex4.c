/*
 * lista_encadeada.c
 * 
 * Copyright 2016 Icaro <icaro@gavazza>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bibli.h"



int main(int argc, char **argv){
	int i=0;
	node estatico[10];
	list *prim;
	prim = malloc(1*sizeof(list));
	prim->tamanho = 0;
	while (i <6){
		append_item(prim, i*i);
		i++;
		}
		
	
	
	return 0;
}
