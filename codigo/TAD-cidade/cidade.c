#include "../TAD-cidade/cidade.h"

Tcidade criaCidade(int ind, int demanda) {
    Tcidade cidade;
    cidade.ind = ind;
    cidade.demanda = demanda;
    cidade.passouCarga = 0;
    return cidade;
}

void passarCarga(Tcidade* cidade){
    cidade->passouCarga = 1;
}
void esvaziaCarga(Tcidade* cidade){
    cidade->passouCarga = 0;
}