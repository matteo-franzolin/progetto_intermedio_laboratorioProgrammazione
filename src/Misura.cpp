#include "../include/Misura.h"
#include "../include/Lettura.h"

//costruttori defualt e con parametri
Misura::Misura()
    :sensors{}
{}
Misura::Misura(Lettura arr[SENSORS_NUMBER])
    :sensors{}
{
    std::copy(arr, arr+SENSORS_NUMBER, this->sensors);
}
Misura::Misura(std::initializer_list<Lettura> lst)
    :sensors{}
{
    if(lst.size() != SENSORS_NUMBER) { throw std::invalid_argument("Inserire tutte le 17 letture"); }
    std::copy(lst.begin(), lst.end(), this->sensors);
}

//lettura dati
Lettura Misura::readSensor(int index) const
{
    if(index < 0 || index >= SENSORS_NUMBER)
    { throw std::invalid_argument("Indice non valido: inserire un numero di sensore corretto (0-16)"); }
    return this->sensors[index];
}
//overload di <<
std::ostream& operator<<(std::ostream& COUT, const Misura& m)
{
    for(int i = 0; i < SENSORS_NUMBER; i++)
    {
        COUT << "Sensore " << i << "\n" << m.readSensor(i);
    }
    return COUT;
}