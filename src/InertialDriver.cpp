#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/Lettura.h"

//costruttore di default
InertialDriver::InertialDriver()
    :buffer{MyVector<Lettura*>(BUFFER_DIM)}, index{0}, buffer_size{0}
{
    //inizializzazione degli array nel buffer
    for(int i = 0; i < BUFFER_DIM; i++)
    {
        this->buffer[i] = new Lettura[SENSORS_NUMBER];
    }
}

//funzioni membro
void InertialDriver::push_back(Lettura (&l)[SENSORS_NUMBER])
{   
    //i valori dell'array l vengono copiati nel buffer
    std::copy(l, l + SENSORS_NUMBER, buffer[this->index]); 
    //incremento dell'indice nel buffer
    this->index = increment(this->index);
    //eventuale incremento del buffer_size se non è già pieno
    if(buffer_size < BUFFER_DIM)
    { buffer_size++; }
}
Lettura* InertialDriver::pop_front()
{
    if(buffer_size == 0) { return nullptr; } //il buffer è vuoto
    //viene individuata la posizione dell'ultimo elemento inserito
    int i = this->index;
    for(int j = 0; j < BUFFER_DIM - buffer_size; j++)
    {
        i = increment(i);
    }
    //si salva l'array trovato
    Lettura* front = this->buffer[i];
    //si riassegna il puntatore nel buffer a un array vuoto
    this->buffer[i] = new Lettura[SENSORS_NUMBER];
    //diminuzione del buffer_size
    this->buffer_size--;
    //si ritorna l'oggetto salvato prima
    return front;
}
void InertialDriver::clear_buffer()
{
    for(int i = 0; i < BUFFER_DIM; i++)
    {
        //eliminazione del puntatore
        delete[] this->buffer[this->index];
        //inizializzazione di un nuovo array vuoto
        this->buffer[this->index] = new Lettura[SENSORS_NUMBER];
        //passaggio al puntatore successivo
        this->index = increment(this->index); 
    }
    //azzeramento del buffer_size
    this->buffer_size = 0;
}
Lettura InertialDriver::get_reading(int sensor)
{
    //controllo della correttezza dell'indice
    if(sensor < 0 || sensor > SENSORS_NUMBER - 1) { throw std::invalid_argument("Inserire un numero di sensore valido"); }
    //si trova l'elemento più recente e si ritorna
    int i = decrement(this->index);
    return this->buffer[i][sensor];
}

int increment(int i)
{
    if(i < BUFFER_DIM - 1)
    { return i + 1; }
    else
    { return 0; }
}
int decrement(int i)
{
    if(i > 0)
    { return i - 1; }
    else
    { return BUFFER_DIM - 1; }
}