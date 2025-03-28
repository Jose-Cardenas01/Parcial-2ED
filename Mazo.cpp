#include "./Mazo.h"
#include <cstdlib>
#include <ctime>

using namespace std;

Mazo::Mazo(){
	poder=0;
	color='p';
	est=2;//0:Disponible, 1:Ya fue lanzada, 2:sin repartir
}

void Mazo::Inicio(int size){
	this->size=size;
	cartas.resize(this->size);
	int aux=1;
	for (int i=0;i<this->size;i++){
		cartas[i].est=2;
		if (i<10){
			cartas[i].color='R';
			cartas[i].poder=aux++;
		}else {
			aux=1;
			if (i<20){
				cartas[i].color='V';
				cartas[i].poder=aux++;
			}else {
				aux=1;
				if (i<30){
					cartas[i].color='A';
					cartas[i].poder=aux++;
				}else {
					aux=1;
					cartas[i].color='N';
					cartas[i].poder=aux++;
				}
			}
		}
	}
}

void Mazo::Revolver(){
	Mazo aux;
	srand(time(NULL));
	int numrandom;
	for (int i=0;i<(size*2);i++){
		numrandom=0+(rand()%41);
		aux=cartas[i];
		cartas[i]=cartas[numrandom];
		cartas[numrandom]=aux;
	}
}

vector<Mazo> Mazo::Repartir(int numcartas){//ultima modificacion se le quito el atributo int jugadores y el vector baraja
	vector<Mazo> baraja(numcartas);
	int aux=0;
	for (int i=0;i<size;i++){
		if (cartas[i].est==2){
			baraja[i]=cartas[i];
			aux+=1;
		}else {
			continue;
		}
		if (aux==6){
			break;
		}
	}
	return baraja;
}

vector<Mazo> Mazo::getmazo(){
	return cartas;
}

int Mazo::getsize(){
	return size;
}

Mazo Mazo::gettipo(){
	return Mazo();
}

void Mazo::settamano(int tamano){
	this->size=tamano;
}