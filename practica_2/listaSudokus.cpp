#include "pch.h"
#include "listaSudokus.h"

//
//				hacer que en mostrarListaSudokus se vean los vacios o no?
//
//


void creaListaVacia(tListaSudokus &lista, tJuego & juego) {
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		lista.array[i].fichero = "VACIO";
		lista.array[i].nivel = EMPTY;
	}
	juego.sudoku.fichero = "VACIO";
	lista.cont = 0;
}

bool cargarListaSudokus(tListaSudokus & lista) {
	bool ok = false;
	string nombre;
	int nivel, ctd = 0;
	ifstream file;
	file.open(listaSudoku);
	if (file.is_open()) {
		while ((!file.eof()) && (ctd < MAX_SUDOKUS)) {
			file >> nombre;
			file >> nivel;
			//cout << nombre << '\t' << nivel << endl;
			lista.array[ctd].fichero = nombre;
			lista.array[ctd].nivel = (tNivelSudoku)(nivel-1);
			ctd++;
		}
		lista.cont = ctd;
		ok = true;
	}
	return ok;
}

void mostrarListaSudokus(const tListaSudokus &lista) {
	string tempStr = "sudokuX.txt";
	cout << "Los sudokus disponibles son los siguientes:" << endl;
	colorStr("# ", VERDE_OSC);
	colorStr("Nombre:", MAGENTA_OSC);
	colorStr("\tNivel:\n", AMARILLO_OSC);
	for (int i = 0; i < MAX_SUDOKUS; i++) {
		tempStr = lista.array[i].fichero;
		if (tempStr!= "VACIO") {
			colorStr(to_string(i+1) + " ", VERDE_OSC);
				tempStr[tempStr.size() - 4] = ' ';
				tempStr = tempStr.substr(0, tempStr.size() - 3);
				swap(tempStr[6], tempStr[7]);
			colorStr(tempStr, MAGENTA_OSC);
			switch (lista.array[i].nivel)
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

int  menuListaSudokus(const tListaSudokus & lista, tJuego & juego) {
	int op;
	cout << "Seleciona un sudoku." << endl;
	mostrarListaSudokus(lista);
	cout << "Introduze el numero del sudoku:\n>";
	op = leerOpcion(0, (lista.cont));
	if(op !=0)
		juego.sudoku.fichero = lista.array[op - 1].fichero;
	clear();
	return op;
}