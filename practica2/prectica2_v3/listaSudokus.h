#ifndef _listaSudokus
#define _listaSudokus
#include "juego.h"
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

const string listaSudoku = "listaSudokus.txt";

// Nъmero mбximo de Sudokus registrados
const int MAX_SUDOKUS = 20;
const int INICIO_SUDOKUS = 5;

// Array de Sudokus
//typedef tSudoku tSudokus[MAX_SUDOKUS];

typedef tSudoku *tSudPtr;

// Lista de Sudokus
typedef struct {
	tSudoku *array; // Array de sudokus
  int cont;
  int cap;
} tListaSudokus;

// inicializa lista a una lista vacía.
void creaLista(tListaSudokus &lista);

//..
bool cargar(tListaSudokus &lista);

// guarda en lista el contenido del archivo listaSudokus.txt.
// devuelve un booleano que indica si la carga se ha podido realizar.
void mostrar(const tListaSudokus &lista);

/*visualiza por pantalla la lista de sudokus dada.*/
int menuListaSudokus(const tListaSudokus &lista, tJuego &juego);

//----------------VERSION 2------------------

/*almacena en el archivo listaSudokus.txt el contenido de lista y devuelve un
valor booleano indicando si la acción fue posible. Debe respetar el formato
indicado para el archivo.*/
bool guardar(const tListaSudokus &lista);

// solicita los datos de un nuevo sudoku(nombre del fichero y puntos que permite
// conseguir) y si no existe un sudoku en lista con igual nombre de fichero lo
// inserta en la posición adecuada respetando el orden existente.Se devuelve un
// booleano que indica si se pudo registrar un nuevo sudoku, para lo cual
// también hay que tener en cuenta si la lista está o no llena.
bool registrarSudoku(tListaSudokus &lista);

// devuelve un boleano que indica si existe o no un sudoku en
// lista con nombre de fichero igual a nombreFich.
bool buscarFichero(const tListaSudokus &lista, string nombreFich);

// devuelve la posición de lista en la que debería insertarse sudoku
// para respetar el orden existente en la lista. Debe implementar una búsqueda
// binaria.
int buscarPos(const tListaSudokus &LISTA, const tSudoku &SUDOKU);

void insertarSudoku(tListaSudokus &lista, const tSudoku &SUDOKU, const int POS);

// compara el nombre de fichero
bool operator<(const tSudoku &opIzq, const tSudoku &opDer);

void eliminarSudoku(tListaSudokus &lista);

//ordena la lista por puntos, a igualidad la ordena por nombre
tListaSudokus ordenarListaSudoku(const tListaSudokus LISTA);

bool menor(const tSudoku &J1, const tSudoku &J2);

//--------------------V3--------------------
void ampliar(tListaSudokus & lista);

void borrarLista(tListaSudokus &lista);


#endif
