#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int* lista;
    int **matrizRes;
    int tam;
    int var;
    int numdeperm;
} Tpermuta;

int numDePermutacoes(int tam);