#ifndef _listaSudokus
#define _listaSudokus
#include <algorithm>
#include <string>
#include <iomanip> 
#include "juego.h"

using namespace std;

const string listaSudoku = "listaSudokus.txt";

// Nъmero mбximo de Sudokus registrados
const int MAX_SUDOKUS = 20;

// Array de Sudokus
typedef tSudoku tSudokus[MAX_SUDOKUS];

// Lista de Sudokus
typedef struct {
	tSudokus array;	// Array de sudokus
	int cont;	
} tListaSudokus;

//inicializa lista a una lista vacía.
void creaListaVacia(tListaSudokus &lista);

bool cargarListaSudokus(tListaSudokus & lista);

//guarda en lista el contenido del archivo listaSudokus.txt.
//devuelve un booleano que indica si la carga se ha podido realizar.
void mostrarListaSudokus(const tListaSudokus &lista);

/*visualiza por pantalla la lista de sudokus dada.*/
int  menuListaSudokus(const tListaSudokus & lista);

#endif