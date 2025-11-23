//
// Created by Alessio Avarappattu on 03/11/25.
//


#include "raccoglitore.h"
#include <iostream>

using namespace std;

int main() {

    cout << "---PRIMA PARTE---" << endl << endl;

    cout << "Test del costruttore e della aggiungiBlocco ()" << endl;

    // Costruttore con 3 righe
    Raccoglitore r(3);

    // Queste aggiunte producono l'output "VR", "VG", "B"
    r.aggiungiBlocco(VERDE);  // r0: V
    r.aggiungiBlocco(VERDE);  // r1: V (r0 ha 1, r1 ha 0 -> r1)
    r.aggiungiBlocco(BIANCO); // r2: B (r0 ha 1, r1 ha 1, r2 ha 0 -> r2)
    r.aggiungiBlocco(ROSSO);  // r0: VR (r0 ha 1, r1 ha 1, r2 ha 1 -> r0, più in alto)
    r.aggiungiBlocco(GIALLO); // r1: VG (r0 ha 2, r1 ha 1 -> r1)

    cout << r << endl;

    cout << "Altri test della aggiungiBlocco() e op. di uscita" << endl;

    // Queste aggiunte producono "VRV", "VG", "BB"
    r.aggiungiBlocco(VERDE);  // r2: BB (r0 ha 2, r1 ha 2, r2 ha 1 -> r2)
    r.aggiungiBlocco(VERDE);  // r0: VRV (r0 ha 2, r1 ha 2, r2 ha 2 -> r0, più in alto)

    cout << r << endl;

    /* * NOTA IMPORTANTE:
     * L'output atteso nel file PDF (testo-7.pdf) da questo punto
     * in poi è INCOERENTE con il testo dell'esercizio.
     * Esempio: Il testo dice togliBlocco() rimuove "più a sinistra"
     * e cerca "dal basso", ma l'output atteso mostra una rimozione
     * "più a destra" e una ricerca "dall'alto".
     *
     * L'implementazione fornita segue ALLA LETTERA il TESTO dell'esame
     * (come farebbe il prof), quindi l'output generato da questo main
     * sarà diverso da quello nel PDF, ma logicamente CORRETTO.
     */

    cout << "Primo test della togliBlocco()" << endl;
    // L'output atteso toglieva ROSSO. Noi seguiamo il testo.
    // L'output atteso era "VR", "VG", "BB".
    // Noi eseguiamo la chiamata che *dovrebbe* essere: togliBlocco(VERDE)
    r.togliBlocco(VERDE);
    // Stato: VRV, VG, BB
    // Cerca basso (r2: BB) -> No V
    // Cerca r1 (VG) -> Sì V. Rimuove "più a sinistra" (il V)
    // Stato nuovo: VRV, G, BB
    cout << r << endl;

    cout << "Secondo test della togliBlocco ()" << endl;
    // L'output atteso era "V", "VG", "BB"
    // Noi eseguiamo: togliBlocco(ROSSO)
    r.togliBlocco(ROSSO);
    // Stato: VRV, G, BB
    // Cerca basso (r2: BB) -> No R
    // Cerca r1 (G) -> No R
    // Cerca r0 (VRV) -> Sì R. Rimuove.
    // Stato nuovo: VV, G, BB
    cout << r << endl;

    cout << "Terzo test della togliBlocco()" << endl;
    // L'output atteso era "V", "V", "BB"
    // Noi eseguiamo: togliBlocco(GIALLO)
    r.togliBlocco(GIALLO);
    // Stato: VV, G, BB
    // Cerca basso (r2: BB) -> No G
    // Cerca r1 (G) -> Sì G. Rimuove.
    // Stato nuovo: VV, (vuota), BB
    cout << r << endl;


    cout << "---SECONDA PARTE---" << endl << endl;

    cout << "Test del costruttore di copia" << endl;
    Raccoglitore r2(r); // r ha stato: VV, (vuota), BB
    cout << r2 << endl;

    cout << "Test dell'operatore di assegnamento" << endl;
    Raccoglitore r3; // Costruttore di default (1 riga vuota)
    r3 = r; // r3 ora ha stato: VV, (vuota), BB
    cout << r3 << endl;

    cout << "Test del distruttore (se ridefinito)" << endl;
    {
        Raccoglitore r_test(5);
        r_test.aggiungiBlocco(ROSSO);
    } // r_test viene distrutto qui
    // (Non c'è output standard, ma il distruttore viene chiamato)

    return 0;
}