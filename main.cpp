#include "include/raylib.h"

int main(){

    InitWindow(1000, 600, "Cuarenta");

    while(!WindowShouldClose()){

        BeginDrawing();

            ClearBackground(BLACK);
            
        EndDrawing();

    }

    CloseWindow();

    return 0;
}
