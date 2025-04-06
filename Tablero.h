#ifndef TABLERO
#define TABLERO
#include <vector>
#include "./Jugadores.h"

using namespace std;

class Tablero{
	public:
		int jugadores=0;
		int contador=0;
		vector<int> jugador;//creo que no lo necesito
		vector<Carta> cartastemp;
		Tablero(int jugadores);
		//Tablero();
		void Turno(Jugadores* pdr);
		void clean();
		void Ganador(vector<Jugadores> player);
};


#endif