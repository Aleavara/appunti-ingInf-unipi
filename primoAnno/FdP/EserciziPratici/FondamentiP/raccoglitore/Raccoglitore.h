//
// Created by Alessio Avarappattu on 03/11/25.
//


#define RACCOGLITORE_H

#include <iostream>

// Definito come da testo d'esame
enum Colore {BIANCO, ROSSO, GIALLO, VERDE};

/**
 * @brief Struct Blocco (Nodo della lista)
 * Non serve una classe, basta una struct semplice
 * per contenere il dato (colore) e il puntatore al prossimo.
 */
struct Blocco {
    Colore c;
    Blocco* next;
};

class Raccoglitore {

private:
    // ---- MEMBRI PRIVATI ----

    /**
     * @brief Array di teste di lista (le "Righe").
     * Questo è il membro dati principale: un array dinamico
     * di puntatori a Blocco. righe[i] è la testa della lista i-esima.
     */
    Blocco** righe;

    /**
     * @brief Numero di righe (dimensione dell'array 'righe')
     */
    int num_righe;

    // ---- METODI PRIVATI DI UTILITÀ ----

    /**
     * @brief Funzione helper per contare i blocchi in una singola riga.
     * È 'const' perché non modifica l'oggetto.
     */
    int contaBlocchi(int indice_riga) const;

    /**
     * @brief Funzione helper per la stampa del colore.
     * È 'static' perché non dipende da un'istanza specifica.
     */
    static char ColoreToChar(Colore c);

    /**
     * @brief Funzione helper per deallocare tutta la memoria.
     * Usata dal distruttore e dall'operatore di assegnamento.
     */
    void dealloca();

    /**
     * @brief Funzione helper per copiare (deep copy) un altro Raccoglitore.
     * Usata dal costruttore di copia e dall'operatore di assegnamento.
     */
    void copia(const Raccoglitore& altro);


public:
    // ---- PRIMA PARTE (come da testo) ----

    Raccoglitore();         // Costruttore default (1 riga)
    Raccoglitore(int n);    // Costruttore (n righe)

    // L'operatore di stampa deve essere 'friend' per accedere
    // ai membri privati di 'r'.
    friend std::ostream& operator<<(std::ostream& os, const Raccoglitore& r);

    void aggiungiBlocco(Colore c);
    void togliBlocco(Colore c);


    // ---- SECONDA PARTE (come da testo) ----

    ~Raccoglitore();
    Raccoglitore(const Raccoglitore& altro); // Costruttore di Copia
    Raccoglitore& operator=(const Raccoglitore& altro); // Operatore di Assegnamento
};


