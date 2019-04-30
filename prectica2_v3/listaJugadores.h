#ifndef _listaJugadores
#define _listaJugadores
#include "casilla.h"
#include "jugador.h"
#include <fstream>





const string nombreListaJug = "listaJugadores.txt";
const int MAX_JUGADORES = 20;
typedef tJugPtr tArrJugadores[MAX_JUGADORES];
typedef struct {
	tArrJugadores *jugador;
	int cont;
	int cap;
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

// anadir nuevo jugador
void anadirJugador(tListaJugadores &lista, const string ID,
	const unsigned int PTS);

// busca al jugador, con el Id y lo elimina
void borrarJugador(tListaJugadores &lista);

// elimina un jugador
bool eliminarJugador(tListaJugadores &lista, const int POS = -1);

// en caso de no haber espacio en la lista, busca jugador con menor puntos,
// compara la pts del jug nuevo y del de menor pts
int buscarConMenorPuntos(const tListaJugadores &LISTA);


tListaJugadores ordenarPorRanking_insercion(const tListaJugadores &LISTA);
tListaJugadores ordenarPorRanking_insercionConIntercambios(const tListaJugadores &LISTA);
tListaJugadores ordenarPorRanking_seleccionDirecta(const tListaJugadores &LISTA);
tListaJugadores ordenarPorRanking_Burbuja(const tListaJugadores &LISTA);

tListaJugadores ordenarPorAscii_insercion(const tListaJugadores &LISTA);
tListaJugadores ordenarPorAscii_insercionConIntercambios(const tListaJugadores &LISTA);
tListaJugadores ordenarPorAscii_seleccionDirecta(const tListaJugadores &LISTA);
tListaJugadores ordenarPorAscii_Burbuja(const tListaJugadores &LISTA);

//----------------------------Version 3----------------------------

//Amplía la dimensión del array dinámico de lista al doble de la que
//tiene.Los datos de los jugadores que ya existen en la lista deben mantenerse.
void ampliar(tListaJugadores & lista);

//Libera la memoria dinámica usada por lista.
void borrarListaJugadores(tListaJugadores & lista);
#endif
