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

        //getter
        Lettura readSensor(int index) const;
    
    private:
        Lettura sensors[SENSORS_NUMBER]; //non è allocato dinamicamente
};

//overload inserimento
std::ostream& operator<<(std::ostream& COUT, const Misura& m);

#endif