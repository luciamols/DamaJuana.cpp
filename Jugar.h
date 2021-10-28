#ifndef JUGAR_H
#define JUGAR_H

class Jugar{
    private:
        int vidas;
        int nivel;
        bool juegoIniciado;
        bool fin;
        bool nuevoNivel;
        bool enJuego;
        bool muerte;
        bool finJuego;
        int puntaje;
        int dirY;
        int dirX;
        int baseX;
        int bolaX;
        int bolaY;
        int velocidad;
    public:
        Jugar();
        int getVidas();
        int getNivel();
        int getPuntaje();
        void setVidas(int);
        void setNivel(int);
        void setPuntaje(int);
        void armoPantalla();
        void nuevoJuego();
        void retomaJuego();
        void chequeoPuntaje();
        void muevoBola();
        void muestroLadrillos();
        int cuentoLadrillos();
};

#endif // JUGAR_H
