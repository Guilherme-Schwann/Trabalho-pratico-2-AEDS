#include "listaDeCidades.h"

TlistaDeCidades inicializaLista(int N, int capacidadeVeiculos) {
    TlistaDeCidades lista;
    lista.listaCidades = (Tcidade*)malloc(sizeof(Tcidade)*N);
    lista.frota.capacidadeIndividual = capacidadeVeiculos;
}

void 