
#include "pch.h"
#include "listaSudokus.h"

int main()
{
	int op;
	tListaSudokus lista;
	tJuego juego;
	int opSudoku;
	creaListaVacia(lista,juego);
	cargarListaSudokus(lista);
	do {
		mostrarMenuPrincipal(juego);
		op = menuListaSudokus(lista, juego);

	} while (op != 0);
	return 0;
}

