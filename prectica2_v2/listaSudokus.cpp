#include "pch.h"
#include "listaSudokus.h"

//
//


void creaLista(tListaSudokus &lista) {
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		lista.array[i].fichero = "VACIO";
		lista.array[i].nivel = 0;
	}
	lista.cont = 0;
}

bool cargar(tListaSudokus & lista) {
	bool ok = false;
	string nombre;
	int nivel, ctd = 0;
	ifstream file;
	file.open(listaSudoku);
	if (file.is_open()) {
		while ((!file.eof()) && (ctd < MAX_SUDOKUS) && (file >> nombre) && (nombre != "")) {
			file >> nivel;
			//cout << nombre << '\t' << nivel << endl;
			lista.array[ctd].fichero = nombre;
			lista.array[ctd].nivel = nivel -1;
			ctd++;
		}
		lista.cont = ctd;
		ok = true;
	}
	return ok;
}

int  menuListaSudokus(const tListaSudokus & LISTA, tJuego & juego) {
	int op;
	cout << "Seleciona un sudoku." << endl;
	mostrarListaSudokus(LISTA);
	cout << "Introduze el numero del sudoku:\n>";
	op = leerOpcion(0, (LISTA.cont));
	if (op != 0) {
		juego.sudoku.fichero = LISTA.array[op - 1].fichero;
		juego.sudoku.nivel = LISTA.array[op - 1].nivel;
		juego.esSalvado = false;
	}
	clear();
	return op;
}

void mostrar(const tListaSudokus &LISTA) {
	clear();
	string tempStr = "sudokuX.txt";
	cout << "Los sudokus disponibles son los siguientes:" << endl;
	colorStr("# ", VERDE_OSC);
	colorStr("Nombre:", MAGENTA_OSC);
	colorStr("\tNivel:\n", AMARILLO_OSC);
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		tempStr = LISTA.array[i].fichero;
		if (tempStr!= "VACIO") {
			colorStr(to_string(i+1) + " ", VERDE_OSC);
			if (tempStr.find(".txt"))
			tempStr = tempStr.substr(0, tempStr.size() - 4);
			colorStr(tempStr, MAGENTA_OSC);
			switch (LISTA.array[i].nivel)
			{
			case 0:
				colorStr("\tFacil", AMARILLO_OSC);
				break;
			case 1:
				colorStr("\tMedio", AMARILLO_OSC);
				break;
			case 2:
				colorStr("\tDificil", AMARILLO_OSC);
				break;
			case 3:
				colorStr("\tVacio", AMARILLO_OSC);
				break;
			}
			cout << endl;
		}
	}
	colorStr("0. Salir\n", CYAN_OSC);
}

//------------VERSION 2------------

bool guardar(const tListaSudokus & lista) {
	ofstream file;
	int i = 0;
	file.open(listaSudoku);
	while(i<MAX_SUDOKUS && lista.array[i].fichero != "VACIO"){
		file << lista.array[i].fichero << '\t' << lista.array[i].nivel << '\n';
		i++;
	}
	return true;
}

bool registrarSudoku(tListaSudokus & lista) {
	int pts;
	bool ok = false;
	string nombreFich;
	cout << "Introduzca el nombre del nuevo sudoku:\n>";
	do {
		getline(cin, nombreFich);
		if (!comprobarStr(nombreFich))
			cout << "Nombre incorrecto" << endl;
	} while (!comprobarStr(nombreFich));
	cout << "Introduzca los puntos del sudoku:\n>";
	cin >> pts;
	if ((lista.cont < MAX_SUDOKUS)  && (!buscarFichero(lista, nombreFich))) {
		lista.cont++;
		lista.array[lista.cont].fichero = nombreFich;
		lista.array[lista.cont].nivel = pts;
		ok = true;
	}
	return ok;
}
//solicita los datos de un nuevo sudoku(nombre del fichero y puntos que permite conseguir) y si
//no existe un sudoku en lista con igual nombre de fichero lo inserta en la
//posición adecuada respetando el orden existente.Se devuelve un booleano
//que indica si se pudo registrar un nuevo sudoku, para lo cual también hay
//que tener en cuenta si la lista está o no llena.

bool buscarFichero(const tListaSudokus & lista, string nombreFich) {
	int i = 0, x = lista.cont;
	bool encontrado = false;
	while ((x--> 0) && !encontrado) {
		if (nombreFich == lista.array[i].fichero)
			encontrado = true;
		i++;
	}
	return encontrado;
}
//devuelve un boleano que indica si existe o no un sudoku en
//lista con nombre de fichero igual a nombreFich.

int buscarPos(const tListaSudokus & lista, const tSudoku &sudoku) {
	//Y POR Q NO INSERTAR AL FINAL??

	return 0;
}
//devuelve la posición de lista en la que debería insertarse sudoku
//para respetar el orden existente en la lista. Debe implementar una búsqueda binaria.
