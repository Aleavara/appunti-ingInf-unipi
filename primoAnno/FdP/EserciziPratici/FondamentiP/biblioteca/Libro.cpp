//
// Created by Alessio Avarappattu on 23/10/25.
//

#include "Libro.h"
using namespace std;
ostream& operator<<(ostream& os, const Libro& l) {
    os << "Titolo: " << l.getTit()
       << ", Autore: " << l.getAutore()
       << ", ISBN: " << l.getIsbn();
    return os;
}