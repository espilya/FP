
#include "juego.h"

void iniciaJuego(tJuego &juego) {
  juego.esSalvado = false;
  juego.sudoku.nivel = 0;
  juego.sudoku.fichero = "VACIO";
  juego.sudoku.fichero = false;
  iniciaTablero(juego.tablero);
}

bool cargaJuego(tJuego &juego) {
  bool ok = false;
  bool esPartidaSalvada = false;
  if (juego.sudoku.fichero != "VACIO")
    ok = cargarTablero(juego.sudoku.fichero, juego.tablero, esPartidaSalvada);
  if (juego.esSalvado || esPartidaSalvada)
    salvarJuego(juego);
  return ok;
}

void startJuego(tJuego &juego) { // mostrarMenuJugada
  clear();
  if (cargaJuego(juego))
    mostrarJuego(juego);
  else if (errorAbrirFichero(juego.sudoku.fichero))
    mostrarJuego(juego);
}

int menuJugarSudoku(int &x, int &y, int &c) {
  const int inf_a = 0;
  const int sup_a = 8;
  const int inf_1 = 1;
  const int sup_9 = 9;
  int op;
  cout << "1. - Ver posibles valores de una casilla vacia\n"
       << "2. - Colocar valor en una casilla\n"
       << "3. - Borrar valor de una casilla\n"
       << "4. - Reiniciar el tablero\n"
       << "5. - Autocompletar celdas simples\n"
       << "6. - Resolver el sudoku\n"
       << "7. - Salvar partida actual\n"
       << "8. - Cargar partida anterior\n"
       << "0. - Abortar la resolucion y volver al menu principal\n";
  op = leerOpcion(inf_a, sup_a);
  switch ((int)op) {
  case 1: // Posibles casos
    cout << "Introduce las coodenadas 'X':\n>";
    x = leerOpcion(inf_1, sup_9);
    cout << " y las coodenadas 'Y':\n>";
    y = leerOpcion(inf_1, sup_9);
    x--;
    y--;
    break;
  case 2: // Introducir numero
    cout << "Introduce las coodenadas 'X':\n>";
    x = leerOpcion(inf_1, sup_9);
    cout << " y las coodenadas 'Y':\n>";
    y = leerOpcion(inf_1, sup_9);
    cout << "Introduce el numero:\n>";
    c = leerOpcion(inf_1, sup_9);
    x--;
    y--;
    break;
  case 3: // Borrar numero
    cout << "Introduce las coodenadas 'X':\n>";
    x = leerOpcion(inf_1, sup_9);
    cout << " y las coodenadas 'Y':\n>";
    y = leerOpcion(inf_1, sup_9);
    x--;
    y--;
    break;
  case 0:
    // colorStr("\n\n\nGracias por jugar!", BLANCO);
    break;
  }
  return op;
}

void mostrarJuego(tJuego &juego) { //(const tJuego &juego)
  int op, x, y, c;
  bool jugGuardado = false;
  short int error;
  string fileStr;
  const string fallo = "\t\tFallo\n";
  const string e_100 = "Error al PONER un digito en una casilla RELLANA.\n";
  const string e_101 = "Error al BORRAR un digito en una casilla FIJA.\n";
  const string e_102 = "Error al PONER un valor IMPOSIBLE en una casilla.\n";
  const string e_200 = "Error al BORRAR un digito en una casilla VACIA.\n";
  const string e_201 = "Error al BORRAR un digito en una casilla FIJA.\n";
  /* ERRORES:
          100 - Error al PONER un digito en una casilla RELLANA
          101 - Error al PONER un digito en una casilla FIJA
          200 - Error al BORRAR un digito en una casilla VACIA
          201 - Error al BORRAR un digito en una casilla FIJA*/
  do {
    error = 0;
    fileStr = juego.sudoku.fichero;
    if (fileStr.find(".txt"))
      fileStr = fileStr.substr(0, fileStr.size() - 4);
    cout << "\t  ";
    colorStr(fileStr, AMARILLO_OSC);
    cout << " de : ";
    colorStr(to_string(juego.sudoku.nivel), AMARILLO_OSC);
    cout << " puntos\n";

    dibujarTablero(juego.tablero);
    op = menuJugarSudoku(x, y, c);
    switch (op) {
    case 1:
      // Posibles casos
      mostrarPosibles(juego.tablero, x, y);
      break;
    case 2:
      // Introducir numero
      if (!ponerNum(juego.tablero, x, y, c, error)) {
        colorStr(fallo, ROJO);
        if (error == 100)
          colorStr(e_100, ROJO);
        else if (error == 101)
          colorStr(e_101, ROJO);
        else if (error = 102)
          colorStr(e_102, ROJO);
      }
      break;
    case 3:
      // Borrar numero
      if (!borraNum(juego.tablero, x, y, error)) {
        colorStr(fallo, ROJO);
        if (error == 200)
          colorStr(e_200, ROJO);
        else if (error == 201)
          colorStr(e_201, ROJO);
      }
      break;
    case 4:
      // Reiniciar el tablero
      if (!juego.esSalvado) {
        iniciaTablero(juego.tablero);
        bool temp = cargaJuego(juego);
        jugGuardado = false;
      } else {
        salvarJuego(juego, true);
      }
      break;
    case 5:
      // Autocompletar celdas simples
      rellenarSimples(juego.tablero);
      break;
    case 6:
      // Resolver el sudoku
      if (!resolver(juego.tablero, 0))
        colorStr(fallo, ROJO);
      break;
    case 7:
      // Salvar
      guardarJuego(juego);
      break;
    case 8:
      // Salvar
      salvarJuego(juego);
      break;
    }
    if (op != 0 && op != 8)
      pausa();
    if (tableroLleno(juego.tablero) && !jugGuardado){
      puntuarJugador(listaJug, juego.sudoku.nivel);
      jugGuardado = true;
    }
    clear();
  } while (op != 0);
}

