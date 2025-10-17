#include <stdio.h>

int main() {

    int numero_itens;

    scanf("%d", &numero_itens);

    int vetor[numero_itens];

    for(int i = 0; i < (numero_itens + 1); i++){
        scanf("%d", &vetor[i]);
    }

}