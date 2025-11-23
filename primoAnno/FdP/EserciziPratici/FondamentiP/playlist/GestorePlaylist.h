//
// Created by Alessio Avarappattu on 19/11/25.
//

#ifndef WORKSPACE_FONDAMENTI_GESTOREPLAYLIST_H
#define WORKSPACE_FONDAMENTI_GESTOREPLAYLIST_H
#include <iosfwd>

struct Canzone {
    char* titolo;
    int durata;
    Canzone* next;
};



class GestorePlaylist {
private:
Canzone** playlist;
int* durataMax;
int numPlaylist;
Canzone* ultimaSongAllIndice(int indice);

    public:
    GestorePlaylist(int numeroPlaylist, int durata_default);
    /*
    *Vincolo: Prima di inserire, devi calcolare la somma delle durate delle canzoni già presenti in quella playlist.
     Se (somma_attuale + minuti) supera il limite previsto in limiti_durata[indice_playlist], l'inserimento fallisce (ritorna false) e non aggiungi nulla.
     */
    bool aggiungiCanzone(int indice_playlist, const char* titolo, int minuti);
    void cambiaLimite(int indice_playlist,int nuovoLimite);
    friend std::ostream& operator<<(std::ostream& os, const GestorePlaylist& gp);
};

/*
*Playlist 0 (Max 60 min): [Song A: 3m] -> [Song B: 5m] -> @
Playlist 1 (Max 120 min): @
Playlist 2 (Max 60 min): [Song C: 10m] -> @
*/
#endif //WORKSPACE_FONDAMENTI_GESTOREPLAYLIST_H