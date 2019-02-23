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

//COLOR
// NEGRO = 0;
// AZUL_OSC = 1;
//	...
// BLANCO =	15; 
typedef enum {
	NEGRO, AZUL_OSC, VERDE_OSC, CYAN_OSC, ROJO_OSC, MAGENTA_OSC, AMARILLO_OSC, 
	BLANCO_OSC, GRIS, AZUL, VERDE, CYAN, ROJO, MAGENTA, AMARILLO, BLANCO}
	tPaleta;


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
void colorFondo(tPaleta colorLet = BLANCO_OSC);

//Ecribe el string del argumento con el color seleccionado. Despues de llamar esta funcion el color vuelve a ser blanco
void colorStr(const string str, tPaleta colorLet = BLANCO_OSC);



#endif
