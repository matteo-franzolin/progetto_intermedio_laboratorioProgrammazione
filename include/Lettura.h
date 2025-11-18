#ifndef LETTURA_H
#define LETTURA_H

#include <iostream>

class Lettura
{
    public:
        Lettura(double yv, double ya, double pv, double pa, double rv, double ra);
        Lettura(std::initializer_list<double> lst);

    private:

    double yaw_v;
    double yaw_a;
    double pitch_v;
    double pitch_a;
    double roll_v;
    double roll_a;

};

#endif