#include "./Tablero.h"
#include <iostream>

using namespace std;

Tablero::Tablero(){
	contador=0;
	jugadores=0;
}


Tablero::Tablero(int jugadores, Jugadores& jug_ref){
	this->jugadores=jugadores;
	this->jug = &jug_ref;
	cartastemp.resize(jugadores);
	jugador.resize(jugadores);
}

void Tablero::Turno(){
	int ad;
	for (int i=0;i<jugadores;i++){
		cout<<"Tira el jugador "<<(i+1)<<endl;
		cartastemp[i]=this->jug->Tirar(i+1);
		jugador[i]=i+1;
	}
	
	int idwin=jugador[0];
	int poder=0, pos;
	char color=cartastemp[0].color;
	
	for (int i=0;i<jugadores;i++){
		if (cartastemp[i].color==color){
			if (cartastemp[i].poder>poder){
				poder=cartastemp[i].poder;
				idwin=jugador[i];
			}
		}
	}
	cout<<"El jugador "<<idwin<<" gano la ronda con la Carta: "<<color<<" "<<poder<<endl;
	this->jug->Puntaje(idwin);
}

bool Tablero::final(){
	vector<Mazo> cartas;
	cartas=m.getmazo();
	int size;
	size=m.getsize();
	for (int i=0;i<size;i++){
		if (cartas[i].est==1){
			contador+=1;
		}
	}
	if (contador==size){
		return true;
	}else {
		return false;
	}
}