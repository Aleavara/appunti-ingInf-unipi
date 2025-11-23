//
// Created by Alessio Avarappattu on 19/11/25.
//

#include "GestorePlaylist.h"

#include <cstring>
#include <ostream>

GestorePlaylist::GestorePlaylist(int numeroPlaylist, int durata_default) {
    int numePlaylist;
    int durata;
    if (numeroPlaylist<0)
        numePlaylist = 10;
        else
            numePlaylist = numeroPlaylist;
    playlist= new Canzone*[numePlaylist];
    this->numPlaylist= numePlaylist;
    if (durata_default>0)
        durata = durata_default;
    else
        durata=100;
    durataMax = new int [numePlaylist];
    for (int i=0;i<numePlaylist;i++) {
        durataMax[i]=durata;
        playlist[i]=nullptr;
    }

}

Canzone *GestorePlaylist::ultimaSongAllIndice(int indice) {
    int index;
    if (indice<0||indice>numPlaylist-1)
        return nullptr;
    index = indice;
    Canzone* song = playlist[index];
    if (song==nullptr)
        return nullptr;
    while (song->next!=nullptr) {
        song=song->next;
    }
    return song;
}



bool GestorePlaylist::aggiungiCanzone(int indice_playlist, const char* titolo, int minuti) {
    if (indice_playlist<0 || indice_playlist>numPlaylist-1 || minuti>durataMax[indice_playlist])
        return false; //se indice invalido o durata già troppo alta finisco qua
    int durataAttuale=0; //vediamo se la durata quando aggiungo la canzone non supera quella attuale
    Canzone* scorriPlaylist=playlist[indice_playlist];
    if (playlist[indice_playlist]!=nullptr) { //se non c'è nessuna canzone non ha senso

        durataAttuale+=scorriPlaylist->durata;//prendo la prima canzone
        while (scorriPlaylist->next!=nullptr) {
            durataAttuale=durataAttuale+scorriPlaylist->next->durata;
            scorriPlaylist=scorriPlaylist->next;
        }
    }
    if (durataAttuale+minuti>durataMax[indice_playlist]) //se la durata nel momento in cui l'aggiungo è troppa finisco
        return false;

    Canzone* song = new Canzone;  //altrimenti parto con la creazione della canzone che andrò a mettere
    int lunghezzaTitolo= strlen(titolo);
    char* titoloSong = new char[lunghezzaTitolo+1];
    strcpy(titoloSong,titolo);
    song->durata = minuti; //parametri dell'utente
    song->titolo = titoloSong;
    song->next=nullptr; //punta a nulla per ora

    if (playlist[indice_playlist]==nullptr) { //se la playlist era vuota questa canzone è la prima di essa
            playlist[indice_playlist]=song;
        return true;//
    }
    else
     scorriPlaylist->next=song;//se c'erano già canzoni attacco la nuova canzone all'ultima della playlist
    return true;
}

std::ostream& operator<<(std::ostream& os, const GestorePlaylist& gp) {

  for (int i=0;i<gp.numPlaylist;i++) {
    os<<"Playlist: " << i << std::endl;
      if (gp.playlist[i]!=nullptr) {
          Canzone* scorriPlaylist=gp.playlist[i];
          while (scorriPlaylist!=nullptr) {
          os<< "titolo canzone" << scorriPlaylist->titolo << " durata" << scorriPlaylist->durata << " minuti" <<std::endl;
              scorriPlaylist=scorriPlaylist->next;
          }
      }
  }

    return os;
}