void pausa() {
  // string str;
  // cin.sync();
  // cout << "\nIntroduze un caracter para seguir.." << endl;
  // cin >> str;
  cout << endl;
  system("pause");
}

int leerOpcion(int inf, int sup) {
  string str;
  bool ok = false;
  int op = -1;

  do {
    cin.sync();
    cin.clear();
    getline(cin, str);

    if (isdigit(str[0]) && (str.size() == 1)) {
      op = str[0] - '0';
      if ((op >= inf) && (op <= sup))
        ok = true;
    }
    if ((!ok) && (str.size() > 0)) {
      cout << "Opcion incorrecta." << endl;
    }
  } while (!ok);
  return op;
}

void clear() { system("cls"); }

void guardarJuego(const tJuego &juego) {
  bool continuar = true;
  string nivel;
  if (tableroLleno(juego.tablero)) {
    cout << "Seguro que desea guardar un juego TERMINADO, con todas las "
            "casillas completas?\n 1. Si\n 0. No\n"
         << endl;
    continuar = leerOpcion(0, 1);
  } else if (tableroSoloFijo(juego.tablero)) {
    cout << "Seguro que desea guardar un juego SIN EMPEZAR,?\n 1. Si\n 0. No\n"
         << endl;
    continuar = leerOpcion(0, 1);
  }
  if (continuar) {
    ofstream file;
    string str;
    cout << "Introduce el nombre del archivo a salvar:\n>";
    cin >> str;
    file.open(str);
    file << "NO TOCAR\nPrimero van los valores Fijos y mas abajo los valores "
            "Rellenos.\n\n";
    for (int j = 0; j < DIMENSION; j++) {
      for (int i = 0; i < DIMENSION; i++) {
        if (juego.tablero[i][j].estado == FIJA) {
          file << juego.tablero[i][j].numero;
        } else {
          file << ' ';
        }
      }
      file << '\n';
    }
    file << "\n\n"
         << ":P\n";
    for (int j = 0; j < DIMENSION; j++) {
      for (int i = 0; i < DIMENSION; i++) {
        if (juego.tablero[i][j].estado == RELLENO) {
          file << juego.tablero[i][j].numero;
        } else {
          file << ' ';
        }
      }
      file << '\n';
    }
    file << juego.sudoku.nivel;
    file.close();
  }
}

void salvarJuego(tJuego &juego, bool reiniciar) {
  bool ok = true;
  ;
  char ch;
  int tempInteger;
  string temp;
  string userInput;
  ifstream file;
  do {
    if (!reiniciar) {
      colorStr("(si desea cargar un sudoku de la lista inicial, por favor, "
               "pulse '0', salga al menu inicial, y cargelo desde el menu)\n",
               GRIS);
      colorStr("Introduce el nombre del archivo a cargar:\n", GRIS);
      cout << '>';
      if (!ok)
        cout << "Nombre incorrecto. \nPara cancelar introduzca '0'." << endl;
      getline(cin, userInput);
    } else
      userInput = juego.sudoku.fichero;
    file.open(userInput);
    ok = file.is_open();
    clear();
  } while (!ok && userInput != "0");
  if (userInput != "0") {
    juego.sudoku.fichero = userInput;
    iniciaTablero(juego.tablero);
    for (int a = 0; a < 3; a++)
      getline(file, temp);

    for (int j = 0; j < 9; j++) {
      for (int i = 0; i < 9; i++) {
        file.get(ch);
        rellenaCasilla(juego.tablero[i][j], ch, true);
      }
      getline(file, temp);
    }

    do {
      getline(file, temp);
    } while (temp != ":P");

    for (int j = 0; j < 9; j++) {
      for (int i = 0; i < 9; i++) {
        file.get(ch);
        if (ch != ' ')
          rellenaCasilla(juego.tablero[i][j], ch);
      }
      getline(file, temp);
    }
    file >> tempInteger;
    juego.sudoku.nivel = tempInteger;
    calcElementosPosibles(juego.tablero);
    juego.esSalvado = true;
  }
}

bool errorAbrirFichero(const string &fichero) {
  int temp;
  bool continuarConVacio = false;
  colorStr("-ERROR AL CARGAR FICHERO-\n", ROJO);
  if (fichero == "VACIO") {
    colorStr("Desea continuar con el tablero VACIO?\n 1. Si.\n 0. No.\n");
    continuarConVacio = leerOpcion(0, 1);
    clear();
  } else {
    cout << "El fichero ";
    colorStr(fichero, AMARILLO_OSC);
    cout << " no se pudo encontrar. Imposible cargar el sudoku." << endl;
    cout << "Pulse '1' para continuar.\n>";
    temp = leerOpcion(1, 1);
  }
  return continuarConVacio;
}
