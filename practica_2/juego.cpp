#include "pch.h"
#include "juego.h"

//cout << "El sudoku: " << juego.sudoku.fichero << ". De nivel: " << juego.sudoku.nivel 
//	<< ". Esta " << ((juego.terminado) ? "completo." : "incompleto.") << endl;

//
// preguntar si hace falta hacer comprobacion de ficheros:
//		-listaSudokus.txt
//		-sudoku9.txt
//
//

// Inicializa el juego
void iniciaJuego(tJuego & juego, const tSudoku &sudoku) {
	iniciaTablero(juego.tablero);
}

//carga del juego
bool cargaJuego(tJuego & juego, const tSudoku &sudoku) {
	bool ok;
	ok =cargarTablero(sudoku.fichero, juego.tablero);
	return ok;
}


int mostrarMenuPrincipal() { //mostrarMenuJugada
	tJuego juego;
	juego.sudoku.fichero = "sudoku1.txt";
	int op;
	do {
		clear();
		cout << "1. - Jugar:\n"
			<< "2. - Seleccionar sudoku\n"
			<< "0. - Salir\n";
		op = leerOpcion(0, 2);
		switch (op)
		{
		case 1:
			clear();
			iniciaJuego(juego, juego.sudoku);
			cargaJuego(juego, juego.sudoku);
			mostrarJuego(juego);
			break;
		case 2:
			
			break;
		case 0:
			cout << "\n\n\n\tAdios!";
			break;
		}
	} while (op != 0);
	return 0;
}

// Bucle del menu(texto) del juego(proceso) de un sudoku.
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
		<< "6. - Resolver el sudoku\n"
		<< "0. - Abortar la resolucion y volver al menu principal\n";
	op = leerOpcion(0, 6);
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
		case 0:
			colorStr("\n\n\nGracias por jugar!", BLANCO);
			break;
	}
return op;
}


//Procesado de opcion seleccionada del menu del juego.
void mostrarJuego(tJuego juego) {//(const tJuego &juego)
	int op, x, y, c;
	short int error;
	const string fallo = "\t\tFallo.\n";
	const string e_100 = "Error al PONER un digito en una casilla RELLANA\n";
	const string e_101 = "Error al BORRAR un digito en una casilla FIJA\n";
	const string e_200 = "Error al BORRAR un digito en una casilla VACIA\n";
	const string e_201 = "Error al BORRAR un digito en una casilla FIJA\n";
	/* ERRORES:
		100 - Error al PONER un digito en una casilla RELLANA
		101 - Error al PONER un digito en una casilla FIJA
		200 - Error al BORRAR un digito en una casilla VACIA
		201 - Error al BORRAR un digito en una casilla FIJA*/
	do {
		error = 0;
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
			if (!ponerNum(juego.tablero, x, y, c, error)) {
				colorStr(fallo, ROJO);
				if (error == 100)
					colorStr(e_100, ROJO);
				else if (error == 101)
					colorStr(e_101, ROJO);

			}
			break;
		case 3:
			//Borrar numero
			if (!borraNum(juego.tablero, x, y, error)) {
				colorStr(fallo, ROJO);
				if (error == 200)
					colorStr(e_200, ROJO);
				else if (error == 201)
					colorStr(e_201, ROJO);
			}
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
		
		case 6:
			//Resolver el sudoku
			if(!resolver(juego.tablero, 0))
				colorStr(fallo, ROJO);
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
	cin.sync();
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
			op= str[0] - '0';
			if ((op >= inf) && (op <= sup))
				ok = true;
		}
		if (!ok) {
			cout << "Opcion incorrecta." << endl;
		}
	} while (!ok);

	return op;
}

void clear() {
	system("cls");
} 

