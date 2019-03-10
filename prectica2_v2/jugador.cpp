#include "pch.h"
#include "jugador.h"

string toString(tJugador jugador){
	return (jugador.id + '\t' + to_string(jugador.pts) + '\n');
}

void modificarJugador(tJugador & jugador, int puntos) {
	jugador.pts += puntos;
}

bool operator<(const tJugador & opIzq, const tJugador &opDer) {
	return(opIzq.id[0] < opDer.id[0]);
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
