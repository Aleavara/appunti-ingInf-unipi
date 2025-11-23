//
// Created by Alessio Avarappattu on 23/10/25.
//

#include <string>;

#include "Libro.h"

using namespace std;

    class Biblioteca {
        Libro* libri;
        int capacita;
        int numeroLibri;

        public:
        Biblioteca(const int& nLibri);
        ~Biblioteca();
        void aggiungiLibro(Libro& libro);
        Libro* cercaPerIsbn(const string& isbn) const;
    };


