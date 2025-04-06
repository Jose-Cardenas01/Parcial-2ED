#include "./Tablero.h"
#include <iostream>

using namespace std;

int main(){
    
    Mazo m(36);//Inicializa el mazo

    m.Revolver();//Mezcla las cartas
	
    int numpla;
    cout<<"Ingrese la cantidad de jugadores (2-4): "<<endl; cin>>numpla;

    if (numpla<2 || numpla>4){
        
        cout<<"Solo se pueden elegir de 2 a 4 jugadores"<<endl;
        return 1;
        
    }

    Jugadores jug(numpla, &m);
    Tablero tab(numpla);
    int tam=jug.getnumcartas();

    for (int i=0;i<tam;i++){
    
        tab.Turno(&jug);
        
    }
    cout<<endl;
    
    tab.Ganador(jug.players);
    
    cout << "El juego ha finalizado." << endl;
    return 0;
    
}





