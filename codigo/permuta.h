#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tam;
    int var;
    int nVeic;
    int numdeperm;
    int numdecomb;
    int* lista;
    int** matrizRes;
    int** matrizComb;
    int** matrizFinal;
} Tpermuta;

Tpermuta inicializaPermuta(int tam, int* lista, int nVeic);