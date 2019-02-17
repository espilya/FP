#include "pch.h"
#include "casilla.h"



///
//
//

void iniciaCasilla(tCasilla & casilla) {
	cjto_lleno(casilla.posibles);
	//casilla.numero = 0;
}

void rellenaCasilla(tCasilla & casilla, char c, bool fija) {
	if (fija) {
		if (c == ' ') {
			casilla.estado = VACIO;
			casilla.numero = 0;
		}
		else {
			casilla.estado = FIJA;
			casilla.numero = c - '0';
		}
	}
	else {
		casilla.estado = RELLENO;
		casilla.numero = c - '0';
	}
}

void borraCasilla(tCasilla & casilla) {
	casilla.estado = VACIO;
	casilla.numero = 0;
}

void dibujaCasilla(const tCasilla & casilla) {
	tPaleta color;
	if (casilla.estado == VACIO) {
		cout << ' ';
	}
	else if (casilla.estado == RELLENO) {
		colorFondo(ROJO);
		cout << casilla.numero;
	}
	else {
		colorFondo(AZUL);
		cout << casilla.numero;
	}
	colorFondo();
}

void colorFondo(tPaleta colorLet){
	//LETRA
		// GRIS = 8
		// 9 = azul;
		// 12 = rojo;
		// 15 = BLANCO;  
	tPaleta color;
	int fondo_Neg = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, colorLet | (0 << 4));
}

void colorStr(string str, tPaleta colorLet) {
	tPaleta color;
	// 1 = azul;
	// 4 = rojo;
	// 15 = BLANCO;  
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, colorLet | (0 << 4));
	if (str.size() > 0) {
		cout << str;
		colorStr("", BLANCO);
	}
}

bool esSimple(const tCasilla & casilla, int & numero) {
	bool estado = false;
	if (casilla.estado == VACIO) {
		estado = esUnitario(casilla.posibles, numero);
	}
	return estado;
}