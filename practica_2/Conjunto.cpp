#include "pch.h"
#include "Conjunto.h"

//hola
void cjto_vacio(tConjunto &c) {
	for (int i = 0; i < DIMENSION; i++) {
		c.elementos[i] = false;
	}
	c.nElems = 0;
}

void cjto_lleno(tConjunto &c) {
	for (int i = 0; i < DIMENSION; i++) {
		c.elementos[i] = true;
	}
	c.nElems = 9;
}

bool pertenece(const tConjunto &c, int e) {
	return c.elementos[e - 1];
}

void addElemento(tConjunto & c, int e) {
	c.elementos[e - 1] = true;
	c.nElems++;
}

void delElemento(tConjunto & c, int e) {
	c.elementos[e - 1] = false;
	c.nElems--;
}

int numElems(const tConjunto & c) {
	return c.nElems;
}

bool esUnitario(const tConjunto & c, int &e) {
	bool unitario = false;
	int	contador = 0;
	int pos;
	for (int i = 0; i < DIMENSION; i++) {
		if (c.elementos[i] == true) {
			contador++;
			pos = i + 1;
		}
	}
	if (contador == 1) {
		e = pos;
		unitario = true;
	}
	return unitario;
}

void mostrar(const tConjunto&c) {
	for (int i = 0; i < DIMENSION; i++) {
		if (c.elementos[i])
			std::cout << i + 1 << ' ';
	}
}