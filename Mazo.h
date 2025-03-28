#ifndef MAZO
#define MAZO
#include <vector>

using namespace std;

class Mazo{
	public:
		int id;
		int poder;
		//vector<char> color={'R', 'V', 'A', 'N'};
		char color;
		int est;
		void settamano(int tamano);
		vector<Mazo> cartas;
		//vector<Mazo> baraja;
		int size=0;
		Mazo();
		vector<Mazo> Repartir(int numcartas);
		void Inicio(int size);
		void Revolver();
		int getsize();
		vector<Mazo> getmazo();
		Mazo gettipo();
};




#endif