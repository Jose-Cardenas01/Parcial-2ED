#include "./Mazo.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Mazo::Mazo(int tam){
    
	this->tam=tam;
	monto.resize(tam);
	char colores[]={'R', 'V', 'A', 'N'};
	
	for (int i=0;i<4;i++){
	    for (int j=0;j<9;j++){
	        monto[(i*9)+j].color=colores[i];
	        monto[(i*9)+j].poder=j+1;
	    }
	}
}

void Mazo::Revolver(){
	Carta aux;
	srand(time(NULL));
	int numrandom;
	
	for (int i=0;i<tam;i++){
	    
		numrandom=rand()%36;
		aux=monto[i];
		monto[i]=monto[numrandom];
		monto[numrandom]=aux;
	    
	}
}

vector<Carta> Mazo::Repartir(int numcartas){//ultima modificacion se le quito el atributo int jugadores y el vector baraja

	vector<Carta> baraja(numcartas);
	int aux=0;
	
	for (int i=0;i<tam;i++){
	        
    	if (monto[i].est==2){//2: esta sin repartir
    	    
    	    monto[i].est=0;
        	baraja[aux]=monto[i];
        	aux+=1;
        	
    	}
    	
    	if (aux==numcartas){
    		break;
    	}
	}
	return baraja;
}



