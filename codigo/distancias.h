#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int tam;
    int **matDist;
}Tdistancias;

Tdistancias* criar_matDist(int n);

void preencher_matDist(Tdistancias *matDist, int i, int j, int Dij);

void exibir_matDist(Tdistancias *matDist);
