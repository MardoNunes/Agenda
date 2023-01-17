#include <stdio.h>
#include <stdlib.h>
#include "libAgenda.h"
	
	/*O menu da agenda!*/
	int menu(){
		int num;
		printf("===============MENU=============\n");
		printf("[1] Para adicionar compromisso;\n");
		printf("[2] Para vereficar agenda;\n");
		printf("[3] Para Remover compromisso;\n");
		printf("[4] Para Sair;\n");
		printf("================================\n");
		printf("\n");
		printf("Entre com sua opção: ");
		scanf("%d", &num);
		printf("\n");
		return num;
	}
	
	/*Struct que ler elemento para um struct que dps é jogada para minha struct main!*/
	struct agenda *adicionaCompromisso(struct agenda **p, int n, int *d){
		struct agenda *c;
		size_t size = 32;
		int aux;

		c = malloc(sizeof(struct agenda));
		c->evento = malloc(size * sizeof(char));
		if(c->evento == NULL){
			printf("Erro em alocamento do evento!!");
		}
		else{
			c->mes = Mes();
			c->dia = Dia();
			c->hora = Hora();
			
			aux = vereficaCompromisso(p, c, n);
			if(aux == 0){
				printf("Qual seu evento?\n");
				getline(&(c->evento), &size, stdin);
			
				printf("\n");
				printf("Compromisso marcado!!\n");
				printf("\n");
				*d = *d + 1;
				return c;
			}
			else{
				printf("Essa data ja tem compromisso marcado!!\n");
			}
		}
	}
	
	/*As funções Mes(), Dia(), Hora() apenas faz a leitura das datas*/
	
	int Mes(){
		int num;
		printf("Qual o mês: ");
		scanf("%d", &num);
		while(num < 1 || num > 12){
			printf("Calma lá, entre com um valor válido! [1 à 12]: ");
			scanf("%d", &num);
		}
		getchar();
		return num;
	}
	
	int Dia(){
		int num;

		printf("Qual o dia: ");
		scanf("%d", &num);
		while(num < 1 || num > 31){
			printf("Opa meu chará! entre com um valor válido! [1 à 31]: ");
			scanf("%d", &num);
		}
		getchar();
		return num;
	}

	int Hora(){
		int num;
		printf("Entre com a hora, em foramto 24hr [12, 14, 16..]: ");
		scanf("%d", &num);
		while(num < 0 || num > 24){
			printf("Hora inválida! [0 à 24]: ");
			scanf("%d", &num);
		}
		getchar();
		return num;
	}

	void removeCompromisso(struct agenda **c, int *id){
		int aux, aux2, aux3, i, ok;
		ok = 1;
		*id = *id - 1; //n-um pq ja somei mesmo sem adicionar la no main!

		printf("->Removendo compromisso...\n");

		aux = Mes();

		aux2 = Dia();

		aux3 = Hora();
		
		i = 1;
		/*fica nesse while ate encontrar a data certa!*/
		while(i <= *id && ok != 0){
			/*essa é uma pequena arvore de decisao*/
			if(c[i]->mes == aux && c[i]->dia == aux2 && c[i]->hora == aux3){
				ok = 0;
				}
			i++;
			}
		
		i--; //i-- pq adiciona um a mais no loop anterior!
		printf("ok = %d\n", ok);
		if(ok == 0){
			/*nesse while ele apenas joga todo mundo para esquerda*/
			while(i < *id){
				c[i]->mes = c[i+1]->mes;
				c[i]->dia = c[i+1]->dia;
				c[i]->hora = c[i+1]->hora;
				c[i]->evento = c[i+1]->evento;
				i++;
			}
			*id--; //diminui o tamanho do array de struct
			printf("->Removido com sucesso!\n");
		}
		else{
			printf("->Compromisso não encontrado na agenda!\n");
		}
	}
	
	/*Essa funçção irá vereficar se a data que quero colocar um compromisso está ocupada!*/
	int vereficaCompromisso(struct agenda **c, struct agenda *c2, int n){
		int ok = 0;
		int i = 1;

		printf("vereficando...\n");
                while(i < n && ok != 1){
			if(c2->mes == c[i]->mes){
				if(c2->dia == c[i]->dia){
					if(c2->hora == c[i]->hora){
						ok = 1;
					}
				}
			}
			i++;
		}
		return ok;
	}

	struct agenda *adicionaNulo(){
                struct agenda *c;

                c = malloc(sizeof(struct agenda));
                c->mes = 0;
                c->dia = 0;
                c->hora = 0;
		c->id = 1;
		return c;
	}







