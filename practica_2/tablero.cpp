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
	tPaleta color;
	//--------------------DIBUJA FILAS--------------------
	for (int i = 1; i <= 13; i++) {
		switch (i)
		{
		case 1:
			cout << "\t ";
			colorFondo(VIOLETA);
			for (int i = 0; i < (int)size(arriba); i++) 
				cout << arriba[i];
			colorFondo();
			cout << endl;
			break;
		case 2:
			colorStr("\t1", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 3:
			colorStr("\t2", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 4:
			colorStr("\t3", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 5:
			cout << "\t ";
			colorFondo(VIOLETA);
			for (int i = 0; i < (int)size(arriba); i++) 
				cout << medio[i];
			colorFondo();
			cout << endl;
			break;
		case 6:
			colorStr("\t4", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 7:
			colorStr("\t5", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 8:
			colorStr("\t6", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 9:
			colorStr("\t ", GRIS);
			colorFondo(VIOLETA);
			for (int i = 0; i < (int)size(arriba); i++) 
				cout << medio[i];
			colorFondo();
			cout << endl;
			break;
		case 10:
			colorStr("\t7", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 11:
			colorStr("\t8", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 12:
			colorStr("\t9", GRIS);
			dibujarCuadrado(t, y);
			break;
		case 13:
			cout << "\t ";
			colorFondo(VIOLETA);
			for (int i = 0; i < (int)size(arriba); i++) 
				cout << abajo[i];
			cout << endl;
			colorStr("\t  1  2  3 4  5  6 7  8  9\n\n", GRIS);
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
	tPaleta color;
	//--------------------DIBUJA COLUMNAS--------------------
	char barraCh = (char)186;
	string barra = "";
	barra += barraCh;
	string blnc = "  ";
	colorStr(barra, VIOLETA);
	for (int x = 0; x < 3; x++) {
		dibujaCasilla(t[x][y]);
		if (x == 0 || x == 1) 
			colorStr(blnc, GRIS);
	}
	colorStr(barra, VIOLETA);
	for (int x = 3; x < 6; x++) {
		dibujaCasilla(t[x][y]);
		if (x == 3 || x == 4) 
			colorStr(blnc, GRIS);
	}
	colorStr(barra, VIOLETA);
	for (int x = 6; x < 9; x++) {
		dibujaCasilla(t[x][y]);
		if (x == 6 || x == 7) 
			colorStr(blnc, GRIS);
	}
	colorStr(barra, VIOLETA);
	cout << endl;	
	y++;
}


bool ponerNum(tTablero t, int x, int y, int c) {
	const int modo = 1;
	bool ok = false;
	cout << t[x][y].estado << endl;
	if (t[x][y].estado == VACIO && ((c > 0) && (c < 10)) && ((x >= 0) && (x < 9)) && ((y >= 0) && (y < 9))){
		rellenaCasilla(t[x][y], c + '0');
		calcElementosPosibles(t, modo, x, y);
		calcElementosPosibles_SubMatriz(t, x, y);
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
		calcElementosPosibles_SubMatriz(t, x, y);
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
	if (((x >= 0)&& (x < 9)) && ((y >= 0) && (y < 9)) && (t[x][y].estado==VACIO)) {
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

void calcElementosPosibles_SubMatriz(tTablero t, int x, int y) {
	int a = x % 3;
	int b = y % 3;

	if (a == 0)
		for (int i = x; i <= x + 2; i++) {
			if (b == 0)
				for (int j = y; j <= y + 2; j++) {
					delElemento(t[y][x].posibles, t[j][i].numero);
				}
			else if (b == 1)
				for (int j = y - 1; j  <= y + 1; j--) {
					delElemento(t[y][x].posibles, t[j][i].numero);
				}
			else
				for (int j = y - 3; j <= y + 2; j--) {
					delElemento(t[y][x].posibles, t[j][i].numero);
				}
		}
	else if (a == 1)
		for (int i = x - 1; i <= x + 1; i--) {
			if (b == 0)
				for (int j = y; j <= y + 2; j++) {
					delElemento(t[y][x].posibles, t[j][i].numero);
				}
			else if (b == 1)
				for (int j = y - 1; j <= y + 1; j--) {
					delElemento(t[y][x].posibles, t[i][j].numero);
				}
			else
				for (int j = y - 3; j <= y + 2; j--) {
					delElemento(t[y][x].posibles, t[j][i].numero);
				}

		}
	else
		for (int i = x - 3; i <= x + 2; i--) {
			if (b == 0)
				for (int j = y; j <= y + 2; j++) {
					delElemento(t[x][y].posibles, t[i][j].numero);
				}
			else if (b == 1)
				for (int j = y - 1; j <= y + 1; j--) {
					delElemento(t[x][y].posibles, t[i][j].numero);
				}
			else
				for (int j = y - 3; j <= y + 2; j--) {
					delElemento(t[x][y].posibles, t[i][j].numero);
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

