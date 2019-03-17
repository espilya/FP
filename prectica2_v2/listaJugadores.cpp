#include "pch.h"
#include "listaJugadores.h"


bool operator <Pts (const tJugador & opIzq, const tJugador &opDer);
				bool menor;
				if (opIzq.pts < opDer.pts)
					menor = true;
				else if(opIzq.pts = opDer.pts)
					menor = (opIzq < opDer);

			return  menor;
}


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
	if(file.is_open()){
		while (!file.eof() && ctd < MAX_JUGADORES) {
		file >> player.id;
		file >> player.pts;
		lista.jugador[ctd] = player;
		ctd++;
		}
		ctd--;
		ok = true;
	}
			return ok;
}


void mostrar(const tListaJugadores & LISTA) {
	for (int i = 0; i < MAX_JUGADORES; i++) {
		showJugador(LISTA.jugador[i]);
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
	file.close();
	return true;
}


void puntuarJugador(tListaJugadores & lista, int puntos) {
	int pos;
	string id;
	cout << "Vamos a puntuar "
	cout << "Introduce tu nickname:\n>";
	do {
		bool = ok;
		getline(cin, id);
		ok = comprobarStr(id);
		if (!ok)
			cout << "Nombre incorrecto" << endl;
	} while (!ok)

	if(buscar(lista, id, pos)){
		modificarJugador(lista.jugador[pos], puntos);//anadir pts
	}
	else {
		anadirJugador(lista, id, puntos);
		modificarJugador(lista.jugador[pos], puntos);//anadir pts
	}

}
//solicita que se introduzca el identificador de un jugador por teclado y se
//actualiza su información en lista. La actualización puede consistir en
//aumentar su puntuación con los nuevos puntos obtenidos(si el jugador se
//	encontraba ya en la lista) o en incorporarlo a la lista con la puntuación
//	obtenida(si no está llena).


bool buscar(const tListaJugadores & LISTA, const string ID, int &pos) {
	tJugador tempJug;
	int pos = -1, ini = 0, fin = LISTA.cont-1, mitad;
	bool encontrado = false;
	tempJug.id = ID;

	while ((ini <= fin) && !encontrado) {
		mitad = (ini + fin) / 2; // División entera
		if (tempJug.id == LISTA.jugador[mitad].id)
			encontrado = true;
		else if (tempJug.id < LISTA.jugador[mitad].id)
			fin = mitad - 1;
		else
			ini = mitad + 1;
		}
		pos = mitad;
	return encontrado;
}

tListaJugadores ordenarPorRanking(const tListaJugadores &LISTA) {
	tListaJugadores listaNew = LISTA;
	int i = 0;
	const int N = LISTA.cont;
	bool inter;
	while((i<N ‐1) && inter)
	{
		for(int j = N ‐1; j > i; j‐‐){
			if (listaNew.jugador[j] <Pts listaNew.jugador[j ‐1]){
				int tmp = listaNew.jugador[j];
				listaNew.jugador[j] = listaNew.jugador[j ‐1];
				listaNew.jugador[j ‐1] = tmp;
				inter = true;
			}
		}
		if (inter)
			i++;
	}

	return listaNew;
}
//Devuelve una copia de la lista dada ordenada por ranking (decrecientemente por puntos, y a igualdad
//de puntos crecientemente por identificador).


void anadirJugador(tListaJugadores &lista, const string ID, const unsigned int PTS) {
	int pos;
	//en caso de estar la lista llena..
	if ((lista.cont >= MAX_JUGADORES)) {
		pos = buscarConMenorPuntos(lista);
		if (PTS > lista.jugador[pos].pts) {
			cout << "La lista de jugadores esta llena, pero ya que tienes mas puntos que algunos jugadores, "
				<< " seras guardado! :D" << endl;
			eliminarJugador(lista, pos);
		}
		else {
			cout << "La lista se encuentra llena! No se ha podido guardar tu resultado." << endl;
		}
	}
	//en caso de estar la lista con espacio O de QUERER METER UN jugador
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


bool eliminarJugador(tListaJugadores &lista, const int POS) {
	bool ok = false;

	for (int i = POS; i < lista.cont; i++)
		lista.jugador[i] = lista.jugador[i + 1];

	return (!ok);
}


int buscarConMenorPuntos(const tListaJugadores &LISTA) {
	int pos;
	unsigned int a = 0, b = 0;
	for (int i = 0; i < LISTA.cont; i++) {
		a = LISTA.jugador[i].pts;
		if (a <= b) {
			b = a;
			pos = i;
		}
	}
	return pos;
}
