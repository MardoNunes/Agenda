#include <stdio.h>
#include <stdlib.h>

	struct agenda{
		int mes, dia, hora, id;
		char *evento;

	};
	int menu();
	struct agenda *adicionaCompromisso();
	int Mes();
	int Dia();
	int Hora();
	void removeCompromisso(struct agenda **c, int *n);
	int vereficaCompromisso(struct agenda **c, struct agenda *c2, int n);
	struct agenda *adicionaNulo();

