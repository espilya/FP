
#include "pch.h"
#include "juego.h"
#include "listaSudokus.h"

int main()
{
	int op;
	tListaSudokus lista;
	creaListaVacia(lista);
	cargarListaSudokus(lista);
	op = menuListaSudokus(lista);
	cout << "el sudoku seleccionado es el: " << lista.array[op].fichero << endl;
	//mostrarMenuPrincipal(); (!file.eof()) &&
}

