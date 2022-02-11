#include <stdio.h>
#include <stdlib.h>
#include "TAD-listaCidades/listaDeCidades.h"

typedef struct{
    int tam;
    int var;
    int nVeic;
    int numdeperm;
    int numdecomb;
    int melhorDist;
    int* lista;
    int* melhorRota;
    int** matrizRes;
    int** matrizComb;
    int** matrizFinal;
} Tpermuta;

Tpermuta inicializaPermuta(TlistaDeCidades lista);

void escolhe_melhor_rota(Tpermuta *permuta, TlistaDeCidades lista);