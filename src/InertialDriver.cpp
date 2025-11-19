#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/Lettura.h"

//costruttore di default
InertialDriver::InertialDriver()
    :buffer{MyVector<Lettura*>(BUFFER_DIM)}, index{0}, buffer_size{0}
{
    for(int i = 0; i < BUFFER_DIM; i++)
    {
        this->buffer[i] = new Lettura[SENSORS_NUMBER];
    }
}

//funzioni membro
void InertialDriver::push_back(Lettura (&l)[SENSORS_NUMBER])
{
    std::copy(l, l + SENSORS_NUMBER, buffer[this->index]);
    this->index = increment(this->index);
    if(buffer_size < BUFFER_DIM)
    { buffer_size++; }
}
Lettura* InertialDriver::pop_front()
{
    if(buffer_size == 0) { return nullptr; } //il buffer è vuoto
    int i = this->index;
    for(int j = 0; j < BUFFER_DIM - buffer_size; j++)
    {
        i = increment(i);
    }
    Lettura* front = new Lettura[SENSORS_NUMBER];
    std::copy(this->buffer[i], this->buffer[i] + SENSORS_NUMBER, front);
    delete[] this->buffer[i];
    this->buffer_size--;
    this->buffer[i] = new Lettura[SENSORS_NUMBER];
    return front;
}
void InertialDriver::clear_buffer()
{
    for(int i = 0; i < BUFFER_DIM; i++)
    {
        delete[] this->buffer[this->index];
        this->buffer[this->index] = new Lettura[SENSORS_NUMBER];
        this->index = increment(this->index); 
    }
}
Lettura InertialDriver::get_reading(int sensor)
{
    if(sensor < 0 || sensor > SENSORS_NUMBER - 1) { throw std::invalid_argument("Inserire un numero di sensore valido"); }
    int i = decrement(this->index);
    return this->buffer[i][sensor];
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