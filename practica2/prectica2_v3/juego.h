#ifndef _juego
#define _juego

#include "listaJugadores.h"
#include "tablero.h"
#include <cmath>
#include <conio.h>
#include <iomanip>
#include <locale.h>
#include <stdio.h>

using namespace std;

// Tipos de Sudokus
typedef enum { FACIL, MEDIO, DIFICIL, EMPTY } tSudokuNivel;

// tipo Sudoku
typedef struct {
  string fichero;
  int nivel;
} tSudoku;

// Juego
typedef struct {
  tSudoku sudoku;
  tTablero tablero;
  bool esSalvado;
  bool guardar;
} tJuego;

// Inicializa el juego
void iniciaJuego(tJuego &juego);

//  iniciamos el proceso del juego
void startJuego(tJuego &juego); // mostrarMenuJugada

//cargar el juego y tablero
bool cargaJuego(tJuego &juego);

// Bucle del menu(texto) del juego(proceso) de un sudoku.
//tambien se leen los valores de entrada.
int menuJugarSudoku(int &x, int &y, int &c);


// Procesado de opcion seleccionada del menu del juego.
void mostrarJuego(tJuego &juego);

void pausa();

//valido solo si esta en el rango
// (op >= inf) && (op <= sup)
int leerOpcion(int inf, int sup);

void clear();

// carga del juego
void guardarJuego(const tJuego &juego);

void salvarJuego(tJuego &juego, bool reiniciar = false);

bool errorAbrirFichero(const string &fichero);

//----------------------------------V2----------------------------------

// incorpora un jugador sin jugar
void incorporarJugador(tListaJugadores &lista);

// da opcion de elegie el algoritmo de ordenacion
tListaJugadores menuOrdenacion(const tListaJugadores &LISTA, bool ranking);

#endif
