#include <stdio.h>

int main() {

    printf("\n");
    printf("QUESTÃO 2\n");

    printf("Digite o número de chaves: ");
    int numero_chaves;
    scanf("%d", &numero_chaves);
    
    printf("\n");

    printf("Digite as chaves: ");
    int vetor[numero_chaves];
    for(int i = 0; i < (numero_chaves); i++){
        scanf("%d", &vetor[i]);
    }

    int ativas = 0;
    int ano = 0;

    printf("\n");
    printf("Começando Verificação\n");

    while (ativas == 0 && ano < 50){

        ano++;
        ativas = 1;
        
        printf("\n");
        printf("Ano: %d\n", ano);

        for(int i = 0; i < (numero_chaves); i++){
            if (ano % vetor[i] != 0){
                ativas = 0;
                printf("Ano %d: Chave %d está inativo.\n", ano, i+1);
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