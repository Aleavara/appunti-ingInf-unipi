//
// Created by Alessio Avarappattu on 15/11/25.
//

#ifndef WORKSPACE_FONDAMENTI_LISTACARATTERI_H
#define WORKSPACE_FONDAMENTI_LISTACARATTERI_H
#include <iostream>
struct Node{;
    char valore;
    Node* next;
    };

class ListaCaratteri {
private:
    Node* head;

    bool isEmpty() const;
    Node* nodoInCoda();
    int numElementi() const;
    Node* elementoInIndice(int indice) const;
    public:
    ListaCaratteri();
    ListaCaratteri(char valoreInTesta);
    bool aggiungiInTesta(char valore);
    bool aggiungiInCoda(char valore);
    bool aggiungiInIndice(int indice, char valore);

    void rimuoviOccorrenze( char valore);
    void rimuoviOccorrenza(char valore);
    bool controlloPalindroma();
    bool cercaSottostringa(const ListaCaratteri& sublist); //vediamo se la lista contiene i valori della sublist
    ListaCaratteri(const ListaCaratteri& altra); //costruttore copia
    friend std::ostream& operator<<(std::ostream& os, const ListaCaratteri& r);
    ~ListaCaratteri();
};


#endif //WORKSPACE_FONDAMENTI_LISTACARATTERI_H