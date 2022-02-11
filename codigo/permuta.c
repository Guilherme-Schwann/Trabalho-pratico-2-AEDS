#include "permuta.h"

int numDePermutacoes(int tam);
void gera_permutacoes(Tpermuta* permuta);
void gera_combinacoes(Tpermuta* permuta);
void permutacao_recursiva(Tpermuta* permuta, int k);
void troca_char(int* lista, int p1, int p2);
int combinacao(int n, int p);
void geraMatrizFinal(Tpermuta* permuta);
void insereZeros(Tpermuta* permuta, int* posZeros, int linhaPermuta, int linhaMF);
void insereZeroInicial(Tpermuta* permuta, int linhaMF);

Tpermuta inicializaPermuta(TlistaDeCidades lista){
    Tpermuta permuta;
    int i, j, tam;
    tam = lista.numCidades;
    permuta.var = 0;
    permuta.tam = tam;
    permuta.numdeperm = numDePermutacoes(tam);
    //Aloca memória;
    permuta.lista = (int*) malloc(tam * sizeof(int));
    permuta.matrizRes = (int**) malloc(permuta.numdeperm * sizeof(int*));
    for (i = 0; i < permuta.numdeperm; i++){
        permuta.matrizRes[i] = (int*) malloc(tam * sizeof(int));
    }
    //Define a lista dentro do TAD permuta;
    for (i = 0; i < tam; i++){
        permuta.lista[i] = i+1;
    }
    gera_permutacoes(&permuta);
    gera_combinacoes(&permuta);
    escolhe_melhor_rota(&permuta, lista);
    return permuta;
}

void gera_permutacoes(Tpermuta* permuta)
{
    permutacao_recursiva(permuta, 0);
}

int numDePermutacoes(int tam)
{
    if (tam>0)
        return tam*numDePermutacoes(tam-1);
    else
        return 1;
}

void permutacao_recursiva(Tpermuta* permuta, int k)
{
    int i, len, j;
    len = permuta->tam;

    if (k == len){
        for (j = 0; j < permuta->tam; j++){
            permuta->matrizRes[permuta->var][j] = permuta->lista[j];
        }
        permuta->var++;
    }
    else
    {
        for (i = k; i < len; i++)
        {
            troca_char(permuta->lista, k, i);
            permutacao_recursiva(permuta, k + 1);
            troca_char(permuta->lista, i, k);
        }
    }
}

void troca_char(int* lista, int p1, int p2)
{
    int tmp;
    tmp = lista[p1];
    lista[p1] = lista[p2];
    lista[p2] = tmp;
}

/*  Function to generate combination  */
void combinationUtil(int arr[], int data[], int start, int end, int index, int r, Tpermuta* permuta)
{
    int j, i;
    // Current combination is ready to be printed, print it
    if (index == r) {
        for (j = 0; j < r; j++){
            permuta->matrizComb[permuta->var][j] = data[j];
        }
        permuta->var++;
        return;
    }

    // replace index with all possible elements. The condition
    // "end-i+1 >= r-index" makes sure that including one element
    // at index will make a combination with remaining elements
    // at remaining positions
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i + 1, end, index + 1, r, permuta);
    }
}
/*  End of combinationutil()  */

/*  Function to print the combination  */
void generateCombination(int arr[], int n, int r, Tpermuta* permuta)
{
    int *data;
    data = (int*) malloc(sizeof(int)*r);
    combinationUtil(arr, data, 0, n - 1, 0, r, permuta);
}
/*  End of printCombination()  */

void gera_combinacoes(Tpermuta* permuta){
    int i, j, r, n = permuta->tam - 1;
    permuta->var = 0;
    int *arr;
    arr = (int*) malloc(sizeof(int)*n);
    int totalComb = 0;
    for (i = 0; i < n; i++){
        arr[i] = i+1;
    }
    for (i = 1; i <= n; i++){
        totalComb+= combinacao(n,i);
    }
    permuta->numdecomb = totalComb;
    permuta->matrizComb = (int**) malloc(totalComb * sizeof(int*));
    for (i = 0; i<totalComb; i++){
        permuta->matrizComb[i] = (int*) malloc(n*sizeof(int));
    }
    for (i = 0; i < totalComb; i++){
        for (j = 0; j < n; j++){
            permuta->matrizComb[i][j] = 0;
        }
    }
    for (r = 1; r<=5; r++)
        generateCombination(arr, n, r, permuta);
    permuta->matrizFinal = (int**) malloc((((permuta->var+2) * permuta->numdeperm)) * sizeof(int*));
    for (i = 0; i < ((permuta->var+2) * permuta->numdeperm); i++){
        permuta->matrizFinal[i] = (int*) malloc((3*permuta->tam)*sizeof(int));
    }
    geraMatrizFinal(permuta);
}

