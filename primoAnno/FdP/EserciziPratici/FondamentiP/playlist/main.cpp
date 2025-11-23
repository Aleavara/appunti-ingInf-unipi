//
// Created by Alessio Avarappattu on 19/11/25.
//

#include "main.h"
#include <iostream>

#include "GestorePlaylist.h"

int main() {
    GestorePlaylist gp(15,200);
   gp.aggiungiCanzone(2,"aleavara",20);


    std::cout<<gp;

}
