#include "demandas.h"

Tdemandas* criar_vetDem(int n)
{
    int i;
    Tdemandas *vet;

    vet = (Tdemandas*) malloc(sizeof(Tdemandas));
    vet->tam = n;
    vet->vetDem = (int*) malloc(n*sizeof(int));

    return vet;
}

void preencher_vetDem(Tdemandas *vetDem, int i, int dem)
{
    vetDem->vetDem[i] = dem;
}

void exibir_vetDem(Tdemandas *vetDem)
{
    int i;
    printf("Vetor Ditancias =\n");
    printf("| ");
    for(i=0; i<vetDem->tam; i++){
        printf("%d ", vetDem->vetDem[i]);
    }    
    printf("|\n");
}
