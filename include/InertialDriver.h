#ifndef INERTIALDRIVER_H
#define INERTIALDRIVER_H

#include <iostream>
#include "MyVector.h"

class InertialDriver{
    
    public:
    
    explicit InertialDriver();  //default
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
    
    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;
    
    const int BUFFER_DIM = 17;

    MyVector buffer(BUFFER_DIM);

}

#endif  //INERTIALDRIVER_H