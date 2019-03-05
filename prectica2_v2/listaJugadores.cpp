#include "listaJugadores.h"


void creaListaVacia(tListaJugadores & lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		lista[i].id = "";
		lista[i].pts = 0;
	}
}


bool cargar(tListaJugadores & lista) {
	tJugador player;
	bool ok = false;
	int ctd = 0;
	ifstream file;
	file.open(nombreListaJug);

	while (!file.eof && ctd < MAX_JUGADORES) {
		//como sera el archivo?
	}
	ok = true;

}

void mostrar(const tListaJugadores & lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		cout << lista[i].id << '\t' << lista[i].pts << endl;
	}
}

bool guardar(const tListaJugadores & lista) {
	ofstream file;
	file.open(nombreListaJug);
	int i = 0;
	while(lista[i].id != ""){
		toString(lista[i]);
		i++;
	}
	return true;
}

void puntuarJugador(tListaJugadores & lista, int puntos) {
	int pos;

	string id;
	cout << "Introduce tu nickname:\n>";
	cin >> id;
	if(buscar(lista, id, pos)){
		modificarJugador(lista[pos], puntos);
	}
	else {
		anadirJugador(lista, id, puntos);
	}

}
//solicita que se introduzca el identificador de un jugador por teclado y se
//actualiza su información en lista. La actualización puede consistir en
//aumentar su puntuación con los nuevos puntos obtenidos(si el jugador se
//	encontraba ya en la lista) o en incorporarlo a la lista con la puntuación
//	obtenida(si no está llena).

bool buscar(const tListaJugadores & lista, string id, int &pos) {
	int i = 0, pos = 0;
	bool encontrado = false;
	while (lista[i].id != "") {
		if (lista[i].id == id) {
			encontrado = true;
			pos = i;
		}
		i++;
	}
}
//busca al jugador con identificador id en lista; devuelve true y la posición(pos)
//en la que se encuentra si el jugador está en la lista; devuelve false y la posición(pos) en la que debería estar si el jugador no está en la
//lista.Debe implementar una búsqueda binaria.

tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {

	return lista;
}
//devuelve una copia de la lista dada ordenada por ranking (decrecientemente por puntos, y a igualdad de puntos crecientemente por identificador).


void anadirJugador(tListaJugadores &lista, string id, unsigned int pts) {

}