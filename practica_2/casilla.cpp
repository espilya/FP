#include "pch.h"
#include "casilla.h"




void iniciaCasilla(tCasilla & casilla) {
	cjto_lleno(casilla.posibles);
	casilla.estado = VACIO;
	casilla.numero = 0;

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

	if (casilla.estado == VACIO) {
		cout << ' ';
	}
	else if (casilla.estado == RELLENO) {
		colorFondo(ROJO_OSC);
		cout << casilla.numero;
	}
	else {
		colorFondo(AZUL);
		cout << casilla.numero;
	}
	colorFondo();
}

bool esSimple(const tCasilla & casilla, int & numero) {
	return esUnitario(casilla.posibles, numero);
}

void colorFondo(tPaleta colorLet){  
	int fondo_Neg = 0;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, colorLet | (0 << 4));
}

void colorStr(const string str, tPaleta colorLet) {
	// 1 = azul;
	// 4 = rojo;
	// 15 = BLANCO;  
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, colorLet | (0 << 4));
	if (str.size() > 0) {
		cout << str;
		colorStr("", BLANCO_OSC);
	}
}



