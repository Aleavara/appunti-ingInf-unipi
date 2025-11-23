//
// Created by Alessio Avarappattu on 03/11/25.
//

#include "Raccoglitore.h"

#include <iostream> // Per std::ostream e std::endl

// ---- METODI PRIVATI DI UTILITÀ ----

/**
 * @brief Conta i blocchi nella lista linkata alla riga 'indice_riga'.
 */
int Raccoglitore::contaBlocchi(int indice_riga) const {
    int count = 0;
    Blocco* current = righe[indice_riga]; // Inizia dalla testa

    // Classico scorrimento di lista linkata
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

/**
 * @brief Converte l'enum Colore in un char per la stampa.
 */
char Raccoglitore::ColoreToChar(Colore c) {
    switch(c) {
        case BIANCO: return 'B';
        case ROSSO:  return 'R';
        case GIALLO: return 'G';
        case VERDE:  return 'V';
        default:     return '?';
    }
}

/**
 * @brief Dealloca tutta la memoria dinamica (nodi e array).
 */
void Raccoglitore::dealloca() {
    // 1. Dealloca tutti i nodi (Blocco) in ogni lista
    for (int i = 0; i < num_righe; i++) {
        Blocco* current = righe[i];
        while (current != nullptr) {
            Blocco* da_eliminare = current;
            current = current->next;
            delete da_eliminare; // Libera la memoria del singolo Blocco
        }
    }

    // 2. Dealloca l'array di puntatori 'righe'
    // Si usa delete[] perché era stato allocato con new[]
    delete[] righe;
}

/**
 * @brief Esegue una "deep copy" da 'altro' a 'this'.
 */
void Raccoglitore::copia(const Raccoglitore& altro) {
    // 1. Copia i membri semplici
    num_righe = altro.num_righe;

    // 2. Alloca il *nuovo* array di puntatori
    righe = new Blocco*[num_righe];

    // 3. Esegui la "deep copy" di ogni lista linkata (riga)
    for (int i = 0; i < num_righe; i++) {

        righe[i] = nullptr; // Inizializza la testa della nuova lista
        Blocco* altro_current = altro.righe[i]; // Puntatore alla lista da copiare
        Blocco* this_coda = nullptr; // Puntatore all'ultimo nodo creato in *questa* lista

        // Scorri la lista 'altro'
        while (altro_current != nullptr) {
            // Crea un nuovo Blocco
            Blocco* nuovo = new Blocco;
            nuovo->c = altro_current->c;
            nuovo->next = nullptr;

            if (righe[i] == nullptr) {
                // È il primo nodo, attacca la testa
                righe[i] = nuovo;
            } else {
                // Nodi successivi, attacca in coda
                this_coda->next = nuovo;
            }

            // Avanza entrambi i puntatori
            this_coda = nuovo; // 'nuovo' è ora l'ultimo nodo
            altro_current = altro_current->next;
        }
    }
}


// ---- IMPLEMENTAZIONE PRIMA PARTE ----

/**
 * @brief Costruttore di default (1 riga).
 */
Raccoglitore::Raccoglitore() {
    num_righe = 1;
    righe = new Blocco*[num_righe];
    righe[0] = nullptr; // Inizializza la testa a nullptr (lista vuota)
}

/**
 * @brief Costruttore parametrico (n righe).
 */
Raccoglitore::Raccoglitore(int n) {
    // Sanitizzazione dell'input (come da stile prof)
    if (n < 1) {
        num_righe = 1;
    } else {
        num_righe = n;
    }

    // Alloca array di puntatori
    righe = new Blocco*[num_righe];

    // Inizializza TUTTE le teste a nullptr (liste vuote)
    for (int i = 0; i < num_righe; i++) {
        righe[i] = nullptr;
    }
}

/**
 * @brief Operatore di stampa (friend).
 */
std::ostream& operator<<(std::ostream& os, const Raccoglitore& r) {
    // Itera su ogni riga
    for (int i = 0; i < r.num_righe; i++) {

        Blocco* current = r.righe[i]; // Testa della lista i-esima
        while (current != nullptr) {
            os << Raccoglitore::ColoreToChar(current->c);
            current = current->next;
        }

        // Aggiungi "a capo" dopo ogni riga (anche se vuota)
        os << std::endl;
    }
    return os;
}

/**
 * @brief Aggiunge un blocco IN CODA alla riga con meno blocchi.
 * "più in alto" in caso di parità (indice 'i' minore).
 */
void Raccoglitore::aggiungiBlocco(Colore c) {
    // 1. Trova la riga giusta

    int riga_scelta = 0; // "più in alto" = indice 0
    int min_blocchi = contaBlocchi(0);

    for (int i = 1; i < num_righe; i++) {
        int blocchi_correnti = contaBlocchi(i);

        // Se troviamo un minimo *strettamente* minore, aggiorniamo.
        // Se è uguale (parità), NON aggiorniamo, così 'riga_scelta'
        // rimane l'indice "più in alto" (più basso) trovato.
        if (blocchi_correnti < min_blocchi) {
            min_blocchi = blocchi_correnti;
            riga_scelta = i;
        }
    }

    // 2. Aggiungi il blocco IN CODA alla lista 'riga_scelta'

    Blocco* nuovo = new Blocco;
    nuovo->c = c;
    nuovo->next = nullptr; // Sarà l'ultimo nodo

    if (righe[riga_scelta] == nullptr) {
        // La lista è vuota, il nuovo nodo è la testa
        righe[riga_scelta] = nuovo;
    } else {
        // La lista non è vuota, scorri fino all'ultimo nodo
        Blocco* current = righe[riga_scelta];
        while (current->next != nullptr) {
            current = current->next;
        }
        // 'current' è ora l'ultimo nodo. Attacca 'nuovo' dopo.
        current->next = nuovo;
    }
}

/**
 * @brief Rimuove il primo blocco (più a sinistra) del colore dato.
 * Cerca "dal basso" (indice array alto) verso l'alto.
 */
void Raccoglitore::togliBlocco(Colore c) {

    // Itera sulle righe "dal basso" (da num_righe-1 a 0)
    for (int i = num_righe - 1; i >= 0; i--) {

        Blocco* current = righe[i];
        Blocco* prev = nullptr; // Necessario per ricollegare la lista

        // Scansiona la lista "da sinistra" (dalla testa)
        while (current != nullptr) {

            if (current->c == c) {
                // Trovato! Esegui la rimozione.

                if (prev == nullptr) {
                    // Stiamo rimuovendo la TESTA della lista
                    righe[i] = current->next;
                } else {
                    // Stiamo rimuovendo un nodo in mezzo o in coda
                    prev->next = current->next;
                }

                delete current; // Dealloca la memoria del nodo rimosso

                // Abbiamo finito, esci dalla funzione (rimuovi solo il *primo*)
                return;
            }

            // Non trovato, avanza i puntatori
            prev = current;
            current = current->next;
        }
        // Se la riga è finita, passa alla riga successiva (più in alto)
    }
    // Se arriviamo qui, il blocco non è stato trovato. Non fa nulla.
}


// ---- IMPLEMENTAZIONE SECONDA PARTE ----

/**
 * @brief Distruttore.
 */
Raccoglitore::~Raccoglitore() {
    dealloca();
}

/**
 * @brief Costruttore di Copia.
 */
Raccoglitore::Raccoglitore(const Raccoglitore& altro) {
    // Chiama l'helper che fa la copia profonda
    copia(altro);
}

/**
 * @brief Operatore di Assegnamento.
 */
Raccoglitore& Raccoglitore::operator=(const Raccoglitore& altro) {
    // 1. Controllo anti auto-assegnamento (es. r = r;)
    if (this != &altro) {
        // 2. Distruggi lo stato attuale di 'this'
        dealloca();
        // 3. Copia il nuovo stato da 'altro'
        copia(altro);
    }
    // 4. Ritorna un riferimento a 'this'
    return *this;
}