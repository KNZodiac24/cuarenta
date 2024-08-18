#include "raylib.h"
#include "Mazo.h"
#include "Carta.h"
#include "Mano.h"
#include <vector>
#include <iostream>


Mano::Mano(Mazo &mazo){
    this->mano = std::vector<Carta>(mazo.getMazo().begin(), mazo.getMazo().begin() + 5);
    mazo.actualizarMazo();

    this->imagenMazo = LoadTexture("recursos/img/mazo_cartas.png");
    this->initCartas();
}

void Mano::initCartas(){
    short aux = 0;
    for(Carta &carta: this->mano){
        carta.setPosicion(Vector2{aux+302.0f, 477.0f});
        aux += 79;
    }
}

void Mano::dibujar(){
    for(Carta &carta: this->mano){
        carta.dibujar(this->imagenMazo);
    }
}

std::vector<Carta>& Mano::getMano(){
    return this->mano;
}
