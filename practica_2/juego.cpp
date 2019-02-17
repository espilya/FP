#include "pch.h"
#include "juego.h"

//cout << "El sudoku: " << juego.sudoku.fichero << ". De nivel: " << juego.sudoku.nivel 
//	<< ". Esta " << ((juego.terminado) ? "completo." : "incompleto.") << endl;

//
// reinuciar no reinicia si hacer autocompletar
//
//
//

// Inicializa el juego
void iniciaJuego(tJuego & juego, const tSudoku &sudoku) {
	iniciaTablero(juego.tablero);
}

//carga del juego
bool cargaJuego(tJuego & juego, const tSudoku &sudoku) {
	return cargarTablero(sudoku.fichero, juego.tablero);
}


int mostrarMenuPrincipal() { //mostrarMenuJugada
	tSudoku sudoku;
	tJuego juego;
	sudoku.fichero = "sudoku1.txt";
	float op;
	do {
		cout << "1. - Jugar:\n"
			<< "2. - Ver jugadores ordenados por identificador\n"
			<< "3. - Ver jugadores ordenados por puntos\n"
			<< "4. - Incorporar sudoku\n"
			<< "0. - Salir\n";
		cin >> op;
		switch ((int)op)
		{
		case 1:
			clear();
			iniciaJuego(juego, sudoku);
			cargaJuego(juego, sudoku);
			mostrarJuego(juego);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 0:
			cout << "\n\n\n\tAdios!";
			break;
		default:
			cout << "Opcion incorrecta." << endl;
		}
	} while (op != 0);

	return 0;
}

// Bucle del menu del juego(proceso) de un sudoku
int JugarUnSudoku(const tSudoku &sudoku, int &x, int &y, int &c) {
	//dada la información del
	//	sudoku elegido lleva a cabo todas las acciones correspondientes a haber
	//	elegido la opción 1 de esta versión y devuelve la puntuación obtenida por el
	//	jugador(0 si aborta la resolución antes de rellenar el tablero o los puntos
	//		asociados al sudoku elegido en caso de resolverlo).
	int op;
		cout << "1. - Ver posibles valores de una casilla vacia\n"
			<< "2. - Colocar valor en una casilla\n"
			<< "3. - Borrar valor de una casilla\n"
			<< "4. - Reiniciar el tablero\n"
			<< "5. - Autocompletar celdas simples\n"
			<< "0. - Abortar la resolucion y volver al menu principal\n";
		cin >> op;
		switch ((int)op)
		{
		case 1://Posibles casos
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y las coodenadas 'Y':\n>";
			cin >> y;
			x--;
			y--;
			break;
		case 2: //Introducir numero
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y las coodenadas 'Y':\n>";
			cin >> y;
			cout << "Introduce el numero:\n>";
			cin >> c;
			x--;
			y--;
			break;
		case 3://Borrar numero
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y las coodenadas 'Y':\n>";
			cin >> y;
			x--;
			y--;
			break;
		case 4:
			break;
		case 5:
			break;
		case 0:
			cout << "\n\n\n\tAdios!";
			break;
		default:
			cout << "Opcion incorrecta." << endl;
		}
		return op;
}


//muestra el juego (procesado de opcion del menu del juego)
void mostrarJuego(tJuego juego) {//(const tJuego &juego)
	int op, x, y, c;
	do {
		dibujarTablero(juego.tablero);
		op = JugarUnSudoku(juego.sudoku, x, y, c);
		switch (op)
		{
		case 1:
			//Posibles casos
			mostrarPosibles(juego.tablero, x, y);
			break;
		case 2: 
			//Introducir numero
			if (!ponerNum(juego.tablero, x, y, c))
				cout << "Fallo" << endl;
			break;
		case 3:
			//Borrar numero
			if (!borraNum(juego.tablero, x, y))
				cout << "Fallo" << endl;
			break;
		case 4:
			//Reiniciar el tablero
			iniciaJuego(juego, juego.sudoku);
			cargaJuego(juego, juego.sudoku);
			break;
		case 5:
			//Autocompletar celdas simples
			rellenarSimples(juego.tablero);
			break;
		}
		pausa();
		clear();
	} while (op != 0);

}

void pausa() {
	string str;
	cin.sync();
	cin >> str;
}

int leerOpcion(int inf, int sup) {
	return 0;
}

void clear() {
	system("cls");
} 

