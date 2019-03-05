#include "jugador.h"

string toString(tJugador jugador){
	return (to_string(jugador.id) + '\t' + to_string(jugador.pts));
}

void modificarJugador(tJugador & jugador, int puntos) {
	jugador.pts += puntos;
}

bool operator<(const tJugador & opIzq, const tJugador &opDer) {
	return(opIzq.id < opDer.id);
}


bool menor(const tJugador & j1, const tJugador & j2) {
	bool menor;
	if (j1.pts < j2.pts) {
		menor = true;
	}
	else if (j1.pts == j2.pts) {
		if (j2 < j1)
			menor = true;
		else
			menor = false;
	}
	else {
		menor = false;
	}

	return menor;
}
//devuelve true si el jugador j1 tiene menos puntos que el jugador j2, o si tienen los
//mismos puntos pero el identificador del jugador j2 es menor que el del
//jugador j1; false en caso contrario.