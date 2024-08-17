#include "raylib.h"
#include "Carta.h"
#include <vector>
#include <algorithm>
#include <random>
#include <iostream>

class Mazo {

    std::vector<Carta> mazo;

    private:
        void barajar(){
            std::random_device rd;
            std::mt19937 g(rd());
            std::shuffle(this->mazo.begin(), this->mazo.end(), g);
        }

    public:
        Mazo(){
            for(unsigned short palo = TREBOL; palo <= PICA; palo++){
                for(unsigned short num = 0; num < 13; num++){
                    Carta temp = Carta(palo, num);
                    if(!temp.getEsPerro()) this->mazo.push_back(temp);
                }
            }

            if (!this->mazo.empty()) {
                this->barajar();
            }
        }

};