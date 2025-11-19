#ifndef LETTURA_H
#define LETTURA_H

#include <iostream>

class Lettura
{
    public:
        //costruttori
        Lettura();
        explicit Lettura(double yv, double ya, double pv, double pa, double rv, double ra);
        Lettura(std::initializer_list<double> lst);

        //copia e move
        Lettura(const Lettura& l) = default;
        Lettura(Lettura&& l) = default;
        Lettura& operator=(const Lettura& l) = default;
        Lettura& operator=(Lettura&& l) = default;

        //funzioni getter
        double getYawVel() const;
        double getPitchVel() const;
        double getRollVel() const;
        double getYawAcc() const;
        double getPitchAcc() const;
        double getRollAcc() const;

    private:
        //dati della lettura
        double yaw_v;
        double yaw_a;
        double pitch_v;
        double pitch_a;
        double roll_v;
        double roll_a;

};

//overload operatore di inserimento
std::ostream& operator<<(std::ostream& COUT,const Lettura& l);

#endif