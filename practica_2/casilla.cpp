#include "pch.h"
#include "casilla.h"
#include <Windows.h>
using namespace std;

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
		colorFondo(color = ROJO);
		cout << casilla.numero;
	}
	else {
		colorFondo(color = AZUL);
		cout << casilla.numero;
	}
	colorFondo(color = NEGRO);
}

void colorFondo(int color) {
	// 1 = azul;
	// 4 = rojo;
	// 0 = negro;  
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, 15 | (color << 4));
}

bool esSimple(const tCasilla & casilla, int & numero) {
	bool estado = false;
	if (casilla.estado == VACIO) {
		estado = esUnitario(casilla.posibles, numero);
	}
	return estado;
}