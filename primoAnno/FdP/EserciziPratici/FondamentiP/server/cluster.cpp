//
// Created by Alessio Avarappattu on 19/11/25.
//

#include "cluster.h"

cluster::cluster(int n, int cap_default) {
    n_servers = n;

    // 1. Allocazione degli array "contenitori"
    servers = new Processo*[n_servers];      // Array di puntatori (teste)
    capacita_max = new int[n_servers];       // Array di interi (limiti)

    // 2. Inizializzazione degli slot
    for (int j = 0; j < n_servers; j++) {

        // A. La lista dei processi parte VUOTA.
        // NON fare 'new processo[...]'. Una lista vuota è solo un null.
        servers[j] = nullptr;

        // B. Impostiamo la capacità massima per questo server
        capacita_max[j] = cap_default;
    }
}
