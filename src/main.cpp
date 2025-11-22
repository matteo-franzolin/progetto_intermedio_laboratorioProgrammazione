#include <iostream>
#include "../include/Lettura.h"
#include "../include/Misura.h"
#include "../include/InertialDriver.h"

int main(void)
{
    //creazione di letture
    Lettura l1 = Lettura(); //costruttore default
    Lettura l2 = Lettura(1,1,1,1,1,1); //costruttore con double
    Lettura l3 = {2,2,2,2,2,2}; //costruttore con initializer list
    Lettura l4 = {3,3,3,3,3,3};
    Lettura l5 = {4,4,4,4,4,4};
    Lettura l6 = {5,5,5,5,5,5};
    Lettura l7 = {6,6,6,6,6,6};
    Lettura l8 = {7,7,7,7,7,7};
    Lettura l9 = {8,8,8,8,8,8};
    Lettura l10 = {19,9,9,9,9,9};
    Lettura l11 = {10,10,10,10,10,10};
    Lettura l12 = {11,11,11,11,11,11};
    Lettura l13 = {12,12,12,12,12,12};
    Lettura l14 = {13,13,13,13,13,13};
    Lettura l15 = {14,14,14,14,14,14};
    Lettura l16 = {15,15,15,15,15,15};
    Lettura l17 = {16,16,16,16,16,16};

    //creazione IntertialDriver
    InertialDriver driver = InertialDriver();
    Lettura misura1[] = {l1,l2,l3,l4,l5,l6,l7,l8,l9,l10,l11,l12,l13,l14,l15,l16,l17}; //la prima misura

    //push_back
    driver.push_back(misura1);
    
    //get_reading
    int sensor = 3;
    std::cout << "Accedo al sensore " << sensor << " dell'ultima misura dopo push_back: \n" << driver.get_reading(3) << "\n";

    //riempio il buffer circolare 
    for(int i = 0; i < BUFFER_DIM - 1; i++)
    {
        driver.push_back(misura1);
    }

    //provo ora ad agiungere una misura diversa
    Lettura lett = {9.9,9.9,9.9,9.9,9.9,9.9};
    Lettura misura2[] = {lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett, lett};
    driver.push_back(misura2);

    //verifico che l'ultima misura sia quella appena inserita
    std::cout << "Verifico che il sensore " << sensor << " dell'ultima misura sia cambiato dopo il riempimento del buffer: \n" << driver.get_reading(3) << "\n";

    //pop_front
    //mi aspetto di poterne fare BUFFER_DIM e poi riottenere l'ultima misura inserita
    for(int i = 0; i < BUFFER_DIM - 1; i++)
    {
        driver.pop_front();
    }
    Lettura* last_measurement = driver.pop_front();
    std::cout << "Verifico che il sensore " << sensor << " restitutito dopo " << BUFFER_DIM << " rimozioni sia uguale a quello dell'ultima aggiunta: \n" << last_measurement[sensor] << "\n";

    //riaggiungo la prima misura
    driver.push_back(misura1);

    //operator<<
    std::cout << "Riaggiungo la prima misura nel buffer e stampo l'ultima misura aggiunta per intero:\n" << driver << "\n";

    //clear_buffer
    driver.clear_buffer();

    //verifico che ora il buffer sia vuoto
    Lettura* vuota = driver.pop_front();
    std::cout << "Eseguo pop_front dopo clear_buffer:\n";
    if(vuota == nullptr)
    {
        std::cout << "L'ultimo array rimosso vale nullptr (CORRETTO)" << "\n";
    }
    else
    {
        std::cout << "Esistono valori nell'ultimo array rimosso (ERRORE)" << "\n";
    }

    return 0;
}