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
} tJuego;

// Mostrar men� de acciones para jugar un sudoku
void startJuego(tJuego &juego); // mostrarMenuJugada

// Bucle del menu(texto) del juego(proceso) de un sudoku.
int menuJugarSudoku(int &x, int &y, int &c);

// Inicializa el juego
void iniciaJuego(tJuego &juego);

bool cargaJuego(tJuego &juego);

// Procesado de opcion seleccionada del menu del juego.
void mostrarJuego(tJuego &juego);

void pausa();

// (op >= inf) && (op <= sup)
int leerOpcion(int inf, int sup);

void clear();

// carga del juego
void guardarJuego(const tJuego &juego);

void salvarJuego(tJuego &juego, bool reiniciar = false);

bool errorAbrirFichero(const string &fichero);

#endif
