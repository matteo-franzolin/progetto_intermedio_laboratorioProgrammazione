#include <iostream>
#include "../include/Lettura.h"
#include "../include/InertialDriver.h"

int main(void)
{
    Lettura l0 = {1.1,2.2,3.3,4.4,5.5,6.6};
    std::cout << l0 << "\n";

    InertialDriver iD;
    Lettura misura1[17];
    misura1[0] = l0;
    std::cout << misura1;
    iD.push_back(misura1);
    
    return 0;
}