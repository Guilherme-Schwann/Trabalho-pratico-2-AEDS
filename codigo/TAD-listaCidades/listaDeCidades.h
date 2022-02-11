#include "../TAD-cidade/cidade.h"

typedef struct{
    int** distancias;
    Tcidade *listaCidades;
    int numCidades;
    int capacidadeVeic;
} TlistaDeCidades;

TlistaDeCidades inicializaLista(int N, int capacidadeVeiculos);

void registraDistancias(TlistaDeCidades* lista, int** dist);
void registraDemandas(TlistaDeCidades* lista, int* dem);