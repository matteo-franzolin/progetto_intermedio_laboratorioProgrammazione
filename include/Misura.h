#ifndef MISURA_H
#define MISURA_H

#include "Lettura.h"

constexpr int SENSORS_NUMBER = 17; //numero di sensori per ogni misura

class Misura
{
    public:
        //costruttori
        Misura(); //default
        Misura(Lettura (&l)[SENSORS_NUMBER]); //con array
        
        //costruttori e operatori copia e move
        Misura(const Misura& m);
        Misura(Misura&& m);
        Misura& operator=(const Misura& m);
        Misura& operator=(Misura&& m);

        //accesso ai dati
        Lettura* get_sensors() const;
        
        //distruttore
        ~Misura();

    private:
        Lettura* sensors; //l'array delle letture di tutti i sensori
};

//overload <<
std::ostream& operator<<(std::ostream& COUT, const Misura& m);
#endif