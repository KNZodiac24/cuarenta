#ifndef MAZO_H
#define MAZO_H

#include "Carta.h"
#include <vector>

class Mazo {

    std::vector<Carta> mazo;

    private:
        void barajar();

    public:
        Mazo();

        std::vector<Carta>& getMazo();

        void actualizarMazo();
};

#endif
