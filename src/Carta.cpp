#include "raylib.h"
#include "Carta.hpp"
#include <iostream>

Carta::Carta(unsigned short palo, unsigned short numero){
    this->palo = palo;
    this->numero = numero - 1;
    this->esPerro = (numero >= 8 && numero <= 10);
    this->hitbox = Rectangle{0.0f, 0.0f, 79.0f, 123.0f};
}

void Carta::setPosicion(Vector2 pos){
    this->hitbox.x = pos.x;
    this->hitbox.y = pos.y;
}

Vector2 Carta::getPosicion(){
    return Vector2{this->hitbox.x, this->hitbox.y};
}

Rectangle& Carta::getHitbox(){
    return this->hitbox;
}

bool Carta::getEsPerro(){
    return this->esPerro;
}

void Carta::dibujar(Texture2D img){
    if (CheckCollisionPointRec(GetMousePosition(), this->hitbox)) DrawRectangleRoundedLines(this->hitbox, 0.07f, 0, 4.0f, YELLOW); // Sombreado al pasar sobre la carta
    DrawTexturePro(img,
                   Rectangle{this->numero*this->hitbox.width, this->palo*this->hitbox.height,79.0f,123.0f}, 
                   Rectangle{this->hitbox.x+this->hitbox.width/2, this->hitbox.y+this->hitbox.height/2, this->hitbox.width, this->hitbox.height},
                   Vector2{this->hitbox.width/2, this->hitbox.height/2},
                   0.0f,
                   WHITE);
}

void Carta::DragAndDrop() {
        
    if (CheckCollisionPointRec(GetMousePosition(), this->hitbox)) {
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            this->estaArrastrando = true;
            this->diffX = GetMouseX() - this->hitbox.x;
            this->diffY = GetMouseY() - this->hitbox.y;
        }
    }

    if (estaArrastrando && IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
        this->hitbox.x = GetMouseX() - this->diffX;
        this->hitbox.y = GetMouseY() - this->diffY;
    }

    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) this->estaArrastrando = false;
}

// Método necesario para barajar
void swap(Carta &a, Carta &b) {
    std::swap(a.palo, b.palo);
    std::swap(a.numero, b.numero);
}

