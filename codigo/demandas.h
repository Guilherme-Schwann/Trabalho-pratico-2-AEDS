#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int tam;
    int *vetDem;
}Tdemandas;

Tdemandas* criar_vetDem(int n);

void preencher_vetDem(Tdemandas *vetDem, int i, int dem);

void exibir_vetDem(Tdemandas *vetDem);
