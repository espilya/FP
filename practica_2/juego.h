#ifndef _juego
#define _juego
#include "pch.h"
#include "tablero.h"
#include <conio.h>
#include <locale.h>
#include <iomanip>     
#include <cmath>
#include <stdio.h>
#include <string.h>

using namespace std;

// Tipos de Sudokus
typedef enum { FACIL, MEDIO, DIFICIL, EMPTY} tNivelSudoku;

// tipo Sudoku
typedef struct {
	string fichero;
	tNivelSudoku nivel;
} tSudoku;

// Juego
typedef struct {
	tSudoku sudoku;
	tTablero tablero;
	bool terminado;
}tJuego;



// Mostrar menú de acciones para jugar un sudoku
void mostrarMenuPrincipal(tJuego &juego); //mostrarMenuJugada

// Bucle del menu(texto) del juego(proceso) de un sudoku.
int menuJugarSudoku(int &x, int &y, int &c);

// Inicializa el juego
void iniciaJuego(tJuego & juego);

//Procesado de opcion seleccionada del menu del juego.
void mostrarJuego(tJuego &juego);//(const tJuego &juego)

void pausa();


// (op >= inf) && (op <= sup)
int leerOpcion(int inf, int sup);

void clear();


//carga del juego
void guardarJuego(const tJuego &juego);

void salvarJuego(tJuego &juego);

bool errorAbrirFichero(const string &fichero);



#endif