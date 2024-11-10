#include "raylib.h"
#include "Mesa.cpp"
#include "Mazo.hpp"
#include "Mano.hpp"

int main(){

    InitWindow(1000, 600, "Cuarenta");
    SetTargetFPS(60);
    SetConfigFlags(FLAG_VSYNC_HINT);
    EnableEventWaiting();

    Mesa mesa;
    Mazo mazo = Mazo();
    Mano mano1 = Mano(mazo);

    while(!WindowShouldClose()){
        
        for(Carta& carta: mano1.getMano()){
            carta.DragAndDrop();
        }

        BeginDrawing();

            ClearBackground(BLACK);

            mesa.dibujar();
            mano1.dibujar();

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
