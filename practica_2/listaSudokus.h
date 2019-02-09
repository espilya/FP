#ifndef _listaSudokus
#define _listaSudokus
#include <algorithm>
#include <string>
#include "juego.h"

using namespace std;

// Número máximo de Sudokus registrados
const int MAX_SUDOKUS = 20;

// Array de Sudokus
typedef tSudoku tSudokus[MAX_SUDOKUS];

// Lista de Sudokus
typedef struct {
	tSudokus array;	// Array de sudokus
	int cont;	
} tListaSudokus;

bool cargarListaSudokus(tListaSudokus & lista);
void mostrarListaSudokus(const tListaSudokus &lista);
int  menuListaSudokus(const tListaSudokus & lista);

#endif