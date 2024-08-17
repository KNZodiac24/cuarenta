#ifndef CARTA_H
#define CARTA_H

#include "raylib.h"

enum Palo{
    TREBOL,
    DIAMANTE,
    CORAZON,
    PICA
};

class Carta {

    Texture2D imagenMazo;
    unsigned short palo;
    unsigned short numero; // J = 11, Q = 12, K = 13
    bool esPerro;
    Rectangle hitbox;

    // Atributos necesarios para aplicar el drag and drop
    bool estaArrastrando = false;
    float diffX = 0.0f;
    float diffY = 0.0f;

    public:
        Carta(unsigned short palo, unsigned short numero);

        void setPosicion(Vector2 x);

        Vector2 getPosicion();

        Rectangle getHitbox();

        bool getEsPerro();

        void dibujar();

        void DragAndDrop();

        friend void swap(Carta &a, Carta &b);
};

#endif
