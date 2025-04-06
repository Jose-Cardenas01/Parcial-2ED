#ifndef JUGADORES
#define JUGADORES
#include "./Mazo.h"
#include <vector>

using namespace std;

class Jugadores{
	public:
		//Mazo m;
		//Mazo* pdr=&m;
		int id=0, numpla=0, puntos=0;
		int numcartas=1;
		vector<Carta> baraja;//baraja para cada jugador
		Jugadores();//tipo de variable para almacenar los jugadores
		Jugadores(int numpla, Mazo* pdr);
		vector<Jugadores> players;//vector de jugadores
		Carta Tirar(int id);//devuelve una sola carta
		void Puntaje(int id);//suma un punto al jugador
		void Mostrar(int id);
		int getnumcartas();
};


#endif