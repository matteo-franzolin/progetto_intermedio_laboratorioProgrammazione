#include <iostream>
#include "../include/Lettura.h"

//costruttore di defualt e con valori double
Lettura::Lettura()
    :yaw_v{0},yaw_a{0},pitch_v{0},pitch_a{0},roll_v{0},roll_a{0}
{}
Lettura::Lettura(double yv, double ya, double pv, double pa, double rv, double ra)
    :yaw_v{yv},yaw_a{ya},pitch_v{pv},pitch_a{pa},roll_v{rv},roll_a{ra}
{}
//costruttore con initializer list
Lettura::Lettura(std::initializer_list<double> lst)
{
    if(lst.size() != 6) 
    { throw std::invalid_argument("Il numero di valori non è coerente con una lettura: inserire yaw_velocity, yaw_acceleration, pitch_velocity, pitch_acceleration, roll_velocity, roll_acceleration"); }

    double t[6];
    std::copy(lst.begin(),lst.end(),t);
    this->yaw_v = t[0];
    this->yaw_a = t[1];
    this->pitch_v = t[2];
    this->pitch_a = t[3];
    this->roll_v = t[4];
    this->roll_a = t[5];
}

//getter dei valori
double Lettura::getYawVel() const { return yaw_v; }
double Lettura::getPitchVel() const { return pitch_v; }
double Lettura::getRollVel() const { return roll_v; }
double Lettura::getYawAcc() const { return yaw_a; }
double Lettura::getPitchAcc() const { return pitch_a; }
double Lettura::getRollAcc() const { return roll_a; }


//overload operatore di inserimento
std::ostream &operator<<(std::ostream& COUT, const Lettura& l)
{
    COUT << "YAW  velocity: " << l.getYawVel() << " acceleration: " << l.getYawAcc() << "\n"
         << "PITCH  velocity: " << l.getPitchVel() << " acceleration: " << l.getPitchAcc() << "\n"
         << "ROLL  velocity: " << l.getRollVel() << " acceleration: " << l.getRollAcc() << "\n";
    
    return COUT;
}
