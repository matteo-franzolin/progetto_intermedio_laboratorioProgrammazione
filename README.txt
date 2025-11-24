Membri del gruppo:
1) Matteo Tordin: Classe IntertialDriver + main.cpp.
    
2) Matteo Franzolin: Classe Lettura.

3) Giovanni Rigon: Classe Misura.
    

Classi del progetto:
1) InertialDriver: Classe che rappresenta il modulo software che riceve e fornisce le misure dei sensori. Implementa un buffer circolare che contiene misure (oggetti della classe Misura).

2) Misura: Classe che contiene un array allocato dinamicamente di 17 letture (oggetti di classe Lettura).

3) Lettura: Contiene 6 valori di tipo double che rappresentano le rilevazioni di un sensore.

4) MyVector: Classe che gestisce vettori di elementi generici tramite allocazione dinamica della memoria, analogamente a quanto svolto dalla funzione della libreria standard vector.