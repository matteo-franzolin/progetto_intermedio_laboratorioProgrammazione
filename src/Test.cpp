#include <iostream>
#include "../include/Lettura.h"
#include "../include/InertialDriver.h"

int main(void)
{
    Lettura l1 = {1,1,1,1,1,1};
    Lettura l2 = {2,2,2,2,2,2};
    Lettura l3 = {3,3,3,3,3,3};
    Lettura l4 = {4,4,4,4,4,4};
    Lettura l5 = {5,5,5,5,5,5};
    Lettura l6 = {6,6,6,6,6,6};
    Lettura l7 = {7,7,7,7,7,7};
    Lettura l8 = {8,8,8,8,8,8};
    Lettura l9 = {9,9,9,9,9,9};
    Lettura l10 = {10,10,10,10,10,10};
    Lettura l11 = {11,11,11,11,11,11};
    Lettura l12 = {12,12,12,12,12,12};
    Lettura l13 = {13,13,13,13,13,13};
    Lettura l14 = {14,14,14,14,14,14};
    Lettura l15 = {15,15,15,15,15,15};
    Lettura l16 = {16,16,16,16,16,16};
    Lettura l17 = {17,17,17,17,17,17};

    Lettura m1[] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l3,l14,l15,l16,l17};

    InertialDriver d1;
    d1.push_back(m1);

    Lettura* res = d1.pop_front();
    std::cout << res[3];

    return 0;
}