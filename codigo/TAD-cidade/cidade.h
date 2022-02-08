#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int ind;
    int demanda;
    int passouCarga;
} Tcidade;

Tcidade criaCidade(int ind, int demanda);

void passarCarga(Tcidade* cidade);
void esvaziaCarga(Tcidade* cidade);

void setDemanda(int demanda, Tcidade* cidade);
