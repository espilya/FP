#include "checkML.h"
#include "listaJugadores.h"

bool comprobarStr(const string &STR) {
	int i = 0;
	if (STR == "")
		return false;
	while (!isspace(STR[i]) && i < (int)STR.size())
		i++;
	return !isspace(STR[i]);
}

void creaLista(tListaJugadores &lista) {
	lista.jugador = new tJugPtr[INICIO_JUGADORES];
}


bool cargar(tListaJugadores &lista) { //CREACION DE NEW
	tJugador player;
	bool ok = false;
	lista.cont = 0;
	lista.cap = INICIO_JUGADORES;
	ifstream file;
	file.open(nombreListaJug);
	if (file.is_open()) {
		while ((!file.eof()) && (file >> player.id) && (lista.cont < MAX_JUGADORES)) {
			if (lista.cont >= lista.cap) {
				ampliar(lista);
			}
			file >> player.pts;
			lista.jugador[lista.cont] = new tJugador(player);
			lista.cont++;
		}
		ok = true;
	}
	file.close();
	return ok;
}

void mostrar(const tListaJugadores &LISTA) {
	if (LISTA.cont == 0) {
		cout << "La lista se encuentra vacia." << endl;
	}
	else {
		cout << "Lista de jugadores:\n";
		cout << "-----------------" << endl;
		cout << "Numero de jugadores: " << LISTA.cont
			<< endl
			<< endl;
		cout << setw(3);
		colorStr("#", VERDE_OSC);
		cout << setw(18);
		colorStr("Identificador:", MAGENTA_OSC);
		cout << setw(18);
		colorStr("Puntos:", AMARILLO_OSC);
		cout << endl << endl;

		for (int i = 0; i < LISTA.cont; i++) {
			cout << setw(3);
			colorStr(to_string(i + 1), VERDE_OSC);
			cout << setw(18);
			colorStr(LISTA.jugador[i]->id, MAGENTA_OSC);
			cout << setw(18);
			colorStr(to_string(LISTA.jugador[i]->pts), AMARILLO_OSC);
			cout << endl;
		}
	}
}

bool guardar(const tListaJugadores &LISTA) {
	ofstream file;
	file.open(nombreListaJug);
	bool ok = false;
	if (file.is_open()) {
		for (int i = 0; i < LISTA.cont; i++) {
			file << showJugador(*LISTA.jugador[i]);
		}
		ok = true;
	}
	file.close();
	return ok;
}

void puntuarJugador(tListaJugadores &lista, int puntos) {
	int pos;
	bool ok;
	string id;
	cout << "Vamos a puntuarte, ";
	cout << "introduce tu nickname:\n>";
	do {
		getline(cin, id);
		ok = comprobarStr(id);
		if (!ok) {
			cout << "Nombre contiene caracteres invalidos!" << endl;
			if (id.size() > 30)
				cout << "El nombre contiene mas de 30 caracteres!" << endl;
			cout << ">";
		}
	} while (!ok);

	if (buscar(lista, id, pos))
		modificarJugador(*lista.jugador[pos], puntos); // anadir pts
	else
		anadirJugador(lista, id, puntos);
}

void anadirJugador(tListaJugadores &lista, const string ID, const unsigned int PTS) {
	// en caso de estar la lista llena..
	int pos;
	tJugador player;
	player.id = ID;
	player.pts = PTS;
	bool meter = false;
	if ((lista.cont >= MAX_JUGADORES)) {
		if (!(lista.cont < lista.cap))
			ampliar(lista);
		pos = buscarConMenorPuntos(lista);
		if ((int)PTS > (int)lista.jugador[pos]->pts) {
			meter = true;
			cout << "La lista de jugadores esta llena, pero ya que tienes "
				"mas puntos que algunos jugadores,"
				<< " seras guardado! :D" << endl;
			eliminarJugador(lista, pos);
		}
		else {
			cout << "La lista se encuentra llena! No se ha podido guardar tu "
				"resultado."
				<< endl;
		}
	}

	if (meter) {
		for (int i = lista.cont - 1; i > pos; i--)
			*lista.jugador[i] = *lista.jugador[i - 1];
		lista.jugador[pos] = new tJugador(player);
	}

	else if ((lista.cont < MAX_JUGADORES)) {
		lista.jugador[lista.cont] = new tJugador(player);
		lista.cont++;
	}
	else
		cout << "Lista llena." << endl;
}

