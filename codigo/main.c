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

/* Includes e Defines */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_ARQUIVOS_TESTE 7

/* Declarações */

void leitura_arquivos();
void nome_arquivo_testes(unsigned int num_teste, char* nome_arquivo);


/* Funções */

// Função principal. Entrada obtida através de arquivo
int main()
{
    // Declarações
    clock_t start, end;  // cock_t YEP COCK (Clock)

    start = clock();
    leitura_arquivos();
    end = clock();
    
    double tempo_gasto = ((double) (end - start) / CLOCKS_PER_SEC);  // Registra tempo gasto
}

// Função para leitura dos arquivos
void leitura_arquivos()
{
    // Declarações
    int N;  // Quantidade de cidades, linha 1
    int Qv;  // Capacidade do caminhão, linha 2
    int* Qi;  // Demanda de cada cidade, linha 3, implementada como vetor
    int Ci, Cj, Dij;  // Cidade i, Cidade j, Distância entre cidades i e j, linhas seguintes
    FILE* input;  // Arquivo de entrada
    FILE* output;  // Arquivo de saída (possivelmente necessario)

    for (int num_teste = 1; num_teste <= NUM_ARQUIVOS_TESTE; num_teste++)  // Percorre todos os arquivos de teste
    {
        char nome_arquivo[31];
        nome_arquivo_testes(num_teste, &nome_arquivo);  // ? deve ta certo ?
        input = fopen(nome_arquivo, "r");  // Abre o arquivo para leitura

        /* 
         * Atribuições 
         *
         */

        // Linha 1
        fscanf(input, "%d", &N);  // Recebe a quantidade de cidades

        // Linha 2
        fscanf(input, "%d", &Qv);  // Recebe a capacidade de um caminhão

        // Linha 3
        // ok não sei como vou fazer ainda pq esse número depende então vo parar

        // permuta()
        // calcula_distancia()
        //       
    }

}

// Escolhe os arquivos a partir do número de teste
void nome_arquivo_testes(unsigned int num_teste, char* nome_arquivo)
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