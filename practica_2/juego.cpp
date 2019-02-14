#include "pch.h"
#include "juego.h"
#include <stdio.h>
#include <string.h>

//cout << "El sudoku: " << juego.sudoku.fichero << ". De nivel: " << juego.sudoku.nivel 
//	<< ". Esta " << ((juego.terminado) ? "completo." : "incompleto.") << endl;



// Inicializa el juego
void iniciaJuego(tJuego & juego, const tSudoku &sudoku) {
		//recibe en sudoku la información del sudoku elegido para jugar e inicializa el
		//parámetro juego a un juego no acabado con dicha información como
		//registro del sudoku a jugar y con un tablero inicializado según se ha
		//indicado en el módulo anterior.
	iniciaTablero(juego.tablero);
}

//carga del juego
bool cargaJuego(tJuego & juego, const tSudoku &sudoku) {
	return cargarTablero(sudoku.fichero, juego.tablero);
}

//Mostrar menu de acciones para jugar un sudoku
//Si alguna carga no tiene éxito la aplicación deberá finalizar.
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
			iniciaJuego(juego, sudoku);
			cargaJuego(juego, sudoku);
			do {
				mostrarJuego(juego);
			} while (JugarUnSudoku(sudoku) != 0);
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
int JugarUnSudoku(const tSudoku &sudoku) {
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
			<< "0. - Abortar la resolución y volver al menu principal\n";
		cin >> op;
		return op;
}


//muestra el juego (procesado de opcion del menu del juego)
void mostrarJuego(tJuego juego) {//(const tJuego &juego)
	/*muestra por pantalla la
		información del sudoku que se va a jugar así como el tablero del mismo.
		pic.Tablero de partida
		*/

	int op, x, y, c;
	do {
		dibujarTablero(juego.tablero);
		op = JugarUnSudoku(juego.sudoku);
		switch ((int)op)
		{
		case 1://Posibles casos
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y 'Y':\n>";
			cin >> y;
			x--;
			y--;
			mostrarPosibles(juego.tablero, x, y);
			break;
		case 2: //Introducir numero
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y 'Y':\n>";
			cin >> y;
			cout << "Introduce el numero:\n>";
			cin >> c;
			x--;
			y--;
			if (!ponerNum(juego.tablero, x, y, c))
				cout << "Fallo" << endl;
			break;
		case 3://Borrar numero
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y 'Y':\n>";
			cin >> y;
			x--;
			y--;
			if (!borraNum(juego.tablero, x, y))
				cout << "Fallo" << endl;
			break;
		case 4:
			iniciaJuego(juego, juego.sudoku);
			cargaJuego(juego, juego.sudoku);
			break;
		case 5:
			rellenarSimples(juego.tablero);
			break;
		case 0:
			cout << "\n\n\n\tAdios!";
			break;
		default:
			cout << "Opcion incorrecta." << endl;
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

