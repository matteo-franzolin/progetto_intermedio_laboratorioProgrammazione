#include "../include/Misura.h"
#include "../include/Lettura.h"

//costruttori defualt e con parametri
Misura::Misura()
    :sensors{new Lettura[SENSORS_NUMBER]}
{

}
Misura::Misura(Lettura arr[SENSORS_NUMBER])
    :sensors{new Lettura[SENSORS_NUMBER]}
{
    std::copy(arr, arr+SENSORS_NUMBER, this->sensors);
}
Misura::Misura(std::initializer_list<Lettura> lst)
    :sensors{new Lettura[SENSORS_NUMBER]}
{
    std::copy(lst.begin(), lst.end(), sensors);
}

//costruttori copia e move
Misura::Misura(const Misura& m)
    :sensors{new Lettura[SENSORS_NUMBER]}
{
    std::copy(m.sensors, m.sensors+SENSORS_NUMBER, this->sensors);
}
Misura::Misura(Misura&& m)
    :sensors{new Lettura[SENSORS_NUMBER]}
{
    this->sensors = m.sensors;
    m.sensors = nullptr;
}

//distruttore
Misura::~Misura()
{
    delete[] sensors;
}

//operatori copia e move
Misura& Misura::operator=(const Misura& m)
{
    std::copy(m.sensors, m.sensors + SENSORS_NUMBER, this->sensors);
    return *this;
}
Misura& Misura::operator=(Misura&& m)
{
    delete[] this->sensors;
    this->sensors = m.sensors;
    m.sensors = nullptr;
    return *this;
}

Lettura Misura::readSensor(int index) const
{
    if(index < 0 || index >= 17)
    { throw std::invalid_argument("Indice non valido: inserire il sensore corretto (0-16)"); }
    return this->sensors[index];
}

std::ostream& operator<<(std::ostream& COUT, const Misura& m)
{
    for(int i = 0; i < 17; i++)
    {
        COUT << "Sensore " << i << "\n" << m.readSensor(i);
    }
    return COUT;
}