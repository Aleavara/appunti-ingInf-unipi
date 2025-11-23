//
// Created by Alessio Avarappattu on 19/11/25.
//

#ifndef WORKSPACE_FONDAMENTI_MENSA_H
#define WORKSPACE_FONDAMENTI_MENSA_H
#include <iostream>

class mensa {

private:
    /**
    simile ad una matrice
    è un array
     */
    char** sedie;

    int numero_sedie; // Dimensione della mensa (N)

public:
    // Costruttore
    mensa(int N);

    // Metodo per occupare una sedia (copia profonda della stringa)
    bool occupa(const char* nome_pranzante);
    bool libera(int k);
    // Operatore di stampa
    friend std::ostream& operator<<(std::ostream& os, const mensa& m);

    // (Il metodo libera() lo farai tu dopo)
    // bool libera(int k);
};


#endif //WORKSPACE_FONDAMENTI_MENSA_H