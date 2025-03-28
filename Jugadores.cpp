#include "./Jugadores.h"
#include <iostream>
#include <cmath>

using namespace std;

Jugadores::Jugadores(){//tipo de variable
	id=-1;
	puntos=-1;
	baraja;//Ayuda a solucionar el problema que tenia de crear una sola baraja
}

/*Jugadores::Jugadores(int players){//se llama despues del constructor con dos atributos
	for (int i=1;i<=players;i++){
		vector<Mazo> bajara;
	}
}*/ //Era para crear un vector de vectores y asi poder darle una baraja a cada jugador

Jugadores::Jugadores(int numpla/*, int random*/){
	//random+=1; ESTO ERA PARA SOBRE CARGAR EL METODO pero ya no es necesario
	this->numpla=numpla;
	numcartas=floor(40/numpla);//define las cartas que le tocan a cada jugador
	baraja.resize(numcartas);
	
	for (int i=0;i<numpla;i++){//agrega posiciones y da valores a cada una de ellas
		Jugadores jugador;
		jugador.id=(i+1);
		jugador.puntos=0;
		jugador.baraja=m.Repartir(numcartas);//se le reparte una baraja a cada jugador (Repartir retorna una baraja)
		players.push_back(jugador);
	}
	
	if (numcartas%2!=0){//todas las cartas son repartidas
		int tamano=40-(numpla*numcartas);
		m.settamano(tamano);//modifica el tamaño del mazo (Le quita una carta)
		for (int i=0;i<numpla;i++){//Posiblemente cambiar
			baraja=m.Repartir(numpla);
		}
	}
}


void Jugadores::Puntaje(int id){//suma un punto al jugador

	for (int i=0;i<players.size();i++){
		if (players[i].id==id){
			players[i].puntos+=1;
		}
	}
}
 
Mazo Jugadores::Tirar(int id){
	
	int carta;
	cout<<"-----Elegir una carta-----"<<endl;
	Mostrar();
	cin>>carta;
	
	if (carta > 0 && carta <= numcartas) {
        return players[id].baraja[carta - 1];
    } else {
        cout<<"La carta que quieres tirar no existe"<<endl;
        return Mazo();
    }
}

void Jugadores::Mostrar(){
	for (int i=0;i<numcartas;i++){
		cout<<(i+1)<<" Carta: "<<baraja[i].color<<" "<<baraja[i].poder<<endl;
	}
}