# progetto_intermedio_laboratorioProgrammazione
Progetto intermedio dell'esame di laboratorio di programmazione

# Specifiche
La classe InertialDriver deve implementare:
● La funzione push_back che accetta un array stile C contenente una misura e la
memorizza nel buffer (sovrascrivendo la misura meno recente se il buffer è pieno);
● La funzione pop_front che fornisce in output un array stile C contenente la misura più
vecchia e la rimuove dal buffer;
● La funzione clear_buffer che elimina (senza restituirle) tutte le misure salvate;
● La funzione get_reading che accetta un numero tra 0 e 16 e ritorna la corrispondente
lettura della misura più recente, senza cancellarla dal buffer;
● L’overloading dell’operator<< che stampa a schermo l’ultima misura salvata (ma non la
rimuove dal buffer).
Note per l’implementazione:
● Le funzioni dell’elenco precedente devono essere opportunamente completate con i tipi di
ritorno; i parametri indicati devono essere opportunamente completati con eventuali
reference e const. È importante implementare le funzioni esattamente con il nome
descritto (case sensitive) e con gli argomenti elencati;
● La classe può essere completata con variabili membro e funzioni membro a scelta;
● Deve essere implementata ogni altra funzione membro ritenuta necessari