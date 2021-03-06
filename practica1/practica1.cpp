
	
//		MICHAL FITAL
//		ILYA LAPSHIN
//			Grupo 27


#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <sstream>

using namespace std;

const int dim40 = 40;
const int dim14 = 14;
const int dim8 = 8;
//------------------------------------INICIO-->DECLARACIONES DE TIPOS-----------------------------------
//------------------------------------------------------------------------------------------------------

typedef double tBaraja[dim40]; //array de [40] contiene la baraja
typedef double tCartasCogidas[dim14]; //array para contar las cartas cogidas modoD
typedef int tTipoDeCartas[dim8]; // array para contar los tipos de cartas (1..7 y 0.5)

//Hicimos tres estructuras, y metimos dos en una
typedef struct {
	tCartasCogidas cartas = { 0 };        //array para contener las cartas que cogio el jugador
	tTipoDeCartas tipoDeCartas = { 0 };    //array para contener los tipos de cartas(de valor 0.5, de valor 7,..)
	int marcador = 0;                //marcador

} tCartasHumano;

typedef struct {
	tCartasCogidas cartas = { 0 };        //array para contener las cartas que cogio la maqina
	tTipoDeCartas tipoDeCartas = { 0 };    //array para contener los tipos de cartas(de valor 0.5, de valor 7,..)
	int marcador = 0;

} tCartasMaquina;

typedef struct {
	tBaraja barajaD = { 0 }; // array del mazo modoD
	tTipoDeCartas tipoDeCartas = { 0 }; //del mazo modoD
	int marcador=40; //empezamos desde el final
	int numPartida = 0; //contador del numero de partidas
	double puntosHumano = 0; 
	double puntosMaquina = 0;
	bool ganadorMaquina = false; // boool que indica si el humano se paso por puntos(lo que significa la victoria de la maquina)
	tCartasHumano cartasHumano;
	tCartasMaquina cartasMaquina;
} tConjuntoCartas;
//------------------------------------------------------------------------------------------------------
//-------------------------------------FIN-->DECLARACIONES DE TIPOS-------------------------------------


//-----------------------------------INICIO-->PROTOTIPOS DE FUNCIONES-----------------------------------
//------------------------------------------------------------------------------------------------------

void readFile(tBaraja Baraja);//Leemos el archivo y ponemos las cartas en un array, para no tener el archivo abierto todo el rato
void modoA(int numCartas, const tBaraja Baraja); 
void modoBhumano(int numCartas, const tBaraja Baraja); 
void modoBmaquina(int numCartas, const tBaraja Baraja, double puntosJugador, int marcadorBaraja, bool ganadorMaquina); 
void determinaGanador(double puntosJugador, double puntosMaquina, bool ganadorMaquina = false); 
void modoChumano(const tBaraja Baraja);
void modoCmaquina(double puntosJugador, int ultimaCartaLeida, const tBaraja Baraja, bool ganadorMaquina);
void cartasRestantes(tTipoDeCartas cartasRest, const tBaraja Baraja, int cartasALeer); //calculamos la ctd de cartas en la baraja y las metemos en un array
bool esProbablePasarse(double puntosMaquina, const tTipoDeCartas cartasRest, int marcadorBaraja); //calculamos la prob de pasarse. en caso de q es probable devolvemos "false"

void inicializa(tConjuntoCartas &conjuntoCartas);// inicializamos el modoD y rellenamos la baraja con cartas
void crearMazo(tConjuntoCartas &conjuntoCartas); //barajeamos el mazo
void sacarCarta(tConjuntoCartas &conjuntoCartas, double &carta);//sacamos la carta del mazo
void annadirCarta(tConjuntoCartas &conjuntoCartas, double carta, bool humano); //anadimos la carta a la baraja del humano o de la maquina(segun el bool)
void modoDhumano(tConjuntoCartas &conjuntoCartas);
void modoDmaquina(tConjuntoCartas &conjuntoCartas);
void tipoCartasJugadores(tConjuntoCartas &conjuntoCartas, double carta, bool humano);//analizamos el tipo de la carta(humano o maquina) y lo almacenamos
void cartasRestantesBarajaD(tConjuntoCartas &conjuntoCartas);//calculamos la ctd de cartas en la baraja y las metemos en un array
bool esProbablePasarseD(tConjuntoCartas conjuntoCartas); //igual que en el modo C
void archivoModoD(tConjuntoCartas conjuntoCartas);//creamos un archivo con las partidas
void determinaGanadorD(double puntosJugador, double puntosMaquina, tConjuntoCartas conjuntoCartas);//determinar jugador del modoD
//-----------------------------------------------------------------------------------------------------
//------------------------------------FIN-->PROTOTIPOS DE FUNCIONES------------------------------------




