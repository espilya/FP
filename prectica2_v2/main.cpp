

#include "listaSudokus.h"

//
//	bool guardar(const tListaJugadores & LISTA)
//		- para que devolver booleano?
//		- por si ya existe un archivo con tal nombre?
//
//	int buscarPos(const tListaSudokus &LISTA, const tSudoku &SUDOKU) {
//		- Y POR Q NO INSERTAR AL FINAL??
//		- hacerla por nivel o nombre?
//		- ahora hecha por nombre..
//

//					TO DO
//			listaJSudokus: buscarPos()
int main() {
  int op, op2;
  bool okListaSud = false, okListaJug = false;
  tListaSudokus listaSud;
  tListaJugadores listaJug;
  tJuego juego;
  creaLista(listaSud); // iniciamos lista de sudoku
  creaLista(listaJug); // iniciamos lista de jugadores
  iniciaJuego(juego);  // iniciamos juego.
  if (cargar(listaSud))
    okListaSud = true;
  if (cargar(listaJug))
    okListaJug = true;

  listaJug = ordenarPorAscii(listaJug);

  if (okListaSud && okListaJug) // cargamos listaSudoku
    do {
      cout << "1. - Jugar\n"
           << "2. - Ver jugadores ordenados por identificador\n"
           << "3. - Ver jugadores ordenados por puntos\n"
           << "4. - Incorporar sudoku\n"
           << "0. - Salir" << endl;
      op = leerOpcion(0, 4);
      clear();
      switch (op) {
      case 1:
        op2 = menuListaSudokus(listaSud, juego);
        if (op2 != 0)
          startJuego(juego);

        break;
      case 2:
        cout << "Lista de jugadores:\n";
        mostrar(listaJug);
        pausa();
        break;
      case 3:
        mostrar(ordenarPorRanking(listaJug));
        pausa();
        break;
      case 4:
        registrarSudoku(listaSud);
        mostrar(listaSud);
        pausa();
        break;
      }

      clear();
    } while (op != 0);

  else if (!okListaSud)
    colorStr("Error al cargar 'listaSudokus.txt'.\n", ROJO);
  else if (!okListaJug)
    colorStr("Error al cargar 'listaJugadores.txt'.\n", ROJO);
  return 0;
}
