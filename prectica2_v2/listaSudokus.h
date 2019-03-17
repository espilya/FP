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
void creaLista(tListaSudokus &lista);

bool cargar(tListaSudokus & lista);

//guarda en lista el contenido del archivo listaSudokus.txt.
//devuelve un booleano que indica si la carga se ha podido realizar.
void mostrar(const tListaSudokus &lista);

/*visualiza por pantalla la lista de sudokus dada.*/
int  menuListaSudokus(const tListaSudokus & lista, tJuego & juego);

bool guardar(const tListaSudokus & lista);
/*almacena en el archivo listaSudokus.txt el contenido de lista y devuelve un valor booleano
indicando si la acción fue posible. Debe respetar el formato indicado para el archivo.*/

bool registrarSudoku(tListaSudokus & lista);
//solicita los datos de un nuevo sudoku(nombre del fichero y puntos que permite conseguir) y si
//no existe un sudoku en lista con igual nombre de fichero lo inserta en la
//posición adecuada respetando el orden existente.Se devuelve un booleano
//que indica si se pudo registrar un nuevo sudoku, para lo cual también hay
//que tener en cuenta si la lista está o no llena.

bool buscarFichero(const tListaSudokus & lista, string nombreFich);
//devuelve un boleano que indica si existe o no un sudoku en
//lista con nombre de fichero igual a nombreFich.

int buscarPos(const tListaSudokus & lista, const tSudoku &sudoku);
//devuelve la posición de lista en la que debería insertarse sudoku
//para respetar el orden existente en la lista.Debe implementar una búsqueda binaria.




#endif