int main()
{
	string tempUserInput = "";
	tBaraja Baraja;//baraja usada en el readFile, en ella estan las cartas leidas del archivo
	tConjuntoCartas conjuntoCartas;//la esctructura del modoD

	int limiteInferior = 3;
	int limiteSuperior = 5;

	while (tempUserInput != "0") {
		cout << "Elige el modo a que quieres jugar:\n"
			<< "  1- Modo A\n"
			<< "  2- Modo B\n"
			<< "  3- Modo C\n"
			<< "  4- Modo D\n"
			<< "  0- Salir del juego\n"
			<< "Tu decision es:";
		getline(cin, tempUserInput);
		cout << endl;

		srand((unsigned)time(NULL));
		int numCartas = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior); //Generacion de numero de cartas a cojer

		if (tempUserInput == "1") {
			readFile(Baraja);                 
			cout << "\n\n\t\t\t\t\t----MODO A----\n\n\n\n" << endl;
			modoA(numCartas, Baraja);
		}
		else if (tempUserInput == "2") {
			readFile(Baraja);        
			cout << "\n\n\t\t\t\t\t----MODO B----\n\n\n\n" << endl;
			modoBhumano(numCartas, Baraja);
		}
		else if (tempUserInput == "3") {
			readFile(Baraja);         
			cout << "\n\n\t\t\t\t\t----MODO C----\n\n\n\n" << endl;
			modoChumano(Baraja);
		}
		else if (tempUserInput == "4") {
			cout << "\n\n\t\t\t\t\t----MODO D----\n\n\n\n" << endl;
			inicializa(conjuntoCartas);      
			crearMazo(conjuntoCartas);
			modoDhumano(conjuntoCartas);
			modoDmaquina(conjuntoCartas);
			archivoModoD(conjuntoCartas);
		}
		else if (tempUserInput == "0") cout << "\t\t\t\tAdios!\n\n\n";
		else cout << "Modo invalido :(\n" << "prueba otra vez!\n\n\n";
	}
	return 0;
}


//lee las cartas y las coloca en el array Baraja[n]
//Leemos el archivo y ponemos las cartas en un array, para no tener el archivo abierto todo el rato
void readFile(tBaraja Baraja) {
	ifstream archivo;
	string fileNameInput;
	double temp;
	cout << "Escribe el nombre del archivo de texto con la baraja. (no hace falta escribir '.txt')" << endl;
	while (!archivo.is_open()) {
		cout << '>';
		getline(cin, fileNameInput);
		fileNameInput += ".txt";
		archivo.open(fileNameInput); // Abrimos el fichero txt
		if (!archivo.is_open()) {
			cout << "\t\tERROR\n No se encontro ningun archivo con este nombre." << endl;
		}
	}//while
	while (!archivo.eof()) {        //Baraja[0] = 0;
		for (int i = 0; i < 40; i++) {
			archivo >> temp;
			if (temp >= 10) {
				Baraja[i] = 0.5;
			}
			else Baraja[i] = temp;
			//cout << "carta: " << Baraja[i] << endl;
		}//for
	}//while
	archivo.close();

}

void modoA(int numCartas, const tBaraja Baraja) //si se pasa el jugador se para el juego y gana de forma automatica la maquina
{ /*Permite a cualquiera de los dos jugadores realizar su turno del
  modo A en una partida.Recibe el archivo con el mazo y el numero de
  cartas que hay que robar, y devuelve los puntos obtenidos tras robar
  ese numero de cartas.*/
	bool ganadorMaquina = false;
	int marcadorBaraja = 0;
	int ctdCartas = 0;
	double puntosPasarse = 7.5;
	double puntosJugador = 0;
	double puntosMaquina = 0;
	cout << "\n\n\t\t\t\tVan a robar los dos, " << numCartas << " cartas.\n" << endl;
	cout << "\t\t\t+----------------------------------------+" << endl;

	while ((ctdCartas < numCartas) && (puntosJugador <= puntosPasarse))
	{
		puntosJugador += Baraja[marcadorBaraja];
		cout << "\t\t\tCarta: " << Baraja[marcadorBaraja] << "\tSuma = " << puntosJugador << endl;
		marcadorBaraja++;
		ctdCartas++;
		if (puntosJugador > puntosPasarse) {
			ganadorMaquina = true;
			cout << "\t\t\tNo vas a coger mas cartas. Te has pasado por puntos." << endl;
		}
	}//while
	cout << "\t\t\t+----------------------------------------+" << endl;
	cout << "\t\t\tSuma total de puntos del humano = " << puntosJugador << endl;
	cout << "\t\t\t+----------------------------------------+" << endl;
	cout << "\n" << endl;
	ctdCartas = 0;
	if (!ganadorMaquina) {
		cout << "\t\t\t+----------------------------------------+" << endl;
		while ((ctdCartas < numCartas) && (puntosMaquina <= puntosPasarse))
		{
			//cout << "---valor:  " << valorDeCarta << endl;
			puntosMaquina += Baraja[marcadorBaraja];
			cout << "\t\t\tCarta : " << Baraja[marcadorBaraja] << "\tSuma = " << puntosMaquina << endl;
			marcadorBaraja++;
			ctdCartas++;
			if (puntosMaquina > puntosPasarse) {
				cout << "\t\t\tLa maquina no va ha coger mas cartas, se paso por puntos." << endl;
			}
		}//while
		cout << "\t\t\t+----------------------------------------+" << endl;
		cout << "\t\t\tSuma total de puntos de maquina = " << puntosMaquina << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
	}//if (!ganadorMaquina)
	determinaGanador(puntosJugador, puntosMaquina);
}

