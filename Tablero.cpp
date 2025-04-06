#include "./Tablero.h"
#include <iostream>

using namespace std;

/*Tablero::Tablero(){
	contador=0;
	jugadores=0;
}*/

Tablero::Tablero(int jugadores){
    
	this->jugadores=jugadores;
	//this->pdr=&jug;//apunta a la clase jugadores
	cartastemp.resize(jugadores);
	jugador.resize(jugadores);//creo que no lo necesito
	
}

void Tablero::Turno(Jugadores* pdr){
	
	for (int i=0;i<jugadores;i++){
	    
		cout<<"Tira el jugador "<<(i+1)<<endl;
		cartastemp[i]=pdr->Tirar(i+1);
		jugador[i]=i+1;//se usa en el siguiente for
		
	}
	
	clean();
	int idwin=jugador[0];
	int poder=cartastemp[0].poder, pos;
	char color=cartastemp[0].color;
	
	for (int i=0;i<jugadores;i++){
	    
		if (cartastemp[i].color==color){
		    
			if (cartastemp[i].poder>poder){
				poder=cartastemp[i].poder;
				idwin=jugador[i];
			}
			
		}
		
	}
	
	cout<<"El jugador "<<idwin<<" gano la ronda con la Carta: "<<color<<" "<<poder<<endl<<endl;
	pdr->Puntaje(idwin);
	
}

void Tablero::Ganador(vector<Jugadores> player){
    
    int puntos=player[0].puntos;
    int id=player[0].id;
    
    for (int i=0;i<player.size();i++){
        
        if (player[i].puntos>puntos){
            
            puntos=player[i].puntos;
            id=player[i].id;
            
        }
        
    }
    
    cout<<endl;
    cout<<"----EL GANADOR ES----\nJugador "<<id<<" con "<<puntos<<" puntos"<<endl;
    
}

void Tablero::clean(){
    
    #ifdef _WIN32
        system("cls");
    #endif

}
















