#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include <iostream>
#include "MyVector.h"
#include "Misura.h"
#include "Lettura.h"

constexpr int BUFFER_DIM = 10;  //numero di misure nel buffer circolare

class InertialDriver
{    
    public:
        //costruttori
        InertialDriver(); //default
        
        //copia e move (costruttori e operatori standard)
        InertialDriver(const InertialDriver& i) = default;
        InertialDriver(InertialDriver&& i) = default;
        InertialDriver& operator=(InertialDriver&& a) = default;
        InertialDriver& operator=(const InertialDriver& a) = default;
        
        //funzioni membro
        void push_back(Lettura (&l)[SENSORS_NUMBER]);
        Lettura* pop_front();
        void clear_buffer();
        Lettura get_reading(int sensor);
        
        //distruttore (standard)
        ~InertialDriver() = default; 

    private:
        int index; //indice per inserimento nel buffer circolare (punta sempre alla posizione DA RIEMPIRE)
        int buffer_size; //dimensione attualmente utilizzata del buffer
        MyVector<Misura> buffer; //buffer circolare

};

//??? sono da lasciare esterne o private ???
int increment(int i);
int decrement(int i);

#endif  //INERTIALDRIVER_H