void modoBhumano(int numCartas, const tBaraja Baraja)
{ /*Permite realizar el turno del jugador humano en el modo B. Recibe el
  archivo con el mazo y el numero maximo de cartas que puede robar,
  y devuelve los puntos obtenidos.*/

	int marcadorBaraja = 0;
	int ctdCartas = 0;
	double puntosJugador = 0;
	bool ganadorMaquina = false;
	string tempUserInput = "";

	cout << "\t\t\t\tPuedes robar como maximo " << numCartas << " cartas.\n" << endl;
	cout << "Acciones del jugador...\n" << endl;
	cout << "\t\t\t+----------------------------------------+" << endl;

	while ((ctdCartas < numCartas) && (tempUserInput != "no") && (puntosJugador <= 7.5))
	{
		puntosJugador += Baraja[marcadorBaraja];
		cout << "\n\t\t\tCarta: " << Baraja[marcadorBaraja] << "\tSuma = " << puntosJugador << endl;
		ctdCartas++;
		marcadorBaraja++;
		if (puntosJugador <= 7.5) {
			if ((ctdCartas < numCartas)) {
				cout << "Quieres seguir robando? (no/si): ";
				getline(cin, tempUserInput);
			}
		}
		else {
			cout << "\t\t\tNo vas a coger mas cartas. Te has pasado por puntos." << endl;
			ganadorMaquina = true;
		}

	}//while
	cout << "\t\t\t+----------------------------------------+" << endl;
	cout << "\t\t\tSuma total = " << puntosJugador << endl;
	cout << "\t\t\t+----------------------------------------+" << endl;
	modoBmaquina(numCartas, Baraja, puntosJugador, marcadorBaraja, ganadorMaquina);
}

void modoBmaquina(int numCartas, const tBaraja Baraja, double puntosJugador, int marcadorBaraja, bool ganadorMaquina)
{ /*Permite realizar el turno del jugador maquina en el modo B.Recibe el
  archivo con el mazo, el numero maximo de cartas que puede robar y la puntuacion
  obtenida por el jugador humano, y devuelve los puntos obtenidos.*/

	int ctdCartas = 0;
	double puntosMaquina = 0;
	string tempUserInput = "";

	if (!ganadorMaquina) {
		cout << "\n\nAcciones de la maquina...\n" << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
		while ((puntosMaquina <= puntosJugador) && (ctdCartas < numCartas) && (puntosMaquina < 7.5))
		{
			puntosMaquina += Baraja[marcadorBaraja];
			cout << "\t\t\tCarta: " << Baraja[marcadorBaraja] << "\tSuma = " << puntosMaquina << endl;
			if (puntosMaquina >= 7.5) {
				cout << "\t\t\tLa maquina no va ha coger mas cartas, se paso por puntos." << endl;
			}
			marcadorBaraja++;
			ctdCartas++;
		}//while
		cout << "\t\t\t+----------------------------------------+" << endl;
		cout << "\t\t\tSuma total = " << puntosMaquina << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
	}//if (!ganadorMaquina)
	determinaGanador(puntosJugador, puntosMaquina);
}

void modoChumano(const tBaraja Baraja) {
	//Permite realizar el turno del jugador humano en el modo C.Recibe el archivo con el mazo y una variable
	//cartas que indica cuantas cartas de cada tipo quedan, y devuelve los puntos obtenidos y actualiza
	//cartas de acuerdo con las cartas que haya robado el humano.

	int marcadorBaraja = 0;
	int ctdCartas = 0;
	double puntosJugador = 0;
	bool ganadorMaquina = false;
	string tempUserInput = "";

	cout << "\t\t\t+----------------------------------------+" << endl;
	while ((tempUserInput != "no") && (puntosJugador <= 7.5))
	{
		puntosJugador += Baraja[marcadorBaraja];
		cout << "\t\t\tCarta: " << Baraja[marcadorBaraja] << "\tSuma = " << puntosJugador << endl;
		marcadorBaraja++;
		ctdCartas++;
		if (puntosJugador <= 7.5) {
			cout << "Quieres seguir robando? (no/si): ";
			getline(cin, tempUserInput);
		}
		else {
			cout << "\t\t\tNo vas a coger mas cartas. Te has pasado por puntos." << endl;
			ganadorMaquina = true;
		}
	}//while
	cout << "\t\t\t+----------------------------------------+" << endl;
	cout << "\t\t\tSuma total = " << puntosJugador << endl;
	cout << "\t\t\t+----------------------------------------+" << endl << endl;
	modoCmaquina(puntosJugador, marcadorBaraja, Baraja, ganadorMaquina);
}

