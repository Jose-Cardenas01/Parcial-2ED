#include "./Tablero.h"
#include <iostream>

using namespace std;

int main(){
    
    Mazo m(36);//Inicializa el mazo
    Mazo* pdrmazo=&m;

    pdrmazo->Revolver();//Mezcla las cartas
	
    int numpla;
    cout<<"Ingrese la cantidad de jugadores (2-4): "<<endl; cin>>numpla;

    if (numpla<2 || numpla>4){
        
        cout<<"Solo se pueden elegir de 2 a 4 jugadores"<<endl;
        return 1;
        
    }
    
    cout<<"commit 1";

    Jugadores jug(numpla, pdrmazo);
    cout<<"Commit 2";
    Jugadores* pdrjug=&jug;
    Tablero tab;
    Tablero* pdrtab=&tab;
    Tablero tab2(numpla);
    int size=pdrjug->getnumcartas();
    
    cout<<"Commit 3";

    for (int i=0;i<size;i++){
    
        pdrtab->Turno(pdrjug);
        
    }

    cout << "El juego ha finalizado." << endl;
    return 0;
    
}