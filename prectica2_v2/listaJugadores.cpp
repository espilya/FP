#include "pch.h"
#include "listaJugadores.h"

bool comprobarStr(const string &STR) {
	int i = 0;
	while (!isspace(STR[i]) && i < STR.size())
		i++;
	return !isspace(STR[i]);
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

void mostrar(const tListaJugadores & LISTA) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		toString(LISTA.jugador[i]);
	}
}

bool guardar(const tListaJugadores & LISTA) {
	ofstream file;
	file.open(nombreListaJug);
	int i = 0;
	while(LISTA.jugador[i].id != ""){
		toString(LISTA.jugador[i]);
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

bool buscar(const tListaJugadores & LISTA, string id, int &pos) {
	int pos = -1, ini = 0, fin = LISTA.cont-1, mitad;
	bool encontrado = false;

	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (id == LISTA.jugador[mitad].id)
			encontrado = true;
		else if (id < LISTA.jugador[mitad].id)
			fin = mitad - 1;
		else 
			ini = mitad + 1;
	}
	if (encontrado) {
		pos = mitad;
	}
	return encontrado;
}
//busca al jugador con identificador id en lista; devuelve true y la posición(pos)
//en la que se encuentra si el jugador está en la lista; devuelve false y la posición(pos) en la que debería estar si el jugador no está en la
//lista.Debe implementar una búsqueda binaria.

//tListaJugadores ordenarPorRanking(const tListaJugadores &lista) {
//
//	return lista;
//}
//devuelve una copia de la lista dada ordenada por ranking (decrecientemente por puntos, y a igualdad 
//de puntos crecientemente por identificador).


void anadirJugador(tListaJugadores &lista, const string ID, const unsigned int PTS) {
	int pos;
	if ((lista.cont >= MAX_JUGADORES)) {
		pos = buscarConMenorPuntos(lista);
		if (PTS > lista.jugador[pos].pts) {
			cout << "La lista de jugadores esta llena, pero ya que tienes mas puntos que algunos jugadores, " 
				<< "enhorabuena, seras guardado! :D" << endl;
			eliminarJugador(lista, "", pos);
		}
		else {
			cout << "La lista se encuentra llena! No se ha podido guardar tu resultado." << endl;
		}
	}
	if ((lista.cont < MAX_JUGADORES) || PTS > lista.jugador[pos].pts)
	{
		int i = 0;
		while (lista.jugador[i].id < ID) {
			i++;
		}
		for (int a = i; a < lista.cont; a++)
			lista.jugador[a+1] = lista.jugador[a];
		lista.jugador[i].id = ID;
		lista.jugador[i].pts = PTS;
		lista.cont++;
	}
		
}

void eliminarJugador(tListaJugadores &lista, const string &ID, const int POS) {
	int pos;
	if (ID == "") 
		pos = POS;
	else {
		if (!buscar(lista, ID, pos))
			cout << "El jugador no se encontro, no se pudo eleminar." << endl;
	}

	for (int i = pos; i < lista.cont; i++) 
		lista.jugador[i] = lista.jugador[i + 1];
}

int buscarConMenorPuntos(const tListaJugadores &LISTA) {
	int pos;
	unsigned int a = 0, b = 0;
	for (int i = 0; i < LISTA.cont; i++) {
		a = LISTA.jugador[i].pts;
		if (a > b) {
			b = a;
			pos = i;
		}
	}
	return pos;
}