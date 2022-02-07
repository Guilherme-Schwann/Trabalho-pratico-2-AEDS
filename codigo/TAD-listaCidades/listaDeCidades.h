#include "../TAD-cidade/cidade.h"

typedef struct {
    int capacidadeIndividual;
    int veiculosNecessarios;
} TfrotaVeiculos;

typedef struct {
    int** distancias;
    Tcidade *listaCidades;
    TfrotaVeiculos frota;
} TlistaDeCidades;

TlistaDeCidades inicializaLista(int N, int capacidadeVeiculos);

void registraDistancias(TlistaDeCidades lista, int** dist);