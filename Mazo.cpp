#include "./Mazo.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Mazo::Mazo(int size){
    
	this->size=size;
	monto.resize(size);
	int aux=1;
	
	for (int i=0;i<size;i++){
		monto[i].est=2;
	}
		
	for (int i=0;i<9;i++){
	    monto[i].color='R';
		monto[i].poder=aux++;
	}
	aux=1;
	
	for (int i=0;i<9;i++){
	    monto[i].color='V';
		monto[i].poder=aux++;
	}
	aux=1;
	
	for (int i=0;i<9;i++){
	    monto[i].color='A';
		monto[i].poder=aux++;
	}
	aux=1;
	
	for (int i=0;i<9;i++){
	    monto[i].color='N';
		monto[i].poder=aux++;
	}
}

void Mazo::Revolver(){
	Carta aux;
	srand(time(NULL));
	int numrandom;
	
	for (int i=0;i<(size*2);i++){
	    
		numrandom=0+(rand()%37);
		aux=monto[i];
		monto[i]=monto[numrandom];
		monto[numrandom]=aux;
	    
	}
}

vector<Carta> Mazo::Repartir(int numcartas){//ultima modificacion se le quito el atributo int jugadores y el vector baraja

	vector<Carta> baraja(numcartas);
	int aux=0;
	
	for (int i=0;i<size;i++){
	    
		if (monto[i].est==2){//2: esta sin repartir
		    if (aux<numcartas){
    			baraja[aux]=monto[i];
    			monto[i].est=0;
    			aux+=1;
		    }
		}
		
		if (aux==6){
			break;
		}
	}
	return baraja;
}