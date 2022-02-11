/*
 * --------------------------------
 * main - Implementação
 * Trabalho Prático realizado por:
 * Guilherme Augusto Schwann Wilke
 * Letícia Oliveira Silva
 * Lucas Barbosa Pena
 *
 * Universidade Federal de Viçosa
 * --------------------------------
*/

/* 
 * Includes e Defines 
 *
 * aqui voce ve um "definer" em seu habitat natural
 */

#include "distancias.h"
#include "demandas.h"
#include "permuta.h"
#include "listaDeCidades.h"
#include <time.h>

#define MAX_CHAR_LIMIT 31
#define TRUE 1
#define PRIMEIRO_ARQUIVO_TESTE 1
#define NUM_ARQUIVOS_TESTE 7

/* Declarações */

void leitura_arquivos(int num_teste, char* pnome_arquivo);
void nome_arquivo_testes(int num_teste, char* pnome_arquivo);

/* Funções */

// Função principal. Entrada obtida através de arquivo
int main()
{
    // Declarações
    clock_t start, end;  // cock_t YEP COCK (Clock)
    int num_teste = 0;  // Número de teste dos arquivos
    char nome_arquivo[MAX_CHAR_LIMIT];
    char *pnome_arquivo = nome_arquivo;

    printf("Escolha um numero de arquivo de teste (1 a 7): ");
    scanf("%d", &num_teste);
    if (num_teste < PRIMEIRO_ARQUIVO_TESTE || num_teste > NUM_ARQUIVOS_TESTE)
    {
        printf("Nao ha arquivo com esse numero");
        exit(TRUE);
    }
    nome_arquivo_testes(num_teste, pnome_arquivo);  

    start = clock();
    leitura_arquivos(num_teste, pnome_arquivo);
    end = clock();
    
    double tempo_gasto = ((double) (end - start) / CLOCKS_PER_SEC);  // Registra tempo gasto
    printf("Tempo gasto para permutação: %lf", tempo_gasto);

    return 0;
}

// Função para leitura dos arquivos
void leitura_arquivos(int num_teste, char* pnome_arquivo)
{
    // Declarações
    int N;  // Quantidade de cidades, linha 1
    int Qv;  // Capacidade do caminhão, linha 2
    int D;  // Demanda de cada cidade, linha 3, implementada como vetor
    int Ci, Cj, Dij;  // Cidade i, Cidade j, Distância entre cidades i e j, linhas seguintes
    
    FILE* input;  // Arquivo de entrada
    FILE* output;  // Arquivo de saída (possivelmente necessario)
    
    /* 
     * 
     * Atribuições 
     *
     */

    input = fopen(pnome_arquivo, "r");  // Abre o arquivo para leitura

    // Linha 1
    fscanf(input, "%d", &N);  // Recebe a quantidade de cidades

    // Linha 2
    fscanf(input, "%d", &Qv);  // Recebe a capacidade de um caminhão

    // Linha 3
    int tam;
    Tdemandas *vetDem;
    
    tam = N-1;
    vetDem = criar_vetDem(tam);
    
    for (int i=0;i<tam;i++)
    {
        fscanf(input, "%d", &D);
        preencher_vetDem(vetDem,i,D);
    }
    
    // Restante das linhas
    Tdistancias *matDist;
    matDist = criar_matDist(N);
    
    int num_linhas;
    if (N == 3)    
    {
        for (int k = 0; k <= N; k++)
        {
            fscanf(input, "%d %d %d", &Ci, &Cj, &Dij);
            preencher_matDist(matDist, Ci, Cj, Dij);
        }
        else
        {
            num_linhas = N + (N-1);
            for (int k = 0; k <= num_linhas; k++)
            {
                fscanf(input, "%d %d %d", &Ci, &Cj, &Dij);
                preencher_matDist(matDist, Ci, Cj, Dij);
            }
        }
    }

    fclose(input);     

    // Permutação
    listac = inicializaLista(N, Qv);
    permutador = inicializaPermuta(listac);

    printf("Teste numero %d\n", num_teste);
    
    printf("Numero de Cidades = %d\n", N);
    printf("Capacidade Caminhao = %d\n", Qv);
    exibir_vetDem(vetDem);
    exibir_matDist(matDist);
    exibir_permuta(permutador);
    }

}

// Escolhe os arquivos a partir do número de teste
void nome_arquivo_testes(int num_teste, char* nome_arquivo)
{
    /* Caso mais testes sejam criados, manutenção aqui é necessária */
    
    switch (num_teste)  
    {
        case 1:
            strcpy(nome_arquivo, "3_cidades.txt");
            break;
        case 2:
            strcpy(nome_arquivo, "4_cidades.txt");
            break;
        case 3:
            strcpy(nome_arquivo, "5_cidades.txt");
            break;
        case 4:
            strcpy(nome_arquivo, "6_cidades.txt");
            break;
        case 5:
            strcpy(nome_arquivo, "7_cidades.txt");
            break;
        case 6:
            strcpy(nome_arquivo, "8_cidades.txt");
            break;
        case 7:
            strcpy(nome_arquivo, "9_cidades.txt");
            break;

        // Caso de erro
        default:
            printf("Arquivo nao existe.\n");
            exit(1);
    }
}
