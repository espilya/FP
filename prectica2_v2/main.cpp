

#include "listaSudokus.h"

//
//	bool guardar(const tListaJugadores & LISTA)
//		-para que devolver booleano
//
//
//
//

//					TO DO
//			listaJSudokus: buscarPos()
int main()
{
	int op, op2;
	bool okListaSud = false, okListaJug = false;
	tListaSudokus listaSud;
	tListaJugadores listaJug;
	tJuego juego;
	creaLista(listaSud); //iniciamos lista de sudoku
	creaLista(listaJug); //iniciamos lista de jugadores
	iniciaJuego(juego);  //iniciamos juego.
	if(cargar(listaSudoku))
		okListaSud = true;
	if(cargar(nombreListaJug))
		okListaJug = true;
	if (okListaSud && okListaJug) //cargamos listaSudoku
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
				op2 = menuListaSudokus(listaSud, juego);
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

	else if(!okListaSud)
		colorStr("Error al cargar 'listaSudokus.txt'.\n", ROJO);
	else if(!okListaJug)
		colorStr("Error al cargar 'listaJugadores.txt'.\n", ROJO);
	return 0;
}
