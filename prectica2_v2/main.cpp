

#include "listaSudokus.h"

//					DUDAS:
//	->bool guardar(const tListaJugadores & LISTA)
//			-Martes
//
//	->int buscarPos(const tListaSudokus &LISTA, const tSudoku &SUDOKU) {
//			-leer pdf
//
//	->hacer probar abrir el nuevo sudoku incorporado?

//					OPCIONALES:
//			->Preguntar con que algoritmo ordenar a los jugadores

//					TO DO:
//			->Eliminar jugador///
//			->primero probar si es posible puntuar(guardar score) y luego preguntar nombre
//			->Mejorar el reinicio del tablero -- tampoco es muy importante. Con que funcione.. :)
//
//		+Ordenacion por ID:
// pepe                    101
// pepe                    100
// pepe                    99

int main() {
  int op, op2;
  bool okListaSud = false, okListaJug = false;
  tListaSudokus listaSud;
  tListaJugadores listaJug;
  tJuego juego;
  creaLista(listaSud); // iniciamos lista de sudoku
  creaLista(listaJug); // iniciamos lista de jugadores
  
  if (cargar(listaSud))
    okListaSud = true;
  if (cargar(listaJug))
    okListaJug = true;


  if (okListaSud && okListaJug) // cargamos listaSudoku
    do {
		iniciaJuego(juego);  // iniciamos juego
		listaJug = ordenarPorAscii_Burbuja(listaJug);
      cout << "1. - Jugar\n"
           << "2. - Ver jugadores ordenados por identificador\n"
           << "3. - Ver jugadores ordenados por puntos\n"
           << "4. - Incorporar sudoku\n"
           << "5. - Eliminar sudoku\n"
           << "0. - Salir" << endl;
      op = leerOpcion(0, 5);
      clear();
      switch (op) {
      case 1:
        op2 = menuListaSudokus(listaSud, juego);
        if (op2 != 0) {
          startJuego(juego);
          if (juego.guardar) {
            puntuarJugador(listaJug, juego.sudoku.nivel);
            mostrar(listaJug);
            guardar(listaJug);
            pausa();         
          }
        }

        break;
      case 2:
        cout << "Lista de jugadores:\n";
		listaJug = ordenarPorAscii_Burbuja(listaJug);
        mostrar(ordenarPorAscii_Burbuja(listaJug));
        pausa();
        break;
      case 3:
		 cout << "Lista de jugadores:\n";
        mostrar(ordenarPorRanking_Burbuja(listaJug));
        pausa();
        break;
      case 4:
        registrarSudoku(listaSud);
        mostrar(listaSud);
        pausa();
        break;
      case 5:
        eliminarSudoku(listaSud);
        mostrar(listaSud);
        pausa();
        break;
	  case 6:
		  borrarJugador(lista, )
		  mostrar(listaJug);
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