void modoCmaquina(double puntosJugador, int marcadorBaraja, const tBaraja Baraja, bool ganadorMaquina) {
	//Permite realizar el turno del jugador maquina en el modo C.Recibe el archivo con el mazo, una variable
	//cartas que indica cuantas cartas de cada tipo quedan y la puntuacion obtenida por el jugador humano,
	//y devuelve los puntos obtenidos y actualiza cartas de acuerdo con las cartas que haya robado la maquina.

	bool cogerMasCartas = true;
	double puntosMaquina = 0;
	tTipoDeCartas cartasRest = { 0 };//array para apuntar la cantidad de cartas de cada tipo, se usara en "void cartasRestantes" y "bool esProbablePasarse"

	if (!ganadorMaquina) {
		cout << "\n\nAcciones de la maquina...\n" << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
		while ((puntosMaquina <= puntosJugador) && (cogerMasCartas) && (puntosMaquina <= 7.5))
		{
			puntosMaquina += Baraja[marcadorBaraja];
			cout << "\t\t\tCarta: " << Baraja[marcadorBaraja] << "\tSuma = " << puntosMaquina << endl;
			marcadorBaraja++;
			if (puntosMaquina > 7.5) {
				cout << "\t\t\tLa maquina no va ha coger mas cartas, se paso por puntos." << endl;
			}
			if (puntosMaquina == puntosJugador) {
				cartasRestantes(cartasRest, Baraja, marcadorBaraja); //hacemos calculo de las cartas restantes
				cogerMasCartas = esProbablePasarse(puntosMaquina, cartasRest, marcadorBaraja); //calculamos la probabilidad de pasarse y segun la probabilidad cambiamos
																							   //el bool
			}
		}//while
		cout << "\t\t\t+----------------------------------------+" << endl;
		cout << "\t\t\tSuma total = " << puntosMaquina << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
	}//if (!ganadorMaquina)

	determinaGanador(puntosJugador, puntosMaquina, ganadorMaquina);
}

//calculamos la ctd de cartas en la baraja y las metemos en un array
void cartasRestantes(tTipoDeCartas cartasRest, const tBaraja Baraja, int marcadorBaraja) {
	for (int i = marcadorBaraja; i < 40; i++) {
		////mostrar las cartas restantes
		//cout << "Cartas restantes: ";
		//cout << Baraja[i];
		//cout << "\tvalor: " << Baraja[i] << "\n\t";

		int valorDeCarta = (int)Baraja[i];
		switch (valorDeCarta) //metemos las cartas restantes en el array con el switch
		{
		case 1:
			cartasRest[1]++;
			break;
		case 2:
			cartasRest[2]++;
			break;
		case 3:
			cartasRest[3]++;
			break;
		case 4:
			cartasRest[4]++;
			break;
		case 5:
			cartasRest[5]++;
			break;
		case 6:
			cartasRest[6]++;
			break;
		case 7:
			cartasRest[7]++;
			break;
		default:
			cartasRest[0]++;
		}
	}//for

	////ensenar las cartas de cada tipo
	//for (int j = 0; j <= 7; j++)
	//{
	//     cout << "cartas de tipo " << j << ": " << cartasRest[j] <<'\t';
	//}
}

bool esProbablePasarse(double puntosMaquina, const tTipoDeCartas cartasRest, int marcadorBaraja) {
	/*Determina si la probabilidad que tiene la maquina de pasarse si robara una carta mas es mayor que 0.5.
	Recibe la puntuacion actual de la maquina y una variable cartas que indica cuantas cartas de cada tipo
	quedan, y devuelve true si la probabilidad de pasarse si roba una carta mas supera 0.5 y false en caso contrario.*/
	int tempInteger;
	int ctdCartasPaPasarse;
	tTipoDeCartas tipoCartaPaPasarse = { 0 };
	bool cogemos = true;
	double probabilidad;
	double ctdCartasTotales = dim40  - marcadorBaraja; //sacamos la ctd de cartas restantes
	double puntosPaPasarse = 7.5 - puntosMaquina; //sacamos los puntos "necesarios" para pasarse

	if (puntosPaPasarse == 0.5) tempInteger = 0; //adaptamos el valor de la carta para usar el switch mas abajo y saber con que cartas nos podemos pasar
	else tempInteger = (int)(puntosPaPasarse + 0.5);

	switch (tempInteger) {
	default:
		tipoCartaPaPasarse[0]++;
	case 1:
		tipoCartaPaPasarse[1]++;
	case 2:
		tipoCartaPaPasarse[2]++;
	case 3:
		tipoCartaPaPasarse[3]++;
	case 4:
		tipoCartaPaPasarse[4]++;
	case 5:
		tipoCartaPaPasarse[5]++;
	case 6:
		tipoCartaPaPasarse[6]++;
	case 7:
		tipoCartaPaPasarse[7]++;
		break;
	}

	//multiplicamos la ctd de cartas restantes por las cartas con cuales nos podemos pasar
	//ejem: nos falta para pasarse 2.5 puntos. con el switch sacamos que las cartas para pasarse son las de valor 3,4,5,6,7 y las cartas con valor 0.5,1,2 no nos afectan
	//pues el array tipoCartaPaPasarse[i] tiene ceros en las posiciones 0(0.5 puntos), 1 y 2, en las otras posiciones esta un 1. 
	//pues multuplicamos la ctd de cartas de tipo(valor) 3,4,5,6,7 por el uno y lo sumamos. y las que no nos afectan las multiplicamos por 0
	//de ahi sacamos la ctd de cartas que nos afectan para calcular la probabilidad
	ctdCartasPaPasarse = 
		(cartasRest[0] * tipoCartaPaPasarse[0]) + (cartasRest[1] * tipoCartaPaPasarse[1]) +
		(cartasRest[2] * tipoCartaPaPasarse[2]) + (cartasRest[3] * tipoCartaPaPasarse[3]) +
		(cartasRest[4] * tipoCartaPaPasarse[4]) + (cartasRest[5] * tipoCartaPaPasarse[5]) +
		(cartasRest[6] * tipoCartaPaPasarse[6]) + (cartasRest[7] * tipoCartaPaPasarse[7]);

	probabilidad = ctdCartasPaPasarse / ctdCartasTotales;    //El calculo de la probabilidad de pasarse (ctd de cartas que nos afectan/ctd cartas totales)

	if (probabilidad >= 0.5) cogemos = false;

	cout << "\npuntosPaPasarse: " << puntosPaPasarse
	    << "\nctdCartasTotales: " << ctdCartasTotales
	    << "\nctdCartasPaPasarse: " << ctdCartasPaPasarse
	    << "\nprobabilidad: " << probabilidad
	    << "\ncogemos: " << cogemos << endl;
	return cogemos;
}

