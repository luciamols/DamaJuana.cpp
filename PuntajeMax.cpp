#include <iostream>
using namespace std;
#include "PuntajeMax.h"

int PuntajeMax::getPuntajeMax(){
    leerPuntaje();
    return puntajeMax;}

void PuntajeMax::setPuntajeMax(int p){puntajeMax=p;}

void PuntajeMax::grabarPuntaje(){
    FILE *p;
    p=fopen("puntajeMax", "ab");
    if (p==NULL){
        cout << "ERROR" << endl ;
        return;
    }
    fwrite(this, sizeof(PuntajeMax), 1, p);
    fclose(p);
    }

void PuntajeMax::leerPuntaje(){
    FILE *p;
    int leer=fread(this, sizeof PuntajeMax, 1, p);
    if (leer==0){
        cout << "Error" << endl ;
    }
    fclose(p);
}
