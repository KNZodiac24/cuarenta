#include "Carta.hpp"
#include "Mazo.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

void Mazo::barajar(){
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(this->mazo.begin(), this->mazo.end(), g);
}

Mazo::Mazo(){
    for(unsigned char palo = TREBOL; palo <= PICA; palo++){
        for(unsigned char num = 1; num <= 13; num++){
            Carta temp = Carta(palo, num);
            if(!temp.getEsPerro()) this->mazo.push_back(temp);
        }
    
        if (!this->mazo.empty()) this->barajar();
    }
}

void Mazo::actualizarMazo(){
    this->mazo.erase(this->mazo.begin(), this->mazo.begin() + 5);
}

std::vector<Carta>& Mazo::getMazo(){
    return this->mazo;
}
