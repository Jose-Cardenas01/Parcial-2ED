#ifndef MAZO
#define MAZO
#include <vector>
#include "./Carta.h"

using namespace std;

class Mazo{
	public:
		vector<Carta> monto;
		int size=0;
		Mazo(){};
		Mazo(int size);
		vector<Carta> Repartir(int numcartas);
		void Revolver();
};




#endif