#ifndef _jugador
#define _jugador
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

typedef struct {
	string id;
	int pts;
}tJugador;

//devuelve la información del
//jugador dado en un formato de cadena de caracteres(una cadena de
//caracteres donde primero aparece el identificador y después los puntos
//conseguidos por el jugador, separados por uno o más espacios en blanco)
string toString(tJugador jugador);

//añade puntos puntos a los puntos que lleva conseguidos el jugador dado.
void modificarJugador(tJugador & jugador, int puntos);

//sobrecarga del operador < para datos del tipo tJugador(se compara en base al identificador).
bool operator<(const tJugador & opIzq, const tJugador &opDer);

//devuelve true si el jugador j1 tiene menos puntos que el jugador j2, o si tienen los
//mismos puntos pero el identificador del jugador j2 es menor que el del
//jugador j1; false en caso contrario.
bool menor(const tJugador & j1, const tJugador & j2);


#endif
