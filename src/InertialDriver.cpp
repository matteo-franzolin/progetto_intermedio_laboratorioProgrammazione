#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/Lettura.h"

//costruttore di default
InertialDriver::InertialDriver()
    :buffer{MyVector<Lettura*>(BUFFER_DIM)}, index{0}
{
    
}

//funzioni membro
void InertialDriver::push_back(Lettura (&l)[17])
{
    buffer[index] = l;
    this->index = increment(index);
}

int increment(int i)
{
    if(i < BUFFER_DIM - 1)
    { return i + 1; }
    else
    { return BUFFER_DIM - i; }
}
int decrement(int i)
{
    if(i > 0)
    { return i - 1; }
    else
    { return BUFFER_DIM - 1; }
}