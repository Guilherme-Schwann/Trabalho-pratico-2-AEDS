#include "distancias.h"

Tdistancias* criar_matDist(int n)
{
    int i;
    Tdistancias *mat;

    mat = (Tdistancias*) malloc(sizeof(Tdistancias));
    mat->tam = n;
    mat->matDist = (int**) malloc(n*sizeof(int*));
    for(i=0; i<n; i++)
        mat->matDist[i] = (int*) calloc(n,sizeof(int));
        //calloc já atribui zero: matriz nula
        
    return mat;
}

void preencher_matDist(Tdistancias *matDist, int i, int j, int Dij)
{
    matDist->matDist[i][j] = Dij;
    matDist->matDist[j][i] = Dij;
}

void exibir_matDist(Tdistancias *matDist)
{
    int i,j;
    printf("Matriz Ditancias =\n");
    for(i=0; i<matDist->tam; i++){
        printf("| ");
        for(j=0; j<matDist->tam; j++){
            printf("%d ", matDist->matDist[i][j]);
        }
        printf("|\n");
    }    
}
