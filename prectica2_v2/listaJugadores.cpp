#include "listaJugadores.h"

bool comprobarStr(const string &STR) {
  int i = 0;
  while (!isspace(STR[i]) && i < (int)STR.size())
    i++;
  return !isspace(STR[i]);
}

void creaLista(tListaJugadores &lista) {
  for (int i = 0; i < MAX_JUGADORES; i++) {
    lista.jugador[i].id = "";
    lista.jugador[i].pts = 0;
  }
}

bool cargar(tListaJugadores &lista) {
  tJugador player;
  bool ok = false;
  int ctd = 0;
  ifstream file;
  file.open(nombreListaJug);
  if (file.is_open()) {
    while (!file.eof() && ctd < MAX_JUGADORES) {
      file >> player.id;
      file >> player.pts;
      lista.jugador[ctd] = player;
      ctd++;
    }
    ok = true;
  }
  lista.cont = ctd;
  return ok;
}

void mostrar(const tListaJugadores &LISTA) {
  for (int i = 0; i < MAX_JUGADORES; i++) {
    if (LISTA.jugador[i].pts != 0)
      cout << showJugador(LISTA.jugador[i]);
  }
}

bool guardar(const tListaJugadores &LISTA) {
  ofstream file;
  file.open(nombreListaJug);
  int i = 0;
  while (LISTA.jugador[i].id != "") {
    showJugador(LISTA.jugador[i]);
    i++;
  }
  file.close();
  return true;
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
    if (!ok)
      cout << "Nombre incorrecto" << endl;
  } while (!ok);

  if (buscar(lista, id, pos)) {
    modificarJugador(lista.jugador[pos], puntos); // anadir pts
  } else {
    anadirJugador(lista, id, puntos);
    modificarJugador(lista.jugador[pos], puntos); // anadir pts
  }
}

bool buscar(const tListaJugadores &LISTA, const string ID, int &pos) {
  tJugador tempJug;
  pos = -1;
  int ini = 0, fin = LISTA.cont - 1, mitad;
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
  pos = ini;
  return encontrado;
}

tListaJugadores ordenarPorAscii_Burbuja(const tListaJugadores &LISTA) {
  //----------BURBUJA----------
  tListaJugadores listaNew = LISTA;
  int i = 0, cont = 0;
  int N = LISTA.cont;
  bool inter = true;
  while ((i < N - 1) && !inter && cont < LISTA.cont) {
    inter = false;
    for (int j = N - 1; j > i; j--) {
      if (listaNew.jugador[j] < listaNew.jugador[j - 1]) {
        tJugador tmp;
        tmp = listaNew.jugador[j];
        listaNew.jugador[j] = listaNew.jugador[j - 1];
        listaNew.jugador[j - 1] = tmp;
        inter = true;
      }
    }
    if (inter)
      i++;
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
      if (menor(listaNew.jugador[j], listaNew.jugador[j - 1])) {
        tJugador tmp;
        tmp = listaNew.jugador[j];
        listaNew.jugador[j] = listaNew.jugador[j - 1];
        listaNew.jugador[j - 1] = tmp;
        inter = true;
      }
    }
    if (inter)
      i++;
  }
  return listaNew;
}

void anadirJugador(tListaJugadores &lista, const string ID,
                   const unsigned int PTS) {
  // en caso de estar la lista llena..
  int pos;
  bool meter = false;
  if ((lista.cont >= MAX_JUGADORES)) {
    pos = buscarConMenorPuntos(lista);
    if (PTS > lista.jugador[pos].pts) {
      meter = true;
      cout << "La lista de jugadores esta llena, pero ya que tienes "
              "mas puntos que algunos jugadores,"
           << " seras guardado! :D" << endl;
      cout << "##eleminar_S" << endl;
      eliminarJugador(lista, pos);
      cout << "##eleminar_E" << endl;
    } else {
      cout << "La lista se encuentra llena! No se ha podido guardar tu "
              "resultado."
           << endl;
    }
  }

  if (meter) {
    cout << "##guardarHARD_STAR//" << endl;
    for (int i = lista.cont - 1; i > pos; i--)
      lista.jugador[i] = lista.jugador[i - 1];
    lista.jugador[pos].id = ID;
    lista.jugador[pos].pts = PTS;
    cout << "##guardarHARD_END//" << endl;
  }

  else if ((lista.cont < MAX_JUGADORES)) {
    cout << "##guardarSLOW_START//" << endl;
    lista.jugador[lista.cont].id = ID;
    lista.jugador[lista.cont].pts = PTS;
    lista.cont++;
    cout << "##guardarSLOW_END//" << endl;
  }
}

bool eliminarJugador(tListaJugadores &lista, const int POS) {
  bool ok = false;

  for (int i = POS; i < lista.cont - 1; i++)
    lista.jugador[i] = lista.jugador[i + 1];

  return (!ok);
}

int buscarConMenorPuntos(const tListaJugadores &LISTA) {
  int pos;
  unsigned int a = 0, b = 999999999;
  for (int i = 0; i < LISTA.cont; i++) {
    a = LISTA.jugador[i].pts;
    if (a <= b) {
      b = a;
      pos = i;
    }
  }
  return pos;
}
