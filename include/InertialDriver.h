#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include <iostream>
#include "MyVector.h"
#include "Lettura.h"

constexpr int BUFFER_DIM = 10;  //Numero provvisorio di misure (17 letture a misura). INERTIAL DRIVER INIZIALIZZA CON PIU' MISURE!!

class InertialDriver
{    
    public:
        //costruttori
        InertialDriver(); //default
        InertialDriver(std::initializer_list<Misura> lst);
        //InertialDriver();  //move
        //InertialDriver();  //copy

        InertialDriver operator=(InertialDriver&& a);  //assegnamento move
        InertialDriver& operator=(const InertialDriver& a);  //assegnamento copy
        
        void push_back(Misura& m);
        Lettura* pop_front();
        void clear_buffer();
        Lettura* get_reading(int index);

        //distruttore
        //~InertialDriver();

    private:
        int index;
        MyVector<Misura> buffer;

};

//??? sono da lasciare esterne o private ???
int increment(int i);
int decrement(int i);

#endif  //INERTIALDRIVER_H