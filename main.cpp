#include <iostream>
#include "Jugar.h"
#include "PuntajeMax.h"
using namespace std;

int main(){
    int opcion=1;
    Jugar juego;
    PuntajeMax puntaje;

    while(opcion){
        cout << "MENU" << endl << endl ;
        cout << "1- Comenzar juego" << endl ;
        cout << "2- Mejor puntuacion " << endl ;
        cout << "0- Salir " << endl << endl ;
        cout << "Elige una opcion: " << endl ;
        cin >> opcion;

        switch (opcion) {
        case 1:
            juego.armoPantalla();
            juego.nuevoJuego();
            juego.chequeoPuntaje();
            break;
        case 2:
            // Puntaje maximo
            cout << "Puntaje maximo: " << puntaje.getPuntajeMax() << endl;
            break;
        case 3:
            break;
        case 0:
            juego.chequeoPuntaje();
            return 0;
            break;
        default:
            cout << "Opcion incorrecta" << endl;
        }
        system ("pause");
    }
}
