#include "jugador.h"

string showJugador(const tJugador &jugador) {
	return (jugador.id + "\t\t\t" + to_string(jugador.pts) + '\n');
}

void modificarJugador(tJugador &jugador, int puntos) { jugador.pts += puntos; }

bool operator<(const tJugador &opIzq, const tJugador &opDer) {
	bool menor = false;
	bool encontrado = false;
	int i = 0;
	const int MAX = 50;
	while ((!encontrado) && (i < (int)opIzq.id.size()) && (i < (int)opDer.id.size()) && (i < MAX)) {
		if (opIzq.id[i] != opDer.id[i]) {
			menor = opIzq.id[i] < opDer.id[i];
			encontrado = true;
		}
		i++;
	}
	if ((!encontrado) && (opIzq.id.size() != opDer.id.size())) {
		if (opIzq.id.size() < opDer.id.size())
			menor = true;
		else
			menor = false;
	}
	return menor;
}

bool menor(const tJugador &J1, const tJugador &J2) {
	bool menor;
	if (J1.pts < J2.pts) {
		menor = true;
	}
	else if (J1.pts == J2.pts) {
		if (J1 < J2)
			menor = true;
		else
			menor = false;
	}
	else {
		menor = false;
	}
	return menor;
}
