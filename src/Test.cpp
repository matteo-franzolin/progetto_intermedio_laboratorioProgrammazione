#include <iostream>
#include "../include/Lettura.h"
#include "../include/Misura.h"
#include "../include/InertialDriver.h"

int main(void)
{
    Lettura l1 = {1.1,2.2,3.3,4.4,5.5,6.6};
    std::cout << l1 << "\n";
    Lettura l2 = l1;
    Lettura l3 = l1;
    Lettura l4 = l1;
    Lettura l5 = l1;
    Lettura l6 = l2;
    Lettura l7 = l3;
    Lettura l8 = l4;
    Lettura l9 = l5;
    Lettura l10 = l1;
    Lettura l11 = l1;
    Lettura l12 = l1;
    Lettura l13 = l1;
    Lettura l14 = l1;
    Lettura l15 = l1;
    Lettura l16 = l1;
    Lettura l17 = l1;

    InertialDriver iD;
    Lettura misura1[17] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l3,l14,l15,l16,l17};
    iD.push_back(misura1);
    
    Misura m1 = misura1;
    Misura m2;
    m2 = m1;
    std::cout << m2;
    return 0;
}