#ifndef MANO_HPP
#define MANO_HPP

#include "Mazo.hpp"
#include "raylib.h"

class Mano {

    std::vector<Carta> mano;
    Texture2D imagenMazo;

    private:
        void initCartas();

    public:
        Mano(Mazo &mazo);

        void dibujar();

        std::vector<Carta>& getMano();
};

#endif