//
// Created by Alessio Avarappattu on 23/10/25.
//

#include   <string>
#include   <iostream>
namespace std {
    class Libro {
        string titolo;
        string autore;
        string isbn;

        public:
        Libro(string titolo,string autore,string isbn);
        string getTit() const;
        string getAutore() const;
        string getIsbn() const;
        friend ostream& operator<<(ostream& os, const Libro& l);

    };
} // std