int fatorial(int n)
{
    if (n>0)
        return n*fatorial(n-1);
    else
        return 1;
}

int arranjo(int n, int p)
{
    if (p>1)
        return n*arranjo(n-1,p-1);
    else
        return n;
}

int combinacao(int n, int p)
{
    return arranjo(n,p)/fatorial(p);
}

void geraMatrizFinal(Tpermuta* permuta){
    int i, j, varlinha, varconta, linhaMF = 0;
    varlinha = 0;
    varconta = 0;
    for (i = 0; i<(permuta->var+2) * permuta->numdeperm; i++){
        for (j = 0; j < 3*permuta->tam; j++){
            if (j<permuta->tam){
                permuta->matrizFinal[i][j] = permuta->matrizRes[varlinha][j];
            } else {
                permuta->matrizFinal[i][j] = 0;
            }
        }
        varconta++;
        if(varconta == permuta->var+2){
            varlinha++;
            varconta = 0;
        }
    }
    for (i = 0; i < permuta->numdeperm; i++){
        for (j = 0; j < permuta->numdecomb+1; j++){
            if(j != 0){
                insereZeros(permuta, permuta->matrizComb[j-1], i, linhaMF);
            }
            insereZeroInicial(permuta, linhaMF);
            linhaMF++;
        }
    }
}

void insereZeros(Tpermuta* permuta, int posZeros[], int linhaPermuta, int linhaMF){
    int i, j, temp, mod = 0;
    for (i = 0; i < permuta->tam-1; i++){
        if (posZeros[i] != 0){
            for (j = permuta->tam - 1 + mod; j >= posZeros[i] + mod; j--){
                temp = permuta->matrizFinal[linhaMF][j];
                permuta->matrizFinal[linhaMF][j] = permuta->matrizFinal[linhaMF][j+2];
                permuta->matrizFinal[linhaMF][j+2] = temp;
            }
            mod += 2;
        }
    }
}

void insereZeroInicial(Tpermuta* permuta, int linhaMF) {
    int i, temp;
    for (i = (permuta->tam*3) - 2; i >= 0; i--){
        temp = permuta->matrizFinal[linhaMF][i];
        permuta->matrizFinal[linhaMF][i] = permuta->matrizFinal[linhaMF][i+1];
        permuta->matrizFinal[linhaMF][i+1] = temp;
    }
}

int calculaDist(int* rota, TlistaDeCidades lista){
    int i, linha, coluna, dist = 0, cap = 0;
    for (i = 0; i < (lista.numCidades*3)-1; i++){
        if (rota[i] != 0){
            cap+=lista.listaCidades->demanda;
            if (cap > lista.capacidadeVeic){
                return 0;
            }
        } else {
            cap = 0;
        }
        linha = rota[i];
        coluna = rota[i+1];
        dist += lista.distancias[linha][coluna];
    }
    return dist;
}

void escolhe_melhor_rota(Tpermuta *permuta, TlistaDeCidades lista){
    int i, *vendoRota, dist, melhorDist, *melhorRota;
    vendoRota = (int*) malloc(lista.numCidades * sizeof(int));
    for (i = 0; i < (permuta->numdecomb+1) * permuta->numdeperm; i++){
        vendoRota = permuta->matrizFinal[i];
        dist = calculaDist(vendoRota, lista);
        if (i == 0) {
            melhorDist = dist;
            melhorRota = vendoRota;
        } else if (dist != 0 && (dist < melhorDist || melhorDist == 0)) {
            melhorDist = dist;
            melhorRota = vendoRota;
        }
    }
    permuta->melhorRota = melhorRota;
    permuta->melhorDist = melhorDist;
}
