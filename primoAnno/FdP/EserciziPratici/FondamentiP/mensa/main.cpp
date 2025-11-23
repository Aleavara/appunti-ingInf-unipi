//
// Created by Alessio Avarappattu on 19/11/25.
//

#include <iostream>
#include "mensa.h"

using namespace std;

int main() {
    cout << "--- Creazione Mensa (3 posti) ---" << endl;
    mensa m(3);
    cout << m << endl;

    cout << "--- Arriva Mario ---" << endl;
    m.occupa("Mario");
    cout << m << endl;

    cout << "--- Arriva Luigi ---" << endl;
    m.occupa("Luigi");
    cout << m << endl;

    cout << "--- Arriva Peach ---" << endl;
    m.occupa("Peach");
    cout << m << endl;

    cout << "--- Arriva Bowser (ma la mensa e' piena!) ---" << endl;
    bool risultato = m.occupa("Bowser");
    if (risultato == false) {
        cout << "Errore: Mensa piena, Bowser non puo' entrare." << endl;
    }

    return 0;
}