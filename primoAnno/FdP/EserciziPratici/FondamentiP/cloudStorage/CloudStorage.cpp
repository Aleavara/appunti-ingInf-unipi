//
// Created by Alessio Avarappattu on 19/11/25.
//

#include "CloudStorage.h"

#include <cstring>


CloudStorage::CloudStorage(int n,int maxMB) {
    int numeroCartelle;
    int dimensione;

    if (n<0)
        numeroCartelle=10;
    else
        numeroCartelle=n;
    cartelle = new File*[numeroCartelle];
    for (int i=0;i<numeroCartelle;i++) {
        cartelle[i]= nullptr;
    }
    if (maxMB<0)
        dimensione=1000;
    else
        dimensione=maxMB;
    this->spazioMaxMB=dimensione;
    this->numCartelle=numeroCartelle;

}

int CloudStorage::calcolaSpazioTotale() {
    int spazioTotale=0;
    for (int i=0;i<numCartelle;i++) {
        if (cartelle[i]!=nullptr) {
            File* file = cartelle[i];
            while (file!=nullptr) {
                spazioTotale+=file->dimensioneMB;
                file=file->next;
            }
        }
    }
    return spazioTotale;
}


bool CloudStorage::uploadFile(int indiceCartella, const char *nome, int dim) {
    if (indiceCartella<0||indiceCartella>numCartelle-1)
        return false;
    if (this->calcolaSpazioTotale()+dim>spazioMaxMB)
        return false;
    File* file=cartelle[indiceCartella];
    File* newFile=new File;
    strlen(nome);
    char* nomeFile= new char[strlen(nome)+1];
    strcpy(nomeFile,nome);
    newFile->nome=nomeFile;
    newFile->dimensioneMB=dim;
    newFile->next=nullptr;
    if (file==nullptr){
    cartelle[indiceCartella]=newFile;
    return true;
}
    else {
        while (file->next!=nullptr) {
            file=file->next;
        }
        file->next=newFile;
        return true;
    }
}

bool CloudStorage::rimuoviFile(int indiceCartella, const char *nome) {
    if (indiceCartella<0 || indiceCartella>=numCartelle) // Ho corretto numCartelle-1
        return false;

    File* current = cartelle[indiceCartella];
    File* prev = nullptr;

    while (current != nullptr) {
        // CORREZIONE CRITICA: USARE strcmp PER CONFRONTARE LE STRINGHE
        if (strcmp(current->nome, nome) == 0) {

            // Caso 1: È la Testa
            if (prev == nullptr) {
                cartelle[indiceCartella] = current->next;
            }
            // Caso 2: È in mezzo o in fondo
            else {
                prev->next = current->next;
            }

            // CORREZIONE: Pulizia profonda del nodo da rimuovere
            delete[] current->nome; // Rimuovi la stringa allocata
            delete current;         // Rimuovi il nodo

            return true;
        }

        prev = current;
        current = current->next;
    }

    return false;
}

std::ostream& operator<<(std::ostream& os, const CloudStorage& cs) {
    for (int i=0;i<cs.numCartelle;i++) {
        if (cs.cartelle[i]!=nullptr) {
        os<<"cartella numero: "<<i<<std::endl;
            File* file=cs.cartelle[i];
            while (file!=nullptr) {
                os<<file->nome<<" "<<file->dimensioneMB<<std::endl;
                file=file->next;
            }
        }
    }

    return os;
}

CloudStorage::~CloudStorage() {

    for (int i = 0; i < numCartelle; i++) {
        File* nodoCorrente = cartelle[i]; // Inizializza la testa

        // Ciclo sulla lista
        while (nodoCorrente != nullptr) {

            // 1. SALVARE il prossimo nodo PRIMA di cancellare
            File* nextNode = nodoCorrente->next;

            // 2. CANCELLARE (dal più profondo al più esterno)
            delete[] nodoCorrente->nome;
            delete nodoCorrente;

            // 3. AVANZARE
            nodoCorrente = nextNode;
        }
    }

    // Pulizia finale
    delete[] cartelle;
}


