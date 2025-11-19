#ifndef MISURA_H
#define MISURA_H

#include <iostream>
#include "Lettura.h"

constexpr int SENSORS_NUMBER = 17;

class Misura
{
    public:
        //costruttori
        Misura();
        Misura(Lettura arr[SENSORS_NUMBER]);
        Misura(std::initializer_list<Lettura> lst);
        Misura(const Misura& m); //copia
        Misura(Misura&& m); //move

        //distruttore 
        ~Misura();

        //operatori copia e move
        Misura& operator=(const Misura& m);
        Misura& operator=(Misura&& m);

        //getter
        Lettura readSensor(int index) const;
    
    private:
        Lettura* sensors;
};

//overload inserimento
std::ostream& operator<<(std::ostream& COUT, const Misura& m);

#endif