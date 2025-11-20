#include <iostream>
#include "../include/InertialDriver.h"
#include "../include/Misura.h"
#include "../include/Lettura.h"

//costruttore di default
InertialDriver::InertialDriver()
    :buffer{MyVector<Misura>(BUFFER_DIM)}, index{0}, buffer_size{0}
{
    
}

//funzioni membro
void InertialDriver::push_back(Lettura (&l)[SENSORS_NUMBER])
{   
    //viene inserita nel buffer una misura con i dati dell'array l
    Misura m = l;
    this->buffer[this->index] = m;
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
    Lettura* front = this->buffer[i].get_sensors();
    //si pulisce la misura nel buffer
    this->buffer[i] = Misura();
    //diminuzione del buffer_size
    this->buffer_size--;
    //si ritorna l'oggetto salvato prima
    return front;
}
void InertialDriver::clear_buffer()
{
    for(int i = 0; i < BUFFER_DIM; i++)
    {
        //inizializzazione di una nuova misura vuota
        this->buffer[this->index] = Misura();
        //passaggio al puntatore successivo
        this->index = increment(this->index); 
    }
    //azzeramento del buffer_size
    this->buffer_size = 0;
}
Lettura InertialDriver::get_reading(int sensor)
{
    if(buffer_size == 0) { throw std::out_of_range("Il buffer è vuoto, impossibile reperire una lettura"); }
    //controllo della correttezza dell'indice
    if(sensor < 0 || sensor > SENSORS_NUMBER - 1) { throw std::invalid_argument("Inserire un numero di sensore valido"); }
    //si trova l'elemento più recente e si ritorna il sensore richiesto
    int i = decrement(this->index);
    return this->buffer[i].get_sensors()[sensor];
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