#include "juego.h"

//cout << "El sudoku: " << juego.sudoku.fichero << ". De nivel: " << juego.sudoku.nivel 
//	<< ". Esta " << ((juego.terminado) ? "completo." : "incompleto.") << endl;


// Inicializa el juego
void iniciaJuego(tJuego & juego, const tSudoku &sudoku) {
		//recibe en sudoku la información del sudoku elegido para jugar e inicializa el
		//parámetro juego a un juego no acabado con dicha información como
		//registro del sudoku a jugar y con un tablero inicializado según se ha
		//indicado en el módulo anterior.
	cargarTablero(sudoku.fichero, juego.tablero);
}

//Mostrar menu de acciones para jugar un sudoku
//Si alguna carga no tiene éxito la aplicación deberá finalizar.
int mostrarMenuPrincipal() { //mostrarMenuJugada
	tSudoku sudoku;
	tJuego juego;
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
}

// Bucle del juego de un sudoku
int JugarUnSudoku(const tSudoku &sudoku) {
	//dada la información del
	//	sudoku elegido lleva a cabo todas las acciones correspondientes a haber
	//	elegido la opción 1 de esta versión y devuelve la puntuación obtenida por el
	//	jugador(0 si aborta la resolución antes de rellenar el tablero o los puntos
	//		asociados al sudoku elegido en caso de resolverlo).
	int op;
		cout << "1. - Ver posibles valores de una casilla vacía\n"
			<< "2. - Colocar valor en una casilla\n"
			<< "3. - Borrar valor de una casilla\n"
			<< "4. - Reiniciar el tablero\n"
			<< "5. - Autocompletar celdas simples\n"
			<< "0. - Abortar la resolución y volver al menú principal\n";
		cin >> op;
		return op;
}


//muestra el juego
void mostrarJuego(const tJuego &juego) {
	/*muestra por pantalla la
		información del sudoku que se va a jugar así como el tablero del mismo.*/
	int op, x, y, c;
	while (op != 0) {
		dibujarTablero(juego.tablero);
		JugarUnSudoku(juego.sudoku);
		switch ((int)op)
		{
		case 1:
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y 'Y':\n>";
			cin >> y;
			mostrarPosibles(juego.tablero, x, y);
			break;
		case 2:
			cout << "Introduce las coodenadas 'X':\n>";
			cin >> x;
			cout << " y 'Y':\n>";
			cin >> y;
			ponerNum(juego.tablero, x, y, c);
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
	}

}

void pausa() {

}

int leerOpcion(int inf, int sup) {

}


//carga del juego
bool cargaJuego(tJuego & juego, const tSudoku &sudoku) {
	//actualiza el tablero del parámetro juego con el contenido del archivo cuyo
	//	nombre figura en el parámetro de tipo tSudoku recibido.
	iniciaTablero(juego.tablero);
	cargarTablero(sudoku.fichero, juego.tablero);
}