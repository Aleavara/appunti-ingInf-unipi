//
// Created by Alessio Avarappattu on 19/11/25.
//

#include "mensa.h"
#include <cstring> // FONDAMENTALE per strlen e strcpy
#include <iostream>
/**
 * COSTRUTTORE
 * Deve allocare l'array di SEDIE (i puntatori), non i pranzanti.
 */
mensa::mensa(int N) {
    // 1. Sanitizzazione (se N è negativo, mettiamo un default)
    if (N <= 0) N = 10;

    numero_sedie = N;

    // 2. Allocazione dell'array di PUNTATORI (Livello 1)
    // Chiediamo spazio per 'N' puntatori a char.
    sedie = new char*[numero_sedie];

    // 3. Inizializzazione a NULLPTR
    // Questo è CRUCIALE. Appena creato, l'array contiene spazzatura.
    // Dobbiamo dire esplicitamente che tutte le sedie sono VUOTE.
    for (int i = 0; i < numero_sedie; i++) {
        sedie[i] = nullptr;
    }
}

/**
 * OCCUPA
 * Cerca la prima sedia vuota (nullptr) e alloca la stringa.
 */
bool mensa::occupa(const char* nome_pranzante) {

    // 1. Scorriamo l'array per cercare un posto libero
    for (int i = 0; i < numero_sedie; i++) {

        // Se troviamo un puntatore che vale nullptr, la sedia è libera!
        if (sedie[i] == nullptr) {


            int lunghezza = strlen(nome_pranzante);
            sedie[i] = new char[lunghezza + 1]; //va nell'heap e crea un array!! in sedie[i] ci va solo l'indirizzo iniziale
   //quindi se abbiamo un array ad esempio di 10 sedie, quelle vuote hanno sedie[i]=nullptr, quelle piene invece hanno un puntatore alla stringa contenente il nome dell'occupante
            // 3. Copia dei caratteri
            // Copiamo i caratteri dalla stringa in input alla nostra nuova memoria
            strcpy(sedie[i], nome_pranzante);

            return true; // Posto trovato e occupato con successo
        }
    }

    // Se il ciclo finisce, non abbiamo trovato sedie libere (tutti != nullptr)
    return false;
}

bool mensa::libera(int k) {
    if (sedie[k-1]!=nullptr) {
        delete[] sedie[k+1];
        sedie[k-1]=nullptr;
    }
}

/**
 * OPERATORE DI STAMPA
 */
std::ostream& operator<<(std::ostream& os, const mensa& m) {

    for (int i = 0; i < m.numero_sedie; i++) {
        os << "sedia " << (i + 1) << ": "; // L'utente vede da 1 a N

        if (m.sedie[i] == nullptr) {
            // Se il puntatore è nullo, è vuota
            os << "(non occupata)";
        } else {
            // Se il puntatore è valido, stampiamo la stringa puntata
            // Basta passare il puntatore a char (char*) a cout e lui stampa la stringa.
            os << m.sedie[i];
        }

        os << std::endl; // A capo dopo ogni sedia
    }

    return os;
}