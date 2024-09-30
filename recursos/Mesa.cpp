#include "raylib.h"
#include <iostream>
#include <vector>

#define ESPACIOS_TOTALES 12

class Mesa{

    float x = 150.0f;
    float y = 100.0f;
    float ancho = 700.0f;
    float alto = 400.0f;

    Rectangle areaJugable;
    std::vector<Rectangle> tempEspacios;
    unsigned char espaciosOcupados = 0;

    private:
        void initEspaciosMesa(){
            unsigned short auxFila = 0;
            for(unsigned char i = 0; i < 6; i++){ // Al inicio la mesa solo tendrá 6 espacios disponibles/vacíos
                this->tempEspacios.push_back(Rectangle{areaJugable.x+18.0f+auxFila, areaJugable.y+88.0f, 79.0f, 123.0f});
                auxFila += 97; // 79 del ancho de cada carta + 18 para el espacio entre cartas
            }
        }

    public:
        Mesa(){
            this->areaJugable = Rectangle{this->x+50.0f, this->y+50.0f, this->ancho-100.0f, this->alto-100.0f};

            initEspaciosMesa();

            /*for (unsigned short i = 0; i < ESPACIOS_TOTALES; i++){
                if(i < 6){
                    this->tempEspacios.push_back(Rectangle{areaJugable.x+18.0f+auxFila1, areaJugable.y+18.0f, 79.0f, 123.0f});
                    auxFila1 += 97.0f; 
                 }else{
                    this->tempEspacios.push_back(Rectangle{areaJugable.x+18.0f+auxFila2, areaJugable.y+159.0f, 79.0f, 123.0f});
                    auxFila2 += 97.0f;
                }
            }*/
        }

        void actualizarEspaciosMesa(){
            if(espaciosOcupados <= 6){
                
            }
        }

        void dibujar(){
            DrawRectangleRounded(Rectangle{125, 75, 750, 450}, 0.1f, 0, DARKBROWN);
            DrawRectangle(150, 100, 700, 400, DARKGREEN);
            DrawRectangleRec(this->areaJugable, RED);
            for(Rectangle& rec: tempEspacios){
                DrawRectangleRec(rec, WHITE);
            }
        }

};
