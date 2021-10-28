#include <iostream>
using namespace std;
#include "Jugar.h"
#include "PuntajeMax.h"

//CONSTRUCTOR
// inicia pantalla y setea valores iniciales

Jugar::Jugar()
{
    int vidas=3;
    int nivel=1;
    int puntaje=0;
    bool juegoIniciado=false;
    bool fin=false;
    bool nuevoNivel=false;
    bool enJuego=false;
    bool muerte=false;
    bool finJuego=false;
    int velocidad=3;
    //bola y ladrillos
    int dirY=-1;
    int dirX=1;
    int baseX=255;
    int bolaX=295;
    int bolaY=650;
}

//SETS Y GETS

int Jugar::getVidas(){return vidas;}

int Jugar::getNivel(){return nivel;}

int Jugar::getPuntaje(){return puntaje;}

void Jugar::setVidas(int v){vidas=v;}

void Jugar::setNivel(int n){nivel=n;}

void Jugar::setPuntaje(int p){puntaje=p;}

void Jugar::armoPantalla(){
    // logo y nombre del juego

    // nivel, puntaje y vidas
    cout << "Nivel: " << getNivel() << "    " ;
    cout << "Puntaje: " << getPuntaje() << "    " ;
    cout << "Vidas: " << getVidas() << endl ;

    // recuadro de los ladrillos

    // Explota la base cuando perdemos

    // bola y base
    if(enJuego){
        // la base empieza a donde termino el juego anterior (perdimos)
    }
    else {
        // la base empieza en el medio (nuevo nivel)
    }
    // ladrillos
    muestroLadrillos();

    // gameover
    if(vidas==0) cout << "GAME OVER" << endl ;
}

void Jugar::nuevoJuego(){
    // Si ya venia jugando, reestablesco el nivel en 1
    nivel=1;
    finJuego=false;

    while (finJuego==false){

        retomaJuego();

        while (nuevoNivel==false && vidas>0){  // no estoy empezando nivel. me quedan 3 vidas o menos
            if(enJuego==false){   // empiezo a jugar
                enJuego=true;
            }

            if (enJuego) {  // si ya empece el juego la bola se tiene que mover
                muevoBola();
                muestroLadrillos();
            }

            if(cuentoLadrillos()==0){  // si rompi todos los ladrillos paso de nivel
                nivel++;
                nuevoNivel=true;
                retomaJuego();
            }
            armoPantalla();

            if (vidas==0) finJuego=true; // si me quede sin vidas pierdo
        }
    }
}

void Jugar::retomaJuego(){  // empieza nivel nuevo. La bola vuelve a la base
    // bola en la base
    baseX=255;
    bolaX=295;
    bolaY=650;
    enJuego=false;
    nuevoNivel=false;
    armoPantalla();
}

void Jugar::chequeoPuntaje(){ // solo quiero grabar el puntaje
    PuntajeMax aux;
    aux.leerPuntaje();
    if (puntaje>aux.getPuntajeMax()){
        aux.setPuntajeMax(puntaje);
        aux.grabarPuntaje();
    }
}

void Jugar::muevoBola(){   // algoritmos de movimiento
    int puntaIzq=baseX+20;  // establezco los limites de la pantalla
    int puntaDer=baseX+100;
    int colBola;
    int filaBola;
    int elemento;

    if(bolaY<225){    // algoritmo de movimiento de la bola cerca de la base
        filaBola=((int)(((bolaY-20)/30))+1);
        colBola=((int)(bolaX-13)/64)+1;
        elemento=(((filaBola-1)*9)+colBola)-1;

       /* if(mapa[elemento]!=0) {  // si golpea un ladrillo entonces rebota:

            if (dirY==1) dirY=-1; // si viene subiendo cambio de direccion hacia abajo
            else dirY=1;   // si viene bajando cambio de direccion hacia arriba

            // Rompe el ladrillo
            mapa[elemento]=0;   //desaparece el ladrillo
            puntaje=puntaje+10;
            muestroLadrillos();
        }
        else {
            if (bolaY>650 && dirY==1) {   // viene bajando chequeo que caiga en la base
                if (bolaX>=baseX && bolaX<=baseX+120) {
                    // que parte de la base toco
                    if(bolaX<=puntaIzq) dirX=-1;   //va para la derecha
                    if(bolaX>=puntaDer) dirX=1;     // va para la izquierda

                    dirY=-1; // siempre va a subir despues de tocar la base
                    return;
                }
                else {
                    // no llego a salvar la bola con la base
                    vidas--;
                    if (vidas>0) retomaJuego();
                    return;
                }
            }
        }*/
        // bola en el medio de la pantalla. chequeo si toca los bordes y rebota
        if (bolaX>580) dirX=-1;
        if (bolaX<15) dirX=1;
        if (bolaY<15) dirY=1;

        // movimiento de la bola
        if (dirX==1) bolaX=bolaX+velocidad;
        if (dirX==-1) bolaX=bolaX-velocidad;
        if (dirY==1) bolaY=bolaY+velocidad;
        if (dirY==-1) bolaY=bolaY-velocidad;

        armoPantalla();
    }
}

void Jugar::muestroLadrillos(){

}
