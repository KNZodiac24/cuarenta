#ifndef MAZO_HPP
#define MAZO_HPP

#include "Carta.hpp"
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