void determinaGanador(double puntosJugador, double puntosMaquina, bool ganadorMaquina) {
	//Recibe los puntos obtenidos por el jugador humano y por la maquina, y devuelve quien gana.

	//en caso de que el humano se paso, no hace falta comparar los puntos, ya que la maquina gana de forma automatica
	if (ganadorMaquina) cout << "\t\t\tGano la maquina, porque el jugador se paso.\n" << endl;
	else {
		if (puntosJugador < puntosMaquina)
		{
			if (puntosMaquina > 7.5) {
				cout << "\t\t\tGano el jugador, la maquina se paso.\n" << endl;
			}
			else {
				cout << "\t\t\tGano la Maquina por cantidad de puntos.\n" << endl;
			}
		}
		else if (puntosJugador > puntosMaquina) {
			if (puntosJugador > 7.5) {
				cout << "\t\t\tGano la Maquina, el jugador se paso.\n" << endl;
			}
			else {
				cout << "\t\t\tGano el jugador por cantidad de puntos.\n" << endl;
			}
		}
		else //(puntosJugador == puntosMaquina)
		{
			// SE GENERA UN NUMERO ALEATORIO ENTRE 1 Y 2 PARA DECIR QUIEN GANA, SOLO SE USA SI LA PUNTUACION DEL HUMANO Y LA MAQUINA SON IGUALES
			int limiteInferior = 1;
			int limiteSuperior = 2;
			int azar = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior);
			if (azar == 1) cout << "\t\t\tGana el jugador por aleatorio.\n" << endl;
			else cout << "\t\t\tGana la maquina por aleatorio.\n" << endl;
		}
	}//else
}

//------------------------------------------MODO D------------------------------------------
void inicializa(tConjuntoCartas &conjuntoCartas) {
	//reseteamos por si no es la primera partida
	//------------------------reset--------------------
	conjuntoCartas.puntosHumano = 0;
	conjuntoCartas.puntosMaquina = 0;
	conjuntoCartas.marcador = 40;
	conjuntoCartas.cartasHumano.marcador = 0;
	conjuntoCartas.cartasMaquina.marcador = 0;
	conjuntoCartas.ganadorMaquina = false;
	for (int i = 0; i < dim40; i++) conjuntoCartas.barajaD[i] = 0;
	for (int i = 0; i < dim8; i++) conjuntoCartas.tipoDeCartas[i] = 0;
	for (int i = 0; i < dim14; i++) conjuntoCartas.cartasHumano.cartas[i] = 0;
	for (int i = 0; i < dim14; i++) conjuntoCartas.cartasMaquina.cartas[i] = 0;
	for (int i = 0; i < dim8; i++) conjuntoCartas.cartasMaquina.tipoDeCartas[i] = 0;
	for (int i = 0; i < dim8; i++) conjuntoCartas.cartasHumano.tipoDeCartas[i] = 0;
	//------------------------reset--------------------

	for (int i = 1; i <= 4; i++) { //rellenamos el mazo con 1..7 10..12(4 veces)
		for (int j = 0; j < 7; j++) {
			conjuntoCartas.barajaD[j + (i * 10 - 10)] = j + 1;
		}
		for (int k = 7; k < 10; k++) {
			conjuntoCartas.barajaD[k + (i * 10 - 10)] = 0.5;
		}
	}
	////Ensenar la baraja
	//for (int i = 0; i < 40; i++) {
	//    cout << "conjuntoCartas.barajaD: " << conjuntoCartas.barajaD[i] << endl;
	//}
}

// MEZCLA EL MAZO PARA EL MODO D
void crearMazo(tConjuntoCartas &conjuntoCartas) {
	double tmp;
	int indice, desp;
	//Almaceno una nueva carta en cada posicion
	for (int i = 0; i < dim40; i++)
	{
		desp = i;
		//Genero un numero aleatorio
		indice = (int)(rand() / (float)RAND_MAX * (dim40 - i) + desp);
		//Intercambio valores de variables
		tmp = conjuntoCartas.barajaD[i];
		conjuntoCartas.barajaD[i] = conjuntoCartas.barajaD[indice];
		conjuntoCartas.barajaD[indice] = tmp;
	}

	//Mostrar
	//for (int i = 0; i < dim40; i++)
	//{
	//cout << "carta" << conjuntoCartas.barajaD[i] << endl;
	//}
}

void sacarCarta(tConjuntoCartas &conjuntoCartas, double &carta) {
	//Elimina una carta de un extremo de la lista cartas y la devuelve en carta.
	conjuntoCartas.marcador--;
	carta = conjuntoCartas.barajaD[conjuntoCartas.marcador];
}

