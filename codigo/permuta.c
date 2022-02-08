#include <stdio.h>
#include <string.h>
#include "permuta.h"

int fatorial(int n)
{
    if (n>0)
        return n*fatorial(n-1);
    else
        return 1;
}

void troca_char(int* lista, int p1, int p2)
{
    int tmp;
    tmp = lista[p1];
    lista[p1] = lista[p2];
    lista[p2] = tmp;
}

void permutacao_recursiva(Tpermuta *permuta, int k)
{
    int i,j;
    int tam = permuta->tam;

    if (k == tam){
        for (j = 0; j < tam; j++){
            permuta->matrizRes[permuta->var][j] = permuta->lista[j];
        }
        permuta->var++;
    }
    else
    {
        for (i = k; i < tam; i++)
        {
            troca_char(permuta->lista, k, i);
            permutacao_recursiva(permuta, k + 1);
            troca_char(permuta->lista, i, k);
        }
    }
}

void lista_permutacoes(Tpermuta *permuta)
{
    permuta->numdeperm = fatorial(permuta->tam);
    permuta->matrizRes = (int**) malloc(sizeof(int)*permuta->tam*permuta->numdeperm);
    permutacao_recursiva(permuta, 0);
}

int main(void) {
    int lista[3];
    lista[0] = 1; lista[1] = 2; lista[2] = 3;
    Tpermuta permuta;
    permuta.tam = 3;
    permuta.lista = lista;
    permuta.var = 0;
    lista_permutacoes(&permuta);
}
