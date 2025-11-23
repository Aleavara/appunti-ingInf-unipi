//
// Created by Alessio Avarappattu on 19/11/25.
//

#ifndef WORKSPACE_FONDAMENTI_CLOUDSTORAGE_H
#define WORKSPACE_FONDAMENTI_CLOUDSTORAGE_H
#include <iostream>
struct File {
    char* nome; //es: "foto_vacanze.jpg
    int dimensioneMB;  //es:5
    File* next;
};

class CloudStorage {
    private:
    File** cartelle; //Array di puntatori (Le teste delle liste)
    int numCartelle; //Dimensione dell'array
    int spazioMaxMB; //capacità totale account (ex: 1000MB)


    public:
    CloudStorage(int n,int maxMB);
    int calcolaSpazioTotale();
    bool uploadFile(int indiceCartella,const char* nome,int dim);
    bool rimuoviFile(int indiceCartella, const char* nome);
    File* trovaFilePiuGrande();
    friend std::ostream& operator<<(std::ostream& os, const CloudStorage& cs);
    ~CloudStorage();
};


#endif //WORKSPACE_FONDAMENTI_CLOUDSTORAGE_H