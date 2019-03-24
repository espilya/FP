#include "listaSudokus.h"

//
//
//		GRUPO: 
//				-1G
//
//		GRUPO: 
//				-27
//
//		NOMBRES:
//				-ILYA LAPSHIN
//				-MICHAL FITAL
//
//

int main()
{
	int op, op2;
	tListaSudokus lista;
	tJuego juego;
	creaListaVacia(lista); //iniciamos lista de sudoku a VACIO
	iniciaJuego(juego);  //iniciamos juego.
	if (cargarListaSudokus(lista)) { //cargamos listaSudoku
		do {
			cout << "1. - Jugar\n"
				<< "0. - Salir" << endl;
			op = leerOpcion(0, 1);

			switch (op)
			{
			case 1:
				op2 = menuListaSudokus(lista, juego);
				if (op2 != 0)
					startJuego(juego);
			break;
				//para otros casos
				//... 
				//..
			}

			clear();
		} while (op != 0);
	}//if_end
  else
    colorStr("Error al cargar 'listaSudokus.txt'.\nFinalizando programa.", ROJO);
  return 0;
}
