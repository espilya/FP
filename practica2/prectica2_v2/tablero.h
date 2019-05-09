#ifndef _tablero
#define _tablero
#include "casilla.h"
#include <iostream>
#include <string>
using namespace std;

const int  DIM_BORDES = 25;

//array para los bordes de la tabla
typedef int tArray[DIM_BORDES];

// Tablero Sudoku
typedef tCasilla tTablero[DIMENSION][DIMENSION];



//Inicia todas las casillas del tablero
void iniciaTablero(tTablero &t);

//Carga un tablero de fichero
bool cargarTablero(const string &fichero, tTablero &t, bool &esSalvado);

// Dibuja el tablero en pantalla
void dibujarTablero(const tTablero &t);

//Dibuja la submatriz
void dibujarCuadrado(const tTablero &t, int &y);


//Coloca c en x, y
//c, x e y estan 1 y 9
//El resultado booleano indica si se ha podido: para ello la casilla ha de estar vacia y c ser uno de los valores posibles
//Una vez colocado se quita ese valor de fila, columna y submatriz con quitarPosibles
bool ponerNum(tTablero &t, int x, int y, int c, short int &error);

//Borra la casilla x,y siempre que no sea fija y en ella haya un valor, en caso contrario devuelve false
//La vaciamos y procedemos a restablecer los valores posibles que se pueda en fila, columna y submatriz
bool borraNum(tTablero &t, int x, int y, short int &error );

//Determina si el tablero ha sido rellenado completamente
//Si el sudoku tiene una unica solucion, como solamente permitimos valores validos no seria posible que estuviese lleno y no fuese correcto
//Si pudiese tener varias soluciones entonces puede terner sentido tener esta funcion
//O si permitiesemos poner valores erroneos
bool tableroLleno (const tTablero &t);

//determina si el tablero esta "vacio" - que no se ha rellanado ninguna casilla
bool tableroSoloFijo(const tTablero &t);

//Muestra los posibles valores de una casilla valida cualquiera
//Si es fija solo figurara su propio valor, ya que no se puede cambiar
void mostrarPosibles(const tTablero &t, int x, int y);

//Recorre la matriz mirando que casillas vacias tienen un unico valor posible y lo rellena
//De nuevo quita valores posibles de la fila, columna y submatriz
void rellenarSimples(tTablero &t);

bool resolver(tTablero &t, int nCasilla);

//--------HECHOS POR LOS ALUMNOS -----
//Recorre todas las casillas y elimina los valores ya no posibles(viejos)
//x,y: coodernadas de las casillas en las cuales se ha borrado/anadido algo
//mode; mode de funcion, 0-para cargar fichero, 1-para poner num, 2-para borrar num
void calcElementosPosibles(tTablero &t, int mode = 0, int x = -1, int y = -1, int c = -1);

void calcElementosPosibles_SubMatriz(tTablero &t);

#endif
