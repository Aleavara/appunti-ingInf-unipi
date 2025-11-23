//
// Created by Alessio Avarappattu on 15/11/25.
//

#include "ListaCaratteri.h"

#include "../raccoglitore/Raccoglitore.h"

ListaCaratteri::ListaCaratteri() {
    head = nullptr;
}

ListaCaratteri::ListaCaratteri(char valoreInTesta) {
    head = new Node();
    head->valore=valoreInTesta;
    head->next = nullptr;
}

bool ListaCaratteri::isEmpty() const {
    if (head == nullptr) {
        return true;
    }
    return false;
}

Node* ListaCaratteri::nodoInCoda() {
    if (isEmpty()) {
        return nullptr;
    }
    Node* nodo = head;
    while (nodo->next != nullptr) {
        nodo = nodo->next;
    }
    return nodo;
}

bool ListaCaratteri::aggiungiInTesta(char valoreInTesta) {
  if (head == nullptr) {
      head = new Node();
      head->valore = valoreInTesta;
      head->next = nullptr;
      return true;
  }
    else {
        Node*  newNode = new Node();
        newNode->valore = valoreInTesta;
        newNode->next = head;
        head = newNode;
        return true;
    }
    return false;
}

bool ListaCaratteri::aggiungiInCoda(char valore) {
    if (isEmpty()) {
        head = new Node();
        head->valore = valore;
        head->next = nullptr;
        return true;
    }
    else {
        Node* nodo = nodoInCoda();
        Node* nuovoNodo = new Node();
        nuovoNodo->valore = valore;
        nuovoNodo->next = nullptr;
        nodo->next = nuovoNodo;
    }
    return true;
}

void ListaCaratteri::rimuoviOccorrenze( char valore) {
    if (isEmpty()) {}
    Node* nodo = head;
    Node* prev= nullptr;
    while(nodo->valore==valore) {
        head = head->next;
        delete nodo;
        nodo = head;
    }
    prev= nodo;
    nodo = nodo->next;
        while (nodo!= nullptr) {
            if (nodo->valore==valore) {
                prev->next = nodo->next;
                delete nodo;
                nodo= prev->next;
            }
            prev= nodo;
            nodo = nodo->next;
        }
}

void ListaCaratteri::rimuoviOccorrenza(char valore) {
    Node* nodo = head;
    Node* prev = nullptr;
    bool trovato=false;
    if (nodo->valore==valore) {
        head = nodo->next;
        delete nodo;
    }
    else{
        prev= nodo;
        nodo = nodo->next;
        while (nodo!=nullptr && trovato==false) {
            if (nodo->valore==valore) {
                prev->next = nodo->next;
                delete nodo;
                trovato=true;
            }else {
                prev= nodo;
                nodo = nodo->next;
            }
        }}

}

int ListaCaratteri::numElementi() const {
    if (isEmpty()) { return 0; }
    int numElementi=0;
    Node* nodo = head;
    while (nodo!=nullptr) {
        numElementi++;
        nodo = nodo->next;
    }
    return numElementi;
}

Node* ListaCaratteri::elementoInIndice(int indice) const {
    if (isEmpty()) { return nullptr; }
    int scorrimento=0;
    Node* nodo = head;
    while (nodo!=nullptr &&scorrimento<indice) {
        nodo=nodo->next;
        scorrimento++;
    }

    return nodo;
}


bool ListaCaratteri::cercaSottostringa(const ListaCaratteri &sublist) {
    Node* primoValore = sublist.head;
    int nElementi=sublist.numElementi();

    Node* nodo = head;
    while (nodo != nullptr) {
        if  (nodo->valore==primoValore->valore) {
            int elementiTrovati=1;
            Node* scansione=nodo->next;
            Node* sublist = primoValore->next;
            while (scansione!=nullptr && sublist!=nullptr && scansione->valore==sublist->valore) {
                elementiTrovati++;
                scansione=scansione->next;
                sublist=sublist->next;
            }
            if (elementiTrovati==nElementi) {
                return true;
            }
        }

        nodo = nodo->next;
    }
    return false;
}

bool ListaCaratteri::controlloPalindroma() {
    int nElementi=numElementi();
    int destra=0;
    int sinistra=0;

    if (nElementi%2==0) {
        destra=nElementi/2;
        sinistra=nElementi-1;
        while (elementoInIndice(destra)->valore==elementoInIndice(sinistra)->valore&&destra<=(nElementi-1)) {
            destra++;
            sinistra--;

        }
    }
    if (nElementi%2==1) {
        destra=(nElementi/2)+1;
        sinistra=(nElementi/2)-1;
        while (elementoInIndice(destra)->valore==elementoInIndice(sinistra)->valore&&destra<=(nElementi-1)) {
            destra++;
            sinistra--;

        }
    }
    std::cout<<destra<<" ";
    if (destra==nElementi-1)
        return true;
    return false;
}





std::ostream& operator<<(std::ostream& os, const ListaCaratteri& lc) {

    Node* current = lc.head; // Accede a 'head' perché è 'friend'

    // 2. Scorre la lista
    while (current != nullptr) {
        os << current->valore << " -> "; // Stampa il dato
        current = current->next;
    }

    // 3. Stampa la fine
    os << "@";

    // 4. Ritorna lo stream
    return os;
}

/**
 * @brief Distruttore.
 * Deve deallocare tutta la memoria dei Nodi della lista
 * per evitare memory leak.
 */
ListaCaratteri::~ListaCaratteri() {

    Node* current = head; // Parti dalla testa
    Node* prossimo = nullptr;

    // Scorre la lista
    while (current != nullptr) {
        // 1. Salva un puntatore al nodo successivo
        //    (devi farlo PRIMA di cancellare 'current',
        //     altrimenti perdi il riferimento)
        prossimo = current->next;

        // 2. Cancella il nodo corrente
        delete current;

        // 3. Passa al nodo successivo
        current = prossimo;
    }

    // A questo punto, tutti i nodi sono stati cancellati.
    // L'oggetto 'ListaCaratteri' sta morendo, quindi non
    // serve nemmeno impostare 'head = nullptr'.
}


