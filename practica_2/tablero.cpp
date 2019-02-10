#include "tablero.h"

//
//		Al eliminar un numero en una casilla, hace falta poner posibles valores para casillas rellenas/fijas?
//		Al poner un numero en una casilla, hace falta eliminar posibles valores para casillas rellenas/fijas?
//
//		--arreglar si se introduze valor malo
//
//

void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			iniciaCasilla(tablero[i][j]);
		}
	}
}

bool cargarTablero(string nombreFichero, tTablero t) {
	char ch;
	bool ok = false;
	ifstream file;
	file.open(nombreFichero);
	if (file.is_open()) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				file.get >> ch;
				rellenaCasilla(t[i][j], ch, true);
			}
			calcElementosPosibles(t);
		}
		ok = true;
	}
	file.close();
	return ok;
}

void calcElementosPosibles(tTablero t, int x = -1, int y = -1, int mode = 0, int c = -1) {
	if (mode == 0) {
		for (int i = 0; i < DIMENSION; i++) {
			for (int j = 0; j < DIMENSION; j++) {
				if(t[i][j].estado==VACIO)
				for (int a = 0; a < DIMENSION; a++) {
					if(t[a][j].estado == FIJA)
						delElemento(t[i][j].posibles, t[a][j].numero);
				}
				for (int b = 0; b < DIMENSION; b++) {
					if(t[i][b].estado == FIJA)
						delElemento(t[i][j].posibles, t[i][b].numero);
				}
			}
		}
	}
	else {
		for (int a = 0; a < DIMENSION; a++) {
			if (t[a][y].estado != FIJA) {
				if (mode == 1)
					delElemento(t[a][y].posibles, t[x][y].numero);
				else
					addElemento(t[a][y].posibles, c);
			}
		}
		for (int b = 0; b < DIMENSION; b++) {
			if (t[x][b].estado != FIJA) {
				if (mode == 1)
					delElemento(t[x][b].posibles, t[x][y].numero);
				else
					addElemento(t[x][b].posibles, c);

			}
		}
	}
}

void dibujarTablero(const tTablero tablero) {

}

bool ponerNum(tTablero t, int x, int y, int c) {
	const int modo = 1;
	bool ok = false;

	if (t[x][y].estado == VACIO && (0 < c && c < 10) && (0 < x&& x < 10) && (0 < y && y < 10)){
		rellenaCasilla(t[x][y], c);
		calcElementosPosibles(t, x, y, modo);
		ok = true;
	}
	return ok;
}

bool borraNum(tTablero t, int x, int y) {
	const int modo = 2;
	bool ok = false;
	const int numero = t[x][y].numero;

	if (t[x][y].estado == RELLENO && (0 < x && x < 10) && (0 < y && y < 10)) {
		borraCasilla(t[x][y]);
		calcElementosPosibles(t, x, y, modo, numero);
		ok = true;
	}
	return ok;
}

//Determina si el tablero ha sido rellenado completamente
//Si el sudoku tiene una unica solucion, como solamente permitimos valores validos no seria posible que estuviese lleno y no fuese correcto
//Si pudiese tener varias soluciones entonces puede terner sentido tener esta funcion
//O si permitiesemos poner valores erroneos
bool tableroLleno(const tTablero t) {
	//devuelve un valor booleano que indica si el tablero dado está relleno por completo.

}

//Muestra los posibles valores de una casilla valida cualquiera
//Si es fija solo figurara su propio valor, ya que no se puede cambiar
void mostrarPosibles(const tTablero t, int x, int y) {
	//muestra los valores posibles de la casilla del tablero dado que tiene
	//coordenadas(fila, col) (fila y col estarán en el intervalo[1, 9])


}

//Recorre la matriz mirando que casillas vacias tienen un unico valor posible y lo rellena
//De nuevo quita valores posibles de la fila, columna y submatriz
void rellenarSimples(tTablero t) {
	//en cada casilla que tiene un
	//único valor posible se pone dicho valor y se actualizan convenientemente
	//los valores posibles de las casillas que puedan verse afectadas.

}

void resolver(tTablero t, int nCasilla, bool &exito) {

}