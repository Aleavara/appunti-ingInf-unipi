//
// Created by Alessio Avarappattu on 23/10/25.
//

#include <string>
#include <iostream>
using namespace std;
class Giocatore {
    string nome;
    string cognome;
    int eta;
    public:
    Giocatore();
    Giocatore(string, string, int);
    string getNome() const;
    string getCognome() const;
    int getEta() const;
};


