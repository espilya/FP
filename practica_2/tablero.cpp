#include "tablero.h"

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			iniciaCasilla(tablero[i][j]);
		}
	}
}

bool cargarTablero(string nombreFichero, tTablero tablero) {
	/*recibe el tablero tablero inicializado como hace el subprograma anterior, lo
	actualiza con la información almacenada en el archivo de nombre
	nombreFichero que contiene el tablero del sudoku a jugar y devuelve un
	booleano que indica si la carga se ha podido realizar.Los valores posibles de
	las casillas deberán quedar convenientemente actualizados.*/
	char ch;
	bool ok;
	ifstream file;
	file.open(nombreFichero);
	if (file.is_open()) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				file.get >> ch;
				rellenaCasilla(tablero[i][j], ch, false);
			}
		}
		calcElementosPosibles(tablero);
		ok = true;
	}
	else ok = false;
	file.close();
	return ok;
}

void calcElementosPosibles(tTablero t){
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (t[i][j].estado != VACIO) {
				delElemento(t[i][j].posibles, t[i][j].numero);
			}
		}
	}
}

