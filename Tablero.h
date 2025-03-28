#ifndef TABLERO
#define TABLERO
#include <vector>
#include "./Mazo.h"
#include "./Jugadores.h"

using namespace std;

class Tablero{
	public:
		int jugadores;
		int contador;
		Jugadores* jug;
		Mazo m;
		vector<int> jugador;
		vector<Mazo> cartastemp;
		Tablero(int jugadores, Jugadores& jug_ref);
		Tablero();
		void Turno();
		bool final();
};


#endif