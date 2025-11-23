//
// Created by Alessio Avarappattu on 23/10/25.
//

// Giocatore.cpp

#include "Giocatore.h"

// Costruttore con parametri che usa la LISTA DI INIZIALIZZAZIONE
Giocatore::Giocatore(std::string n, std::string c, int e)
    : nome(n), cognome(c), eta(e) {

}

// Costruttore di default
Giocatore::Giocatore()
    : nome("N/D"), cognome("N/D"), eta(0) {

}

// Implementazione dei metodi "getter"
std::string Giocatore::getNome() const {
    return this->nome;
}

std::string Giocatore::getCognome() const {
    return this->cognome;
}

int Giocatore::getEta() const {
    return this->eta;
}