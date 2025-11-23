//
// Created by Alessio Avarappattu on 15/11/25.
//


#include "ListaCaratteri.h"

#include <iostream>
using namespace std;

int main() {
ListaCaratteri lista= ListaCaratteri();
    ListaCaratteri lista2=ListaCaratteri();
    lista2.aggiungiInTesta('b');
    lista2.aggiungiInTesta('b');
lista.aggiungiInCoda('a');
    lista.aggiungiInCoda('b');
    lista.aggiungiInCoda('b');
    lista.aggiungiInCoda('a');
    cout<<lista<<endl;

if (lista.controlloPalindroma()==true) {
    cout<<"palindroma"<<endl;
}
    if (lista.cercaSottostringa(lista2))
        cout<<"trovata"<<endl;











}
