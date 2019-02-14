#include "pch.h"
#include "tablero.h"

//
//		--arreglar si se introduze valor malo
//
//		como mejor pasar constantes: "const string &fichero" o "const string fichero"??
// proteccion contra poner num malo
//


void iniciaTablero(tTablero tablero) {
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			iniciaCasilla(tablero[i][j]);
		}
	}
}

bool cargarTablero(const string &fichero, tTablero t) {
	char ch;
	string temp;
	bool ok = false;
	ifstream file;
	file.open(fichero);
	cout << fichero << endl;
	if (file.is_open()) {
		for (int j = 0; j < 9; j++) {
			for (int i = 0; i < 9; i++) {
				file.get(ch);
				rellenaCasilla(t[i][j], ch, true);
			}
			getline(file, temp);
		}
		calcElementosPosibles(t);
		ok = true;
	}
	file.close();
	return ok;
}

void dibujarTablero(const tTablero t) {
	//lineas de fuera: 200, 201, 202, 203, 204, 205, 206, 188, 187, 186, 185
	// ╚ ╔ ╩ ╦ ╠ ═ ╬ ╝ ║ ╣ ╗
	//dentro: 191, 192 ,193, 194 , 195 ,196, 197, 217, 218, 124
	//╚ ╔ ╩ ╦ ╠ ═ ╬ ╝ ║ ╣ ╗
	//2,3,,4,5,,10,11,,13,14,,18,19,,21,22
	//-----------------------------
	//	╔═══════╦═══════╦═══════╗
	//	║2  4  5║       ║       ║
	//	║      5║       ║      4║
	//	║   8   ║  3    ║       ║
	//	╠═══════╬═══════╬═══════╣
	//	║2  4  5║       ║       ║
	//	║      5║       ║      4║
	//	║   8   ║  3    ║       ║
	//	╠═══════╬═══════╬═══════╣
	//	║2  4  5║       ║       ║
	//	║      5║       ║      4║
	//	║   8   ║  3    ║       ║
	//	╚═══════╩═══════╩═══════╝
	const tArray arriba = {201,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,203,205,205,205,205,205,205,205,187};
	const tArray medio = {204,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,206,205,205,205,205,205,205,205,185};
	const tArray abajo = {200,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,202,205,205,205,205,205,205,205,188};
	int y = 0;
	for (int i = 1; i <= 13; i++) {
		switch (i)
		{
		case 1:
			for (int i = 0; i < (int)size(arriba); i++) cout << (char)arriba[i];
			cout << endl;
			break;
		case 2:
			dibujarCuadrado(t, y);
			break;
		case 3:
			dibujarCuadrado(t, y);
			break;
		case 4:
			dibujarCuadrado(t, y);
			break;
		case 5:
			for (int i = 0; i < (int)size(arriba); i++) cout << (char)medio[i];
			cout << endl;
			break;
		case 6:
			dibujarCuadrado(t, y);
			break;
		case 7:
			dibujarCuadrado(t, y);
			break;
		case 8:
			dibujarCuadrado(t, y);
			break;
		case 9:
			for (int i = 0; i < (int)size(arriba); i++) cout << (char)medio[i];
			cout << endl;
			break;
		case 10:
			dibujarCuadrado(t, y);
			break;
		case 11:
			dibujarCuadrado(t, y);
			break;
		case 12:
			dibujarCuadrado(t, y);
			break;
		case 13:
			for (int i = 0; i < (int)size(arriba); i++) cout << (char)abajo[i];
			cout << endl;
			break;
		default:
			break;
		}
	/*	if (i == 1) { 
			for (int i = 0; i < size(arriba); i++) cout << (char)arriba[i];
			cout << endl; 
		}

		else if (i > 1 && i < 5){
			dibujarCasilla(t, y);
		}

		else if (i == 5) {
			for (int i = 0; i < size(arriba); i++) cout << (char)medio[i];
			cout << endl;
		}

		else if (i > 5 && i < 9) {
			dibujarCasilla(t, y);
		}

		else if (i == 9) {
			for (int i = 0; i < size(arriba); i++) 	cout << (char)medio[i];
			cout << endl;
		}

		else if (i > 9 && i < 12) { 
			dibujarCasilla(t, y); 
		}

		else {
			for (int i = 0; i < size(arriba); i++) cout << (char)abajo[i];
			cout << endl;
		}*/
	}
}

