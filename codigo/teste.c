#include "permuta.h"
#include <stdio.h>

int main(void){
    Tpermuta permuta;
    int j = 5;
    int lista[5];
    for (int i = 0; i < j; i++){
        lista[i] = i+1;
    }
    permuta = inicializaPermuta(j, lista, 4);
}