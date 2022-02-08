#include "../TAD-cidade/cidade.h"

typedef struct {
    int capacidadeIndividual;
    int veiculosNecessarios;
} TfrotaVeiculos;

typedef struct {
    int** distancias;
    Tcidade *listaCidades;
    int numCidades;
    TfrotaVeiculos frota;
} TlistaDeCidades;

TlistaDeCidades inicializaLista(int N, int capacidadeVeiculos);

void registraDistancias(TlistaDeCidades lista, int** dist);

void setCapacidadeVeic(int capacidade, TlistaDeCidades* lista);