bool buscar(const tListaJugadores &LISTA, const string ID, int &pos) {
	//tJugador tempJug;
	//pos = -1;
	//int ini = 0, fin = LISTA.cont - 1, mitad;
	//tempJug.id = ID;
	//while ((ini <= fin) && !encontrado) {
	//	mitad = (ini + fin) / 2; // División entera
	//	if (tempJug.id == LISTA.jugador[mitad]->id)
	//		encontrado = true;
	//	else if (tempJug.id < LISTA.jugador[mitad]->id)
	//		fin = mitad - 1;
	//	else
	//		ini = mitad + 1;
	//}
	//pos = mitad;
	pos = buscarBR(LISTA, ID, 0, LISTA.cont - 1);
	if (pos == -1)
		return false;
	else
		return true;
}

int buscarBR(const tListaJugadores LISTA, const string ID, int ini, int fin) {
	int pos = -1;
	if (ini <= fin) {
		int mitad = (ini + fin) / 2;
		if (ID == LISTA.jugador[mitad]->id) {
			pos = mitad;
		}
		else if (ID < LISTA.jugador[mitad]->id) {
			pos = buscarBR(LISTA, ID, ini, mitad - 1);
		}
		else {
			pos = buscarBR(LISTA, ID, mitad + 1, fin);
		}
	}
	return pos;
}

void borrarJugador(tListaJugadores &lista) {
	int pos;
	bool ok = false, salir = false;
	string id;
	cout << "Introduce tu nickname(0.-Para salir):\n>";
	do {
		getline(cin, id);
		if (id == "0") {
			salir = true;
		}
		else {
			ok = comprobarStr(id);
			if (!ok)
				cout << "Nombre contiene caracteres invalidos!" << endl;
			if (id.size() > 30)
				cout << "El nombre contiene mas de 30 caracteres!" << endl;
		}
	} while (!ok && !salir);
	if (buscar(lista, id, pos)) {
		eliminarJugador(lista, pos);
		lista.cont--;
	}
	else
		cout << "Jugador no encontrado." << endl;
}

bool eliminarJugador(tListaJugadores &lista, const int POS) { // quita al jugador de la lista
	bool ok = false;

	for (int i = POS; i < lista.cont - 1; i++)
		*lista.jugador[i] = *lista.jugador[i + 1];
	delete lista.jugador[lista.cont - 1];

	return (!ok);
}

int buscarConMenorPuntos(const tListaJugadores &LISTA) {
	int pos;
	unsigned int a = 0, b = 2147483647; // el valor de int maximo
	for (int i = 0; i < LISTA.cont; i++) {
		a = LISTA.jugador[i]->pts;
		if (a <= b) {
			b = a;
			pos = i;
		}
	}
	return pos;
}