void dibujarCuadrado(const tTablero t, int &y) {
	char barra = (char)186;
	string blnc = "  ";
	cout << barra;
	for (int x = 0; x < 3; x++) {
		dibujaCasilla(t[x][y]);
		if (x == 0 || x == 1) cout << blnc;
	}
	cout << barra;
	for (int x = 3; x < 6; x++) {
		dibujaCasilla(t[x][y]);
		if (x == 3 || x == 4) cout << blnc;
	}
	cout << barra;
	for (int x = 6; x < 9; x++) {
		dibujaCasilla(t[x][y]);
		if (x == 6 || x == 7) cout << blnc;
	}
	cout << barra << endl;
	//for (int x = 0; x < DIMENSION; x++) {
	//	//2,3,,4,5,,10,11,,13,14,,18,19,,21,22
	//}
	//if ((x == 0) || (x == 8) || (x == 16) || (x == 24)) cout << barra;
	//if ((x == 1) || (x == 4) || (x == 7) || (x == 9) || (x == 12) || (x == 15) || (x == 17) || (x == 20) || (x == 23)) cout << dibujarNumero(t, x, y);
	//if ((x == 2) || (x == 5) || (x == 10) | (x == 13) || (x == 18) || (x == 21))
	y++;
}


bool ponerNum(tTablero t, int x, int y, int c) {
	const int modo = 1;
	bool ok = false;
	cout << t[x][y].estado << endl;
	if (t[x][y].estado == VACIO && ((c > 0) && (c < 10)) && ((x >= 0) && (x < 9)) && ((y >= 0) && (y < 9))){
		rellenaCasilla(t[x][y], c + '0');
		calcElementosPosibles(t, modo, x, y);
		ok = true;
	}
	return ok;
}

bool borraNum(tTablero t, int x, int y) {
	const int modo = 2;
	bool ok = false;
	const int numero = t[x][y].numero;

	if ((t[x][y].estado == RELLENO) && ((x >= 0) && (x < 9)) && ((y >= 0) && (y < 9))) {
		borraCasilla(t[x][y]);
		calcElementosPosibles(t, modo, x, y, numero);
		ok = true;
	}
	return ok;
}

bool tableroLleno(const tTablero t) {
	bool lleno = true;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (t[j][i].estado == VACIO) {
				lleno = false;
			}
		}
	}
	return lleno;
}
	

void mostrarPosibles(const tTablero t, int x, int y) {
	//muestra los valores posibles de la casilla del tablero dado que tiene
	//coordenadas(fila, col) (fila y col estarán en el intervalo[1, 9])
	cout << t[x][y].estado << endl;
	if (((x >= 0)&& (x < 9)) && ((y >= 0) && (y < 9))) {
		if (t[x][y].estado != FIJA) {
			cout << "Valores posibles: ";
			for (int i = 0; i < DIMENSION; i++) {
				if(t[x][y].posibles.elementos[i])
				cout << i+1 << ' ';
			}
			cout << endl;
		}
		else {
			cout << t[x][y].numero << endl;
		}
	}
	else cout << "Coordenada incorrecta." << endl;
}


void rellenarSimples(tTablero t) {
	int numero;
	for (int i = 0; i < DIMENSION; i++) {
		for (int j = 0; j < DIMENSION; j++) {
			if (esSimple(t[j][i], numero))
				ponerNum(t, j, i, numero);
		}
	}
}

void calcElementosPosibles(tTablero t, int mode, int x, int y, int c) {
	if (mode == 0) {
		for (int j = 0; j < DIMENSION; j++) {
			for (int i = 0; i < DIMENSION; i++) {
				if (t[i][j].estado == VACIO) {
					for (int a = 0; a < DIMENSION; a++) {
						if (t[a][j].estado == FIJA)
							delElemento(t[i][j].posibles, t[a][j].numero);
					}
					for (int b = 0; b < DIMENSION; b++) {
						if (t[i][b].estado == FIJA)
							delElemento(t[i][j].posibles, t[i][b].numero);
					}
				}
			}
		}
	}
	else {
		for (int a = 0; a < DIMENSION; a++) {
			if (t[a][y].estado != FIJA) { //tampoco es necesario. de todos modos en ningun caso se va a modificar el valor de casilla FIJA
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

void resolver(tTablero t, int nCasilla, bool &exito) {
	const int limiteCtd = 30;
	int ctd = 0; //para no entrar en un bucle infinito, si no se puede resolver con esta algoritmo/funcion rellenarSimples()
	exito = false;

	while ((!exito) && (ctd<limiteCtd)) {
		rellenarSimples(t);
		ctd++;
		exito = tableroLleno(t);
	}
}

