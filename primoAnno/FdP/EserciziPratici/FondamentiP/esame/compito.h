#include <iostream>
using namespace std;

struct Node{ //nodo         //in struct i membri sono public di default
    char data;   //il carattere dentro il nodo
    Node* next;  //puntatore al prossimo nodo
};

class ListaCaratteri{       //prima di "public:" i membri sono private di default
    Node* head;                //riferimento al nodo in testa
    void inserisciFine(char value);     //metti alla fine della lista
    void inserisciInizio(char value);   //metti inizio lista
    bool rimuoviCarattere(char value);  //rimuovi valore da lista
    bool rimuoviTutti(char value);      //rimuove tutti i valori value dalla lista
    static bool controllaSottostringa(const Node* mainList, const Node* sublist);
    void pulisci();                     //pulisce lista, IMPORTANTE ALLA FINE DEL MAIN
    ListaCaratteri(const ListaCaratteri& other);  //costruttore copia

public:     //tutti i metodi public
    // PRIMA PARTE
    ListaCaratteri();  //costruttore copia
    void inserisci(char value, bool coda); //inserisci valore
    bool rimuovi(char value, bool tutti); //rimuovi valore
    friend ostream& operator<<(ostream& os, const ListaCaratteri& list); //Tostring, operator<< è il Tostring di Java
    bool controllaPalindroma() const; //const significa che questo metodo è di sola lettura, non modifica l'oggetto

    // SECONDA PARTE
    bool operator==(const ListaCaratteri& other) const;   //equal
    void operator~(); //operator overloading Bitwise NOT per invertire bit di interi, io lo uso per invertire una lista
    bool cercaSottostringa(const ListaCaratteri& sublist) const;
    char estraiNultimoCarattere(int n); //estrae l'ennesimo elemento da una lista dal fondo
    ~ListaCaratteri();  //distruttore
};