void annadirCarta(tConjuntoCartas &conjuntoCartas, double carta, bool humano) {

	//Anade la carta carta en un extremo de la lista cartas.
	if (humano) {
		conjuntoCartas.cartasHumano.marcador++;
		conjuntoCartas.cartasHumano.cartas[conjuntoCartas.cartasHumano.marcador] = carta;
	}
	else {
		conjuntoCartas.cartasMaquina.marcador++;
		conjuntoCartas.cartasMaquina.cartas[conjuntoCartas.cartasMaquina.marcador] = carta;
	}
}

void modoDhumano(tConjuntoCartas &conjuntoCartas) {
	//Permite realizar el turno del jugador humano en el modo D. al finalizar su ejecucion deja cartas y mazo actualizados segun las cartas que haya
	//robado el humano en su turno y devuelve los puntos obtenidos por el humano asi como las cartas que ha robado.

	double carta;
	double tempValor;
	string tempUserInput = "";
	const bool humano = true; //usado en annadirCarta y tipoCartasJugadores, para indicar que hay que meter la carta en el conjunto de humano

	cout << "\t\t\t+----------------------------------------+" << endl;
	while ((tempUserInput != "no") && (conjuntoCartas.puntosHumano <= 7.5))
	{
		sacarCarta(conjuntoCartas, carta);			//sacamos carta del mazo general
		annadirCarta(conjuntoCartas, carta, humano);//anadimos la carta sacada al conjunto de cartas del humano
		conjuntoCartas.puntosHumano += carta;		//suma de puntos
		tipoCartasJugadores(conjuntoCartas, carta, humano); //almacenamos el tipo de carta
		cout << "\t\t\tCarta: " << carta << "\tSuma = " << conjuntoCartas.puntosHumano << endl;
		cout << "\t\t\tTus cartas: '" << conjuntoCartas.cartasHumano.marcador << "'\n" << "\t\t\tCartas del mazo: '" << conjuntoCartas.marcador << "'" << endl;
		cout << "\t\t\tTus cartas en la mano:" << endl;
		//hacemos un recorrido en las cartas que cogio el humano
		for (int i = 0; i < 8; i++) {
			if (conjuntoCartas.cartasHumano.tipoDeCartas[i] != 0) {//en caso de que la posicion este vacia no la mostramos en el cout
				if (i == 0) tempValor = 0.5;
				else tempValor = i;
				cout << "\t\t\t\t---> " << conjuntoCartas.cartasHumano.tipoDeCartas[i] << " de valor: '" << tempValor << "'" << endl;
			}
		}//for
		if (conjuntoCartas.puntosHumano <= 7.5) {
			cout << "Quieres seguir robando? (no/si): ";
			getline(cin, tempUserInput);
			cout << endl;
		}
		else {
			cout << "\n\t\t\tNo vas a coger mas cartas. Te has pasado por puntos." << endl;
			conjuntoCartas.ganadorMaquina = true;
		}
	}//while
	cout << "\n\t\t\t+----------------------------------------+" << endl;
	cout << "\t\t\tSuma total = " << conjuntoCartas.puntosHumano << endl;
	cout << "\t\t\t+----------------------------------------+" << endl << endl;
}

void modoDmaquina(tConjuntoCartas &conjuntoCartas) {
	//Permite realizar el turno del jugador maquina en el modo D. al finalizar su ejecucion deja cartas
	//    y mazo actualizados segun las cartas que haya robado la maquina en su turno y devuelve los puntos obtenidos por la
	//    maquina asi como las cartas que ha robado.

	double carta;
	bool cogerMasCartas = true;
	const bool humano = false; //le toca a la maquina, pues la maquina no es un humano :D

	if (!conjuntoCartas.ganadorMaquina) {
		cout << "Ahora le toca a la maquina.." << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
		while ((conjuntoCartas.puntosMaquina <= conjuntoCartas.puntosHumano) && (cogerMasCartas) && (conjuntoCartas.puntosMaquina <= 7.5))
		{
			sacarCarta(conjuntoCartas, carta);
			annadirCarta(conjuntoCartas, carta, humano);
			conjuntoCartas.puntosMaquina += carta;
			tipoCartasJugadores(conjuntoCartas, carta, humano); //almacenamos el tipo de carta
			cout << "\t\t\tCarta: " << carta << "\tSuma = " << conjuntoCartas.puntosMaquina << endl;
			if (conjuntoCartas.puntosMaquina == conjuntoCartas.puntosHumano) {
				cartasRestantesBarajaD(conjuntoCartas); //calculamos las cartas sin cojer en la baraja
				cogerMasCartas = esProbablePasarseD(conjuntoCartas);// calculamos la probabilidad
			}
		}//while
		cout << "\t\t\t+----------------------------------------+" << endl;
		cout << "\t\t\tSuma total = " << conjuntoCartas.puntosMaquina << endl;
		cout << "\t\t\t+----------------------------------------+" << endl;
	}//if (!conjuntoCartas.ganadorMaquina)
	determinaGanadorD(conjuntoCartas.puntosHumano, conjuntoCartas.puntosMaquina, conjuntoCartas);
	conjuntoCartas.numPartida++;//anadimos al contador de la partida un 1 :)
}

