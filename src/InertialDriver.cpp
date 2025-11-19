#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/Lettura.h"
#include "../include/Misura.h"

//costruttore di default
InertialDriver::InertialDriver()
    :buffer{MyVector<Misura>(BUFFER_DIM)}, index{0}
{
    
}
InertialDriver::InertialDriver(std::initializer_list<Misura> lst)
    :buffer{MyVector<Misura>(BUFFER_DIM)}, index{0}
{
    Misura temp[lst.size()];
    std::copy(lst.begin(), lst.end(), temp);
    for(int i = 0; i < lst.size(); i++)
    {
        this->push_back(temp[i]);
    }
}

//funzioni membro
void InertialDriver::push_back(Misura& m)
{
    buffer[index] = m;
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