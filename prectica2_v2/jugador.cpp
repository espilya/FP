
#include "jugador.h"

string showJugador(tJugador jugador) {
  return (jugador.id + '\t' + to_string(jugador.pts) + '\n');
}

void modificarJugador(tJugador &jugador, int puntos) { jugador.pts += puntos; }

bool operator<(const tJugador &opIzq, const tJugador &opDer) {
  bool menor = false;
  int i = 0;
  while ((!menor) && (i < opIzq.id.size()) && (i < opDer.id.size())) {
    menor = (opIzq.id[i] < opDer.id[i]);
    i++;
  }
  return menor;
}

bool menor(const tJugador &J1, const tJugador &J2) {
  bool menor;
  if (J1.pts < J2.pts) {
    menor = true;
  } else if (J1.pts == J2.pts) {
    if (J2 < J1)
      menor = true;
    else
      menor = false;
  } else {
    menor = false;
  }
  return menor;
}
