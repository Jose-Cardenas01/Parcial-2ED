#ifndef JUGADORES
#define JUGADORES
#include "./Mazo.h"
#include <vector>



class Jugadores{
	public:
		Mazo m;
		int id, numpla, puntos;
		int numcartas=1;
		vector<Mazo> baraja;
		//vector<Mazo> bajara(numcartas);
		Jugadores();
		Jugadores(int numpla);
		vector<Jugadores> players;
		Mazo Tirar(int id);
		void Puntaje(int id);
		void Mostrar();
};



#endif