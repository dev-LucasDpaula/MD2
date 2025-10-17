#include <stdio.h>

int main() {

    int numero_itens;

    scanf("%d", &numero_itens);

    int vetor[numero_itens];

    for(int i = 0; i < (numero_itens); i++){
        scanf("%d", &vetor[i]);
    }

    int ativas = 0;
    int ano = 0;

    while (ativas == 0 && ano < 50){

        ano++;
        ativas = 1;

        for(int i = 0; i < (numero_itens); i++){
            if (ano % vetor[i] != 0){
                ativas = 0;
                break;
            }
        }
    }

    if (ativas == 1){
        printf("Ano em que todas estão ativas: %d\n", ano);
    } else {
        printf("Não há ano em que todas então ativas.\n");
    }

}