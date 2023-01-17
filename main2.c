#include <stdio.h>
#include <stdlib.h>
#include "libAgenda.h"


int main(){
	int input;
	int id = 1;
	int n;
	n = id;
	struct agenda **c;
	c = malloc(n * sizeof(struct agenda));
	c[n] = adicionaNulo();
	
	input = menu();
	while(input != 4){
		if(input == 1){
			c[n] = adicionaCompromisso(c, n, &id);
			n = id;
			c = realloc(c, n*sizeof(struct agenda));
		}
		else if(input == 2){
			if(n == 1){
				printf("Sem compromissos!!\n");
			}
			else{
				for(int i = 1; i < n; i++){
					
					printf("%d/%d às %dhr: %s\n", c[i]->dia, c[i]->mes, c[i]->hora, c[i]->evento);
				}
			}
		}
		else if(input == 3){
			removeCompromisso(c, &id);
			n = id;
			c = realloc(c, n*sizeof(struct agenda));	
		}
		input = menu();	
	}
	free(c);
	return 0;
}