//analizamos la carta sacada y la metemos al conjunto de cartas de los jugadores(humano o maquina)
void tipoCartasJugadores(tConjuntoCartas &conjuntoCartas, double carta, bool humano) {
	if (humano) {
		int valorDeCarta = (int)carta;
		switch (valorDeCarta)
		{
		case 1:
			conjuntoCartas.cartasHumano.tipoDeCartas[1]++;
			break;
		case 2:
			conjuntoCartas.cartasHumano.tipoDeCartas[2]++;
			break;
		case 3:
			conjuntoCartas.cartasHumano.tipoDeCartas[3]++;
			break;
		case 4:
			conjuntoCartas.cartasHumano.tipoDeCartas[4]++;
			break;
		case 5:
			conjuntoCartas.cartasHumano.tipoDeCartas[5]++;
			break;
		case 6:
			conjuntoCartas.cartasHumano.tipoDeCartas[6]++;
			break;
		case 7:
			conjuntoCartas.cartasHumano.tipoDeCartas[7]++;
			break;
		default:
			conjuntoCartas.cartasHumano.tipoDeCartas[0]++;
		}
	}
	else {
		////mostras las cartas restantes
		//cout << "Cartas restantes: ";
		//cout << Baraja[i];
		//cout << "\tvalor: " << Baraja[i] << "\n\t";
		int valorDeCarta = (int)carta;
		switch (valorDeCarta)
		{
		case 1:
			conjuntoCartas.cartasMaquina.tipoDeCartas[1]++;
			break;
		case 2:
			conjuntoCartas.cartasMaquina.tipoDeCartas[2]++;
			break;
		case 3:
			conjuntoCartas.cartasMaquina.tipoDeCartas[3]++;
			break;
		case 4:
			conjuntoCartas.cartasMaquina.tipoDeCartas[4]++;
			break;
		case 5:
			conjuntoCartas.cartasMaquina.tipoDeCartas[5]++;
			break;
		case 6:
			conjuntoCartas.cartasMaquina.tipoDeCartas[6]++;
			break;
		case 7:
			conjuntoCartas.cartasMaquina.tipoDeCartas[7]++;
			break;
		default:
			conjuntoCartas.cartasMaquina.tipoDeCartas[0]++;
		}
	}

	////ensenar las cartas de cada tipo
	//for (int j = 0; j <= 7; j++)
	//{
	//     cout << "cartas de tipo " << j << ": " << conjuntoCartas.cartasHumano.tipoDeCartas[j] <<'\t';
	//}
}

// SEPARA LAS CARTAS QUE QUEDAN EN EL MAZO CREADO PARA AGRUPARLAS SEGUN SU VALOR
void cartasRestantesBarajaD(tConjuntoCartas &conjuntoCartas) {
	for (int i = 0; i < conjuntoCartas.marcador; i++) {
		int valorDeCarta = (int)conjuntoCartas.barajaD[i];
		switch (valorDeCarta)
		{
		case 1:
			conjuntoCartas.tipoDeCartas[1]++;
			break;
		case 2:
			conjuntoCartas.tipoDeCartas[2]++;
			break;
		case 3:
			conjuntoCartas.tipoDeCartas[3]++;
			break;
		case 4:
			conjuntoCartas.tipoDeCartas[4]++;
			break;
		case 5:
			conjuntoCartas.tipoDeCartas[5]++;
			break;
		case 6:
			conjuntoCartas.tipoDeCartas[6]++;
			break;
		case 7:
			conjuntoCartas.tipoDeCartas[7]++;
			break;
		default:
			conjuntoCartas.tipoDeCartas[0]++;
		}
	}
}

//igual que en el modoC, pero adaptado a la estructura
bool esProbablePasarseD(tConjuntoCartas conjuntoCartas) {
	/*Determina si la probabilidad que tiene la maquina de pasarse si robara una carta mas es mayor que 0.5.
	Recibe la puntuacion actual de la maquina y una variable cartas que indica cuantas cartas de cada tipo
	quedan, y devuelve true si la probabilidad de pasarse si roba una carta mas supera 0.5 y false en caso contrario.*/

	int tempInteger;
	tTipoDeCartas tipoCartaPaPasarse = { 0 };
	bool cogemos = true;
	for (int i = 0; i <= 7; i++) tipoCartaPaPasarse[i] = 0;
	double puntosPaPasarse = 7.5 - conjuntoCartas.puntosMaquina;
	double ctdCartasTotales = 0;
	for (int k = 0; k <= 7; k++) ctdCartasTotales += conjuntoCartas.tipoDeCartas[k];


	if (puntosPaPasarse == 0.5) tempInteger = 0;
	else tempInteger = (int)(puntosPaPasarse + 0.5);

	switch (tempInteger) {
	default:
		tipoCartaPaPasarse[0]++;
		break;
	case 1:
		tipoCartaPaPasarse[1]++;
	case 2:
		tipoCartaPaPasarse[2]++;
	case 3:
		tipoCartaPaPasarse[3]++;
	case 4:
		tipoCartaPaPasarse[4]++;
	case 5:
		tipoCartaPaPasarse[5]++;
	case 6:
		tipoCartaPaPasarse[6]++;
	case 7:
		tipoCartaPaPasarse[7]++;
		break;
	}

	int ctdCartasPaPasarse =
		(conjuntoCartas.tipoDeCartas[0] * tipoCartaPaPasarse[0]) + (conjuntoCartas.tipoDeCartas[1] * tipoCartaPaPasarse[1]) +
		(conjuntoCartas.tipoDeCartas[2] * tipoCartaPaPasarse[2]) + (conjuntoCartas.tipoDeCartas[3] * tipoCartaPaPasarse[3]) +
		(conjuntoCartas.tipoDeCartas[4] * tipoCartaPaPasarse[4]) + (conjuntoCartas.tipoDeCartas[5] * tipoCartaPaPasarse[5]) +
		(conjuntoCartas.tipoDeCartas[6] * tipoCartaPaPasarse[6]) + (conjuntoCartas.tipoDeCartas[7] * tipoCartaPaPasarse[7]);

	double probabilidad = ctdCartasPaPasarse / ctdCartasTotales;    //El calculo de la probabilidad de pasarse
																	//    la ecuacion se dedujo a partir del ejemplo de la hoja con el enunciado de la practica

	if (probabilidad >= 0.5) cogemos = false;
	
	//descomentar para ver los resultados de los calculos
	/*cout << "\npuntosPaPasarse: " << puntosPaPasarse
		<< "\nctdCartasTotales: " << ctdCartasTotales
		<< "\nctdCartasPaPasarse: " << ctdCartasPaPasarse
		<< "\nprobabilidad: " << probabilidad
		<< "\ncogemos: " << cogemos << endl;*/
	return cogemos;
}

