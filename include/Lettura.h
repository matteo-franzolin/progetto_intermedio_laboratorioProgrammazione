#ifndef LETTURA_H
#define LETTURA_H

#include <iostream>

class Lettura
{
    public:
        //costruttori
        explicit Lettura(double yv=0, double ya=0, double pv=0, double pa=0, double rv=0, double ra=0);
        Lettura(std::initializer_list<double> lst);
        Lettura(const Lettura& l); //copia
        Lettura(Lettura&& l); //move

        //funzioni getter
        double getYawVel() const;
        double getPitchVel() const;
        double getRollVel() const;
        double getYawAcc() const;
        double getPitchAcc() const;
        double getRollAcc() const;

        //operatore di copia e move
        Lettura& operator=(const Lettura& l);
        Lettura& operator=(Lettura&& l);

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