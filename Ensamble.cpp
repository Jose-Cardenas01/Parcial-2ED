#include "./Tablero.h"
#include <iostream>

using namespace std;

int Ensamble() {
    Mazo m;

    m.Inicio(40); // Inicializa el mazo
    m.Revolver(); // Mezcla las cartas

    int numpla;
    cout << "Ingrese la cantidad de jugadores (2-5): " << endl;  
    cin >> numpla;

    if (numpla < 2 || numpla > 5) { // Validación de número de jugadores
        cout << "Error: Elegir entre 2 y 5 jugadores." << endl;
        return 1;
    }

    Jugadores jug(numpla);
    Tablero tab(numpla, jug);

    bool seguir = false;
    while (!seguir) {  // Mientras el juego no termine
        tab.Turno();
        seguir = tab.final();
        cout << "Estado del juego: " << (seguir ? "Finalizado" : "Continúa") << endl;
    }

    cout << "El juego ha finalizado." << endl;
    return 0;
}
