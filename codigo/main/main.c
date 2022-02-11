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
 */

#include "distancias.h"
#include "demandas.h"
#include "../TAD-permuta/permuta.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define PRIMEIRO_ARQUIVO_TESTE 1
#define NUM_ARQUIVOS_TESTE 7

/* Declarações */

void leitura_arquivos(int num_teste, char* pnome_arquivo);
void nome_arquivo_testes(int num_teste, char* pnome_arquivo);
void formata_tempo(char* str_tempo);

/* Funções */

// Função principal
int main()
{
    // Declarações
    clock_t start, end;  // Clock
    int num_teste = 0;  // Número de teste dos arquivos
    char *pnome_arquivo;  // Nome do arquivo lido para input
    char *str_tempo;  // String de tempo
    FILE* output;  // Arquivo de saída

    printf("Escolha um numero de arquivo de teste (1 a 7): ");
    scanf("%d", &num_teste);
    if (num_teste < PRIMEIRO_ARQUIVO_TESTE || num_teste > NUM_ARQUIVOS_TESTE)
    {
        printf("Nao ha arquivo com esse numero");
        exit(TRUE);
    }
    nome_arquivo_testes(num_teste, pnome_arquivo);  

    /* Medição de tempo do algoritmo */
    start = clock();
    leitura_arquivos(num_teste, pnome_arquivo);
    end = clock();
    
    double tempo_gasto = ((double)(end - start) / CLOCKS_PER_SEC);  // Registra tempo gasto
    printf("Tempo gasto para permutação: %lf seg\n", tempo_gasto);

    /* Após printar em console, o tipo de teste e o tempo são registrados em um arquivo
     * Formato segue assim:
     * DATA_ATUAL NUM_TESTE TEMPO_GASTO
     */

    formata_tempo(str_tempo);  // Salva a data e hora atual para salvar no output

    output = fopen("output.txt", "r+");

    fseek(output, 0, SEEK_END);  // Feito para imprimir na última linha
    fprintf(output, "%s %d %lf\n", str_tempo, num_teste, tempo_gasto);
    fclose(output);
    system("PAUSE");
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
    int tam, i;
    Tdemandas *vetDem;

    TlistaDeCidades listac;
    Tpermuta permutador;
    
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
    num_linhas = combinacao(N, 2);
    for (int k = 0; k < num_linhas; k++)
    {
        fscanf(input, "%d %d %d", &Ci, &Cj, &Dij);
        preencher_matDist(matDist, Ci, Cj, Dij);
    }
    for (int k = 0; k < N; k++){
        for (int j = 0; j < N; j++){
            printf("%d ", matDist->matDist[k][j]);
        }
        printf("\n");
    }

    fclose(input);     

    // Permutação
    listac = inicializaLista(N, Qv);
    registraDistancias(&listac, matDist->matDist);
    registraDemandas(&listac, vetDem->vetDem);
    permutador = inicializaPermuta(listac);

    printf("Teste numero %d\n", num_teste);
    
    printf("Numero de Cidades = %d\n", N);
    printf("Capacidade Caminhao = %d\n", Qv);
    exibir_vetDem(vetDem);
    exibir_matDist(matDist);
    printf("Melhor distância encontrda: %d\n", permutador.melhorDist);
    printf("Melhor rota encontrada:\n");
    for (i = 0; i < (N-1)*3; i++){
        printf("%d ", permutador.melhorRota[i]);
    }
    printf("\n");
}

// Escolhe os arquivos a partir do número de teste
void nome_arquivo_testes(int num_teste, char* nome_arquivo)
{
    /* Caso mais testes sejam criados, manutenção aqui é necessária */
    
    switch (num_teste)  
    {
        case 1:
            strcpy(nome_arquivo, "../3_cidades.txt");
            break;
        case 2:
            strcpy(nome_arquivo, "../4_cidades.txt");
            break;
        case 3:
            strcpy(nome_arquivo, "../5_cidades.txt");
            break;
        case 4:
            strcpy(nome_arquivo, "../6_cidades.txt");
            break;
        case 5:
            strcpy(nome_arquivo, "../7_cidades.txt");
            break;
        case 6:
            strcpy(nome_arquivo, "../8_cidades.txt");
            break;
        case 7:
            strcpy(nome_arquivo, "../9_cidades.txt");
            break;

        // Caso de erro
        default:
            printf("Arquivo nao existe.\n");
            exit(1);
    }
}

// Formata tempo atual para salvar no output
void formata_tempo(char* str_tempo)
{
    time_t tempo_unix;
    struct tm* tempo_info;
    
    time(&tempo_unix);  // Pega tempo em unix
    tempo_info = localtime(&tempo_unix);  // Converte tempo em unix para tempo local
    
    sprintf(str_tempo,  // String de output
        "[%d %d %d %d:%d:%d]",  // Formato
        tempo_info->tm_mday,  // Dia
        tempo_info->tm_mon + 1, // Mês
        tempo_info->tm_year + 1900,  // Anos desde 1900
        tempo_info->tm_hour,  // Hora
        tempo_info->tm_min,  // Minuto
        tempo_info->tm_sec);  // Segundo
}
