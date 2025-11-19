# progetto_intermedio_laboratorioProgrammazione
Progetto intermedio dell'esame di laboratorio di programmazione

# Specifiche
Elenco delle classi:
Lettura: contiene i dati rilevati da un sensore, salvati in 6 double. Ha un getter per ogni valore e può essere stampata con cout.
Misura:  contiene un array da 17 letture, non allocato dinamicamente, così che il MyVector di InertialDriver contenga un buffer di misure allocate dinamicamente e non un buffer di puntatori a dati salvati altrove. Ha un getter che restituisce un oggetto di tipo Lettura del sensore specificato. Può essere stampato con cout.
MyVector: classe template del laboratorio 5.
IntertialDriver:
