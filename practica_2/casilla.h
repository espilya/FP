#ifndef _casilla
#define _casilla
#include "pch.h"
#include "Conjunto.h"
#include <Windows.h>
#include <string>
using namespace std;

// Estado de cada casilla
typedef enum { VACIO, FIJA, RELLENO} tEstadoCasilla;
//Tamaño del tablero
//const int DIMENSION = 9;

// Casilla en tablero
typedef struct {
	int numero;
	tEstadoCasilla estado;
	tConjunto posibles; //valores posibles de una casilla
}tCasilla;

//LETRA
// 9 = azul;
// 12 = rojo;
// 15 = negro; 
typedef enum {VIOLETA = 5, BLANCO = 7, GRIS = 8, AZUL = 9, ROJO = 12 } tPaleta;


//Inicialmente casilla vacia con todos los valores posibles
void iniciaCasilla(tCasilla & casilla);

//Rellena con el caracter c la casilla 
//Si fija es true el estado se pone a FIJA: cuando se carga el tablero se llama con true, el resto de los casos a false
//El valor por defecto de fija es false
void rellenaCasilla(tCasilla & casilla, char c, bool fija=false); //fija es true cuando se lee de fichero

void borraCasilla(tCasilla & casilla);


// Dibuja una casilla
void dibujaCasilla(const tCasilla &casilla);

// Determina si una casilla aun no rellena tiene un unico valor posible
//Devuelve falso para las casillas fijas o ya rellenas
bool esSimple(const tCasilla & casilla, int & numero);

// Establece el color de una casilla
void colorFondo(tPaleta colorLet = BLANCO);

//Ecribe la string con el coloe seleccionado. Despues de llamar esta funcion el colo vuelve a ser blanco
//{VIOLETA = 5, GRIS = 8, AZUL = 9, ROJO = 12, BLANCO = 15} tPaleta;
void colorStr(string str, tPaleta colorLet = BLANCO);


#endif
