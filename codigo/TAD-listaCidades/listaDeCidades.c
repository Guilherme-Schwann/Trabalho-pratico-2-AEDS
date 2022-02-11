#include "listaDeCidades.h"

TlistaDeCidades inicializaLista(int N, int capacidadeVeiculos) {
    int i;
    TlistaDeCidades lista;
    lista.numCidades = N;
    lista.listaCidades = (Tcidade*)malloc(sizeof(Tcidade)*N);
    lista.capacidadeVeic = capacidadeVeiculos;
    lista.distancias = (int**) malloc(N * sizeof(int*));
    for (i = 0; i < N; i++){
        lista.distancias[i] = (int*) malloc(N * sizeof(int));
    }
    return lista;
}

void registraDistancias(TlistaDeCidades* lista, int** dist){
    int i, j;
    for (i = 0; i < lista->numCidades; i++) {
        for (j = 0; j < lista->numCidades; j++){
            lista->distancias[i][j] = dist[i][j];
        }
    }
}

void registraDemandas(TlistaDeCidades* lista, int* dem) {
    int i;
    for (i = 0; i < lista->numCidades; i++){
        if (i != 0){
            lista->listaCidades[i] = criaCidade(i, dem[i]);
        } else {
            lista->listaCidades[i] = criaCidade(i, 0);
        }
    }
}