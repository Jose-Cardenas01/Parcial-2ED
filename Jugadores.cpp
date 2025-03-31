#include "./Jugadores.h"
#include <iostream>

using namespace std;

Jugadores::Jugadores(){//tipo de variable
	id=-1;
	puntos=-1;
	baraja.resize(1);
};


Jugadores::Jugadores(int numpla, Mazo* pdr){
	
	cout<<"jugadores 1";
	this->numpla=numpla;
	numcartas=(36/numpla);//define las cartas que le tocan a cada jugador
	baraja.resize(numcartas);
	players.resize(numpla);
	cout<<"jugadores 2";
	
	for (int i=0;i<numpla;i++){//da valores a cada posicion
	
		cout<<"jugadores 3";
		Jugadores jugador;
		jugador.id=(i+1);
		jugador.puntos=0;
		jugador.baraja=pdr->Repartir(18/*numcartas*/);//se le reparte una baraja a cada jugador (Repartir retorna una baraja)
		players[i]=jugador;//se agrega el jugador con sus atributos al vector players
		cout<<"jugadores 4";
		
	}
}


void Jugadores::Puntaje(int id){//suma un punto al jugador

	for (int i=0;i<players.size();i++){
	    
		if (players[i].id==id){
			players[i].puntos+=1;
		}
		
	}
	
}
 
Carta Jugadores::Tirar(int id){
	
	int lanzar;
	cout<<"-----Elegir una carta-----"<<endl;
	Mostrar(id);
	cin>>lanzar;
	
	if (lanzar>0 && lanzar<=numcartas) {
	    players[id - 1].baraja[lanzar - 1].est=1;
        cout<<"El jugador "<<id<<" lanzo la carta: "<<players[id - 1].baraja[lanzar - 1].color<<" "<<players[id - 1].baraja[lanzar - 1].poder<<endl;
        return players[id - 1].baraja[lanzar - 1];
    } else {
        cout<<"La carta que quieres tirar no existe"<<endl;
        Carta car;
        return car;
    }
    
}

void Jugadores::Mostrar(int id){
    
	for (int i=0;i<numcartas;i++){
	    
	    if (players[id - 1].baraja[i].est==0){//si la carta ya fue lanzada est:1 no se muestra
		    cout<<(i+1)<<" Carta: "<<players[id - 1].baraja[i].color<<" "<<players[id - 1].baraja[i].poder<<endl;
	    }
	    
	}
	
}

int Jugadores::getnumcartas(){
    return numcartas;
}