//igual que en el modoC, pero adaptado a la estructura
void determinaGanadorD(double puntosJugador, double puntosMaquina, tConjuntoCartas conjuntoCartas)
{/*Recibe los puntos obtenidos por el jugador humano y por la maquina, y devuelve
 un valor que indica quien gana (1 = gana el humano, 2 = gana la maquina).*/
	int ganador = 0;
	double ctdCartasHumano = 0;
	double ctdCartasMaquina = 0;
	int limiteInferior = 1;
	int limiteSuperior = 2;
	bool ganadorAzar;
	cout << "\t\t\t";
	if (conjuntoCartas.ganadorMaquina) cout << "Gano la maquina, porque el jugador se paso." << endl;
	else {
		if (puntosJugador < puntosMaquina)
		{
			if (puntosMaquina > 7.5) {
				cout << "Gano el jugador, la maquina se paso" << endl;
			}
			else {
				cout << "Gano la Maquina por cantidad de puntos" << endl;
			}
		}
		else if (puntosJugador > puntosMaquina) {
			if (puntosJugador > 7.5) {
				cout << "Gano la Maquina, el jugador se paso" << endl;
			}
			else {
				cout << "Gano el jugador por cantidad de puntos" << endl;
			}
		}
		else
		{
			for (int i = 0; i < dim14; i++) {//contamos las cartas totales de los jugadores
				ctdCartasHumano += conjuntoCartas.cartasHumano.cartas[i];
			}
			for (int i = 0; i < dim14; i++) {
				ctdCartasMaquina += conjuntoCartas.cartasMaquina.cartas[i];
			}
			if (ctdCartasHumano < ctdCartasMaquina) cout << "Gana el jugador por tener menos cartas." << endl;
			else if (ctdCartasHumano > ctdCartasMaquina) cout << "Gana la maquina por tener menos cartas." << endl;
			else {
				ganadorAzar = limiteInferior + rand() % (limiteSuperior + 1 - limiteInferior); //Generacion un numero aleatorio entre 1 y 2 para deducir quien es el ganador( solo si las puntuaciones son las mismas
				if (ganadorAzar) cout << "Gana el jugador, por el azar." << endl;
				else cout << "Gana la maquina, por el azar." << endl;
			}

		}
	}
	cout << "\n";
}

//crea el archivo con las partidas
void archivoModoD(tConjuntoCartas conjuntoCartas) {
	ofstream archivo; 
	archivo.open("Partida_" + to_string(conjuntoCartas.numPartida) + ".txt"); //creamos
	archivo << "\t\t\tPartida #" + to_string(conjuntoCartas.numPartida) + "\n";
	archivo << "\tEl ganador es ";
	if (conjuntoCartas.ganadorMaquina) archivo << "el jugador!\n";
	else archivo << "la maquina!\n";
	archivo << "Las cartas del jugador fueron las siguientes:\n";
	for (int i = 0; i < 8; i++) {
		if (conjuntoCartas.cartasHumano.tipoDeCartas[i] != 0) {
			double tempValor;
			if (i == 0) tempValor = 0.5;
			else tempValor = i;
			archivo << "\t-- " << conjuntoCartas.cartasHumano.tipoDeCartas[i] << " de valor '" << tempValor << "'\n";
		}
	}//for
	archivo << "\nLas cartas de la maquina fueron las siguientes:\n";
	for (int i = 0; i < 8; i++) {
		if (conjuntoCartas.cartasMaquina.tipoDeCartas[i] != 0) {
			double tempValor;
			if (i == 0) tempValor = 0.5;
			else tempValor = i;
			archivo << "\t-- " << conjuntoCartas.cartasMaquina.tipoDeCartas[i] << " de valor '" << tempValor << "'\n";
		}
	}//for
	archivo.close();//cerramos
}
