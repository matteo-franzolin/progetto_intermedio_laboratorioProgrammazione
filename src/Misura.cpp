#include "../include/Misura.h"

//costruttore default
Misura::Misura()
    :sensors{new Lettura[SENSORS_NUMBER]}
{

}
//costruttore con array
Misura::Misura(Lettura (&l)[SENSORS_NUMBER])
    :sensors{new Lettura[SENSORS_NUMBER]}
{
    std::copy(l, l + SENSORS_NUMBER, this->sensors);
}
//costruttori copia e move
Misura::Misura(const Misura& m)
    :sensors{new Lettura[SENSORS_NUMBER]}
{
    std::copy(m.sensors, m.sensors + SENSORS_NUMBER, this->sensors);
}
Misura::Misura(Misura&& m)
{
    this->sensors = m.sensors;
    m.sensors = nullptr;
}
//distruttore
Misura::~Misura()
{
    delete[] this->sensors;
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
//getter
Lettura* Misura::get_sensors() const
{
    Lettura* temp = new Lettura[SENSORS_NUMBER];
    std::copy(this->sensors, this->sensors + SENSORS_NUMBER, temp);
    return temp;
}

//overload <<
std::ostream& operator<<(std::ostream& COUT, const Misura& m)
{
    const Lettura* sensors = m.get_sensors();
    for(int i = 0; i < SENSORS_NUMBER; i++)
    {
        COUT << "Sensore " << i << "\n" << sensors[i] << "\n";
    }
    return COUT;
}