tListaJugadores ordenarPorAscii_insercion(const tListaJugadores &LISTA) {
	tListaJugadores listaNew = LISTA;
	int pos;
	tJugador tmp;
	for (int i = 0; i < LISTA.cont; i++) {
		tmp = *listaNew.jugador[i];
		pos = 0;
		while ((pos < i) && (*listaNew.jugador[pos] < tmp)) {
			pos++;
		}
		for (int j = i; j > pos; j--) {
			*listaNew.jugador[j] = *listaNew.jugador[j - 1];
		}
		*listaNew.jugador[pos] = tmp;
	}
	return listaNew;
}
tListaJugadores ordenarPorAscii_insercionConIntercambios(const tListaJugadores &LISTA) {
	int pos, limit = 0;
	tListaJugadores listaNew = LISTA;
	tJugador tmp;
	bool insertado = false;
	for (int i = 1; i < LISTA.cont; i++) {
		pos = i;
		insertado = false;
		while ((pos > 0) && (*listaNew.jugador[pos] < *listaNew.jugador[pos - 1])) {
			tmp = *listaNew.jugador[pos];
			*listaNew.jugador[pos] = *listaNew.jugador[pos - 1];
			*listaNew.jugador[pos - 1] = tmp;
			pos--;
		}
	}
	return listaNew;
}
tListaJugadores ordenarPorAscii_seleccionDirecta(const tListaJugadores &LISTA) {
	tListaJugadores listaNew = LISTA;
	for (int i = 0; i < LISTA.cont - 1; i++) {
		int menorPos = i;
		for (int j = i + 1; j < LISTA.cont; j++) {
			if (*listaNew.jugador[j] < *listaNew.jugador[menorPos]) {
				menorPos = j;
			}
		}
		if (*listaNew.jugador[menorPos] < *listaNew.jugador[i]) {
			tJugador tmp;
			tmp = *listaNew.jugador[i];
			*listaNew.jugador[i] = *listaNew.jugador[menorPos];
			*listaNew.jugador[menorPos] = tmp;
		}
	}
	return listaNew;
}
tListaJugadores ordenarPorAscii_Burbuja(const tListaJugadores &LISTA) {
	//----------BURBUJA----------
	tListaJugadores listaNew = LISTA;
	int i = 0;
	int N = LISTA.cont;
	bool inter = true;
	while ((i < N - 1) && (inter)) {
		inter = false;
		for (int j = N - 1; j > i; j--) {
			if (*listaNew.jugador[j] < *listaNew.jugador[j - 1]) {
				tJugador tmp;
				tmp = *listaNew.jugador[j];
				*listaNew.jugador[j] = *listaNew.jugador[j - 1];
				*listaNew.jugador[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter)
			i++;
	}
	return listaNew;
}

tListaJugadores ordenarPorRanking_insercion(const tListaJugadores &LISTA) {
	tListaJugadores listaNew = LISTA;
	int pos;
	tJugador tmp;
	for (int i = 0; i < LISTA.cont; i++) {
		tmp = *listaNew.jugador[i];
		pos = 0;
		while ((pos < i) && (!menor(*listaNew.jugador[pos], tmp))) {
			pos++;
		}
		for (int j = i; j > pos; j--) {
			*listaNew.jugador[j] = *listaNew.jugador[j - 1];
		}
		*listaNew.jugador[pos] = tmp;
	}
	return listaNew;
}
tListaJugadores ordenarPorRanking_insercionConIntercambios(const tListaJugadores &LISTA) {
	int pos, limit = 0;
	tListaJugadores listaNew = LISTA;
	tJugador tmp;
	bool insertado = false;
	for (int i = 1; i < LISTA.cont; i++) {
		pos = i;
		insertado = false;
		while ((pos > 0) && (menor(*listaNew.jugador[pos - 1], *listaNew.jugador[pos]))) {
			tmp = *listaNew.jugador[pos];
			*listaNew.jugador[pos] = *listaNew.jugador[pos - 1];
			*listaNew.jugador[pos - 1] = tmp;
			pos--;
		}
	}
	return listaNew;
}
tListaJugadores ordenarPorRanking_seleccionDirecta(const tListaJugadores &LISTA) {
	tListaJugadores listaNew = LISTA;
	for (int i = 0; i < LISTA.cont - 1; i++) {
		int menorPos = i;
		for (int j = i + 1; j < LISTA.cont; j++) {
			if (menor(*listaNew.jugador[menorPos], *listaNew.jugador[j])) {
				menorPos = j;
			}
		}
		if (menor(*listaNew.jugador[i], *listaNew.jugador[menorPos])) {
			tJugador tmp;
			tmp = *listaNew.jugador[i];
			*listaNew.jugador[i] = *listaNew.jugador[menorPos];
			*listaNew.jugador[menorPos] = tmp;
		}
	}
	return listaNew;
}
tListaJugadores ordenarPorRanking_Burbuja(const tListaJugadores &LISTA) {
	//----------BURBUJA----------
	tListaJugadores listaNew = LISTA;
	int i = 0;
	int N = LISTA.cont;
	bool inter = true;
	while ((i < N - 1) && inter) {
		inter = false;
		for (int j = N - 1; j > i; j--) {
			if (menor(*listaNew.jugador[j - 1], *listaNew.jugador[j])) {
				tJugador tmp;
				tmp = *listaNew.jugador[j];
				*listaNew.jugador[j] = *listaNew.jugador[j - 1];
				*listaNew.jugador[j - 1] = tmp;
				inter = true;
			}
		}
		if (inter)
			i++;
	}
	return listaNew;
}

//----------------------------Version 3----------------------------

//Amplía la dimensión del array dinámico de lista al doble de la que
//tiene.Los datos de los jugadores que ya existen en la lista deben mantenerse.
void ampliar(tListaJugadores & lista) {
	lista.cap = lista.cont * 2;
	tJugPtr *new_jugador = new tJugPtr[lista.cap];
	for (int i = 0; i < lista.cont; i++)
		new_jugador[i] = lista.jugador[i];
	borrarLista(lista);
	lista.jugador = new_jugador;
}

void borrarJugadores(tListaJugadores & lista) {
	for (int i = 0; i < lista.cont; i++)
		delete  lista.jugador[i];
}

//Libera la memoria dinámica usada por lista.
void borrarLista(tListaJugadores & lista) {
	delete[] lista.jugador;
}

