
#include "pch.h"
#include "listaSudokus.h"

//
//	bool guardar(const tListaJugadores & LISTA)
//		-para que devolver booleano
//
//
//
//

//					TO DO
//	-BUSCAR() listaJugadores
int main()
{
	int op, op2;
	tListaSudokus lista;
	tJuego juego;
	creaListaVacia(lista); //iniciamos lista de sudoku a VACIO
	iniciaJuego(juego);  //iniciamos juego.
	if (cargarListaSudokus(lista)) //cargamos listaSudoku
		do {
			cout << "1. - Jugar\n"
				<< "2. - Ver jugadores ordenados por identificador\n"
				<< "3. - Ver jugadores ordenados por puntos\n"
				<< "4. - Incorporar sudoku\n"
				<< "0. - Salir" << endl;
			op = leerOpcion(0, 1);
			switch (op)
			{
			case 1:
				op2 = menuListaSudokus(lista, juego);
				if (op2 != 0)
					startJuego(juego);
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			}

			clear();
		} while (op != 0);

	else
		colorStr("Error al cargar 'listaSudokus.txt'.\nFinalizando programa.", ROJO);
	return 0;
}
