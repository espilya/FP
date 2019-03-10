#include "pch.h"
#include "listaJugadores.h"

bool comprobarStr(const string &str) {
	int i = 0;
	while (!isspace(str[i]) && i < str.size())
		i++;
	return !isspace(str[i]);
}


void creaListaVacia(tListaJugadores & lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		lista.jugador[i].id = "";
		lista.jugador[i].pts = 0;
	}
}


bool cargar(tListaJugadores & lista) {
	tJugador player;
	bool ok = false;
	int ctd = 0;
	ifstream file;
	file.open(nombreListaJug);

	while (!file.eof() && ctd < MAX_JUGADORES) {
		
	}
	ok = true;
	return false;
}

void mostrar(const tListaJugadores & lista) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		toString(lista.jugador[i]);
	}
}

bool guardar(const tListaJugadores & lista) {
	ofstream file;
	file.open(nombreListaJug);
	int i = 0;
	while(lista.jugador[i].id != ""){
		toString(lista.jugador[i]);
		i++;
	}
	return true;
}

void puntuarJugador(tListaJugadores & lista, int puntos) {
	int pos;
	string id;
	cout << "Introduce tu nickname:\n>";
	do {
		getline(cin, id);
		if (!comprobarStr(id))
			cout << "Nombre incorrecto" << endl;
	} while (!comprobarStr(id));

	if(buscar(lista, id, pos)){
		modificarJugador(lista.jugador[pos], puntos);
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

bool buscar(const tListaJugadores & lista, string id, int &pos, int inf, int sup) {
	int i = 0;
	string inf = lista.jugador[inf].id;
	string sup = lista.jugador[sup].id;
	bool encontrado = false;
	if(id == inf)
		

	else if (id == sup)

	else
		if (id[0] < lista.jugador[lista.cont / 2].id[0])


	return false;
}
//busca al jugador con identificador id en lista; devuelve true y la posición(pos)
//en la que se encuentra si el jugador está en la lista; devuelve false y la posición(pos) en la que debería estar si el jugador no está en la
//lista.Debe implementar una búsqueda binaria.

//tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {
//
//	return lista;
//}
//devuelve una copia de la lista dada ordenada por ranking (decrecientemente por puntos, y a igualdad de puntos crecientemente por identificador).


void anadirJugador(tListaJugadores &lista, string id, unsigned int pts) {

}