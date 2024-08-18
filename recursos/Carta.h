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

        void setPosicion(Vector2 pos);

        Vector2 getPosicion();

        Rectangle& getHitbox();

        bool getEsPerro();

        void dibujar(Texture2D img);

        void DragAndDrop();

        friend void swap(Carta &a, Carta &b);
};

#endif
