﻿#ifndef _conjunto
#define _conjunto

#include <iostream>
#include <fstream>

const int DIMENSION = 9;

//hola
//Tipo de datos que representa un subconjunto del conjunto de elementos {1,2,3,4,5,6,7,8,9}

typedef bool tElementos[DIMENSION];
typedef struct{
	int nElems; //cardinal del conjunto
	tElementos elementos; //elementos contenidos en el conjunto
} tConjunto;

void cjto_vacio(tConjunto & c); //conjunto vacio
void cjto_lleno(tConjunto & c); //conjunto de elementos{ 1, 2, 3, 4, 5, 6, 7, 8, 9 }
bool pertenece(const tConjunto &c, int e);
void addElemento(tConjunto & c, int e);
void delElemento(tConjunto & c, int e); //saca el elemento e(nº entero ∈[1, 9]) del conjunto c. y pone false
int numElems(const tConjunto & c);
bool esUnitario(const tConjunto & c, int &e);
void mostrar(const tConjunto&c);

#endif
