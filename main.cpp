#include "raylib.h"
#include "recursos/Mesa.cpp"
#include "recursos/Carta.h"
#include "recursos/Mazo.cpp"

int main(){

    InitWindow(1000, 600, "Cuarenta");

    Mesa mesa;
    Carta carta = Carta(DIAMANTE, 5);

    while(!WindowShouldClose()){
        carta.DragAndDrop();

        BeginDrawing();

            ClearBackground(BLACK);

            mesa.dibujar();
            carta.dibujar();

        EndDrawing();

    }

    CloseWindow();

    return 0;
}
