#ifndef _listaJugadores
#define _listaJugadores
#include "jugador.h"
#include <fstream>

const string nombreListaJug = "listaJugadores.txt";
const int MAX_JUGADORES = 25;
typedef tJugador tArrJugadores[MAX_JUGADORES];
typedef struct {
  tArrJugadores jugador;
  int cont;
} tListaJugadores;

// comprueba un string si contiene espacios
bool comprobarStr(const string &STR);

// inicializa lista a una lista vacía.
void creaLista(tListaJugadores &lista);

// guarda en lista el contenido del archivo listaJugadores.txt; devuelve un
// booleano que indica si la carga se ha podido realizar.
bool cargar(tListaJugadores &lista);

// visualiza por pantalla la lista de jugadores dada.
void mostrar(const tListaJugadores &LISTA);

// almacena en el archivo listaJugadores.txt el contenido de lista y devuelve un
// valor booleano indicando si la acción fue posible. Debe respetar el formato
// indicado para el archivo.
bool guardar(const tListaJugadores &LISTA);

// solicita que se introduzca el identificador de un jugador por teclado y se
// actualiza su información en lista. La actualización puede consistir en
// aumentar su puntuación con los nuevos puntos obtenidos(si el jugador se
// encontraba ya en la lista) o en incorporarlo a la lista con la puntuación
// obtenida(si no está llena).
void puntuarJugador(tListaJugadores &lista, int puntos);

// busca al jugador con identificador id en lista; devuelve true y la
// posición(pos) en la que se encuentra si el jugador está en la lista; devuelve
// false y la posición(pos) en la que debería estar si el jugador no está en la
// lista.Debe implementar una búsqueda binaria.
bool buscar(const tListaJugadores &LISTA, const string ID, int &pos);

// devuelve una copia de la lista dada ordenada por ranking (decrecientemente
// por puntos, y a igualdad de puntos crecientemente por identificador).
tListaJugadores ordenarPorRanking_Burbuja(const tListaJugadores &LISTA);

tListaJugadores ordenarPorAscii_Burbuja(const tListaJugadores &LISTA);

// anadir nuevo jugador
void anadirJugador(tListaJugadores &lista, const string ID,
                   const unsigned int PTS);

// elimina un jugador
bool eliminarJugador(tListaJugadores &lista, const int POS = -1);

// en caso de no haber espacio en la lista, busca jugador con menor puntos,
// compara la pts del jug nuevo y del de menor pts
int buscarConMenorPuntos(const tListaJugadores &LISTA);

#endif
