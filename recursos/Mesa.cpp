#include "raylib.h"

class Mesa{

    public:
        void dibujar(){
            DrawRectangleRounded(Rectangle{125, 75, 750, 450}, 0.1f, 0, DARKBROWN);
            DrawRectangle(150, 100, 700, 400, DARKGREEN);
        }

};