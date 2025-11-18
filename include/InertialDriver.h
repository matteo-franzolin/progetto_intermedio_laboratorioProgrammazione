#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include <iostream>
#include "MyVector.h"

class InertialDriver{
    
    public:
    
    InertialDriver();  //default
    InertialDriver(std::initializer_list<MyVector> lst);
    InertialDriver();
    InertialDriver();  //move
    InertialDriver();  //copy

    InertialDriver operator=(InertialDriver&& a);  //assegnamento move
    InertialDriver& operator=(const InertialDriver& a);  //assegnamento copy
    
    void push_back(double* array);
    double* pop_front();
    void clear_buffer();
    double* get_reading(int index);

    ~InertialDriver();  //Distruttore

    private:
    
    /* DA COPIARE !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;

    double[] lettura {yaw_v, yaw_a, pitch_v, pitch_a, roll_v, roll_a};
    */

    const int BUFFER_DIM = 1;  //Numero provvisorio di misure (17 letture a misura). INERTIAL DRIVER INIZIALIZZA CON PIU' MISURE!!



    MyVector buffer(BUFFER_DIM);

};

#endif  //INERTIALDRIVER_H