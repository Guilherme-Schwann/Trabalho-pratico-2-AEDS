#include <stdio.h>
#include <string.h>

typedef char * string;

void main(void)
{
  int lista[] = {1,2,3,4};
  int tam = 4;
  lista_permutacoes(lista, tam);
}

void troca_char(string str, int p1, int p2)
{
  char tmp;
  tmp = str[p1]; 
  str[p1] = str[p2]; 
  str[p2] = tmp;
}

void permutacao_recursiva(int* lista, int k)
{
  int i, len;
  len = strlen(str);

  if (k == len) 
    printf( "%s\n", str);
  else 
  {
    for (i = k; i < len; i++) 
    {
      troca_char(str, k, i);
      permutacao_recursiva(str, k + 1);
      troca_char(str, i, k);
    }
  }
}

void lista_permutacoes(int* lista)
{
  permutacao_recursiva(lista, 0);
}

void main(void)
{
  int lista[] = {1,2,3,4};
  lista_permutacoes(lista);
}