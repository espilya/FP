#include "listaJugadores.h"


void creaListaVacia(tListaJugadores & lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		lista[i].id = 0;
		lista[i].pts = 0;
	}
}
//inicializa lista a una lista vacía.

bool cargar(tListaJugadores & lista) {
	const string nombreArch = "listaJugadores.txt";
	tJugador player;
	bool ok = false;
	int ctd = 0;
	ifstream file;
	file.open(nombreArch);
	if (file.is_open()) {
		while (!file.eof && ctd < MAX_JUGADORES) {
			//como sera el archivo?
		}
		ok = true;
	}

}
//guarda en lista el contenido del archivo listaJugadores.txt; devuelve un booleano que indica si la carga se ha podido realizar.

void mostrar(const tListaJugadores & lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		cout <<
	}
}
//visualiza por pantalla la lista de jugadores dada.

bool guardar(const tListaJugadores & lista) {

}
//almacena en el archivo listaJugadores.txt el contenido de lista y devuelve un valor
//booleano indicando si la acción fue posible.Debe respetar el formato indicado para el archivo.

void puntuarJugador(tListaJugadores & lista, int puntos) {

}
//solicita que se introduzca el identificador de un jugador por teclado y se
//actualiza su información en lista.La actualización puede consistir en
//aumentar su puntuación con los nuevos puntos obtenidos(si el jugador se
//	encontraba ya en la lista) o en incorporarlo a la lista con la puntuación
//	obtenida(si no está llena).

bool buscar(const tListaJugadores & lista, string id, int &pos) {

}
//busca al jugador con identificador id en lista; devuelve true y la posición(pos)
//en la que se encuentra si el jugador está en la lista; devuelve false y la posición(pos) en la que debería estar si el jugador no está en la
//lista.Debe implementar una búsqueda binaria.

tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {

	return lista;
}
//devuelve una copia de la lista dada ordenada por ranking (decrecientemente por puntos, y a igualdad de puntos crecientemente por identificador).
