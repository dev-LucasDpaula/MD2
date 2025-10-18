#include <stdio.h>

int main() {

    //printf("\n");
    //printf("QUESTAO 2\n");

    //printf("Digite o numero de chaves: ");
    int numero_chaves;
    scanf("%d", &numero_chaves);
    
    //printf("\n");

    //printf("Digite as chaves: ");
    int vetor[numero_chaves];
    for(int i = 0; i < (numero_chaves); i++){
        scanf("%d", &vetor[i]);
    }

    int ativas = 0;
    int ano = 0;

    //printf("\n");
    //printf("Começando Verificacao\n");

    while (ativas == 0 && ano < 50){

        ano++;
        ativas = 1;
        
        //printf("\n");
        //printf("Ano: %d\n", ano);

        for(int i = 0; i < (numero_chaves); i++){
            if (ano % vetor[i] != 0){
                ativas = 0;
                //printf("Ano %d: Chave %d esta inativo.\n", ano, vetor[i]);
                break;
            }
        }
    }

    if (ativas == 1){
        printf("Ano em que todas estao ativas: %d\n", ano);
    } else {
        printf("Nao ha ano em que todas entao ativas.\n");
    }

}